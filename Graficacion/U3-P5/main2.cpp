#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>

#define Radio     .15
#define Slices    25
#define Stack     25

void display(void)
{
     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
     glOrtho(-2.0,2.0, -2.0,2.0, -5.0,1.0);
     glLoadIdentity();             //cargamos la matrix identidad
	 
	 glTranslatef(0,.5,0);
     glColor3f(.5,.5,.5);
     glutSolidSphere(.1,Slices,Stack);
     glLoadIdentity();   
     glTranslatef(.5,.0,0);
     glColor3f(.8,.5,.5);
     glutSolidSphere(.1,Slices,Stack);
     glFlush();   
}


main(int argc, char **argv){
    glutInit(&argc,argv); 
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(480,480);
    glutInitWindowPosition(150,150);
    glutCreateWindow("Unidad 3 Practica 5");
    glutDisplayFunc(display);
    glutMainLoop();     
    return 0;
}  

