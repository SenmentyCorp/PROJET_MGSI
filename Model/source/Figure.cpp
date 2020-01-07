#include "../header/Figure.h"

Figure::Figure(){
    
}

void Figure::trace(){
    float n = 500.0f;
    float i, j = 0.0f;
    float fx, fy = 0.0f;

    for(i=0;i<500;i++){
        for(j=0;j<500;j++){
            fx = i/n;
            fy = j/n;
            if (dedans(fx, fy)){
                glColor3f(1.f,1.f,1.f);
                glBegin(GL_POINTS);
                    glVertex2f(fx, fy);
                glEnd();
            }else{
                glColor3f(0.f,0.f,0.f);
                glBegin(GL_POINTS);
                    glVertex2f(fx, fy);
                glEnd();
            }
        }
    }
}