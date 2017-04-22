#include <GL/gl.h>
#include <GL/glut.h>
#include <stdlib.h>
double rotate_y=0;
double rotate_x=0;
double rotate_z=0;

GLfloat X = 0.10f;
GLfloat zoom =0.1f;
GLfloat Y = 0.10f;
GLfloat Z = 0.10f;
GLfloat a= 0.1045646f;

void specialKeys( int key, int x, int y )
{
    if (key == GLUT_KEY_RIGHT)
        rotate_y += 5;
    else if (key == GLUT_KEY_LEFT)
        rotate_y -= 5;
    else if (key == GLUT_KEY_UP)
        rotate_x += 5;
    else if (key == GLUT_KEY_DOWN)
        rotate_x -= 5;
    glutPostRedisplay();

}
void init(void)
{
   glShadeModel(GL_SMOOTH);
// Ubicamos la fuente de luz en e punto
    GLfloat light_position[] = { -0, -.0, 35.0, .0 };
    GLfloat luz_ambiental[] = { .0, 10.0, 10.0, 0.0 };
// Activamos la fuente de luz
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glDepthFunc(GL_LESS);
    glEnable(GL_DEPTH_TEST);

    glLightfv(GL_LIGHT0,GL_POSITION,light_position);
// Queremos que se dibujen las caras frontales
// y con un color solido de relleno.
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

}

void reshape(int w, int h)
{
    glViewport(0, 0,  (GLsizei) w, (GLsizei) h);
// Activamos la matriz de proyeccion.
    glMatrixMode(GL_PROJECTION);
// "limpiamos" esta con la matriz identidad.
    glLoadIdentity();
// Usamos proyeccion ortogonal
    glOrtho(-1.5, 1.5, -1.5, 1.5, -1.5, 1.5);
// Activamos la matriz de modelado/visionado.
    glMatrixMode(GL_MODELVIEW);
// "Limpiamos" la matriz
    glLoadIdentity();
}

// Aqui ponemos lo que queremos dibujar.
void display(void)
{
// Propiedades del material

    GLfloat mat_ambient[] = { a, 0.223529f, 0.027451f,1.0f };
    GLfloat mat_diffuse[] = { 0.780392f, a, 0.113725f, 1.0f };
    GLfloat mat_specular[] = { a, 0.941176f, 0.807843f, 1.0f };
    GLfloat shine[] = {27.8974f};
// "Limpiamos" el frame buffer con el color de "Clear", en este
// caso negro.
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode( GL_MODELVIEW_MATRIX );
    glLoadIdentity();

    glRotatef( rotate_x, 00.0, 15, 0.0 );
    glRotatef( rotate_y, 0.0, 15, 0.0 );
    glRotatef( rotate_z, 0.0, 0.0, 15 );
    glPushMatrix();
//setMaterial
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, shine);
    //glutSolidTeapot(125.0);
    //glutSolidCube(12.0);
   //glScalef(9,9,9);
    glutSolidTetrahedron();
   // glutSolidTorus(50.0,80.0,90,90);
    glFlush();
}

// Termina la ejecucion del programa cuando se presiona ESC
void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
        case '1':
            a=0.165589;
            break;
        case '2':
            a=0.5;
            break;
        case '3':
            a= 0.8045646f;
        break;
        case '4':
            a=1.015;
            break;
        case '5':
            a=1.555555;
            break;
        case 27:
            exit(0);
            break;
    }
    glutPostRedisplay();
    
}

// Main del programa.
int main(int argc, char **argv)
{
// Inicializo OpenGL
    glutInit(&argc, argv);

// Activamos buffer simple y colores del tipo RGB
    glutInitDisplayMode (GLUT_RGB | GLUT_DEPTH);

// Definimos una ventana de medidas 800 x 600 como ventana
// de visualizacion en pixels
    glutInitWindowSize (500, 500);

// Posicionamos la ventana en la esquina superior izquierda de
// la pantalla.
    glutInitWindowPosition (0, 0);

// Creamos literalmente la ventana y le adjudicamos el nombre que se
// observara en su barra de titulo.
    glutCreateWindow ("Piramide");

// Inicializamos el sistema
    init();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(specialKeys);
    glutMainLoop();

    return 0;
}