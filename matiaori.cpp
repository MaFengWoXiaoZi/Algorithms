// 马跳日问题, 显示出每一种方案下马在棋盘中每一步的位置
//以5*5棋盘为例, 可以填满该棋盘的每一个单元格
// 当然也可以是M, N可以为任何数字, 即任意行任意列, 但随着行数列数增加
// 计算量也会增加, 而且不能保证棋盘里每一个单元格都能被填满
#include<iostream>
#include<queue>

#define M 5
#define N 5

using namespace std;

int trace[M][N]; // trace数组用来进行记录棋盘上每一个单元格是马跳日的第几步
int visit[M][N]; // 用visit数组记录每个访问过的位置
int count = 0; // 记录有多少种走法
int moveDirection[][8] = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};
// 马跳日中下一步移动的方向


// 打印出每次求解的结果
void PrintEveryResult(int trace[M][N], int count)
{
	cout<<"第"<<count<<"种解法: "<<endl;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout<<trace[i][j]<<"\t";
		}
		cout<<endl;
	}
}

// 递归求解方式
void Matiaori(int x, int y, int step)
{
	int nextX, nextY; // 用于记录下一步要走的位置
	trace[x][y] = step;


	if (M * N == step) // 如果步数正好等于棋盘的大小, 则结束一次求解过程
	{
		count++;
		PrintEveryResult(trace, count);
	}
	else
	{
		for (int i = 0; i < 8; i++)
		{
			nextX = x + moveDirection[i][0];
			nextY = y + moveDirection[i][1];

			if (nextX < 0 || nextX >= M || nextY < 0 || nextY >= N || visit[nextX][nextY] == 1)
			{
				continue;
			}
			
			visit[nextX][nextY] = 1;
			Matiaori(nextX, nextY, step+1);
			visit[nextX][nextY] = 0; // 每次求解出一种方案后需要把visit数组置为0
									 // 以便可以继续求解下一个可行的方案
		}		
		
	}
}

int main()
{
	int x = 0, y = 0; // 初始化位置为0,0
	int step = 1; //表示当前为第几步, 初始化为第一步

	visit[x][y] = 1; //用visit数组记录每个访问过的位置

	Matiaori(x, y, step);

	cout<<"------------------------"<<endl;
	cout<<"共"<<count<<"解法!"<<endl;

	return 0;
	
}
