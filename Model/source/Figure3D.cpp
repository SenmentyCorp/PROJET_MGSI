#include "../header/Figure3D.h"

Figure3D::Figure3D(){

}

void Figure3D::trace(){
    float n = 120.0f;
    float i, j, k = 0.0f;
    float fx, fy, fz = 0.0f;

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            for(k=0;k<n;k++){
                fx = i/n;
                fy = j/n;
                fz = k/n;
                if (dedans(fx, fy, fz)){
                    glColor4f(1.f,1.f,1.f,1.f);
                    glBegin(GL_POINTS);
                        glVertex3f(fx, fy, fz);
                    glEnd();
                }else{
                    /*glColor4f(0.f,0.f,0.f,0.1f);
                    glBegin(GL_POINTS);
                        glVertex3f(fx, fy, fz);
                    glEnd();*/
                }
            }
        }
    }
}

void Figure3D::trace(float r, float g, float b){
    float n = 220.0f;
    float i, j, k = 0.0f;
    float fx, fy, fz = 0.0f;

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            for(k=0;k<n;k++){
                fx = i/n;
                fy = j/n;
                fz = k/n;
                if (dedans(fx, fy, fz)){
                    glColor4f(r,g,b,1.f);
                    glBegin(GL_POINTS);
                        glVertex3f(fx, fy, fz);
                    glEnd();
                }else{
                    /*glColor4f(0.f,0.f,0.f,0.1f);
                    glBegin(GL_POINTS);
                        glVertex3f(fx, fy, fz);
                    glEnd();*/
                }
            }
        }
    }
}