#include <GL/gl.h>
#include <GL/glut.h>
#include <stdlib.h>
double rotate_y=0;
double rotate_x=0;
double rotate_z=0;

GLfloat X = 10.0f;
GLfloat zoom =0.1f;
GLfloat Y = 10.0f;
GLfloat Z = 10.0f;
GLfloat scale = 10.0f;

void specialKeys( int key, int x, int y )
{
    if (key == GLUT_KEY_RIGHT)
        rotate_y += 10;
    else if (key == GLUT_KEY_LEFT)
        rotate_y -= 10;
    else if (key == GLUT_KEY_UP)
        rotate_x += 10;
    else if (key == GLUT_KEY_DOWN)
        rotate_x -= 10;
    glutPostRedisplay();

}
void init(void)
{
    glShadeModel(GL_SMOOTH);
// Ubicamos la fuente de luz en el punto
    GLfloat light_position[] = { -100, -100.0, 0.0, 0.0 };
    GLfloat luz_ambiental[] = { 0.2, 0.2, 0.2, 1.0 };


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
    glOrtho(-200, 200, -200, 200, -200, 200);
// Activamos la matriz de modelado/visionado.
    glMatrixMode(GL_MODELVIEW);
// "Limpiamos" la matriz
    glLoadIdentity();
}

// Aqui ponemos lo que queremos dibujar.
void display(void)
{
// Propiedades del material

    GLfloat mat_ambient[] = { 0.329412f, 0.223529f, 0.027451f,1.0f };
    GLfloat mat_diffuse[] = { 0.780392f, 0.568627f, 0.113725f, 1.0f };
    GLfloat mat_specular[] = { 0.992157f, 0.941176f, 0.807843f, 1.0f };
    GLfloat shine[] = {27.8974f};

// "Limpiamos" el frame buffer con el color de "Clear", en este
// caso negro.
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode( GL_MODELVIEW_MATRIX );
    glLoadIdentity();

    glRotatef( rotate_x, 200.0, 0.0, 0.0 );
    glRotatef( rotate_y, 0.0, 200.0, 0.0 );
    glRotatef( rotate_z, 0.0, 0.0, 200.0 );
    glTranslatef(X, Y, Z);  
    //glPushMatrix();
//setMaterial
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, shine);
    //glutSolidTeapot(125.0);
    //glutSolidCube(125.0);
    glutSolidTorus(50.0,80.0,90,90);
    glFlush();
}

// Termina la ejecucion del programa cuando se presiona ESC
void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 27:
        exit(0);
        break;
    }
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
    glutInitWindowSize (800, 600);

// Posicionamos la ventana en la esquina superior izquierda de
// la pantalla.
    glutInitWindowPosition (0, 0);

// Creamos literalmente la ventana y le adjudicamos el nombre que se
// observara en su barra de titulo.
    glutCreateWindow ("Teapot");

// Inicializamos el sistema
    init();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
     glutSpecialFunc(specialKeys);
    glutMainLoop();

    return 0;
}