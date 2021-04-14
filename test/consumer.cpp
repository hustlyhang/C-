#pragma once

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <vector>



std::mutex _mtx;
std::condition_variable _cv_not_full;
std::condition_variable _cv_not_empty;

const int max_queue_size_10 = 10;

enum
{
	// ��������Ŀ
	cnt_total_10 = 10,
};


template<typename T>
struct repo_
{
	// ����������ʻ�����
	std::mutex				_mtx_queue;

	// ���������size
	unsigned int			_count_max_queue_10 = 10;

	// ������
	std::queue<T>			_queue;

	// ������û������֪ͨ�����߼�������
	std::condition_variable _cv_queue_not_full;

	// ��������Ϊ�գ�֪ͨ�����߼�������
	std::condition_variable _cv_queue_not_empty;



	// ����������֮��ľ���
	std::mutex				_mtx_pro;
	// ���㵱ǰ�Ѿ������˶���������
	unsigned int			_cnt_cur_pro = 0;


	// ����������֮��ľ���
	std::mutex				_mtx_con;
	// ���㵱ǰ�Ѿ����Ѷ���������
	unsigned int			_cnt_cur_con = 0;


	repo_(const unsigned int count_max_queue = 10) :_count_max_queue_10(count_max_queue)
		, _cnt_cur_con(0)

	{
		;
	}

	repo_(const repo_&instance) = delete;
	repo_& operator = (const repo_& instance) = delete;
	repo_(const repo_&&instance) = delete;
	repo_& operator = (const repo_&& instance) = delete;

};

template <typename T>
using repo = repo_<T>;





//----------------------------------------------------------------------------------------

// ��������������
template <typename T>
void thread_produce_item(const int &thread_index, repo<T>& param_repo, const T& repo_item)
{
	std::unique_lock<std::mutex> lock(param_repo._mtx_queue);

	// 1. ������ֻҪ���ֻ�����û������ �ͼ�������
	param_repo._cv_queue_not_full.wait(lock, [&] { return param_repo._queue.size() < param_repo._count_max_queue_10; });

	// 2. �������õ���Ʒ���뻺����
	param_repo._queue.push(repo_item);

	// log to console
	std::cout << "������" << thread_index << "�������ݣ�" << repo_item << "\n";

	// 3. ֪ͨ�����߿���������
	//param_repo._cv_queue_not_empty.notify_one();
	param_repo._cv_queue_not_empty.notify_one();
}


//----------------------------------------------------------------------------------------
// ��������������

template <typename T>
T thread_consume_item(const int thread_index, repo<T>& param_repo)
{
	std::unique_lock<std::mutex> lock(param_repo._mtx_queue);

	// 1. ��������Ҫ�ȴ�����������Ϊ�ա����ź�
	param_repo._cv_queue_not_empty.wait(lock, [&] {return !param_repo._queue.empty(); });

	// 2. �ó�����
	T item;
	item = param_repo._queue.front();
	param_repo._queue.pop();

	std::cout << "������" << thread_index << "�ӻ��������ó�һ������:" << item << std::endl;

	// 3. ֪ͨ�����ߣ���������
	param_repo._cv_queue_not_full.notify_one();

	return item;
}


//----------------------------------------------------------------------------------------

/**
*  @ brief: �������߳�
*  @ thread_index - �̱߳�ʶ����������һ���߳�
*  @ count_max_produce - �����������
*  @ param_repo - ������
*  @ return - void

*/
template< typename T >
void thread_pro(const int thread_index, const int count_max_produce, repo<T>* param_repo)
{
	if (nullptr == param_repo || NULL == param_repo)
		return;
	

	while (true)
	{
		bool is_running = true;

		{
			// ����������֮�侺��
			std::unique_lock<std::mutex> lock(param_repo->_mtx_pro);

			// ������û��������������
			if (param_repo->_cnt_cur_pro < cnt_total_10)
			{
				thread_produce_item<T>(thread_index, *param_repo, param_repo->_cnt_cur_pro);
				++param_repo->_cnt_cur_pro;
			}
			else
				is_running = false;
		}

		std::this_thread::sleep_for(std::chrono::microseconds(16));
		if (!is_running)
			break;
	}
}



/**
*  @ brief: �������߳�
*  @ thread_index - �̱߳�ʶ�������߳�
*  @ param_repo - ������
*  @ return - void

*/
template< typename T >
void thread_con(const int thread_index, repo<T>* param_repo)
{
	if (nullptr == param_repo || NULL == param_repo)
		return;

	while (true)
	{
		bool is_running = true;
		{
			std::unique_lock<std::mutex> lock(param_repo->_mtx_con);
			// ��û���ѵ�ָ������Ŀ����������
			if (param_repo->_cnt_cur_con < cnt_total_10)
			{
				thread_consume_item<T>(thread_index, *param_repo);
				++param_repo->_cnt_cur_con;
			}
			else
				is_running = false;

		}

		std::this_thread::sleep_for(std::chrono::microseconds(16));

		// �����߳�
		if ((!is_running))
			break;
	}
}


// ��ں���
//----------------------------------------------------------------------------------------

int main(int argc, char *argv[], char *env[])
{
	// ������
	repo<int> repository;
	// �̳߳�
	std::vector<std::thread> vec_thread;

	// ������
	vec_thread.push_back(std::thread(thread_pro<int>, 1, cnt_total_10, &repository));
	vec_thread.push_back(std::thread(thread_pro<int>, 2, cnt_total_10, &repository));

	// ������
	vec_thread.push_back(std::thread(thread_con<int>, 1, &repository));
	vec_thread.push_back(std::thread(thread_con<int>, 2, &repository));



	for (auto &item : vec_thread)
	{
		item.join();
	}

	return 0;
}
