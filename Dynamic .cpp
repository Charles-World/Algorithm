#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <math.h>
#include <Windows.h>

using namespace std;

//大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项（从0开始，第0项为0）。
//n <= 39
//子问题：前i个数分别是多少
//重叠子问题：(i - 2) + (i - 1) = i
//最优子结构：要想知道最优解，必然要先算出子问题的最优解
//而且可以在求解最优解的同时，找到生成这个最优解的方法（只要提供一个空间来保存这些值）
class Soulution
{
public:
	int Fibonacci(int n)
	{
		if (n <= 0)
		{
			return 0;
		}
		if (n == 1 || n == 2)
		{
			return 1;
		}
		return Fibonacci(n - 2) + Fibonacci(n - 1);
	}
private:
	int f;
};

//一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多
//少种跳法。
//它的子问题是前i阶台阶有多少种跳法
//状态：跳上i级台阶的方法数
//F(i) = F(I - 1) + F(I - 2) + ...+F(1)
//F(i - 1) = F(I - 2) + ...+F(1)
//F(I) = 2 * F(I - 1)
//时间复杂度：2 ^ (n - 1)
//重叠子问题是，第i阶的跳法要通过第i-1阶来算，而第i-1阶要通过第i-2阶来算……
//它的最优子结构，在最优解中可以找到，因为要算出最优解，就得先算出最优子结构的解
//根据得到的最优解，只要申请了保存的空间，可以找到构成最优解的方法，也就是构成最优解的路径
//并且可以根据算出的最优解来构造一个新的生成最优的方法
class Soulution1
{
public:
	Soulution1()
		:f1(1)
	{}
	int jumpFloorII(int number)
	{
		f1 = 1;
		for (int i = 2; i <= number; ++i)
		{
			f1 = 2 * f1;
		}
		return f1;
	}
private:
	int f1;
};

//HZ偶尔会拿些专业问题来忽悠那些非计算机专业的同学。今天测试组开完会后,他又发话了:在古老的一维模式
//识别中, 常常需要计算连续子向量的最大和, 当向量全为正数的时候, 问题很好解决。但是, 如果向量中包含负数, 是
//否应该包含某个负数, 并期望旁边的正数会弥补它呢？例如:{6, -3, -2, 7, -15, 1, 2, 2}, 连续子向量的最大和为8(从第0
//个开始, 到第3个为止)。给一个数组，返回它的最大连续子序列的和，你会不会被他忽悠住？(子向量的长度至少
//是1)
//状态F(I): i项的连续子序列的最大和
//F(I):
//F(I - 1):
//
//
//

class Solution2
{
public:
	int FindGreattestSumOfSubArray(vector<int> array)
	{
		if (array.empty())
		{
			return 0;
		}
		vector<int> ret(array.size(), 0);

		ret[0] = array[0];
		for (int i = 1; i < array.size(); i++)
		{
			ret[i] = max(ret[i - 1] + array[i], array[i]);
		}
		int maxNum = ret[0];
		for (int i = 1; i < array.size(); ++i)
		{
			maxNum = max(maxNum, ret[i]);
		}
		return maxNum;
	}
};

// 给定一个字符串和一个词典dict，确定s是否可以根据词典中的词分成
//一个或多个单词。
//比如，给定
//s = "leetcode"
//dict = ["leet", "code"]
//返回true，因为"leetcode"可以被分成"leet code"
//状态F(I):前i个字符能否被分割
//F(I):S[I - 1] S[0] ~ S[I - 2]
//要判断能否被分割，要先判断前i个字符能否被分割，空字符设置成
//能被分割，判断后一个字符能否被分割，只需要判断那个字符自身能否
//被分割，如果可以再判断前面已经判断过的那个
//字符串能否被分割，如果也不行，再判断它们两个拼接之后的字符串能否
//被分割。如果它本身和前i个字符都能分割，那就能分割，或它俩拼接之后
//如果能分割就能分割

class Solution3
{
public:
	bool wordBreak(string s, unordered_set<string> &dict)
	{
		if (s.empty())
		{
			return false;
		}
		if (dict.empty())
			return false;
		vector<bool> Fn(s.size() + 1, false);
		{
			Fn[0] = true;
			for (int i = 1; i <= s.size(); ++i)
			{
				for (int j = i - 1; j >= 0; --j)
				{
					if (Fn[j] && dict.find(s.substr(j, i - j)) != dict.end())
					{
						Fn[i] = true;
						break;
					}
				}
			}
		}
		return Fn[s.size()];
	}
};
//题目描述：
//给定一个三角矩阵，找出自顶向下的最短路径和，每一步可以移动到下一行的相邻数字。
//比如给定下面一个三角矩阵，自顶向下的最短路径和为11。
//状态：F(I,J):从(0, 0)到(i, j)的最短路径和
//F(0, 0) = A[0][0]
//返回结果;MIN(F(N - 1, J))
//F(I, 0): F(I - 1, 0) + A[I][0]
//F(I, I):F(I - 1, I - 1) + A[I][I]
//子问题就是到每一行中每个元素的最短路径是多少
//重叠子问题是每一行中的每个元素的最短路径，要比较上一行相邻两个元素加上这个元素的值来计算
//每次计算完一个最短路径就把它存储在那个元素的地方，等到计算下一层时
//只需要用上一层的相邻元素相加，然后进行比较，就可以得出到达这一层的最短路径
//到最后，最后一层存储的就是，到达最后一层中每个元素的最短路径
//所以只要将最后一层中最小的元素找出来，就可以得到这个三角形矩阵的最短路径
//这种方式是从上到下的寻找最短路径的方式（注意不是动态规划的从顶而下的备忘录方法）
//而且它也是具有最优子结构的，因为每一层的每个元素存储的都是，到达它的最短路径
//只有这样才能求解出最后的解，所以说最优解中包含了子问题的最优解，只要我们愿意付出一定空间
//来存储它，那么我们就可以得到每一层的最优解
//而且只要我们付出一定空间，可以找到一条达到最优解的方法，也就是如何到达最优解的 
//最后还可以根据得出的最优解，重新构造一个新的最优解，因为达到最优解的路径顺序不一定唯一
class Solution4
{
public:
	int minimumTotal(vector<vector<int> > &triangle)
	{
		if (triangle.empty())
		{
			return 0;
		}
		int row = triangle.size();
		int col = triangle[0].size();
		vector<vector<int>> ret(triangle);
		for (int i = 1; i < row; ++i)
		{
			ret[i][0] = ret[i - 1][0] + triangle[i][0];
		}
		for (int i = 1; i < row; ++i)
		{
			ret[i][i] = ret[i - 1][i - 1] + triangle[i][i];
		}
		for (int i = 1; i < row; ++i)
		{
			for (int j = 1; j < i; ++j)
			{
				ret[i][j] = min(ret[i - 1][j] + triangle[i][j], ret[i - 1][j - 1] + triangle[i][j]);
			}
		}
		int minSum = ret[row - 1][0];
		for (int j = 1; j < row; ++j)
		{
			minSum = min(minSum, ret[row - 1][j]);
		}
		return minSum;
	}
};

class Solution5
{
	int minimumTotal(vector<vector<int> > &triangle)
	{
		if (triangle.empty())
		{
			return 0;
		}
		int row = triangle.size();
		int col = triangle[0].size();
		vector<vector<int>> ret(triangle);


		for (int i = row - 2; i >= 0; --i)
		{
			for (int j = 0; j <= i; ++j)
			{
				ret[i][j] = min(ret[i + 1][j] + triangle[i][j], ret[i + 1][j + 1] + triangle[i][j]);
			}
			return ret[0][0];
		}
	}
};

//在一个m*n的网格的左上角有一个机器人，机器人在任何时候只能向下或者向右移动，
//机器人试图到达网格的右下角，有多少可能的路径。
//方法：动态规划
//状态：
//子状态：从(0, 0)到达(1, 0), (1, 1), (2, 1), ...(m - 1, n - 1)的路径数
//F(i, j) : 从(0, 0)到达F(i, j)的路径数
//状态递推：
//F(i, j) = F(i - 1, j) + F(i, j - 1)
//初始化：
//特殊情况：第0行和第0列
//F(0, i) = 1
//F(i, 0) = 1
//返回结果：
//F(m - 1, n - 1)

class Solution6
{
public:
	int uniquePaths(int m, int n)
	{
		vector<vector<int>> pathNum(m, vector<int>(n, 0));
		pathNum[0][0] = 1;
		for (int i = 0; i < m; ++i)
		{
			for (int j = 1; j < n; ++j)
			{
				pathNum[i][j] = pathNum[i - 1][j] + pathNum[i][j - 1];
			}
		}
		return pathNum[m - 1][n - 1];
	}
};

class Solution7
{
public:
	int uniquePathWithObstacles(vector<vector<int>> &obstacleGrid)
	{
		if (obstacleGrid.empty())
		{
			return 0;
		}
		if (obstacleGrid[0][0] == 1)
			return 0;
		int row = obstacleGrid.size();
		int col = obstacleGrid[0].size();
		vector<vector<int>> pathNum(row, vector<int>(col, 0));
		for (int i = 0; i < row; ++i)
		{
			if (obstacleGrid[i][0] == 1)
				break;
			else
				pathNum[i][0] = 1;
		}
		for (int i = 0; i < row; ++i)
		{
			if (obstacleGrid[0][i] == 1)
				break;
			else
				pathNum[0][i] = 1;
		}
		for (int i = 1; i < row; ++i)
		{
			for (int j = 1; i < col; ++j)
			{
				if (obstacleGrid[i][j] == 1)
				{
					pathNum[i][j] = 0;
				}
				else
				{
					pathNum[i][j] = pathNum[i - 1][j] + pathNum[i][j - 1];
				}
			}
		}
		return pathNum[row - 1][col - 1];
	}
};
//0-1背包问题，每个物品只能放一个
//状态：
//F(i, j) : 前i个物品放入大小为j的背包中所获得的最大价值
//状态递推：对于第i个商品，有一种例外，装不下，两种选择，放或者不放
//如果装不下：此时的价值与前i - 1个的价值是一样的
//F(i, j) = F(i - 1, j)
//如果可以装入：需要在两种选择中找最大的
//F(i, j) = max{ F(i - 1,j), F(i - 1, j - A[i]) + V[i] }
//F(i - 1, j) : 表示不把第i个物品放入背包中， 所以它的价值就是前i - 1个物品放入大小为j的背包的最大价值
//F(i - 1, j - A[i]) + V[i]：表示把第i个物品放入背包中，价值增加V[i], 但是需要腾出j - A[i]的大小放
//第i个商品
//初始化：第0行和第0列都为0，表示没有装物品时的价值都为0
//F(0, j) = F(i, 0) = 0
//返回值：F(n, m)
//它的子问题是前n个类型的物品所能获得的总价值是多少
//重叠子问题是，第n个物品所能获得的总价值，必须通过n-1个物品所能获得的总价值来推导
//而n-1个物品所能获得的总价值必须通过n-2个物品来推导，所以必须在计算前n个物品价值时
//把这些值存储起来，以避免子问题的反复计算
//那如何进行从n-1推导n的，就是要往背包里面放东西，不管是n个类型物品求背包总价值背包
//还是3个类型的物品求背包总价值，放的时候大小都得小于背包所能承受的总大小
//而且在计算有n个类型的物品所能得到的总价值时，要依赖有n-1个类型物品
//在背包大小范围内，每个大小，所能得到的总价值
//因为在计算n个类型物品，所以能得到的总价值时，必须拿到n-1个类型的物品所能拿到的总价值
//但并不是n-1个类型物品占满全部背包时的总价值，而是全部背包大小减去第n个物品所能拿到的总价值
//然后再加上第n个物品所能得到的总价值
//并且还要进行判断，如果算出的第n个类型物品的总价值没有，第n-1个物品总价值大
//那么第n-1个物品的总价值就是第n个类型物品的总价值
//并且还有一个问题，就是在计算第n个物品的总价值时，如果第n个物品大小比现在要循环的背包大小大
//那么直接就让n-1个类型物品，当前背包大小的总价值就是第n个物品再的总价值
//而且这个问题也是具有最优子结构的，要求出最优解，就得先求出子问题的最优解，所以只要我们开辟空间
//进行保存，就可以得到最优了结构
//而且我们还可以在解出最优解的同时，只要申请空间，就可以寻找到解出最优解的方法，也就是如何到达最优解的
//利用计算出的最优解，我们可以重新构造一个最优解，或者用我们寻找出来的路径（也就是求出最优解的方法）
//来构造最优解
class Solution8
{
public:
	int backPackII(int m, vector<int> &A, vector<int> &v)
	{
		if (A.empty())
		{
			return 0;
		}
		int row = A.size();
		vector<vector<int>> maxValue(row + 1, vector<int>(m + 1, 0));
		for (int i = 1; i <= row; ++i)
		{
			for (int j = 1; j <= m; ++j)
			{
				if (A[i - 1] > j)
				{
					maxValue[i][j] = maxValue[i - 1][j];
				}
				else
				{
					maxValue[i][j] = max(maxValue[i - 1][j],
						maxValue[i - 1][j - A[i - 1]] + v[i - 1]);
				}
			}
		}
		return maxValue[row][m];
	}
};
//状态：
//子状态：到第1, 2, 3, ..., n个字符需要的最小分割数
//F(i) : 到第i个字符需要的最小分割数
//状态递推：
//F(i) = min{ F(i), 1 + F(j) }, where j<i && j + 1到i是回文串
//	上式表示如果从j + 1到i判断为回文字符串，且已经知道从第1个字符
//	到第j个字符的最小切割数，那么只需要再切一次，就可以保证
//	1-->j, j + 1-->i都为回文串。
//	初始化：
//	F(i) = i - 1
//	上式表示到第i个字符需要的最大分割数
//	比如单个字符只需要切0次，因为单子符都为回文串
//	2个字符最大需要1次，3个2次......
//	返回结果：
//	F(n)
//	遗留问题：如何判断一段字符串为回文串
//	循环判断首尾元素是否相同，如果全部相同，则是回文串
class Solution8
{
public:
	int minCut(string s)
	{
		if (s.empty())
		{
			return 0;
		}
		int strlen = s.size();
		vector<int> minCut(strlen + 1, 0);
		for (int i = 0; i <= strlen; ++i)
		{
			minCut[i] = i - 1;
		}
		for (int i = 1; i <= strlen; ++i)
		{
			for (int j = 0; j < i; ++j)
			{
				if (isPal(s, j, i - 1))
				{
					minCut[i] = min(minCut[i], min[j] + 1);
				}
			}
		}
		return minCut[strlen];
	}

	bool isPal(string& str, int startIdx, int endIdx)
	{
		while (startIdx < endIdx)
		{
			if (str[startIdx] != str[endIdx])
			{
				return false;
			}
			startIdx++;
			endIdx++;
		}
		return true;
	}

	vector<vector<bool>> isPalMat(string& str)
	{
		vector<vector<bool>> Mat(str.size(), vector<bool>(str.size(), false));
		for (int i = str.size() - 1; i >= 0; --i)
		{
			for (int j = i; j < str.size(); ++j)
			{
				if (j == i)
				{
					Mat[i][j] = true;
				}
				else if (j == i + 1)
				{
					Mat[i][j] = str[i] == str[j];
				}
				else
				{
					Mat[i][j] = (Mat[i + 1][j - 1] && str[i] == str[j]);
				}
			}
		}
		return Mat;
	}
};