#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>

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
     


     
     glBegin(GL_QUADS);      //dibujamos un CUADRADO
       glColor3f(0.0,1.0,1.0);
       glVertex3f(-0.5,0.5,-0.5); //coordenadas del primer vertice(SUPERIOR-IZDA)
       glVertex3f(-0.5,-0.5,0.5);   //coordenadas del 2do vertice(INFERIOR-IZDA)
       glVertex3f(0.5,-0.5,0.5);   //coordenadas del 3er vertice(INFERIOR-DCHA)
       glVertex3f(0.5,0.5,-0.5);   //coordenadas del 3er vertice(SUPERIOR-DCHA)
     glEnd();
    
     glBegin(GL_TRIANGLES);      //dibujamos un TRIANGULO
       glColor3f(1.0,1.0,0.0);
        glVertex3f(0.0, 0.7, 0.0);
        glVertex3f(-0.9,-0.7, 0.0);
        glVertex3f(0.9,-0.7, 0.0);
     glEnd();
     
     glFlush();   
}


    main(int argc, char **argv)
{
   glutInit(&argc,argv); 
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(50,50);
    glutCreateWindow("Unidad 3 Practica 2");
    glutDisplayFunc(display);
     glutMainLoop();     
     return 0;
}  

