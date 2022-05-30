#include<bits/stdc++.h>

/*
广度优先搜索算法的基本思想：
1、对于初始状态入队，设置初始状态为已访问
2、如果队列不为空时，出队队头元素，否则跳到第5步
3、检查出队的元素是否为最终解，如果是则跳到第5步。
4、对于出队的元素，检查所有相邻状态，如果有效并且未访问，则将
   所有有效的相邻状态进行入队，并且设置这些状态为已访问，然后
   跳到第2步重复执行
5、检查最后出队的元素是否为最终解，如果是输出结果，否则说明无解

广度优先搜索是借助于队列这种数据结构进行搜索的，队列的特点是先
进先出（FIFO），通过包含queue这个队列模板头文件，就可以利用c++
的队列模板定义自己的队列了，队列的操作非常简单，主要有以下几个：
q.push() 入队操作
q.front() 取队头元素
q.pop() 队头元素出队
q.size() 获取队列的元素个数
q.empty() 判断队列是否为空，为空返回true，不为空返回false

广度优先搜索算法的关键是要搞清楚求解过程中每一步的相邻状态有哪些，
每个状态需要记录什么信息，在搜索过程中如何标记这些状态为已访问。

在本题中，相邻状态为当前所在楼层通过按向上或向下按钮所能到达的楼
层，每个状态要记录的信息包括楼层编号和按按钮的次数。
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
