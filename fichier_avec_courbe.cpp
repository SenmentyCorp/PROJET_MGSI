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

struct CouleurRVB{
	double r, v, b;
	CouleurRVB(double a=0, double b=0, double c=0) {set(a,b,c);}
	void set(double a, double b, double c) {r=a; v=b; b=c;}
};

Point P[NMAX];
const int nbPoints=10000;
const int col=sqrt(nbPoints);
Point3D P3D[nbPoints]; 
CouleurRVB Couleur[nbPoints-col];

// ---
const int NB_POINTS = 16;
const int DISCRET = 10;
const int N_Parcours = NB_POINTS + 3;
Point P_Parcours[NMAX];
Point rails[NB_POINTS*DISCRET];
int init = 0;


float map(float value, float istart, float istop, float ostart, float ostop) {
    return ostart + (ostop - ostart) * ((value - istart) / (istop - istart));
}

void initPointsParcours() {
    P_Parcours[0] = {171.,472.};
    P_Parcours[1] = {260.,471.};
    P_Parcours[2] = {316.,426.};
    P_Parcours[3] = {297.,343.};
    P_Parcours[4] = {254.,262.};
    P_Parcours[5] = {263.,195.};
    P_Parcours[6] = {304.,136.};
    P_Parcours[7] = {297.,63.};
    P_Parcours[8] = {188.,50.};
    P_Parcours[9] = {142.,104.};
    P_Parcours[10] = {67.,121.};
    P_Parcours[11] = {62.,218.};
    P_Parcours[12] = {129.,263.};
    P_Parcours[13] = {143.,351.};
    P_Parcours[14] = {104.,399.};
    P_Parcours[15] = {110.,457.};
}

void catmullromParcours() 
{
	mat m = mat(4,4);
	m << -s << 2-s << s-2 << s << endr
		<< 2*s << s-3 << 3-2*s << -s << endr
		<< -s << 0 << s << 0 << endr
		<< 0 << 1 << 0 << 0 << endr;

    if(init==0) {
        initPointsParcours();
        init = 1;
    }

	int i;
	for(i=0;i<N_Parcours;i++) {
		colvec vectX = colvec(4);
		vectX 	<< P_Parcours[i%NB_POINTS].x 
				<< P_Parcours[(i+1)%NB_POINTS].x 
				<< P_Parcours[(i+2)%NB_POINTS].x
				<< P_Parcours[(i+3)%NB_POINTS].x;
		
		colvec vectY = colvec(4);
		vectY 	<< P_Parcours[i%NB_POINTS].y 
				<< P_Parcours[(i+1)%NB_POINTS].y 
				<< P_Parcours[(i+2)%NB_POINTS].y 
				<< P_Parcours[(i+3)%NB_POINTS].y;
		

		mat prodMPx = m*vectX;
		mat prodMPy = m*vectY;
		
		glColor3f(1.0,0.0,0.0);
		glBegin(GL_LINE_STRIP);
		
		int t;
		for(t=0; t<=DISCRET; t++) {
			double a = (double)t/10.;
			rowvec rv = rowvec(4);
			rv << (double)(pow(a,3.)) << (double)(pow(a,2.)) << a << 1.;
			mat cX = rv*prodMPx;
			mat cY = rv*prodMPy;
			
			glVertex2f(cX(0,0),cY(0,0));
            if(t!=DISCRET) { 
				rails[(i%NB_POINTS)*DISCRET+(int)(a*DISCRET)] = {(double)cX(0,0)*2.-500.,(double)cY(0,0)*2.-500.};
			}
		}
		glEnd();
	}

}

int calculHauteur(int i) {
	double x = rails[i].x/10.;
	double z = rails[i].y/10.;
	float mult=30.0;

	float ri=(x+50)/100.0;
	ri*=PI;
	float rj=(z+50)/100.0;
	rj*=PI;

	int temp=mult*(sinf(2*(ri))*cosf(3*(rj)));
	return temp;
}

void parcours3D() {	
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_LINE_STRIP);
	/*float mult=30.0;
	int i;
	for(i=0;i<NB_POINTS*DISCRET;i++) {
		double x = ((rails[i].x*2.-500.)/1000.)*PI;
		double z = ((rails[i].y*2.-500.)/1000.)*PI;
		double y = mult*(sinf(2.*(x)*cosf(3.*(z))));

		glVertex3d(rails[i].x*2.-500.,y,rails[i].y*2.-500.);
	}
	glVertex3d(rails[0].x*2-500,40,rails[0].y*2-500);*/

	int i, temp;
	for(i=0;i<NB_POINTS*DISCRET;i++) {
		temp = calculHauteur(i);
		glVertex3d(rails[i].x,temp,rails[i].y);
	}
	temp = calculHauteur(0);
	glVertex3d(rails[0].x,temp,rails[0].y);
	glEnd();
}

void initializePoints(){
	int cpt =0;
	float mult=30.0;
	float mult2=0.05;
	for(int i=-50;i<50;i++){
		for(int j=-50;j<50;j++){

			float ri=(i+50)/100.0;
			ri*=PI;
			float rj=(j+50)/100.0;
			rj*=PI;

			int temp=mult*(sinf(2*(ri))*cosf(3*(rj)));

			P3D[cpt].x = i*10;
			P3D[cpt].y = temp;
			P3D[cpt].z = j*10;
		cout<<temp<<" ";
			cpt++;
		}
		cout<<endl;
	}

	
	//miny=abs(miny);
	for(int i=0;i<nbPoints-col;i++){
		Point3D p = P3D[i];
		Couleur[i].r = map(p.y,-mult/2,mult/2,60/255.0,130/255.0);
		Couleur[i].v = 0.4+map(p.x,-500,500,0,0.3);;//static_cast <float> ((p.y/maxy)+0.1);
		Couleur[i].b = 0.31+map(p.z,-500,500,0,0.2);//static_cast <float> ((p.y/maxy)+0.1);
		//cout<<Couleur[i].r *255<<" "<<Couleur[i].r<<p.y<<endl;
	}
	//cout<<P3D[4700].y<<endl;
}

void tracePointsParcours()
{
	glColor3f(0.0,1.0,0.0);
	glBegin(GL_POINTS);
	for (int i=0;i<N_Parcours-3;i++){
		glVertex2f(P_Parcours[i].x,P_Parcours[i].y);
	}
	glEnd();
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

		if((i+1)%col==0){
			glEnd();
			glBegin(GL_TRIANGLE_STRIP);
		}else{
			glVertex3f(P3D[i].x, P3D[i].y, P3D[i].z);
			glVertex3f(P3D[i+col].x, P3D[i+col].y, P3D[i+col].z);
			glVertex3f(P3D[i+1].x, P3D[i+1].y, P3D[i+1].z);
			glVertex3f(P3D[i+col+1].x, P3D[i+col+1].y, P3D[i+col+1].z);
		}
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

			for (int i = 0;i<N_Parcours;i++) {
				glLoadName(i);
				glBegin(GL_POINTS);
				glVertex2f(P_Parcours[i].x,P_Parcours[i].y);
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
		P_Parcours[i].x = x;
		P_Parcours[i].y =  viewport[3]-y;
		tracePointsParcours();

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

    //catmullRom3D();
    //glutSolidCube(500);
	TracePoints();
	parcours3D();

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
    for (int i=0;i<N_Parcours;i++){
        glLoadName(i);
        glBegin(GL_POINTS);
        glVertex2f(P_Parcours[i].x,P_Parcours[i].y);
        glEnd();
    }
	tracePointsParcours();
    catmullromParcours();
    
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



