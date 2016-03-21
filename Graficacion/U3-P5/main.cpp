#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>

#define Radio     .15
#define Slices    250
#define Stack     250

void display(void)
{
     
     glDepthFunc(GL_LEQUAL);
     glEnable(GL_DEPTH_TEST);
     glClearDepth(1.0);
     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
     glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
     
     glClearColor(0.0,0.0,0.0,0.0);//color de fondo: negro
     
     glClear(GL_COLOR_BUFFER_BIT); //BORRAMOS PANTALLA
    
     glMatrixMode(GL_PROJECTION);  //MODO DE PROYECCION
          
     glLoadIdentity();             //cargamos la matrix identidad
     
     //glOrtho(-1.0,1.0, -1.0,1.0, -5.0,1.0);
     gluPerspective(60.0,1.0,1.0,100.0);
     
     glMatrixMode(GL_MODELVIEW);    //MODO DE MODELADO
     
     glTranslatef(0.0,0.0,-2.0); // movemos el observador 2 unidades en Z
     /*glColor3f(1.0,0.0,0.0);
     glutSolidSphere(Radio,Slices,Stack);

     glColor3f(0.0,0.0,1.0);     
     glTranslatef(0.65,0.0,0.0);
     glutSolidSphere(Radio,Slices,Stack);
	 */
	 
	 glTranslatef(0,.5,0);
      glColor3f(.5,.5,.5);
      glutSolidSphere(.1,25,25);
      glTranslatef(.5,0,0);
      glColor3f(.8,.5,.5);
      glutSolidSphere(.1,25,25);

	 
     glFlush();   
}


    main(int argc, char **argv)
{
   glutInit(&argc,argv); 
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(480,480);
    glutInitWindowPosition(150,150);
    glutCreateWindow("Unidad 3 Practica 5");
    glutDisplayFunc(display);
     glutMainLoop();     
     return 0;
}  

