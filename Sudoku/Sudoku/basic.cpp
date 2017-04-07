#include <windows.h>
#include <GL/glut.h>
#include <conio.h>
#include <SOIL.h>
#include <stdio.h>
#include <Record.h>
#include <MP3.h>
#include <stdlib.h>

#define LEFT 37
#define UP 38
#define RIGHT 39
#define DOWN 40

GLuint Texture[37];
GLfloat angle=0.0f;
int m=0,n=0,number,k=0;
int Screen=0,icord=0,t=0;

int A[9][9];
bool lock[9][9];
int *P,SNo=1;

void Lock()
{
	for(int i=0; i<9; i++)
		for(int j=0;j<9;j++)
		{
			if(A[i][j]!=0)
				lock[i][j]=TRUE;
			else
				lock[i][j]=FALSE;
		}
}

void AskSudoku(int k)
{
	if(k > 3){
	
		exit(0);	
	}

	for(int i=0; i<9; i++)
		for(int j=0; j<9; j++)
		{
			lock[i][j]=false;
			A[i][j]=0;
		}

	P=Rec(k);

	k=1;

	for(int i=0; i<9; i++)
		for(int j=0; j<9; j++)
		{
			A[i][j]=*(P+k);
			k++;

			printf("%d ",A[i][j]);
		}

	Lock();
	printf("\n");
}

void Play(int KEY)
{
	if(KEY==LEFT)
		n--;
	else if(KEY==RIGHT)
		n++;
	else if(KEY==UP)
		m--;
	else if(KEY==DOWN)
		m++;

	if(m>8)
		m=0;
	else if(m<0) 
		m=8;
	if(n>8)
		n=0;
	else if(n<0)
		n=8;
}

int LoadGLTexture(int i)
{
	Texture[0]=SOIL_load_OGL_texture("Data/empty.bmp",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
	Texture[1]=SOIL_load_OGL_texture("Data/number1.bmp",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
	Texture[2]=SOIL_load_OGL_texture("Data/number2.bmp",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
	Texture[3]=SOIL_load_OGL_texture("Data/number3.bmp",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
	Texture[4]=SOIL_load_OGL_texture("Data/number4.bmp",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
	Texture[5]=SOIL_load_OGL_texture("Data/number5.bmp",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
	Texture[6]=SOIL_load_OGL_texture("Data/number6.bmp",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
	Texture[7]=SOIL_load_OGL_texture("Data/number7.bmp",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
	Texture[8]=SOIL_load_OGL_texture("Data/number8.bmp",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
	Texture[9]=SOIL_load_OGL_texture("Data/number9.bmp",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
	Texture[10]=SOIL_load_OGL_texture("Data/sudoku.bmp",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
	Texture[11]=SOIL_load_OGL_texture("Data/instruction_back.bmp",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
	Texture[12]=SOIL_load_OGL_texture("Data/ques.bmp",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
	Texture[13]=SOIL_load_OGL_texture("Data/back.bmp",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
	Texture[14]=SOIL_load_OGL_texture("Data/number1s.bmp",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
	Texture[15]=SOIL_load_OGL_texture("Data/number2s.bmp",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
	Texture[16]=SOIL_load_OGL_texture("Data/number3s.bmp",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
	Texture[17]=SOIL_load_OGL_texture("Data/number4s.bmp",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
	Texture[18]=SOIL_load_OGL_texture("Data/number5s.bmp",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
	Texture[19]=SOIL_load_OGL_texture("Data/number6s.bmp",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
	Texture[20]=SOIL_load_OGL_texture("Data/number7s.bmp",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
	Texture[21]=SOIL_load_OGL_texture("Data/number8s.bmp",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
	Texture[22]=SOIL_load_OGL_texture("Data/number9s.bmp",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
	Texture[23]=SOIL_load_OGL_texture("Data/setting.bmp",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
	Texture[24]=SOIL_load_OGL_texture("Data/options.bmp",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
	Texture[25]=SOIL_load_OGL_texture("Data/quess.bmp",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
	Texture[26]=SOIL_load_OGL_texture("Data/main_back.bmp",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
	Texture[27]=SOIL_load_OGL_texture("Data/number1e.bmp",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
	Texture[28]=SOIL_load_OGL_texture("Data/number2e.bmp",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
	Texture[29]=SOIL_load_OGL_texture("Data/number3e.bmp",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
	Texture[30]=SOIL_load_OGL_texture("Data/number4e.bmp",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
	Texture[31]=SOIL_load_OGL_texture("Data/number5e.bmp",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
	Texture[32]=SOIL_load_OGL_texture("Data/number6e.bmp",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
	Texture[33]=SOIL_load_OGL_texture("Data/number7e.bmp",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
	Texture[34]=SOIL_load_OGL_texture("Data/number8e.bmp",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);
	Texture[35]=SOIL_load_OGL_texture("Data/number9e.bmp",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,SOIL_FLAG_INVERT_Y);

	glBindTexture(GL_TEXTURE_2D,Texture[0]);
	glBindTexture(GL_TEXTURE_2D,Texture[1]);
	glBindTexture(GL_TEXTURE_2D,Texture[2]);
	glBindTexture(GL_TEXTURE_2D,Texture[3]);
	glBindTexture(GL_TEXTURE_2D,Texture[4]);
	glBindTexture(GL_TEXTURE_2D,Texture[5]);
	glBindTexture(GL_TEXTURE_2D,Texture[6]);
	glBindTexture(GL_TEXTURE_2D,Texture[7]);
	glBindTexture(GL_TEXTURE_2D,Texture[8]);
	glBindTexture(GL_TEXTURE_2D,Texture[9]);
	glBindTexture(GL_TEXTURE_2D,Texture[10]);
	glBindTexture(GL_TEXTURE_2D,Texture[11]);
	glBindTexture(GL_TEXTURE_2D,Texture[12]);
	glBindTexture(GL_TEXTURE_2D,Texture[13]);
	glBindTexture(GL_TEXTURE_2D,Texture[14]);
	glBindTexture(GL_TEXTURE_2D,Texture[15]);
	glBindTexture(GL_TEXTURE_2D,Texture[16]);
	glBindTexture(GL_TEXTURE_2D,Texture[17]);
	glBindTexture(GL_TEXTURE_2D,Texture[18]);
	glBindTexture(GL_TEXTURE_2D,Texture[19]);
	glBindTexture(GL_TEXTURE_2D,Texture[20]);
	glBindTexture(GL_TEXTURE_2D,Texture[21]);
	glBindTexture(GL_TEXTURE_2D,Texture[22]);
	glBindTexture(GL_TEXTURE_2D,Texture[25]);
	glBindTexture(GL_TEXTURE_2D,Texture[26]);
	glBindTexture(GL_TEXTURE_2D,Texture[27]);
	glBindTexture(GL_TEXTURE_2D,Texture[28]);
	glBindTexture(GL_TEXTURE_2D,Texture[29]);
	glBindTexture(GL_TEXTURE_2D,Texture[30]);
	glBindTexture(GL_TEXTURE_2D,Texture[31]);
	glBindTexture(GL_TEXTURE_2D,Texture[32]);
	glBindTexture(GL_TEXTURE_2D,Texture[33]);
	glBindTexture(GL_TEXTURE_2D,Texture[34]);
	glBindTexture(GL_TEXTURE_2D,Texture[35]);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

	return TRUE;		
}

void DrawRec(int length , int width,int tex)
{
	glBindTexture(GL_TEXTURE_2D,Texture[tex]);
	glBegin(GL_QUADS);
		glTexCoord2f(0.0,1.0);glVertex2f((0-length/2),width/2);
		glTexCoord2f(1.0,1.0);glVertex2f(length/2,width/2);
		glTexCoord2f(1.0,0.0);glVertex2f(length/2,(0-width/2));
		glTexCoord2f(0.0,0.0);glVertex2f((0-length/2),(0-width/2));
	glEnd();
}

void Drawcube()
{
	glBegin(GL_QUADS);
		glTexCoord2f(0.0,1.0);glVertex3f(-1,1,1);
		glTexCoord2f(1.0,1.0);glVertex3f(1,1,1);
		glTexCoord2f(1.0,0.0);glVertex3f(1,-1,1);
		glTexCoord2f(0.0,0.0);glVertex3f(-1,-1,1);

		glTexCoord2f(0.0,1.0);glVertex3f(1,1,-1);
		glTexCoord2f(1.0,1.0);glVertex3f(-1,1,-1);
		glTexCoord2f(1.0,0.0);glVertex3f(-1,-1,-1);
		glTexCoord2f(0.0,0.0);glVertex3f(1,-1,-1);

		glTexCoord2f(0.0,1.0);glVertex3f(-1,1,-1);
		glTexCoord2f(1.0,1.0);glVertex3f(-1,1,1);
		glTexCoord2f(1.0,0.0);glVertex3f(-1,-1,1);
		glTexCoord2f(0.0,0.0);glVertex3f(-1,-1,-1);

		glTexCoord2f(0.0,1.0);glVertex3f(1,1,1);
		glTexCoord2f(1.0,1.0);glVertex3f(1,1,-1);
		glTexCoord2f(1.0,0.0);glVertex3f(1,-1,-1);
		glTexCoord2f(0.0,0.0);glVertex3f(1,-1,1);

		glTexCoord2f(0.0,1.0);glVertex3f(-1,1,-1);
		glTexCoord2f(1.0,1.0);glVertex3f(1,1,-1);
		glTexCoord2f(1.0,0.0);glVertex3f(1,1,1);
		glTexCoord2f(0.0,0.0);glVertex3f(-1,1,1);

		glTexCoord2f(0.0,1.0);glVertex3f(-1,-1,1);
		glTexCoord2f(1.0,1.0);glVertex3f(1,-1,1);
		glTexCoord2f(1.0,0.0);glVertex3f(1,-1,-1);
		glTexCoord2f(0.0,0.0);glVertex3f(-1,-1,-1);
		
	glEnd();
}

void Arrange()
{
	for(int i=0, k=0; i<=16; i+=2,k-=2)
		for(int j=0; j<=16; j+=2)
		{
			glLoadIdentity();
			glScalef(1.3,1.3,1.3);
			glTranslatef(j-8,k+6,0);
			if(i/2==m && j/2==n)
				glRotatef(angle,0,1,0);
			if(A[i/2][j/2]!=0)
			{
				if(i/2==m && j/2==n){
				
					if(A[i/2][j/2] < 10)glBindTexture(GL_TEXTURE_2D,Texture[A[i/2][j/2]+13]);
					else glBindTexture(GL_TEXTURE_2D,Texture[A[i/2][j/2]]);
				}
				else
					glBindTexture(GL_TEXTURE_2D,Texture[A[i/2][j/2]]);
			}
			else
				if(i/2==m && j/2==n)
					glBindTexture(GL_TEXTURE_2D,Texture[25]);
				else
					glBindTexture(GL_TEXTURE_2D,Texture[12]);

			Drawcube();
		}

		glLoadIdentity();
		glScalef(2.3,2.3,2.3);
		glTranslatef(0.0,6,0
			);
		DrawRec(8,2,10);
		
	glLoadIdentity();
	glScalef(1.2,1.2,1.2);
	DrawRec(30,30,13);
}

static void Timer1(int value)
{
	glutTimerFunc(28000,Timer1,0);
}

static void Timer(int value)
{
	Mp3Init();
	Mp3Load("tune.mp3");
	Mp3Play();
	glutTimerFunc(28000,Timer,0);
}

int Initiate(int i)
{
	if(!LoadGLTexture(i))
		return FALSE;

	glEnable(GL_TEXTURE_2D);
	glShadeModel(GL_SMOOTH);
	glClearColor(0.5,0.5,0.5,0.0);
	return TRUE;
}

void spin()
{
	angle+=0.1;
	glutPostRedisplay();
}

void Reshape(int x,int y)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45,x/y,0.5,100);
	gluLookAt(0.0,0.0,40.0,0.0,0.0,0.0,0.0,1.0,0.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void SpecialKey(int key,int x,int y)
{
	if(Screen==0)
	{
		switch(key)
		{
		case GLUT_KEY_UP:
			icord--;
			break;
		case GLUT_KEY_DOWN:
			icord++;
			break;
		}
		printf("%d ",icord);
	}
	else
	{
		switch(key)
		{
		case GLUT_KEY_UP:
			Play(UP);
			break;
		case GLUT_KEY_DOWN:
			Play(DOWN);
			break;
		case GLUT_KEY_LEFT:
			Play(LEFT);
			break;
		case GLUT_KEY_RIGHT:
			Play(RIGHT);
			break;
		}
	}
}


int Place(int A[][9], int row, int col, int num)
{
    int rowStart = (row/3) * 3;
    int colStart = (col/3) * 3;
    int i, j;

    for(i=0; i<9; ++i)
    {
        if (A[row][i] == num) return 0;
        if (A[i][col] == num) return 0;
        if (A[rowStart + (i%3)][colStart + (i/3)] == num) return 0;
    }
    return 1;
}

int fillSudoku(int A[][9], int row, int col)
{
    int i;
    if(row<9 && col<9)
    {
        if(lock[row][col])
        {
            if((col+1)<9) return fillSudoku(A, row, col+1);
            else if((row+1)<9) return fillSudoku(A, row+1, 0);
            else return 1;
        }
        else
        {
            for(i=0; i<9; ++i)
            {
                if(Place(A, row, col, i+1))
                {
                    A[row][col] = i+1;
                    if((col+1)<9)
                    {
                        if(fillSudoku(A, row, col+1)) return 1;
                        else A[row][col] = 0;
                    }
                    else if((row+1)<9)
                    {
                        if(fillSudoku(A, row+1, 0)) return 1;
                        else A[row][col] = 0;
                    }
                    else return 1;
                }
            }
        }
        return 0;
    }
    else return 1;
}

void solve(char key)
{
	if(key=='s'){

		for(int i = 0 ; i < 9 ; i++){
		
			for(int j =0 ; j < 9 ; j++){
			
				if(!lock[i][j])
					A[i][j] = 0;
			}
		}

		fillSudoku(A, 0, 0);
	}
	else if(key=='n')
		AskSudoku(++SNo);
}

void MainScreen()
{
	glLoadIdentity();
	glTranslatef(0,14,0);
	DrawRec(15,4,10);

	glLoadIdentity();
	glTranslatef(0,1,0);
	DrawRec(27,18,11);
	/*glTranslatef(0,-6,0);
	DrawRec(14,4,23);
	glTranslatef(0,-6,0);
	DrawRec(14,4,24);*/

	glLoadIdentity();
	glScalef(1.2,1.2,1.2);
	DrawRec(30,30,26);
}

void Display()
{
	if(Screen==0)
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		MainScreen();
	}
	else
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	
		Arrange();		
	}
	glFlush();
	glutSwapBuffers();
}

void Keyboard(unsigned char key,int x,int y)
{
	if(!kbhit())
	{
		if(key==27)
			exit(0);
		else if(key==13)
			Screen=1;
		else if(key=='s' || key=='n')
		{
			solve(key);
			Arrange();
		}
		else if(48<key<57)
		{
			number=key-48;
			if(lock[m][n]==FALSE){
			
				if(Place(A,m,n,number))
					A[m][n]=number;
				else
					A[m][n]=key-22;
			}
		}
	}
}


int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowPosition(10,10);
	glutInitWindowSize(500,500);
	glutCreateWindow("Sudoku");
	FreeConsole();
	AskSudoku(1);
	Initiate(0);
	glutDisplayFunc(Display);
	glutReshapeFunc(Reshape);
	glutKeyboardFunc(Keyboard);
	glutSpecialFunc(SpecialKey);
	glutIdleFunc(spin);
	
	glEnable(GL_DEPTH_TEST);
	
	Timer(0);

	glutMainLoop();

	Mp3Stop();
	
	return 0;
}