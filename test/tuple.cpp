#include <iostream>
#include <string>
#include <tuple>
#include <utility>
#include <functional>	// ref

// ���� std::tie() �� std::make_tuple() ����ͬ

using namespace std;

#ifdef TUPLE
template<class T1, class T2>
ostream& operator<<(ostream& out, const pair<T1, T2>& _)
{
    return out << "(" << _.first << ", " << _.second << ")";
}


void display_separator() { cout << "--------" << endl; }

int main()
{
    string name = "alice";
    char rank = 'A';
    int score = 5;

    auto student = make_tuple(name, rank, score);
    // => name: alice, rank: A, score: 5
    cout << "student> name: " << get<0>(student)
        << ", rank: " << get<1>(student)
        << ", score: " << get<2>(student) << endl;
    cout << "Here, (score, get<2>(student)) is "
        << make_pair(score, get<2>(student)) << endl;
    score += 10;
    cout << "        score   +=  10 => "
        << make_pair(score, get<2>(student)) << endl;
    get<2>(student) += 100;
    cout << "get<2>(student) += 100 => "
        << make_pair(score, get<2>(student)) << endl;
    return 0;
}

/*
student> name: alice, rank: A, score: 5
Here, (score, get<2>(student)) is (5, 5)
        score   +=  10 => (15, 5)
get<2>(student) += 100 => (15, 105)

˵��make_tuple ֻ�ǽ�ֵ�����˴���
Ĭ���´���һ����������ֱ�ӹ���������һ������
*/
#endif // TUPLE




#ifdef TIE
template<class T1, class T2>
ostream& operator<<(ostream& out, const pair<T1, T2>& _)
{
    return out << "(" << _.first << ", " << _.second << ")";
}

template<class T1, class T2, class T3>
ostream& operator<<(ostream& out, const tuple<T1, T2, T3>& _)
{
    auto [_1, _2, _3] = _;
    return out << "[" << _1 << ", " << _2 << ", " << _3 << "]";
}

void display_separator() { cout << "--------" << endl; }

int main()
{
    string names[3] = { "alice", "bob", "carl" };
    char ranks[3] = { 'A', 'B', 'C' };
    int score[3] = { 5, 6, 7 };

    int hoge;
    auto student0 = tie(names[0], ranks[0], score[0]);
    // => name: bob, rank: B, score: 6
    tie(std::ignore, std::ignore, hoge) = student0;
    cout << "student0> [hoge, score[0], get<2>(student0)] is "
        << make_tuple(hoge, score[0], get<2>(student0)) << endl;
    hoge += 10;
    cout << "            hoge +=   10 => "
        << make_tuple(hoge, score[0], get<2>(student0)) << endl;
    score[0] += 100;
    cout << "        score[0] +=  100 => "
        << make_tuple(hoge, score[0], get<2>(student0)) << endl;
    get<2>(student0) += 1000;
    cout << "get<2>(student0) += 1000 => "
        << make_tuple(hoge, score[0], get<2>(student0)) << endl;

    display_separator();

    auto student1 = make_tuple(names[1], ranks[1], score[1]);
    // => name: carl, rank: C, score: 7
    auto [_1, _2, piyo] = student1;
    cout << "student1> [piyo, score[1], get<2>(student1)] is "
        << make_tuple(piyo, score[1], get<2>(student1)) << endl;
    piyo += 10;
    cout << "            piyo +=   10 => "
        << make_tuple(piyo, score[1], get<2>(student1)) << endl;
    score[1] += 100;
    cout << "        score[1] +=  100 => "
        << make_tuple(piyo, score[1], get<2>(student1)) << endl;
    get<2>(student1) += 1000;
    cout << "get<2>(student1) += 1000 => "
        << make_tuple(piyo, score[1], get<2>(student1)) << endl;

    display_separator();

    auto student2 = tie(names[2], ranks[2], score[2]);
    // => name: carl, rank: C, score: 7
    auto [_3, _4, fuga] = student2;
    cout << "student2> [fuga, score[2], get<2>(student2)] is "
        << make_tuple(fuga, score[2], get<2>(student2)) << endl;
    fuga += 10;
    cout << "            fuga +=   10 => "
        << make_tuple(fuga, score[2], get<2>(student2)) << endl;
    score[2] += 100;
    cout << "        score[2] +=  100 => "
        << make_tuple(fuga, score[2], get<2>(student2)) << endl;
    get<2>(student2) += 1000;
    cout << "get<2>(student2) += 1000 => "
        << make_tuple(fuga, score[2], get<2>(student2)) << endl;
    return 0;
}

/*
student0> [hoge, score[0], get<2>(student0)] is [5, 5, 5]
            hoge +=   10 => [15, 5, 5]
        score[0] +=  100 => [15, 105, 105]
get<2>(student0) += 1000 => [15, 1105, 1105]

��������ܿ���ͨ��tie������tuple��ʹ�õ�����
std::tie() ��Ĭ�ϴ���ԭʼ���������ã�Ȼ���ڰ�װ�� tuple ���棻
--------
student1> [piyo, score[1], get<2>(student1)] is [6, 6, 6]
            piyo +=   10 => [16, 6, 6]
        score[1] +=  100 => [16, 106, 6]
get<2>(student1) += 1000 => [16, 106, 1006]

auto [_1, _2, piyo] ����������ݿ�����ԭԭ�����ĸ��ƣ�
--------
student2> [fuga, score[2], get<2>(student2)] is [7, 7, 7]
            fuga +=   10 => [17, 17, 17]
        score[2] +=  100 => [117, 117, 117]
get<2>(student2) += 1000 => [1117, 1117, 1117]
std::tie() ������ԭʼ���ݵ����ã����� auto [_3, _4, fuga] ���ʱͬ��������һ�����ó�����
*/

#endif // TIE

#ifdef AUTO

#include <type_traits>

void display_separator() { cout << "--------" << endl; }

int main()
{
    string names[4] = { "alice", "bob", "carl", "dell" };
    char ranks[4] = { 'A', 'B', 'C', 'D' };
    int score[4] = { 5, 6, 7, 8 };

    cout << std::boolalpha;

    int hoge;
    auto student0 = tie(names[0], ranks[0], score[0]);
    // => name: bob, rank: B, score: 6
    tie(std::ignore, std::ignore, hoge) = student0;
    cout << "0> " << std::is_same<int, decltype(hoge)>::value;
    cout << ", " << std::is_same<int&, decltype(hoge)>::value << endl;

    display_separator();

    auto student1 = make_tuple(names[1], ranks[1], score[1]);
    // => name: carl, rank: C, score: 7
    auto [_1, _2, piyo] = student1;
    cout << "1> " << std::is_same<int, decltype(piyo)>::value;
    cout << ", " << std::is_same<int&, decltype(piyo)>::value << endl;

    display_separator();

    auto student2 = tie(names[2], ranks[2], score[2]);
    // => name: carl, rank: C, score: 7
    auto [_3, _4, fuga] = student2;
    cout << "2> " << std::is_same<int, decltype(fuga)>::value;
    cout << ", " << std::is_same<int&, decltype(fuga)>::value << endl;

    display_separator();

    auto student3 = make_tuple(names[2], ranks[2], std::ref(score[2]));
    // => name: carl, rank: C, score: 7
    auto [_5, _6, pika] = student3;
    cout << "3> " << std::is_same<int, decltype(pika)>::value;
    cout << ", " << std::is_same<int&, decltype(pika)>::value << endl;

    display_separator();

    cout << "bonus> "
        << std::is_same<int&, decltype(std::get<2>(student0))>::value << ", "
        << std::is_same<int&, decltype(std::get<2>(student1))>::value << endl;
    return 0;
}
/*
0> true, false

--------
1> true, false
--------
2> false, true
--------
3> false, true
--------
bonus> true, true



std::make_tuple() �Լ� std::tie() �����Թ���һ�� tuple�����ߵ���������ǰ�߹��츴�ƣ����ߴ������ã���׼ȷ��˵���Ǻ��ߴ���һ����ֵ���ã�
std::get() ���������̶�λ�õ�ֵ���䷵��ֵ��Ԫ���ڲ�ֵ�����ã�
std::tie() ����������Ԫ�������ֵ������Ҫ��λ�ÿ�����ռλ�� std::ignore ���棬������ݵ����������ǻ������Ͷ����������ͣ�
C++17 ����� structured binding ���� auto [_1, _2, _3, ...] �ڽ��ʱ�ı����� std::tie() ���ơ�
*/

#endif // AUTO

#ifdef Id...

#include <tuple>
#include <iostream>
#include <array>
#include <utility> // index_sequence

// ���Ը���
template<typename T, T... ints>
void print_sequence(std::integer_sequence<T, ints...> int_seq)
{
    std::cout << "The sequence of size " << int_seq.size() << ": ";
    ((std::cout << ints << '`'), ...);
    std::cout << '\n';
}
// ��ģ�� std::integer_sequence ��ʾһ������ʱ���������С�����������ģ���ʵ��ʱ�����Ƶ������� Ints ���������ڰ�չ����
// 
// ת������Ϊ tuple
template<typename Array, std::size_t... I>
auto a2t_impl(const Array& a, std::index_sequence<I...>)
{
    return std::make_tuple(a[I]...);
}

template<typename T, std::size_t N, typename Indices = std::make_index_sequence<N>>
auto a2t(const std::array<T, N>& a)
{
    return a2t_impl(a, Indices{});
}

// Ư���ش�ӡ tuple

template<class Ch, class Tr, class Tuple, std::size_t... Is>
void print_tuple_impl(std::basic_ostream<Ch, Tr>& os, const Tuple& t, std::index_sequence<Is...>)
{
    ((os << (Is == 0 ? "" : ", ") << std::get<Is>(t)), ...);
}

template<class Ch, class Tr, class... Args>
auto& operator<<(std::basic_ostream<Ch, Tr>& os, const std::tuple<Args...>& t)
{
    os << "(";
    print_tuple_impl(os, t, std::index_sequence_for<Args...>{});
    return os << ")";
}

int main()
{
    print_sequence(std::integer_sequence<unsigned, 9, 2, 5, 1, 9, 1, 6>{});
    print_sequence(std::make_integer_sequence<int, 20>{});
    print_sequence(std::make_index_sequence<10>{});
    // index_sequence_for ��ת���κ����Ͳ�����Ϊͬ���ȵ��±����У�
    print_sequence(std::index_sequence_for<float, std::iostream, char>{});

    std::array<int, 4> array = { 1,2,3,4 };

    // ת�� array Ϊ tuple
    auto tuple = a2t(array);
    static_assert(std::is_same<decltype(tuple),
        std::tuple<int, int, int, int>>::value, "");

    // ��ӡ�� cout
    std::cout << tuple << '\n';
}

#endif // ...

#define INITIALIZER_LIST
#ifdef INITIALIZER_LIST

// ����initializer_list��ȡtuple�����ֵ
// ����initializer_list�Լ�
template<typename Tuple, std::size_t Id>
void pp() {
    printf("This is a test:%d\n", Id);
}

template<typename Tuple, std::size_t... I>
Tuple get_tuple(std::index_sequence<I...>) {
    Tuple t;
    initializer_list<int>{((pp<Tuple, I>()), 0)...};
    return t;
}

int main() {
    get_tuple<std::tuple<size_t>>(make_index_sequence<10>{});
}

#endif // INITIALIZER_LIST
