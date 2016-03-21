#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>

#define Radio     .15
#define Slices    25
#define Stack     25

void p5a (void){
     glTranslatef(0,.5,0);
     glColor3f(.5,.5,.5);
     glutSolidSphere(.1,Slices,Stack);
     glLoadIdentity();   
     glTranslatef(.5,.0,0);
     glColor3f(.8,.5,.5);
     glutSolidSphere(.1,Slices,Stack);
     glFlush();  
}

void p5c(void){
     glPushMatrix();
     glTranslatef(0,.5,0);
     glRotatef(45,0,.5,0);
     glColor3f(.5,.5,.5);
     glutSolidSphere(.1,Slices,Stack);//ESFERA GRIS ------UNA
     glTranslatef(.5,0,0);
     glColor3f(.8,.5,.5);
     glutSolidSphere(.1,Slices,Stack);// ESFERA CARNE----- DOS
     glPopMatrix();
     glFlush();
}


void p5b(void){
     glPushMatrix();
     glTranslatef(0,.5,0);
     glRotatef(45,0,.5,0);
     glColor3f(.5,.5,.5);
     glutSolidSphere(.1,Slices,Stack);//ESFERA GRIS ------UNA
     glPopMatrix();
  
     glPushMatrix();
     glTranslatef(.5,0,0);
     glColor3f(.8,.5,.5);
     glutSolidSphere(.1,Slices,Stack);// ESFERA CARNE----- DOS
     glPopMatrix();
     glFlush();
}


void display(void)
{
     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
	 
//	 p5a();
 //   p5b();
    p5c();
   
}


main(int argc, char **argv){
    glutInit(&argc,argv); 
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(480,480);
    glutInitWindowPosition(150,150);
    glutCreateWindow("Unidad 3 Practica 5 A, B y C");
    glutDisplayFunc(display);
    glutMainLoop();     
    return 0;
}  

