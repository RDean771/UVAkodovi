#include <iostream>
using namespace std;
class Side //implementacija stranice
{
	public:
	char elements[3][3]; // spremanje boja u svaku kockicu (svaki dio strane kojih je 9)
	char backup_elements[3][3]; //backup stanja strane potreban prilikom rotiranja strane kako ne bih izgubio pristup pojedinim dijelovima
	Side(){}
	void operator=(Side&); //operator kopiranja strane u stranu
	void set(); // inicijalizacija stanja strane
	void show(); // display strane
	void rotateCCW(); //implementacija okretanja strane CounterClockWise (CCW), tj. obrnuto od smjera kazaljke na satu
	void rotateCW(); //implementacija okretanja strane ClockWise(CW), tj. u smjeru okretanja kazaljke na satu
};
void Side::operator=(Side &need_backup)
{
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			this->elements[i][j]=need_backup.elements[i][j];
}
void Side::set()
{
	for(int i=0;i<3;i++)
		cin >> elements[i][0] >> elements[i][1] >> elements[i][2];
}
void Side::show(void)
{
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			cout << elements[i][j] << '\t';
		}
		cout << endl;
	}
	cout << endl;
}
void Side::rotateCCW()
{
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
		backup_elements[i][j]=elements[i][j];
			elements[0][0]=backup_elements[0][2];
			elements[0][1]=backup_elements[1][2];
			elements[0][2]=backup_elements[2][2];
			elements[1][0]=backup_elements[0][1];
			elements[1][2]=backup_elements[2][1];
			elements[2][0]=backup_elements[0][0];
			elements[2][1]=backup_elements[1][0];
			elements[2][2]=backup_elements[2][0];
}
void Side::rotateCW()
{
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
		backup_elements[i][j]=elements[i][j];
			elements[0][0]=backup_elements[2][0];
			elements[0][1]=backup_elements[1][0];
			elements[0][2]=backup_elements[0][0];
			elements[1][0]=backup_elements[2][1];
			elements[1][2]=backup_elements[0][1];
			elements[2][0]=backup_elements[2][2];
			elements[2][1]=backup_elements[1][2];
			elements[2][2]=backup_elements[0][2];
}
class RubiksCube
{
		public:
		RubiksCube(){}
		Side B,R,G,O,Y,W,B_backup,R_backup,G_backup,O_backup,Y_backup,W_backup; // inicijalizacija 6 strana i njihovih kopija
		void initialize(); //inicijalizacija kocke, unos rasporeda boja pocevsi od zute strane, zatim plave, crvene, zelene,narancaste i bijele
		void solve(); // pokrece slaganje kocke
		void solveedges(); // slaze rubne kockice
		void solvecorners(); // slaze vrsne kockice
		void turn(int); // okrece stranu u danome smjeru
		void backup(); // cuva trenutno stanje kocke
		void display(); //ispisuje trenutno stanje kocke
		void R_turn(); //radi R potez (okretanje desne strane u smjeru kazaljke na satu)
		void x_rotation(); // radi rotaciju kocke u pozitivnom smjeru x osi, tj rotacija u smjeru R strane (prednja strana postaje bijela, a gornja plava)
		void y_rotation(); // rotacija kocke u pozitivnom smjeru y osi, tj rotacija u smjeru U strane (prednja strana postaje crvena, a gornja ostaje zuta)
		void z_rotation(); // radi rotaciju kocke u pozitivnom smjeru z osi, tj rotaciju u smjeru F strane (prednja strana je plava, a gornja narancasta)
		// koristeci R_turn() i 3 navedene rotacije,moguce je postici okretanje bilo koje strane na kocki
		// implementacija T,Ja,Jb i Y permutacija
		void T_perm(); 
		void J1_perm();
		void J2_perm();
		void Y_perm();
		bool areedgesSolved(); //provjerava jesu li sve rubne kockice slozene
		bool isSolved(); //provjerava je li kocka slozena
		//implementacija ispucavanja rubnih i vrsnih kockica na svoje mjesto
		void shootedgetoA();
		void shootedgetoC();
		void shootedgetoD();
		void shootedgetoE();
		void shootedgetoF();
		void shootedgetoG();
		void shootedgetoH();
		void shootedgetoI();
		void shootedgetoJ();
		void shootedgetoK();
		void shootedgetoL();
		void shootedgetoM();
		void shootedgetoN();
		void shootedgetoO();
		void shootedgetoP();
		void shootedgetoR();
		void shootedgetoS();
		void shootedgetoSh();
		void shootedgetoT();
		void shootedgetoU();
		void shootedgetoV();
		void shootedgetoZ();
		void shootedgetoZh();
		void shootcornertoB();
		void shootcornertoC();
		void shootcornertoD();
		void shootcornertoE();
		void shootcornertoF();
		void shootcornertoG();
		void shootcornertoH();
		void shootcornertoI();
		void shootcornertoJ();
		void shootcornertoK();
		void shootcornertoL();
		void shootcornertoM();
		void shootcornertoO();
		void shootcornertoP();
		void shootcornertoS();
		void shootcornertoSh();
		void shootcornertoT();
		void shootcornertoU();
		void shootcornertoV();
		void shootcornertoZ();
		void shootcornertoZh();
};		
void RubiksCube::initialize()
{
	cout << "Input elements on the yellow side (row by row): " << endl;
	Y.set();
	cout << "Input elements on the blue side (row by row): " << endl;
	B.set();
	cout << "Input elements on the red side (row by row) : " << endl;
	R.set();
	cout << "Input elements on the green side (row by row) : " << endl;
	G.set();
	cout << "Input elements on the orange side (row by row) : " << endl;
	O.set();
	cout << "Input elements on the white side (row by row) : " << endl;
	W.set();
}
void RubiksCube::display()
{
	cout << "Up side : " << endl;
	Y.show();
	cout << "Front side : " << endl;
	B.show();
	cout << "Right side : " << endl;
	R.show();
	cout << "Back side : " << endl;
	G.show();
	cout << "Left side : " << endl;
	O.show();
	cout << "Down side : " << endl;
	W.show();
	cout << endl << endl << endl << endl << endl;
}
void RubiksCube::backup()
{
	B_backup=B;
	R_backup=R;
	G_backup=G;
	O_backup=O;
	Y_backup=Y;
	W_backup=W;
}
void RubiksCube::R_turn()
{
	backup();
	for(int i=0;i<3;i++)
		{
			Y.elements[i][2]=B_backup.elements[i][2];
			B.elements[i][2]=W_backup.elements[i][2];
		}
			R.rotateCW();
			G.elements[0][0]=Y_backup.elements[2][2];
			G.elements[1][0]=Y_backup.elements[1][2];
			G.elements[2][0]=Y_backup.elements[0][2];
			W.elements[0][2]=G_backup.elements[2][0];
			W.elements[1][2]=G_backup.elements[1][0];
			W.elements[2][2]=G_backup.elements[0][0];
	backup();
}
void RubiksCube::x_rotation()
{
	backup();
	Y=B_backup;
	B=W_backup;
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++){
			G.elements[i][j]=Y_backup.elements[2-i][2-j];
			W.elements[i][j]=G_backup.elements[2-i][2-j];
	}
	R.rotateCW();
	O.rotateCCW();
	backup();
}
void RubiksCube::y_rotation()
{
	backup();
	R=G_backup;
	G=O_backup;
	O=B_backup;
	B=R_backup;
	Y.rotateCW();
	W.rotateCCW();
	backup();
}
void RubiksCube::z_rotation()
{
	x_rotation();
	y_rotation();
	for(int i=0;i<3;i++)
	x_rotation();
}
void RubiksCube::T_perm()
{
	//R U R' U' R' F R2 U' R' U' R U R' F'
	turn(82);
	turn(85);
	turn(187);
	turn(190);
	turn(187);
	turn(70);
	turn(132);
	turn(190);
	turn(187);
	turn(190);
	turn(82);
	turn(85);
	turn(187);
	turn(175);
	cout << "R U R' U' R' F R2 U' R' U' R U R' F'";
}
void RubiksCube::J1_perm()
{
	//R U R' F' R U R' U' R' F R2 U' R' U'
	turn(82);
	turn(85);
	turn(187);
	turn(175);
	turn(82);
	turn(85);
	turn(187);
	turn(190);
	turn(187);
	turn(70);
	turn(132);
	turn(190);
	turn(187);
	turn(190);
	cout << "R U R' F' R U R' U' R' F R2 U' R' U'";
}
void RubiksCube::J2_perm()
{
	// (R' U L') U2 (R U' R') U2 (L R U')
	turn(187);
	turn(85);
	turn(181);
	turn(135);
	turn(82);
	turn(190);
	turn(187);
	turn(135);
	turn(76);
	turn(82);
	turn(190);
	cout << "R' U L' U2 R U' R' U2 L R U'";
}
void RubiksCube::Y_perm()
{
	// F R U' R' U' R U R' F' R U R' U' R' F R F'
	
	turn(70);
	turn(82);
	turn(190);
	turn(187);
	turn(190);
	turn(82);
	turn(85);
	turn(187);
	turn(175);
	turn(82);
	turn(85);
	turn(187);
	turn(190);
	turn(187);
	turn(70);
	turn(82);
	turn(175);
	cout << "F R U' R' U' R U R' F' R U R' U' R' F R F' ";
}
bool RubiksCube::areedgesSolved()
{
	if(Y.elements[0][1]=='y' && Y.elements[1][0]=='y' && Y.elements[1][2]=='y' && Y.elements[2][1]=='y' &&
		W.elements[0][1]=='w' && W.elements[1][0]=='w' && W.elements[1][2]=='w' && W.elements[2][1]=='w' &&
			G.elements[0][1]=='g' && G.elements[1][0]=='g' && G.elements[1][2]=='g' && G.elements[2][1]=='g' &&
				B.elements[0][1]=='b' && B.elements[1][0]=='b' && B.elements[1][2]=='b' && B.elements[2][1]=='b' &&
					R.elements[0][1]=='r' && R.elements[1][0]=='r' && R.elements[1][2]=='r' && R.elements[2][1]=='r' &&
						O.elements[0][1]=='o' && O.elements[1][0]=='o' && O.elements[1][2]=='o' && O.elements[2][1]=='o')
							return 1;
	return 0;
}
bool RubiksCube::isSolved()
{
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			if(B.elements[i][j]!='b' || R.elements[i][j]!='r' || G.elements[i][j]!='g' || O.elements[i][j]!='o' || Y.elements[i][j]!='y' || W.elements[i][j]!='w')
				return 0;
	return 1;
}
void RubiksCube::turn(int direction)
{
	switch(direction)
	{
		case 181: //L'
		y_rotation();
		y_rotation();
		R_turn();
		R_turn();
		R_turn();
		y_rotation();
		y_rotation();
		break;
		
		case 76: //L
		y_rotation();
		y_rotation();
		R_turn();
		y_rotation();
		y_rotation();
		break;
		
		case 126: //L2
		y_rotation();
		y_rotation();
		R_turn();
		R_turn();
		y_rotation();
		y_rotation();
		break;
		
		case 187: //R'
		for(int i=0;i<3;i++)
		R_turn();
		break;
		
		case 82: //R
		R_turn();
		break;
		
		case 132: //R2
		R_turn();
		R_turn();
		break;
		
		case 190: //U'
		z_rotation();
		for(int i=0;i<3;i++)
		R_turn();
		for(int i=0;i<3;i++)
		z_rotation();
		break;
		
		case 85: //U
		z_rotation();
		R_turn();
		for(int i=0;i<3;i++)
		z_rotation();
		break;
		
		case 135: //U2
		z_rotation();
		R_turn();
		R_turn();
		for(int i=0;i<3;i++)
		z_rotation();
		break;
		
		case 173: //D'
		for(int i=0;i<3;i++)
		z_rotation();
		for(int i=0;i<3;i++)
		R_turn();
		z_rotation();
		break;
		
		case 68: //D
		for(int i=0;i<3;i++)
		z_rotation();
		R_turn();
		z_rotation();
		break;
		
		case 118: //D2
		for(int i=0;i<3;i++)
		z_rotation();
		R_turn();
		R_turn();
		z_rotation();
		break;
		
		case 175: //F'
		for(int i=0;i<3;i++)
		y_rotation();
		for(int i=0;i<3;i++)
		R_turn();
		y_rotation();
		break;
		
		case 70: //F
		for(int i=0;i<3;i++)
		y_rotation();
		R_turn();
		y_rotation();
		break;
		
		case 120: //F2
		for(int i=0;i<3;i++)
		y_rotation();
		R_turn();
		R_turn();
		y_rotation();
		break;
		
		case 171: //B'
		y_rotation();
		for(int i=0;i<3;i++)
		R_turn();
		for(int i=0;i<3;i++)
		y_rotation();
		break;
		
		case 66: //B
		y_rotation();
		R_turn();
		for(int i=0;i<3;i++)
		y_rotation();
		break;
		
		case 116: //B2
		y_rotation();
		R_turn();
		R_turn();
		for(int i=0;i<3;i++)
		y_rotation();
}
}
void RubiksCube::solve()
{
	solveedges();
	solvecorners();
}
void RubiksCube::shootedgetoD()
{
	 T_perm();
	 cout << endl;
}
void RubiksCube::shootedgetoA()
{
	cout <<" U' ";
	turn(190);
	J2_perm();
	cout <<" U ";
	turn(85);
	cout << endl;
}
void RubiksCube::shootedgetoC()
{
	J1_perm();
	cout <<endl;
}
void RubiksCube::shootedgetoZh()
{
	cout << " L2 ";
	turn(126);
	T_perm();
	cout << " L2 ";
	turn(126);
	cout << endl;
}
void RubiksCube::shootedgetoZ()
{
	cout <<" Lw2 ";
	x_rotation();
	x_rotation();
	turn(132);
	J1_perm();
	x_rotation();
	x_rotation();
	cout <<" Lw2 ";
	turn(132);
	cout <<endl;
}
void RubiksCube::shootedgetoU()
{
	cout <<" Lw2 ";
	x_rotation();
	x_rotation();
	turn(132);
	turn(190);
	cout <<" U' ";
	J2_perm();
	cout << "U";
	turn(85);
	cout <<" Lw2 ";
	x_rotation();
	x_rotation();
	turn(132);
    cout << endl;
}
void RubiksCube::shootedgetoV()
{
	cout <<" D2 ";
	turn(118);
	cout <<" L2 ";
	turn(126);
	T_perm();
	cout <<" L2 ";
	turn(126);
	cout <<" D2 ";
	turn(118);
	cout << endl;
}
void RubiksCube::shootedgetoO()
{
	cout <<" Lw";
	for(int i=0;i<3;i++)
	x_rotation();
	turn(82);
	cout <<" U' ";
	turn(190);
	J2_perm();
	cout<<" U ";
	turn(85);
	cout<<" Lw '";
	x_rotation();
	turn(187);
	cout << endl;
}
void RubiksCube::shootedgetoM()
{
	
	cout <<" Lw ";
	for(int i=0;i<3;i++)
	x_rotation();
	turn(82);
	J1_perm();
	cout << " Lw' ";
	x_rotation();
	turn(187);
	cout <<endl;
}
void RubiksCube::shootedgetoP()
{
	cout << "Dw2 L' ";
	y_rotation();
	y_rotation();
	turn(135);
	turn(181);
	T_perm();
	cout<< "L Dw2";
	turn(76);
	turn(135);
	y_rotation();
	y_rotation();
	cout <<endl;
}
void RubiksCube::shootedgetoN()
{
	cout <<" L ";
	turn(76);
	T_perm();
	cout <<" L' ";
	turn(181);
	cout <<endl;
}
void RubiksCube::shootedgetoE()
{
	
	cout <<" Lw' ";
	x_rotation();
	turn(187);
	cout <<" U' ";
	turn(190);
	J2_perm();
	cout <<" U ";
	turn(85);
	cout <<" Lw ";
	for(int i=0;i<3;i++)
	x_rotation();
	turn(82);
	cout << endl;
}
void RubiksCube::shootedgetoG()
{

	cout<<" Lw' ";
	x_rotation();
	turn(187);
	J1_perm();
	for(int i=0;i<3;i++)
	x_rotation();
	turn(82);
	cout<<" Lw ";
	cout<<endl;
}
void RubiksCube::shootedgetoF()
{
	cout << " Dw2 " ;
	y_rotation();
	y_rotation();
	turn(135);
	cout << " L ";
	turn(76);
	T_perm();
	cout <<" L' ";
	turn(181);
	turn(135);
	y_rotation();
	y_rotation();
	cout <<" Dw2 ";
	cout << endl;
}
void RubiksCube::shootedgetoH()
{

	cout <<" L' ";
	turn(181);
	T_perm();
	turn(76);
	cout <<" L ";
	cout << endl;
}
void RubiksCube::shootedgetoL()
{
	cout <<" Dw' ";
	y_rotation();
	turn(190);
	cout <<" L' ";
	turn(181);
	T_perm();
	turn(76);
	cout <<" L ";
	for(int i=0;i<3;i++)
	y_rotation();
	turn(85);
	cout <<" Dw ";
	cout << endl;
}
void RubiksCube::shootedgetoJ()
{
	cout << " Dw ";
	for(int i=0;i<3;i++)
	y_rotation();
	turn(85);
	cout << " L ";
	turn(76);
	T_perm();
	cout << " L' ";
	turn(181);
	cout << " Dw' ";
	y_rotation();
	turn(190);
	cout << endl;
}
void RubiksCube::shootedgetoK()
{

	cout << " Dw ' ";
	y_rotation();
	turn(190);
	cout << " Lw ' ";
	x_rotation();
	turn(187);
	J1_perm();
	cout << " Lw ";
	for(int i=0;i<3;i++)
	x_rotation();
	turn(82);
	cout << " Dw ";
	for(int i=0;i<3;i++)
	y_rotation();
	turn(85);
	cout << endl;
}
void RubiksCube::shootedgetoR()
{ 
	cout <<" L' ";
	turn(181);
	turn(85);
	turn(171);
	turn(190);
	cout <<" Dw ";
	cout <<" L' ";
	T_perm();
	cout <<" L ";
	cout <<" Dw' ";
	cout <<" L";
	turn(85);
	turn(66);
	turn(190);
	turn(76);
	cout <<endl;
}
void RubiksCube::shootedgetoSh()
{
	cout<< " Dw ";
	turn(85);
	for(int i=0;i<3;i++)
	y_rotation();
	x_rotation();
	cout <<" Lw' ";
	turn(187);
	J1_perm();
	cout << " Lw ";
	cout << " Dw' ";
	turn(82);
	for(int i=0;i<3;i++)
	x_rotation();
	y_rotation();
	turn(190);
	cout << endl;
}
void RubiksCube::shootedgetoS()
{
	cout << " Dw' ";
	y_rotation();
	turn(190);
	cout << " L ";
	turn(76);
	T_perm();
	cout << " L' ";
	turn(181);
	cout << " Dw ";
	for(int i=0;i<3;i++)
	y_rotation();
	turn(85);
	cout << endl;
}
void RubiksCube::shootedgetoT()
{
	cout << " Dw ";
	for(int i=0;i<3;i++)
	y_rotation();
	turn(85);
	cout << " L' ";
	turn(181);
	T_perm();
	cout << " L ";
	turn(76);
	cout << " Dw' ";
	y_rotation();
	turn(190);
	cout << endl;
}
void RubiksCube::solveedges()
{
    cout << "Solving edges: " << endl; 
	while(!areedgesSolved())
	{
		if((Y.elements[1][2]=='y' && R.elements[0][1]=='r') || (Y.elements[1][2]=='r' && R.elements[0][1]=='y'))
		{
			if(Y.elements[0][1]!='y') shootedgetoA();
			else if(Y.elements[1][0]!='y') shootedgetoD(); 
			else if(Y.elements[2][1]!='y') shootedgetoC(); 
			else if(W.elements[0][1]!='w') shootedgetoU(); 
			else if(W.elements[1][2]!='w') shootedgetoV(); 
			else if(W.elements[1][0]!='w') shootedgetoZh();
			else if(W.elements[2][1]!='w') shootedgetoZ(); 
			else if(B.elements[0][1]!='b') shootedgetoE(); 
			else if(B.elements[1][0]!='b') shootedgetoH(); 
			else if(B.elements[2][1]!='b') shootedgetoG(); 
			else if(B.elements[1][2]!='b') shootedgetoF(); 
			else if(G.elements[0][1]!='g') shootedgetoM(); 
			else if(G.elements[1][0]!='g') shootedgetoP(); 
			else if(G.elements[2][1]!='g') shootedgetoO(); 
			else if(G.elements[1][2]!='g') shootedgetoN(); 
			else if(R.elements[1][0]!='r') shootedgetoL(); 
			else if(R.elements[1][2]!='r') shootedgetoJ(); 
			else if(R.elements[2][1]!='r') shootedgetoK(); 
			else if(O.elements[0][1]!='o') shootedgetoR();
			else if(O.elements[1][0]!='o') shootedgetoT(); 
			else if(O.elements[1][2]!='o') shootedgetoS(); 
			else if(O.elements[2][1]!='o') shootedgetoSh();
		}
		else
		{
			if(Y.elements[1][2]=='y')
			{
				if(R.elements[0][1]=='o')shootedgetoD();
				else if(R.elements[0][1]=='g')shootedgetoA();
				else if(R.elements[0][1]=='b')shootedgetoC();
			}
			if(Y.elements[1][2]=='w')
			{
				if(R.elements[0][1]=='o') shootedgetoZh();
				else if(R.elements[0][1]=='g') shootedgetoZ();
				else if(R.elements[0][1]=='b') shootedgetoU();
				else if(R.elements[0][1]=='r') shootedgetoV();
			}
			if(Y.elements[1][2]=='g')
			{
				if(R.elements[0][1]=='w') shootedgetoO();
				else if(R.elements[0][1]=='y') shootedgetoM();
				else if(R.elements[0][1]=='r') shootedgetoP();
				else if(R.elements[0][1]=='o') shootedgetoN();
			}
			if(Y.elements[1][2]=='b')
			{
				if(R.elements[0][1]=='y') shootedgetoE();
				else if(R.elements[0][1]=='w') shootedgetoG();
				else if(R.elements[0][1]=='r') shootedgetoF();
				else if(R.elements[0][1]=='o') shootedgetoH();
		   }
		   if(Y.elements[1][2]=='r')
		   {
			    if(R.elements[0][1]=='b') shootedgetoL();
				else if(R.elements[0][1]=='g') shootedgetoJ();
				else if(R.elements[0][1]=='w') shootedgetoK();
		   }
			if(Y.elements[1][2]=='o') 
			{
				if(R.elements[0][1]=='y') shootedgetoR();
				else if(R.elements[0][1]=='w') shootedgetoSh();
				else if(R.elements[0][1]=='b') shootedgetoS();
				else if(R.elements[0][1]=='g') shootedgetoT();
		    }
				   
		}
		
	}
		
}
void RubiksCube::shootcornertoB()
{
	J2_perm();
	cout << endl;
}
void RubiksCube::shootcornertoC()
{
	Y_perm();
	cout << endl;
}
void RubiksCube::shootcornertoD()
{
	cout << " U2 ";
	turn(135);
	J1_perm();
	cout << " U2 ";
	turn(135);
	cout << endl;
}
void RubiksCube::shootcornertoE()
{
	cout << "F2 R ";
	turn(120);
	turn(82);
	Y_perm();
	cout << " R' F2 ";
	turn(187);
	turn(120);
	cout << endl;
}
void RubiksCube::shootcornertoF()
{
	cout << " R ";
	turn(82);
	J2_perm();
	cout << " R' ";
	turn(187);
	cout << endl;
}
void RubiksCube::shootcornertoG()
{
	cout << " R ";
	turn(82);
	Y_perm();
	cout << " R' ";
	turn(187);
	cout << endl;
}
void RubiksCube::shootcornertoH()
{
	cout << " F' ";
	turn(175);
	cout << " R ";
	turn(82);
	Y_perm();
	cout << " R' ";
	turn(187);
	cout << " F ";
	turn(70);
	cout << endl;
}
void RubiksCube::shootcornertoI()
{
	cout << " F' U2 ";
	turn(175);
	turn(135);
	J1_perm();
	cout << " U2 F ";
	turn(135);
	turn(70);
	cout << endl;
}
void RubiksCube::shootcornertoJ()
{
	cout << " R' F' U2 ";
	turn(187);
	turn(175);
	turn(135);
	J1_perm();
	cout << " U2 F R ";
	turn(135);
	turn(70);
	turn(82);
	cout << endl;
}
void RubiksCube::shootcornertoK()
{
	cout << " D' R ";
	turn(173);
	turn(82);
	Y_perm();
	cout << " R' D ";
	turn(187);
	turn(68);
	cout << endl;
}
void RubiksCube::shootcornertoL()
{
	cout << " F' ";
	turn(175);
	Y_perm();
	cout << " F ";
	turn(70);
	cout << endl;
}
void RubiksCube::shootcornertoM()
{
	cout << " R' ";
	turn(187);
	Y_perm();
	cout << " R ";
	turn(82);
	cout << endl;
}
void RubiksCube::shootcornertoO()
{
	cout << "D2 R ";
	turn(118);
	turn(82);
	Y_perm();
	cout << " R' D2 ";
	turn(187);
	turn(118);
	cout << endl;
}
void RubiksCube::shootcornertoP()
{
	cout << " R' ";
	turn(187);
	J2_perm();
	cout << " R ";
	turn(82);
	cout << endl;
}
void RubiksCube::shootcornertoS()
{
	cout << " F ";
	turn(70);
	Y_perm();
	cout << " F' ";
	turn(175);
	cout << endl;
}
void RubiksCube::shootcornertoSh()
{
	cout << "D R ";
	turn(68);
	turn(82);
	Y_perm();
	cout << "R' D' ";
	turn(187);
	turn(173);
	cout << endl;
}
void RubiksCube::shootcornertoT()
{
	cout << "D' R' ";
	turn(173);
	turn(187);
	J2_perm();
	cout << "R D ";
	turn(82);
	turn(68);
	cout << endl;
}
void RubiksCube::shootcornertoU()
{
	cout << " F2 ";
	turn(120);
	Y_perm();
	cout << " F2 ";
	turn(120);
	cout << endl;
}
void RubiksCube::shootcornertoV()
{
	cout << " R2 ";
	turn(132);
	J2_perm();
	cout << " R2 ";
	turn(132);
	cout << endl;
}
void RubiksCube::shootcornertoZ()
{
	cout << " R2 ";
	turn(132);
	Y_perm();
	cout << " R2 ";
	turn(132);
	cout << endl;
}
void RubiksCube::shootcornertoZh()
{
	cout << "D2 R2 ";
	turn(118);
	turn(132);
	J2_perm();
	cout << " R2 D2 ";
	turn(132);
	turn(118);
	cout << endl;
}
void RubiksCube::solvecorners()
{
    cout << endl;
    cout << "Solving corners... " << endl;
	while(!isSolved())
	{
		if((Y.elements[0][0]=='y' && O.elements[0][0]=='o') || (Y.elements[0][0]=='g' && O.elements[0][0]=='y') || (Y.elements[0][0]=='o' && O.elements[0][0]=='g'))
		{
			if(Y.elements[0][2]!='y') shootcornertoB();
			else if(Y.elements[2][2]!='y') shootcornertoC(); 
			else if(Y.elements[2][0]!='y') shootcornertoD();
			else if(B.elements[0][0]!='b') shootcornertoE(); 
			else if(B.elements[0][2]!='b') shootcornertoF();
			else if(B.elements[2][2]!='b') shootcornertoG();
			else if(B.elements[2][0]!='b') shootcornertoH(); 
			else if(R.elements[0][0]!='r') shootcornertoI();
			else if(R.elements[0][2]!='r') shootcornertoJ(); 
			else if(R.elements[2][2]!='r') shootcornertoK(); 
			else if(R.elements[2][0]!='r') shootcornertoL(); 
			else if(G.elements[0][0]!='g') shootcornertoM();
			else if(G.elements[2][2]!='g') shootcornertoO();
			else if(G.elements[2][0]!='g') shootcornertoP();
			else if(O.elements[0][2]!='o') shootcornertoS(); 
			else if(O.elements[2][2]!='o') shootcornertoSh();
			else if(O.elements[2][0]!='o') shootcornertoT(); 
			else if(W.elements[0][0]!='w') shootcornertoU(); 
			else if(W.elements[0][2]!='w') shootcornertoV();
			else if(W.elements[2][2]!='w') shootcornertoZ();
			else if(W.elements[2][0]!='w') shootcornertoZh();
		}
		else
		{
			if(Y.elements[0][0]=='y')
			{
				if(O.elements[0][0]=='r') shootcornertoC();
				else if(O.elements[0][0]=='b') shootcornertoD();
				else if(O.elements[0][0]=='g') shootcornertoB();
			}
			else if(Y.elements[0][0]=='w')
			{
				if(O.elements[0][0]=='o') shootcornertoU();
				else if(O.elements[0][0]=='b') shootcornertoV();
				else if(O.elements[0][0]=='r') shootcornertoZ();
				else if(O.elements[0][0]=='g') shootcornertoZh();
			}
			else if(Y.elements[0][0]=='b')
			{
				if(O.elements[0][0]=='o') shootcornertoE();
				else if(O.elements[0][0]=='y') shootcornertoF();
				else if(O.elements[0][0]=='r') shootcornertoG();
				else if(O.elements[0][0]=='w') shootcornertoH();
			}
			else if(Y.elements[0][0]=='r')
			{
				if(O.elements[0][0]=='b') shootcornertoI();
				else if(O.elements[0][0]=='y') shootcornertoJ();
				else if(O.elements[0][0]=='g') shootcornertoK();
				else if(O.elements[0][0]=='w') shootcornertoL();
			}
			else if(Y.elements[0][0]=='g')
			{
				if(O.elements[0][0]=='r') shootcornertoM();
				else if(O.elements[0][0]=='o') shootcornertoO();
				else if(O.elements[0][0]=='w') shootcornertoP();
			}
			else
			{
				if(O.elements[0][0]=='y') shootcornertoS();
				else if(O.elements[0][0]=='b') shootcornertoSh();
				else if(O.elements[0][0]=='w') shootcornertoT();
			}
		}
	}
	cout << "Solved!" << endl;
}
int main(void)
{
	RubiksCube r;
	r.initialize();
	r.display();
	r.solve();
	r.display();
	return 0;
}