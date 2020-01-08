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
#define PI 3.14159
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


void traceRail(Point3D a, Point3D b) {

	double dist = sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z));

	double longueur = 100;
	double hauteur = 30;

	glColor3f(0.15,0.10,0.1);
	glEnable(GL_DEPTH_TEST);

	// face cote A
	glBegin(GL_QUADS);
		glVertex3d(a.x+longueur, a.y, a.z);
		glVertex3d(a.x+longueur, a.y+hauteur, a.z);
		glVertex3d(a.x-longueur, a.y+hauteur, a.z);
		glVertex3d(a.x-longueur, a.y, a.z);
	glEnd();

	// face superieure
	glBegin(GL_QUADS);
		glVertex3d(a.x+longueur, a.y+hauteur, a.z+dist);
		glVertex3d(a.x+longueur, a.y+hauteur, a.z);
		glVertex3d(a.x-longueur, a.y+hauteur, a.z);
		glVertex3d(a.x-longueur, a.y+hauteur, a.z+dist);
	glEnd();

	// face cote B
	glBegin(GL_QUADS);
		glVertex3d(a.x+longueur, a.y+hauteur, a.z+dist);
		glVertex3d(a.x+longueur, a.y, a.z+dist);
		glVertex3d(a.x-longueur, a.y, a.z+dist);
		glVertex3d(a.x-longueur, a.y+hauteur, a.z+dist);
	glEnd();

	// face inferieure
	glBegin(GL_QUADS);
		glVertex3d(a.x+longueur, a.y, a.z);
		glVertex3d(a.x+longueur, a.y, a.z+dist);
		glVertex3d(a.x-longueur, a.y, a.z+dist);
		glVertex3d(a.x-longueur, a.y, a.z);
	glEnd();

	// face droite (x positif)
	glBegin(GL_QUADS);
		glVertex3d(a.x+longueur, a.y, a.z);
		glVertex3d(a.x+longueur, a.y, a.z+dist);
		glVertex3d(a.x+longueur, a.y+hauteur, a.z+dist);
		glVertex3d(a.x+longueur, a.y+hauteur, a.z);
	glEnd();

	// face gauche (x negatif)
	glBegin(GL_QUADS);
		glVertex3d(a.x-longueur, a.y, a.z);
		glVertex3d(a.x-longueur, a.y+hauteur, a.z);
		glVertex3d(a.x-longueur, a.y+hauteur, a.z+dist);
		glVertex3d(a.x-longueur, a.y, a.z+dist);
	glEnd();

	// ---
	// RAIL DROIT

	glColor3f(0.4,0.4,0.4);

	// face A
	glBegin(GL_QUADS);
		glVertex3d(a.x+longueur*2./3., a.y+hauteur, a.z);
		glVertex3d(a.x+longueur*2./3., a.y+hauteur*1.5, a.z);
		glVertex3d(a.x+longueur*0.5, a.y+hauteur*1.5, a.z);
		glVertex3d(a.x+longueur*0.5, a.y+hauteur, a.z);
	glEnd();

	// face superieure
	glBegin(GL_QUADS);
		glVertex3d(a.x+longueur*2./3., a.y+hauteur*1.5, a.z+dist);
		glVertex3d(a.x+longueur*2./3., a.y+hauteur*1.5, a.z);
		glVertex3d(a.x+longueur*0.5, a.y+hauteur*1.5, a.z);
		glVertex3d(a.x+longueur*0.5, a.y+hauteur*1.5, a.z+dist);
	glEnd();

	// face B
	glBegin(GL_QUADS);
		glVertex3d(a.x+longueur*0.5, a.y+hauteur, a.z+dist);
		glVertex3d(a.x+longueur*0.5, a.y+hauteur*1.5, a.z+dist);
		glVertex3d(a.x+longueur*2./3., a.y+hauteur*1.5, a.z+dist);
		glVertex3d(a.x+longueur*2./3., a.y+hauteur, a.z+dist);
	glEnd();

	// face droite (x 2/3)
	glBegin(GL_QUADS);
		glVertex3d(a.x+longueur*2./3., a.y+hauteur, a.z);
		glVertex3d(a.x+longueur*2./3., a.y+hauteur, a.z+dist);
		glVertex3d(a.x+longueur*2./3., a.y+hauteur*1.5, a.z+dist);
		glVertex3d(a.x+longueur*2./3., a.y+hauteur*1.5, a.z);
	glEnd();

	// face gauche (x 1/2)
	glBegin(GL_QUADS);
		glVertex3d(a.x+longueur*0.5, a.y+hauteur, a.z+dist);
		glVertex3d(a.x+longueur*0.5, a.y+hauteur, a.z);
		glVertex3d(a.x+longueur*0.5, a.y+hauteur*1.5, a.z);
		glVertex3d(a.x+longueur*0.5, a.y+hauteur*1.5, a.z+dist);
	glEnd();




	// RAIL GAUCHE

	// face A
	glBegin(GL_QUADS);
		glVertex3d(a.x-longueur*0.5, a.y+hauteur, a.z);
		glVertex3d(a.x-longueur*0.5, a.y+hauteur*1.5, a.z);
		glVertex3d(a.x-longueur*2./3., a.y+hauteur*1.5, a.z);
		glVertex3d(a.x-longueur*2./3., a.y+hauteur, a.z);
	glEnd();

	// face superieure
	glBegin(GL_QUADS);
		glVertex3d(a.x-longueur*0.5, a.y+hauteur*1.5, a.z+dist);
		glVertex3d(a.x-longueur*0.5, a.y+hauteur*1.5, a.z);
		glVertex3d(a.x-longueur*2./3., a.y+hauteur*1.5, a.z);
		glVertex3d(a.x-longueur*2./3., a.y+hauteur*1.5, a.z+dist);
	glEnd();

	// face B
	glBegin(GL_QUADS);
		glVertex3d(a.x-longueur*2./3., a.y+hauteur, a.z+dist);
		glVertex3d(a.x-longueur*2./3., a.y+hauteur*1.5, a.z+dist);
		glVertex3d(a.x-longueur*0.5, a.y+hauteur*1.5, a.z+dist);
		glVertex3d(a.x-longueur*0.5, a.y+hauteur, a.z+dist);
	glEnd();

	// face droite (x 2/3)
	glBegin(GL_QUADS);
		glVertex3d(a.x-longueur*0.5, a.y+hauteur, a.z);
		glVertex3d(a.x-longueur*0.5, a.y+hauteur, a.z+dist);
		glVertex3d(a.x-longueur*0.5, a.y+hauteur*1.5, a.z+dist);
		glVertex3d(a.x-longueur*0.5, a.y+hauteur*1.5, a.z);
	glEnd();

	// face gauche (x 1/2)
	glBegin(GL_QUADS);
		glVertex3d(a.x-longueur*2./3., a.y+hauteur, a.z+dist);
		glVertex3d(a.x-longueur*2./3., a.y+hauteur, a.z);
		glVertex3d(a.x-longueur*2./3., a.y+hauteur*1.5, a.z);
		glVertex3d(a.x-longueur*2./3., a.y+hauteur*1.5, a.z+dist);
	glEnd();




}



void main_reshape(int width,  int height) 
{
    GLint viewport[4];
    glViewport(0, 0, width, height);
    glGetIntegerv(GL_VIEWPORT, viewport);
    float prof = viewport[2]>viewport[3]?viewport[2]:viewport[3];

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, viewport[2], 0.0,viewport[3], -prof, prof);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}


void main_display(void)
{
    glClearColor(0.5, 0.5, 0.5, 0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
    glutPostRedisplay();
    glutSwapBuffers();
}



void Mouse(int button, int state, int x, int y) {
	GLint viewport[4];

	glutSetCursor(GLUT_CURSOR_CROSSHAIR);
	glGetIntegerv(GL_VIEWPORT, viewport);

	if(button == GLUT_RIGHT_BUTTON) {
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

		glutPostRedisplay();
	}
}

void keyboard(unsigned char key, int x, int y){
	switch (key)
    {
	case 'f': /* affichage du carre plein */
      glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
      glutPostRedisplay();
      break;
    case 'e': /* affichage en mode fil de fer */
      glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
      glutPostRedisplay();
      break;
	}
}

void F3D_reshape(int x, int y){
    if (x<y)
        glViewport(0,(y-x)/2,x,x);
    else
        glViewport((x-y)/2,0,y,y);
}

void temoin_reshape(int width, int height){
	GLint viewport[4];
    glViewport(0, 0, width, height);
    glGetIntegerv(GL_VIEWPORT, viewport);
    float prof = viewport[2]>viewport[3]?viewport[2]:viewport[3];

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, viewport[2], 0.0,viewport[3], -prof, prof);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void F3D_affichage(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glOrtho(-500,500,-500,500,-1000,1000);
    glRotatef(-(float)angley,1.0,0.0,0.0);
    glRotatef(-(float)anglex,0.0,1.0,0.0);

    glutPostRedisplay();

	//
	Point3D p1 = {0.,10.,10.};
	Point3D p2 = {0.,10.,150.};
	Point3D p3 = {0.,10.,170.};
	Point3D p4 = {0.,10.,190.};
	traceRail(p1,p2);
	traceRail(p3,p4);

    glutSwapBuffers();
}

void temoin_affichage(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
    glColor3f(0.0,1.0,0.0);
    glPointSize(3.0);
    glInitNames();
    glPushName(1);
    
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

    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
    glutInitWindowSize(WX, WY);
    glutInitWindowPosition(0, 0);
    glutInit(&argc, argv);
	glEnable(GL_DEPTH_TEST);
    glEnable(GL_MULTISAMPLE);
    window = glutCreateWindow("Courbes Cubiques");

    glutDisplayFunc(main_display);
	glutReshapeFunc(main_reshape);

    //Fenetre 3D
    F3D = glutCreateSubWindow(window, GAP, GAP, WX/2, WY);
    glutReshapeFunc(F3D_reshape);
    glutDisplayFunc(F3D_affichage);
    glutMotionFunc(F3D_motion);
    glutMouseFunc(F3D_mouse);
glutKeyboardFunc(keyboard);

    //Fenetre 2D
    temoin = glutCreateSubWindow(window, GAP+WX/2+GAP, GAP, WX/2, WY);
    glutReshapeFunc(temoin_reshape);
    glutDisplayFunc(temoin_affichage);
    glutMouseFunc(Mouse);
	glutMotionFunc(Motion);
	

	glutPostRedisplay();

    glutMainLoop();
    return (1);
}



