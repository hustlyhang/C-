#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



int ret = 0;

int dd(vector<int>& nums, int start) {
    //? �������ֲ��������ʱ�����������
    /*
        * һ��1,2������
        * ����2��3 ������
        
    */
   int a = start, b= start + 1, c = start + 2;
   int len = nums.size();

   //? ��ǰ������ȫ������
   if (a < len && b < len && c < len && nums[a] <= nums[b] && nums[b] <= nums[c] && nums[b] - nums[a] <= 10 && nums[c] - nums[b] <= 10) {
       return 3;
   }

   //? ǰ������������
   if (a < len && b < len && nums[b] - nums[a] > 10 && nums[b] - nums[a] <= 20) {
       //? ��Ҫ���һ����
       ret++;
       return 2;
   }
    //? ǰ������������
   if (a < len && b < len && nums[b] - nums[a] > 20) {
       //? ��Ҫ���������
       ret+=2;
       return 1;
   }
   //? ǰ����������
   if (a < len && b < len  && nums[b] - nums[a] <= 10) {
       //? ��Ҫ���һ����
       ret+=1;
       return 2;
   }
   //? ֻʣ���һ������
   if (a == len - 1) {
       ret+=2;
       return 1;
   }
   return 0;
}

int main() {

    int n = 0;
    cin>>n;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; ++i) {
        cin>> nums[i];
    }

    sort(nums.begin(), nums.end());

    int k = 0;
    while (k < n) {
        //cout<<"k="<<k<<endl;
        k+=dd(nums, k);
    }
    
    cout<< ret;


    return 0;
}