/********/

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <armadillo>
#include <ctime>
#include <cstdlib>

#include <GL/glut.h>

#define WX 1000
#define WY 500
#define GAP 10

using namespace arma;

// variables globales pour OpenGL
int window,width,height, F3D, temoin;
const int NMAX = 100;
int N = 0;
int mp=-1,droite=0,gauche=0;
float s=0.5f;
int presse=0;
int anglex=0,angley=0,xold,yold;
int NP=50;

enum TypeBouton
{
    action1 = 0,
    action2,
    action3,
	action4
} bouton_action = action1;


struct Point {
	double x,y;
	Point(double a=0, double b=0) {set(a,b);}
	void set(double a, double b) {x=a;y=b;}
};

struct Point3D{
	double x, y, z;
	Point3D(double a=0, double b=0, double c=0) {set(a,b,c);}
	void set(double a, double b, double c) {x=a; y=b; z=c;}
};

struct CouleurRVB{
	double r, v, b;
	CouleurRVB(double a=0, double b=0, double c=0) {set(a,b,c);}
	void set(double a, double b, double c) {r=a; v=b; b=c;}
};

Point P[NMAX];
const int nbPoints=10000;
const int col=sqrt(nbPoints);
float maxy=1;
Point3D P3D[nbPoints]; 
CouleurRVB Couleur[nbPoints-col];

static void menu (int item)
{
    bouton_action = static_cast<TypeBouton> (item);
    glutPostRedisplay ();
}

void initializePoints(){
	int cpt =0;
	float mult=20;
	for(int i=-50;i<50;i++){
		for(int j=-50;j<50;j++){

			int temp=mult*abs(sinf(2*i)*cosf(3*j));

			P3D[cpt].x = i*10;
			P3D[cpt].y = temp;
			P3D[cpt].z = j*10;
			
			if(maxy<temp)
				maxy=temp;

			cpt++;
		}
	}

	for(int i=0;i<nbPoints-col;i++){
		Point3D p = P3D[i];
		Couleur[i].r = static_cast <float> ((p.y/maxy)+0.1);
		Couleur[i].v = static_cast <float> ((p.y/maxy)+0.1);
		Couleur[i].b = static_cast <float> ((p.y/maxy)+0.1);
	}
}
void TracePoints(){

	float r,v,b;
	glColor3f(r,v,b);
	glBegin(GL_TRIANGLE_STRIP);

	for (int i=0;i<nbPoints-col-1;i++){

		r = Couleur[i].r;
		v = Couleur[i].v;
		b = Couleur[i].b;
		glColor3f(r,v,b);

		glVertex3f(P3D[i].x, P3D[i].y, P3D[i].z);
		glVertex3f(P3D[i+col].x, P3D[i+col].y, P3D[i+col].z);
		glVertex3f(P3D[i+1].x, P3D[i+1].y, P3D[i+1].z);
		glVertex3f(P3D[i+col+1].x, P3D[i+col+1].y, P3D[i+col+1].z);

		

	}
	glEnd();
}

/*
void TracePoints()
{
	glColor3f(0.0,1.0,0.0);
	glBegin(GL_POINTS);
	for (int i=0;i<N;i++){
		glVertex2f(P[i].x,P[i].y);
	}
	glEnd();
	glColor3f(1.0,1.0,1.0);
	glLineStipple(1, 0x3F07);
	glEnable(GL_LINE_STIPPLE);
	glBegin(GL_LINE_STRIP);
	for (int i=0;i<N;i++){
		glVertex2f(P[i].x,P[i].y);
	}
	glEnd();	
	glDisable(GL_LINE_STIPPLE);
}
*/

/*
void bezier(){
	mat matBezier = {{-1,3,-3,1}, {3, -6, 3, 0}, {-3, 3, 0, 0}, {1, 0, 0, 0}};
	mat matParam(1,4);

	mat matPointX(4, 1);
	mat matPointY(4, 1);
	
	for(int i=0;i<N;i++){
		if(i!=0 && i%3 == 0){
			for(int k=0;k<4;k++){
				double coordX = P[i-k].x;
				double coordY = P[i-k].y;

				matPointX.at(k,0) = coordX;
				matPointY.at(k,0) = coordY;
			}

			glBegin(GL_LINE_STRIP);
			glColor3f(1.0f, 0.0f, 0.0f);
			for(double j=0;j<1;j+=0.01){

				//double scJ=
				mat matParam = {{pow(j,3), pow(j,2), j, 1}};

				mat resultMultX = matParam*matBezier*matPointX;
				mat resultMultY = matParam*matBezier*matPointY;

				glVertex2f(resultMultX(0,0), resultMultY(0,0));
			}
			glEnd();
		}
	}
}
*/

void catmullRom(){
	mat matCatmullRom = { {-s, 2-s, s-2, s} , {2*s, s-3, 3-2*s, -s} , {-s, 0, s, 0} , {0, 1, 0, 0} };


	mat matPointX(4, 1);
	mat matPointY(4, 1);

	for(int i=3;i<N;i++){
		if(N>3 && i%1 == 0){
			for(int k=0;k<4;k++){
				double coordX = P[i-k].x;
				double coordY = P[i-k].y;

				matPointX.at(k,0) = coordX;
				matPointY.at(k,0) = coordY;
			}

			glBegin(GL_LINE_STRIP);
			glColor3f(1.0f, 1.0f, 0.0f);
			for(double j=0;j<1;j+=0.01){

				mat matParam = {{pow(j,3), pow(j,2), j, 1}};

				mat resultMultX = matParam*matCatmullRom*matPointX;
				mat resultMultY = matParam*matCatmullRom*matPointY;

				glVertex2f(resultMultX(0,0), resultMultY(0,0));
			}
			glEnd();
		}
	}
}

/*
void catmullRom3D(){

    mat matCatmullRom = { {-s, 2-s, s-2, s} , {2*s, s-3, 3-2*s, -s} , {-s, 0, s, 0} , {0, 1, 0, 0} };


    mat matPointX(4, 1);
    mat matPointY(4, 1);

    for(int i=3;i<N;i++){
        if(N>3 && i%1 == 0){
            for(int k=0;k<4;k++){
                double coordX = P[i-k].x;
                double coordY = P[i-k].y;

                matPointX.at(k,0) = coordX;
                matPointY.at(k,0) = coordY;
            }

            glBegin(GL_LINE_STRIP);
            glColor3f(1.0f, 1.0f, 0.0f);
            for(double j=0;j<1;j+=0.01){

                mat matParam = {{pow(j,3), pow(j,2), j, 1}};

                mat resultMultX = matParam*matCatmullRom*matPointX;
                mat resultMultY = matParam*matCatmullRom*matPointY;

                float teta = 0;
                float decalage = 2*M_PI/NP;

                for(int k=0;k<NP;k++){
                    float coordX, coordY, coordZ;
                    coordX = resultMultX(0,0) * cosf(teta);
                    coordY = resultMultY(0,0);
                    coordZ = resultMultX(0,0) * sinf(teta);

                    glVertex3f(coordX, coordY, coordZ);

                    teta+=decalage;
                }

            }
            glEnd();
        }
    }
}
*/

/*
void BSplines(){
	mat matBSplines = { {-1, 3, -3, 1} , {3, -6, 3, 0} , {-3, 0, 3, 0} , {1, 4, 1, 0} };

	mat matPointX(4, 1);
	mat matPointY(4, 1);

	for(int i=3;i<N;i++){
		if(N>3 && i%1 == 0){
			for(int k=0;k<4;k++){
				double coordX = P[i-k].x;
				double coordY = P[i-k].y;

				matPointX.at(k,0) = coordX;
				matPointY.at(k,0) = coordY;
			}

			glBegin(GL_LINE_STRIP);
			glColor3f(1.0f, 0.0f, 1.0f);
			for(double j=0;j<1;j+=0.01){

				mat matParam = {{pow(j,3), pow(j,2), j, 1}};
				matParam = matParam * 1.0f/6.0f;

				mat resultMultX = matParam*matBSplines*matPointX;
				mat resultMultY = matParam*matBSplines*matPointY;

				glVertex2f(resultMultX(0,0), resultMultY(0,0));
			}
			glEnd();
		}
	}
}
*/

void main_reshape(int width,  int height) 
{
    GLint viewport[4];
	
    glViewport(0, 0, width, height);
    glGetIntegerv(GL_VIEWPORT, viewport);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

	glOrtho(0.0, viewport[2], 0.0,viewport[3], -50.0, 50.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}


void main_display(void)
{
    glClearColor(0.5, 0.5, 0.5, 0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glutPostRedisplay();
    glutSwapBuffers();
}



void Mouse(int button, int state, int x, int y) {
	GLint viewport[4];

	glutSetCursor(GLUT_CURSOR_CROSSHAIR);
	glGetIntegerv(GL_VIEWPORT, viewport);
	

	if(glutGetModifiers() ==  GLUT_ACTIVE_CTRL && button == GLUT_LEFT_BUTTON) {
		droite = 0; gauche = 1;
			glColor3f(0.0,1.0,0.0);
			glPointSize(3.0);
			glInitNames();
			glPushName(1);

			P[N].x = x;
			P[N].y =  viewport[3]-y;

			glLoadName(N);
			glBegin(GL_POINTS);
				glVertex2f(P[N].x,P[N].y);
			glEnd();
			
			if(state == GLUT_UP) N++;
			glutPostRedisplay();		
		}


	if(glutGetModifiers() !=  GLUT_ACTIVE_CTRL && button == GLUT_LEFT_BUTTON) {
		gauche = 0; droite = 1;
		if(state == GLUT_DOWN) {
			GLuint *selectBuf = new GLuint[200];
			GLuint *ptr;
			GLint hits;

			glSelectBuffer(200, selectBuf);
			glRenderMode(GL_SELECT);

			glPushMatrix();
			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			gluPickMatrix(x, viewport[3]-y, 5.0, 5.0, viewport);
			glOrtho(0.0,  viewport[2], 0.0,  viewport[3], -50.0, 50.0);

			glColor3f(0.0,1.0,0.0);
			glPointSize(3.0);
			glInitNames();
			glPushName(1);

			for (int i = 0;i<N;i++) {
				glLoadName(i);
				glBegin(GL_POINTS);
				glVertex2f(P[i].x,P[i].y);
				glEnd();			
			}
				
			glPopMatrix();
			glFlush();

			hits = glRenderMode(GL_RENDER);
			if(hits) {
				ptr = (GLuint *)selectBuf;
				ptr += 3;
				mp = *ptr;
			}
		}

		if(state == GLUT_UP)
			mp = -1;

		main_reshape(viewport[2], viewport[3]);
		glutPostRedisplay();
	}
}

void Motion(int x, int y) {
	GLint viewport[4];
	glGetIntegerv(GL_VIEWPORT, viewport);

	if ((droite) &&(mp != -1)) {
		int i= mp;
		P[i].x = x;
		P[i].y =  viewport[3]-y;
		//TracePoints();

		glutPostRedisplay();
	}
}

void keyboard(unsigned char key, int x, int y){

}

void F3D_reshape(int x, int y){
    if (x<y)
        glViewport(0,(y-x)/2,x,x);
    else
        glViewport((x-y)/2,0,y,y);
}

void temoin_reshape(int width, int height){

}

void F3D_affichage(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glOrtho(-500,500,-500,500,-500,500);
    glRotatef(-(float)angley,1.0,0.0,0.0);
    glRotatef(-(float)anglex,0.0,1.0,0.0);

    glutPostRedisplay();

    //catmullRom3D();
    //glutSolidCube(500);
	TracePoints();

    glutSwapBuffers();
}

void temoin_affichage(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	/*
    switch (bouton_action) {
        case action1:
            bezier();
            break;
        case action2:
            catmullRom();
            break;
        case action3:
            BSplines();
            break;
        case action4:
            catmullRom();
            bezier();
            BSplines();
            break;
    }	
	*/

    glColor3f(0.0,1.0,0.0);
    glPointSize(3.0);
    glInitNames();
    glPushName(1);
    for (int i=0;i<N;i++){
        glLoadName(i);
        glBegin(GL_POINTS);
        glVertex2f(P[i].x,P[i].y);
        glEnd();
    }

    //TracePoints();
    glutPostRedisplay();

    glutSwapBuffers();
}

void F3D_motion(int x, int y){
    {
        if (presse) /* si le bouton gauche est presse */
        {
            /* on modifie les angles de rotation de l'objet
           en fonction de la position actuelle de la souris et de la derniere
           position sauvegardee */
            anglex=anglex+(x-xold);
            angley=angley+(y-yold);
            glutPostRedisplay(); /* on demande un rafraichissement de l'affichage */
        }

        xold=x; /* sauvegarde des valeurs courante de le position de la souris */
        yold=y;
    }
}

void F3D_mouse(int button, int state, int x,int y){
    /* si on appuie sur le bouton gauche */
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        presse = 1; /* le booleen presse passe a 1 (vrai) */
        xold = x; /* on sauvegarde la position de la souris */
        yold=y;
    }
    /* si on relache le bouton gauche */
    if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
        presse=0; /* le booleen presse passe a 0 (faux) */
}


int main (int argc, char** argv)
{
	srand (static_cast <unsigned> (time(0)));
	initializePoints();

    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
    glutInitWindowSize(WX, WY);
    glutInitWindowPosition(0, 0);
    glutInit(&argc, argv);
	glEnable(GL_DEPTH_TEST);
    
    window = glutCreateWindow("Courbes Cubiques");

    glutReshapeFunc(main_reshape);
    glutDisplayFunc(main_display);

    //Fenetre 3D
    F3D = glutCreateSubWindow(window, GAP, GAP, WX/2, WY);
    glutReshapeFunc(F3D_reshape);
    glutDisplayFunc(F3D_affichage);
    glutMotionFunc(F3D_motion);
    glutMouseFunc(F3D_mouse);


    //Fenetre 2D
    temoin = glutCreateSubWindow(window, GAP+WX/2+GAP, GAP, WX/2, WY);
    glutReshapeFunc(temoin_reshape);
    glutDisplayFunc(temoin_affichage);
    glutMouseFunc(Mouse);
	glutMotionFunc(Motion);
	glutKeyboardFunc(keyboard);

    glutCreateMenu(menu);
    glutAddMenuEntry ("Bezier", action1);
    glutAddMenuEntry ("CatmullRom", action2);
    glutAddMenuEntry ("BSplines", action3);
    glutAddMenuEntry ("TOUT", action4);
    glutAttachMenu (GLUT_RIGHT_BUTTON);

	glutPostRedisplay();

    glutMainLoop();
    return (1);
}



