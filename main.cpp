#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;


const int size = 7;

#define SIZE 7
#define inf 10000

vector <vector <int>> matrix(int size, vector <vector <int>> c)
{
	vector <vector <int>> matr(size*size + 2, vector<int>(size*size + 2, inf));

	for (int i = 2; i < size + 2; i++)
	{
		matr[0][i] = c[i - 2][0];
	}
	for (int i = 44; i < 51; i++)
	{
		//matr[i][1] = c[i - 44][6];
		matr[i][1] = 0;
	}


	for (int i = 2; i < size + 2; i++)
	{
		matr[i][size + i] = c[i - 2][1];
	}


	for (int i = size + 2; i < size * 2 + 2; i++)
	{
		matr[i][size + i] = c[i - size - 2][2];
		if (i - size - 1 < size) matr[i][i + 1] = c[i - size - 1][1];
		if (i > size + 2) matr[i][i - 1] = c[i - size - 3][1];
	}

	for (int i = size * 2 + 2; i < size * 3 + 2; i++)
	{
		matr[i][size + i] = c[i - size * 2 - 2][3];

		if (i - size * 2 - 1 < size) matr[i][i + 1] = c[i - size * 2 - 1][2];
		if (i > size * 2 + 2) matr[i][i - 1] = c[i - size * 2 - 3][2];
	}

	for (int i = size * 3 + 2; i < size * 4 + 2; i++)
	{
		matr[i][size + i] = c[i - size * 3 - 2][4];

		if (i - size * 3 - 1 < size) matr[i][i + 1] = c[i - size * 3 - 1][3];
		if (i > size * 3 + 2) matr[i][i - 1] = c[i - size * 3 - 3][3];
	}

	for (int i = size * 4 + 2; i < size * 5 + 2; i++)
	{
		matr[i][size + i] = c[i - size * 4 - 2][5];
		if (i - size * 4 - 1 < size) matr[i][i + 1] = c[i - size * 4 - 1][4];
		if (i > size * 4 + 2) matr[i][i - 1] = c[i - size * 4 - 3][4];
	}

	for (int i = size * 5 + 2; i < size * 6 + 2; i++)
	{
		matr[i][size + i] = c[i - size * 5 - 2][6];
		if (i - size * 5 - 1 < size) matr[i][i + 1] = c[i - size * 5 - 1][5];
		if (i > size * 5 + 2) matr[i][i - 1] = c[i - size * 5 - 3][5];
	}

/*	for (int i = size * 6 + 2; i < size * 7 + 2; i++)
	{
		if (i - size * 6 - 1 < size) matr[i][i + 1] = c[i - size * 6 - 1][6];
		if (i > size * 6 + 2) matr[i][i - 1] = c[i - size * 6 - 3][6];
	}  */
/*
	for (int i = 0; i < size*size + 2; i++)
	{
		cout << i << " ";
	}
	cout << endl;
	for (int i = 0; i < size * size + 2; i++)
	{
		cout << i << " ";
		for (int j = 0; j < size * size + 2; j++)
		{
			cout << matr[i][j] << " ";
		}
		cout << endl;
	}

	system("pause>>NULL");
	*/

	return matr;
}

bool pos(vector <bool> a)
{
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] == false)
			return false;
	}
	return true;

}

vector <int> Dijkstra(int n, int st, vector<vector<int >> w, int k)
{
	vector <bool> visited(n,false); // массив посещенных вершин( индекс равен номеру вершины)
	vector <int> D(n,inf); // массив минимальный путей
	vector <vector <int>> path(n, vector<int>(n, 0));

	for (int i = 0; i < n; i++)
	{
		D[i] = w[st][i];
		visited[i] = false;
	}

	D[st] = 0;
	int index = 0, u = 0;

	int min = inf;

	for (int i = 0; i < n; i++)
	{
		min = inf;

		for (int j = 0; j < n; j++)
		{
			if (!visited[j] && D[j] < min)
			{
				min = D[j];
				index = j;
			}
		}

		u = index;
		visited[u] = true;
		for (int j = 0; j < n; j++)
		{
			if (!visited[j] && w[u][j] != inf && D[u] != inf && (D[u] + w[u][j] < D[j]))
			{
				D[j] = D[u] + w[u][j];
			}
		}
	}

	if (false)
	{
		cout << "Стоимость пути из начальной вершины до остальных(Алгоритм Дейкстры):\t\n";
		for (int i = 0; i < n; i++)
		{
			if (D[i] != inf)
				cout << st << " -> " << i << " = " << D[i] << endl;
			else
				cout << st << " -> " << i << " = " << "маршрут недоступен" << endl;
		}

		for (int i = n - 7; i < n; i++)
		{
			if (D[1] - D[i] > 0)
				cout << " k = " << k + 1 << " " << D[1] - D[i] << " " << endl;
		}
	}
	
	return D;
}



int main()
{
	int size = 7;
	vector <vector <int>> c(size, vector<int>(size, 0));
	setlocale(LC_ALL, "Rus");

	ifstream fin("C:\\Users\\l0ki\\Desktop\\mazes_1.txt");
	//ofstream fout("C:\\Users\\l0ki\\Desktop\\pass.txt");

	string str;
	int m = 0;

	vector <vector <int>> pass;
	vector <int> Pass;
	int  k = 0;

	while (m < 40)
	{
		int K = 0;
		while (getline(fin, str)) { 
			K++;
			if (K == 3) break;
		}

		for (int i = 0; i < SIZE; i++)
		{
			for (int j = 0; j < SIZE; j++)
			{
				fin >> c[i][j];
			}
		}

		vector <vector <int>> matr(size*size + 2, vector<int>(size*size + 2, inf));

		matr.swap(matrix(size, c));
		vector <int> path;
		
		path.swap(Dijkstra(size * size + 2, 0, matr,m));

		Pass.push_back(path[1]);
		m++;

	/*	for (int i = 44; i < 51; i++)
		{
			if (path[1] - path[i] == 0) {
				if (k == m)
				{
					cout << c[i - 44][6];
					k++;
				}
				else
				{
					cout << endl;
					cout << "m = " << m + 1 << " " << c[i - 44][6] << endl;
				}
			}
		}
		 */
	}
	string s;
	for (int i = 0; i < Pass.size() - 1; i++)
	{
		cout << Pass[i] - 100;
		s += char(Pass[i] - 100);
	}

	cout << s;
	

	fin.close();
	system("pause>>NULL");


	return 0;
}