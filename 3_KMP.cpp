/*
输入
第一行一个整数N，表示测试数据组数。

接下来的N*2行，每两行表示一个测试数据。在每一个测试数据中，第一行为模式串，由不超过10^4个大写字母组成，第二行为原串，由不超过10^6个大写字母组成。

其中N<=20

输出
对于每一个测试数据，按照它们在输入中出现的顺序输出一行Ans，表示模式串在原串中出现的次数。
Sample input
5
HA
HAHAHA
WQN
WQN
ADA
ADADADA
BABABB
BABABABABABABABABB
DAD
ADDAADAADDAAADAAD
Sample Output
3
1
3
1
0
*/

#include <cstring>
#include <string>
#include <cstdio>
#include <iostream>
using namespace std;

#include <cstring>
#include <cstdio>
using namespace std;

void getNextArr(char * p, int next[]) {
	int len = strlen(p);
	next[0] = -1;
	int j = 1, k;
	while (j < len) {
		k = next[j - 1];
		while (true) {
			if (k == -1 || p[k] == p[j - 1]) {
				next[j++] = k + 1;
				break;
			}
			else
				k = next[k];
		}
	}
}
int kmpSearch(char * p, char * s, int next[]) {
	int cnt = 0;
	int i = 0, j = 0;
	int plen = strlen(p), slen = strlen(s);
	if (plen == 0)
		return 0;
	while (i < slen) {
		if (j == -1 || s[i] == p[j]) {
			++j;
			if (j == plen) {
				++cnt;
				j = next[j - 1];
			}
			else
				++i;
		}
		else
			j = next[j];
	}
	return cnt;
}
int main() {
	int n;
	scanf("%d", &n);
	char p[10005], s[1000005];
	int next[1000];
	while (n--) {
		scanf("%s%s", p, s);
		getNextArr(p, next);
		printf("%d\n", kmpSearch(p, s, next));
	}
}

/*
1
DABCDABDE
DABCDABDE


*/