#include<bits/stdc++.h>

/*
������������㷨�Ļ���˼�룺
1�����ڳ�ʼ״̬��ӣ����ó�ʼ״̬Ϊ�ѷ���
2��������в�Ϊ��ʱ�����Ӷ�ͷԪ�أ�����������5��
3�������ӵ�Ԫ���Ƿ�Ϊ���ս⣬�������������5����
4�����ڳ��ӵ�Ԫ�أ������������״̬�������Ч����δ���ʣ���
   ������Ч������״̬������ӣ�����������Щ״̬Ϊ�ѷ��ʣ�Ȼ��
   ������2���ظ�ִ��
5����������ӵ�Ԫ���Ƿ�Ϊ���ս⣬�����������������˵���޽�

������������ǽ����ڶ����������ݽṹ���������ģ����е��ص�����
���ȳ���FIFO����ͨ������queue�������ģ��ͷ�ļ����Ϳ�������c++
�Ķ���ģ�嶨���Լ��Ķ����ˣ����еĲ����ǳ��򵥣���Ҫ�����¼�����
q.push() ��Ӳ���
q.front() ȡ��ͷԪ��
q.pop() ��ͷԪ�س���
q.size() ��ȡ���е�Ԫ�ظ���
q.empty() �ж϶����Ƿ�Ϊ�գ�Ϊ�շ���true����Ϊ�շ���false

������������㷨�Ĺؼ���Ҫ�������������ÿһ��������״̬����Щ��
ÿ��״̬��Ҫ��¼ʲô��Ϣ����������������α����Щ״̬Ϊ�ѷ��ʡ�

�ڱ����У�����״̬Ϊ��ǰ����¥��ͨ�������ϻ����°�ť���ܵ����¥
�㣬ÿ��״̬Ҫ��¼����Ϣ����¥���źͰ���ť�Ĵ�����
*/

using namespace std;

struct Floor{
    int index;
    int total;
};

queue<Floor> q;

int n, a, b;
int t[401];
bool check[401] = { false };

int main(){
    Floor c, d;
    int i;
    cin >> n >> a >> b;
    for(int i = 1; i <= n; i ++) cin >> t[i];
    c.index = a;
    c.total = 0;
    q.push(c);
    check[1] = true;
    while(!q.empty()){
        d = q.front();
        q.pop();
        if(d.index == b) break;
        i = d.index + t[d.index];
        if(i <= n && !check[i]) {
            c.index = i;
            c.total = d.total + 1;
            q.push(c);
            check[i] = true;
        }
        i = d.index - t[d.index];
        if(i >= 1 && !check[i]) {
            c.index = i;
            c.total = d.total + 1;
            q.push(c);
            check[i] = true;
        }
    }
    if(d.index == b) cout << d.total;
    else cout << -1;
    return 0;
}
