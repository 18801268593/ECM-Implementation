#include <iostream>

using namespace std;



//Edwards curve
struct Prime_Re_Edw {
	 
	double Type[14];  //0表示双基链，1表示双基展开，2表示Lucas链
	double Add_Num[14];  //表示加法数
	double Signal[14][4]; //展开式中的加减号，1表示加，-1表示减，0表示不需要加了
	double DBL[14][4]; //每个展开式中2的次数
	double TPL[14][4];  //每个展开式中3的次数
	
	void Set_Value()
	{
		for (int i=0; i < 14; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				DBL[i][j] = 0;
				TPL[i][j] = 0;
				Signal[i][j] = 0;
			}
			Type[i] = 0;
			Add_Num[i] = 0;
		}
		Type[11] = 1;

		Signal[0][0] = -1;
		Add_Num[0] = 1;
		DBL[0][0] = 15;
		
		Signal[1][0] = -1;
		Add_Num[1] = 1;
		DBL[1][0] = 9;
		TPL[1][0] = 5;

		Signal[2][0] = 1;
		Add_Num[2] = 1;
		DBL[2][0] = 21;
		TPL[2][0] = 2;

		Signal[3][0] = -1;
		Add_Num[3] = 1;
		DBL[3][0] = 12;
		TPL[3][0] = 18;

		Signal[4][0] = 1;
		Signal[4][1] = 1;
		Add_Num[4] = 2;
		DBL[4][0] = 14;
		DBL[4][1] = 4;
		TPL[4][0] = 3;
		TPL[4][1] = 2;

		Signal[5][0] = 1;
		Signal[5][1] = -1;
		Add_Num[5] = 2;
		DBL[5][0] = 20;
		DBL[5][1] = 4;

		Signal[6][0] = -1;
		Signal[6][1] = -1;
		Add_Num[6] = 2;
		DBL[6][0] = 22;
		DBL[6][1] = 8;

		Signal[7][0] = 1;
		Signal[7][1] = -1;
		Add_Num[7] = 2;
		DBL[7][0] = 27;
		DBL[7][1] = 18;
		TPL[7][0] = 2;
		TPL[7][1] = 1;

		Signal[8][0] = 1;
		Signal[8][1] = -1;
		Add_Num[8] = 2;
		DBL[8][0] = 30;
		DBL[8][1] = 11;
		TPL[8][0] = 2;

		Signal[9][0] = -1;
		Signal[9][1] = -1;
		Add_Num[9] = 2;
		DBL[9][0] = 38;
		DBL[9][1] = 3;
		

		Signal[10][0] = 1;
		Signal[10][1] = -1;
		Signal[10][2] = -1;
		Add_Num[10] = 3;
		DBL[10][0] = 24;
		DBL[10][1] = 17;
		DBL[10][2] = 8;
		TPL[10][0] = 4;
		TPL[10][1] = 4;

		Signal[11][0] = 1;
		Signal[11][1] = 1;
		Signal[11][2] = 1;
		Add_Num[11] = 3;
		DBL[11][0] = 46;
		DBL[11][1] = 42;
		DBL[11][2] = 14;
		TPL[11][0] = 6;
		TPL[11][3] = 3;

		Signal[12][0] = 1;
		Signal[12][1] = -1;
		Add_Num[12] = 2;
		DBL[12][0] = 7;
		DBL[12][1] = 6;
		TPL[12][0] = 2;

		Signal[13][0] = 0;
		Add_Num[13] = -1;
		DBL[13][0] = 8;
	}
	
};




void Arith_cost_Edw()
{
	double Edw_Add = 7;
	double Edw_Add_E = 8;
	double Edw_DBL = 7;
	double Edw_DBL_E = 8;
	double Edw_TPL = 12;
	double Edw_TPL_E = 14;

	double cost[14]; //算术花费
	double Total_cost = 0;
	double Per_cost = 0;

	double prime[14][8];

	for (int i = 0; i < 14; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			prime[i][j] = 0;
		}
	}

	prime[0][0] = 151;
	prime[0][1] = 31;
	prime[0][2] = 7;

	prime[1][0] = 167;
	prime[1][1] = 149;
	prime[1][2] = 5;

	prime[2][0] = 227;
	prime[2][1] = 73;
	prime[2][2] = 67;
	prime[2][3] = 17;

	prime[3][0] = 193;
	prime[3][1] = 127;
	prime[3][2] = 109;
	prime[3][3] = 107;
	prime[3][4] = 61;
	prime[3][5] = 13;
	prime[3][6] = 7;

	prime[4][0] = 251;
	prime[4][1] = 43;
	prime[4][2] = 41;

	prime[5][0] = 241;
	prime[5][1] = 229;
	prime[5][2] = 19;

	prime[6][0] = 211;
	prime[6][1] = 139;
	prime[6][2] = 13;
	prime[6][3] = 11;
	 
	prime[7][0] = 233;
	prime[7][1] = 191;
	prime[7][2] = 173;
	prime[7][3] = 157;

	prime[8][0] = 223;
	prime[8][1] = 137;
	prime[8][2] = 103;
	prime[8][3] = 83;
	prime[8][4] = 37;

	prime[9][0] = 179;
	prime[9][1] = 101;
	prime[9][2] = 97;
	prime[9][3] = 47;
	prime[9][4] = 29;
	prime[9][5] = 23;
	prime[9][6] = 5;

	prime[10][0] = 181;
	prime[10][1] = 131;
	prime[10][2] = 89;
	prime[10][3] = 59;
	prime[10][4] = 11;
	
	prime[11][0] = 239;
	prime[11][1] = 199;
	prime[11][2] = 197;
	prime[11][3] = 163;
	prime[11][4] = 113;
	prime[11][5] = 79;
	prime[11][6] = 71;
	prime[11][7] = 53;

	prime[12][0] = 5;
	prime[12][1] = 3;
	prime[12][2] = 3;
	prime[12][3] = 3;
	prime[12][4] = 3;
	prime[12][5] = 3;

	prime[13][0] = 2;
	prime[13][1] = 2;
	prime[13][2] = 2;
	prime[13][3] = 2;
	prime[13][4] = 2;
	prime[13][5] = 2;
	prime[13][6] = 2;
	prime[13][7] = 2;

	struct Prime_Re_Edw PRE;
	PRE.Set_Value();
	int index = 0;

	for (int i = 0; i < 14; i++)
	{
		cost[i] = 0;
		if (PRE.Type[i] == 0)
		{
			if (PRE.Add_Num[i] > 0)
			{
				cost[i] = cost[i] + PRE.Add_Num[i] * Edw_Add_E; //加法部分的花费
				cost[i] = cost[i] + Edw_DBL_E + Edw_DBL * (PRE.DBL[i][0] - 1);  //2倍点部分的花费
				cost[i] = cost[i] + Edw_TPL * PRE.TPL[i][0];  //3倍点部分的花费
			}
			else
			{
				cost[i] = cost[i] + Edw_DBL * PRE.DBL[i][0];  //2倍点部分的花费
			}

		}
		else
		{
			if (PRE.Add_Num[i] > 0)
			{
				cost[i] = cost[i] + PRE.Add_Num[i] * Edw_Add_E; //加法部分的花费
				cost[i] = cost[i] + Edw_DBL_E + Edw_DBL * (PRE.DBL[i][0] - 1);  //2倍点部分的花费
				cost[i] = cost[i] + Edw_TPL_E + Edw_TPL * (PRE.TPL[i][0] - 1);  //3倍点部分的花费
			}

		}

		for (int j = 0; j < 8; j++)
		{
			if (prime[i][j] > 0)
			{
				cout << prime[i][j];
				if (j<7 && prime[i][j + 1] > 0)
				{
					cout << "*";
				}
			}
			else
			{
				break;
			}
		}
		if (PRE.Type[i] == 0)
		{
			cout << "  " << "c  ";
		}
		else
		{
			cout << "  " << "e  ";
		}


		for (int j = 0; j < 4; j++)
		{
			if (PRE.DBL[i][j]!=0 )
			{
				cout << "2^{" << PRE.DBL[i][j] << "}";
				if (PRE.TPL[i][j] != 0)
				{
					cout << "3^{" << PRE.TPL[i][j] << "}";
				}				
				
			}

			if (PRE.DBL[i][j] == 0 && PRE.TPL[i][j] != 0)
			{
				cout << "3^{" << PRE.TPL[i][j] << "}";
			}

			if (PRE.Signal[i][j] == 1)
			{
				cout << " + ";
				PRE.Add_Num[i]--;
			}
			else if (PRE.Signal[i][j] == -1)
			{
				cout << " - ";
				PRE.Add_Num[i]--;
			}
			else if(PRE.Type[i]==0&&i<13)
			{
				cout << "1";
				break;
			}
			else if (PRE.Type[i] != 0)
			{
				cout << " ";
				break;
			}
			else
			{
				break;
			}
			
		}
		

		cout <<"   "<< cost[i] << "M" << endl;

		Total_cost = Total_cost + cost[i];
	}
	Per_cost = Total_cost / 363.5;
	cout << "Individual's total cost is ：" << Total_cost << "M" << endl;
	cout << "The cost of every bit is ：" << Per_cost << "M" << endl;

}




//Hessian curve
struct Prime_Re_Hes {
	
	double Type[6];  //0表示最后一项是1，1表示最后一项非1，即所有加法都是一般的加法，没有mixed加法
	double Add_Num[6]; //展开式中加法数
	double DBL[6][4]; //每个展开式中2的次数
	double TPL[6][4];  //每个展开式中3的次数
	double Signal[6][4]; //展开式中的加减号，1表示加，-1表示减，0表示不需要加了
	double Index[6]; //0表示c，1表示e

	void Set_Value()
	{
		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				DBL[i][j] = 0;
				TPL[i][j] = 0;
				Signal[i][j] = 0;
			}
			Type[i] = 0;
			Add_Num[i] = 0;
			Index[i] = 1;
		}
		Type[4] = 1;
		Type[5] = 1;
		Index[0] = 0;
		Index[1] = 0;


		Add_Num[0] = 3;
		Signal[0][0] = -1;
		Signal[0][1] = -1;
		Signal[0][2] = 1;
		DBL[0][0] = 12;
		DBL[0][1] = 10;
		DBL[0][2] = 10;
		TPL[0][0] = 18;
		TPL[0][1] = 14;
		TPL[0][2] = 6;

		Add_Num[1] = 3;
		Signal[1][0] = 1;
		Signal[1][1] = 1;
		Signal[1][2] = 1;
		DBL[1][0] = 18;
		DBL[1][1] = 16;
		DBL[1][2] = 10;
		TPL[1][0] = 15;
		TPL[1][1] = 12;
		TPL[1][2] = 7;

		Add_Num[2] = 3;
		Signal[2][0] = 1;
		Signal[2][1] = -1;
		Signal[2][2] = 1;
		DBL[2][0] = 6;
		DBL[2][1] = 4;
		DBL[2][2] = 6;
		TPL[2][0] = 22;
		TPL[2][1] = 10;
		TPL[2][2] = 4;

		Add_Num[3] = 3;
		Signal[3][0] = -1;
		Signal[3][1] = -1;
		Signal[3][2] = 1;
		DBL[3][0] = 32;
		DBL[3][1] = 12;
		DBL[3][2] = 20;
		TPL[3][0] = 18;
		TPL[3][1] = 18;
		

		Add_Num[4] = 3;
		Signal[4][0] = 1;
		Signal[4][1] = -1;
		Signal[4][2] = -1;
		DBL[4][0] = 10;	
		DBL[4][1] = 7;
		DBL[4][3] = 5;
		TPL[4][0] = 24;
		TPL[4][1] = 19;
		TPL[4][2] = 5;
		

		Add_Num[5] = 3;
		Signal[5][0] = 1;
		Signal[5][1] = -1;
		Signal[5][2] = 1;
		DBL[5][0] = 6;
		DBL[5][2] = 2;
		DBL[5][3] = 1;
		TPL[5][0] = 23;
		TPL[5][1] = 15;
		TPL[5][2] = 10;

		/*for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				cout << Signal[i][j] << "  ";
			}
			cout << endl;
		}*/
	}
};



//Montgomery curve
struct Prime_Re_Mon 
{

	double cost[10];  //0表示双基链，1表示双基展开，2表示Lucas链

	void Set_Value()
	{
		cost[0] = 101;
		cost[1] = 86;
		cost[2] = 86;
		cost[3] = 64;
		cost[4] = 80;
		cost[5] = 73;
		cost[6] = 63;
		cost[7] = 73;
		cost[8] = 52;
		cost[9] = 40;
	}

};





void Arith_cost_Hes_Mon()
{
	double Hes_Add = 11;
	double Hes_Add_Mixed = 9;
	double Hes_DBL = 8;
	double Hes_TPL = 12;
	

	double cost[16]; //算术花费
	double Total_cost = 0;
	double Per_cost = 0;

	double prime2[16][13];

	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			prime2[i][j] = 0;
		}
	}

	prime2[0][0] = 227;
	prime2[0][1] = 167;
	prime2[0][2] = 149;
	prime2[0][3] = 101;
	prime2[0][4] = 59;
	prime2[0][5] = 47;

	prime2[1][0] = 191;
	prime2[1][1] = 173;
	prime2[1][2] = 151;
	prime2[1][3] = 103;
	prime2[1][4] = 89;
	prime2[1][5] = 83;

	prime2[2][0] = 241;
	prime2[2][1] = 223;
	prime2[2][2] = 157;
	prime2[2][3] = 131;
	prime2[2][4] = 79;
	prime2[2][5] = 23;

	prime2[3][0] = 193;
	prime2[3][1] = 127;
	prime2[3][2] = 109;
	prime2[3][3] = 107;
	prime2[3][4] = 61;
	prime2[3][5] = 41;
	prime2[3][6] = 31;
	prime2[3][7] = 13;
	prime2[3][8] = 11;
	prime2[3][9] = 7;
	prime2[3][10] = 5;
	prime2[3][11] = 5;
	prime2[3][12] = 3;

	prime2[4][0] = 239;
	prime2[4][1] = 233;
	prime2[4][2] = 211;
	prime2[4][3] = 73;
	prime2[4][4] = 67;
	prime2[4][5] = 53;
	prime2[4][6] = 19;
	prime2[4][7] = 5;

	prime2[5][0] = 229;
	prime2[5][1] = 199;
	prime2[5][2] = 197;
	prime2[5][3] = 97;
	prime2[5][4] = 37;
	prime2[5][5] = 17;
	prime2[5][6] = 11;

	prime2[6][0] = 113;
	prime2[6][1] = 13;
	prime2[6][2] = 3;

	prime2[7][0] = 181;
	prime2[7][1] = 7;

	prime2[8][0] = 43;
	prime2[8][1] = 29;

	prime2[9][0] = 179;
	
	prime2[10][0] = 251;
	prime2[10][1] = 3;

	prime2[11][0] = 139;
	prime2[11][1] = 3;

	prime2[12][0] = 163;
	
	prime2[13][0] = 137;
	prime2[13][1] = 3;

	prime2[14][0] = 71;
	
	prime2[15][0] = 2;
	prime2[15][1] = 2;
	prime2[15][2] = 2;
	prime2[15][3] = 2;
	prime2[15][4] = 2;
	prime2[15][5] = 2;
	prime2[15][6] = 2;
	prime2[15][7] = 2;

	struct Prime_Re_Hes PRH;
	PRH.Set_Value();

	for (int i = 0; i < 6; i++)
	{
		cost[i] = 0;

		if (PRH.Type[i] == 0)
		{
			cost[i] = cost[i] + Hes_Add_Mixed + Hes_Add * (PRH.Add_Num[i] - 1);
			cost[i] = cost[i] + Hes_DBL * PRH.DBL[i][0];
			cost[i] = cost[i] + Hes_TPL * PRH.TPL[i][0];
		}
		else
		{
			cost[i] = cost[i] + Hes_Add * (PRH.Add_Num[i]);
			cost[i] = cost[i] + Hes_DBL * PRH.DBL[i][0];
			cost[i] = cost[i] + Hes_TPL * PRH.TPL[i][0];
		}
		

		
		/*if (PRH.Index[i] == 0)
		{
			
		}
		else
		{
			cost[i] = cost[i] + Hes_Add_Mixed + Hes_Add * (PRH.Add_Num[i] - 1);
			cost[i] = cost[i] + Hes_DBL * PRH.DBL[i][0];
			cost[i] = cost[i] + Hes_TPL * PRH.TPL[i][0];
		}*/
	}

	struct Prime_Re_Mon PRM;
	PRM.Set_Value();



	for (int i = 6; i < 16; i++)
	{
		cost[i] = PRM.cost[i - 6];
	}

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			if (prime2[i][j] > 0)
			{
				cout << prime2[i][j];
				if (j < 12 && prime2[i][j + 1] > 0)
				{
					cout << "*";
				}
			}
			else
			{
				break;
			}
		}


		if (PRH.Index[i] == 0)
		{
			cout << "   c   ";
		}
		else
		{
			cout << "   e   ";
		}
		for (int j = 0; j < 4; j++)
		{
			
					if(PRH.DBL[i][j] != 0)
					{
						cout << "2^{" << PRH.DBL[i][j] << "}";
						if (PRH.TPL[i][j] != 0)
						{
							cout << "3^{" << PRH.TPL[i][j] << "}";
						}

					}

					if (PRH.DBL[i][j] == 0 && PRH.TPL[i][j] != 0)
					{
						cout << "3^{" << PRH.TPL[i][j] << "}";
					}

					if (PRH.Signal[i][j] == 1)
					{
						cout << " + ";
						PRH.Add_Num[i]--;
					}
					else if (PRH.Signal[i][j] == -1)
					{
						cout << " - ";
						PRH.Add_Num[i]--;
					}
					else if (PRH.Type[i] == 0)
					{
						cout << "1   ";
						break;
					}
					else if (PRH.Type[i] != 0)
					{
						cout << "    ";
						break;
					}
					else
					{
						break;
					}
		}

		cout << cost[i] << "M" << endl;
		Total_cost = Total_cost + cost[i];
	}
	for (int i = 6; i < 16; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			if (prime2[i][j] > 0)
			{
				cout << prime2[i][j];
				if (j < 12 && prime2[i][j + 1] > 0)
				{
					cout << "*";
				}
			}
			else
			{
				break;
			}
		}

		cout<<"         m       "<< cost[i] << "M" << endl;
		Total_cost = Total_cost + cost[i];
	}

	Per_cost = Total_cost / 363.5;
	cout << "Mixed Representation's total cost is ：" << Total_cost << "M" << endl;
	cout << "The cost of every bit is ：" << Per_cost << "M" << endl;
}




int main()
{
	

	Arith_cost_Edw();
	cout << endl;
	cout << endl;
	Arith_cost_Hes_Mon();

	return 0;
}