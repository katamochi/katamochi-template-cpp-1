#include <iostream> // cout, endl, cin,gcd,lcm
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include<random>

using namespace std;

#define pi = 2*asin(1) //円周率
#define rep(i,n) for(i=0;i<n;i++)　//for文
#define rep_ini(i,initial,n) for(i=initial;i<n;i++)　//for文（初期定数値）
#define rep_sta(e,vec) for(auto &a:vec)//範囲for
#define if_choose(if_case,t,f)  id_case: t ?f　//if文（3項演算子）
#define pb push_back　//プッシュバック
#define read(a) cin>>a　//読み取り
#define write(a) cout<<a<<endl　//書き出し
#define all(v) v.begin(),v.end()　//vectorなど全体

//Σ(0→k)x
template <typename T> T siguma_func_one(T k) {
	return (k * (k + 1)) / 2;
}
//Σ(0→k)x^2
template <typename T> T siguma_func_two(T k) {
	return (k * (k + 1) * (2 * k + 1)) / 6;
}
//Σ(0→k)x^3
template <typename T> T siguma_func_three(T k) {
	return powl(siguma_func_one(k), 2);
}
//正の整数の桁数
template<typename T>T number_usigned_int_disdigit_rank(T x) {
	return (floorl((log10l(x))) + 1);
}
//ある数で割り続ける
template<typename T>T split_num(T x, T y) {
	T ans = 0;
	if ((x % y) == 0) {
		ans = split_num((x / y), y);
		ans++;
	}
	return ans;
}
//2つの平均
template<typename T>T ave_two(T x, T y) {
	return((x + y) / 2);
}
//1変数最適化_二分木
template<typename T>T optimation_one(T func(T), T x, T y, T tolerate) {
	T ans;
	if (abs(x - y) <= tolerate) {
		ans = ave_two(x, y);
	}
	else {
		if (func(x) <= func(y)) {
			y = ave_two(x, y);
		}
		else {
			x = ave_two(x, y);
		}
		ans = optimation_one(func, x, y, tolerate);
	}
	return ans;
}
//積分
//台形
template<typename T, typename U> T integral_trapezoid(T func(T), T min, T max, U n) {
	T pitch;
	pitch = (max - min) / n;
	T x = min;
	T ans1 = func(x);
	T ans2;
	T ans_re = 0;
	while (x < max)
	{
		x += pitch;
		ans2 = func(x);
		ans_re += (ave_two(ans1, ans2)) * pitch;
		ans1 = ans2;
	}
	return ans_re;
}
//MC
template<typename T, typename U> T integral_rand(T func(T), T min, T max, U n) {
	T ans = 0;
	U  i;
	random_device seed1;
	uniform_real_distribution<>dist(min, max);
	rep(i, n) {
		ans += (func(dist(seed1)));
	}
	return((max - min) * ans / n);
}
//中点則
template<typename T, typename U> T integral_rectangle(T func(T), T min, T max, U n) {
	T pitch;
	pitch = (max - min) / n;
	T x = min;
	T ans1;
	T ans_re = 0;
	while (x < max)
	{
		x += (pitch / 2);
		ans1 = func(x);
		ans_re += (ans1 * pitch);
		x += (pitch / 2);
	}
	return ans_re;
}
//入れ替え
template <typename T> void swep(T& a, T& b) {
	T tmp;
	tmp = a;
	a = b;
	b = tmp;
}
int main() {

}