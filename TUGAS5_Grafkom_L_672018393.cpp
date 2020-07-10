#include<windows.h>
#include<GL/glut.h>
#include<stdlib.h>
#include<math.h>
const double PI = 3.141592653589793;
int i;

void init(void);
void tampil(void);
void mouse(int button, int state, int x, int y);
void keyboard(unsigned char, int, int);
void ukuran(int, int);
void mouseMotion(int x, int y);

float xrot = 0.0f;
float yrot = 0.0f;
float xdiff = 0.0f;
float ydiff = 0.0f;
bool mouseDown = false;
int is_depth;

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1000, 800);
    glutInitWindowPosition(300, 100);
    glutCreateWindow("Thomas Ken Timur - 672018393");
    init();
    glutDisplayFunc(tampil);
    glutReshapeFunc(ukuran);

    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(mouseMotion);

    glutIdleFunc(tampil);
    glutMainLoop();
    return 0;
}
void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 1.0);
    //GLfloat light_position0[] = { 100.0,100.0,-350.0,0.0 };
    //glLightfv(GL_LIGHT0, GL_POSITION, light_position0);
    glMatrixMode(GL_PROJECTION);
    //glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
    //glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
    is_depth = 1;
    glMatrixMode(GL_MODELVIEW);
    glPointSize(9.0);
    glLineWidth(6.0f);

}
void jalan_rumah()
{
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.658824, 0.658824, 0.658824);
    glVertex3f(-50, -9.9, 70.0);
    glVertex3f(50, -9.9, 70.0);
    glVertex3f(50, -9.9, 30.1);
    glVertex3f(-50, -9.9, 30.1);
    glEnd();
    glPopMatrix();
}
void rumah()
{
    glPushMatrix();
        //depan
        glBegin(GL_QUADS);
        glColor3f(1.0f, 0.0f, 1.0f);
        glVertex3f(-30.0, -10.0, 30.0);
        glVertex3f(-30.0, 50.0, 30.0);
        glVertex3f(5.0, 50.0, 30.0);
        glVertex3f(5.0, -10.0, 30.0);


        glEnd();

        glBegin(GL_QUADS);
        glColor3f(1.0f, 0.0f, 1.0f);
        glVertex3f(5.0, 50.0, 20.0);
        glVertex3f(35.0, 50.0, 20.0);
        glVertex3f(35.0, -10.0, 20.0);
        glVertex3f(5.0, -10.0, 20.0);


        glEnd();

        //kiri
        glBegin(GL_QUADS);
        glColor3f(1.0f, 0.0f, 1.0f);
        glVertex3f(-30.0, -10.0, 30.0);
        glVertex3f(-30.0, 50.0, 30.0);
        glVertex3f(-30.0, 50.0, -60.0);
        glVertex3f(-30.0, -10.0, -60.0);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(1.0f, 0.0f, 1.0f);
        glVertex3f(5.0, -10.0, 30.0);
        glVertex3f(5.0, 50.0, 30.0);
        glVertex3f(5.0, 50.0,  20.0);
        glVertex3f(5.0, -10.0, 20.0);
        glEnd();

        //kanan
        glBegin(GL_QUADS);
        glColor3f(1.0f, 0.0f, 1.0f);
        glVertex3f(35.0, 50.0, 20.0);
        glVertex3f(35.0, 50.0, -60.0);
        glVertex3f(35.0, -10.0, -60.0);
        glVertex3f(35.0, -10.0, 20.0);


        glEnd();
        //belakang
        glBegin(GL_QUADS);
        glColor3f(1.0f, 0.0f, 1.0f);
        glVertex3f(35.0, 50.0, -60.0);
        glVertex3f(35.0, -10.0, -60.0);
        glVertex3f(-30.0, -10.0, -60.0);
        glVertex3f(-30.0, 50.0, -60.0);


        glEnd();
        //lantai
        glBegin(GL_QUADS);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f(-30.0, -10.0, 30.0);
        glVertex3f(-30.0, -10.0, -60.0);
        glVertex3f(5.0, -10.0, -60.0);
        glVertex3f(5.0, -10.0, 30.0);


        glEnd();

        glBegin(GL_QUADS);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f(5.0, -10.0, 20.0);
        glVertex3f(35.0, -10.0, 20.0);
        glVertex3f(35.0, -10.0, -59.9);
        glVertex3f(5.0, -10.0, -59.9);

        glEnd();

        //atas
        glBegin(GL_QUADS);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f(-30.0, 40.0, 30.0);
        glVertex3f(-30.0, 40.0, -60.0);
        glVertex3f(5.0, 40.0, -60.0);
        glVertex3f(5.0, 40.0, 30.0);


        glEnd();

        glBegin(GL_QUADS);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f(5.0, 40.0, 20.0);
        glVertex3f(35.0, 40.0, 20.0);
        glVertex3f(35.0, 40.0, -59.9);
        glVertex3f(5.0, 40.0, -59.9);

        glEnd();

        //tv
        glBegin(GL_QUADS);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex3f(20.0, 20.0, -59.9);
        glVertex3f(5.0, 20.0, -59.9);
        glVertex3f(5.0, 10.0, -59.9);
        glVertex3f(20.0, 10.0, -59.9);

        glEnd();

        //kasur
        glBegin(GL_QUADS);
        glColor3f(0.0f, -5.0f, 1.0f);
        glVertex3f(34.9, -5.0, -59.9);
        glVertex3f(34.9, -5.0, -40.0);
        glVertex3f(20.0, -5.0, -40.0);
        glVertex3f(20.0, -5.0, -59.9);

        glEnd();
        glBegin(GL_QUADS);
        glColor3f(0.0f, -5.0f, 1.0f);
        glVertex3f(34.9, -5.0, -40.0);
        glVertex3f(20.0, -5.0, -40.0);
        glVertex3f(20.0, -10.0, -40.0);
        glVertex3f(34.9, -10.0, -40.0);



        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0.0f, -5.0f, 1.0f);
        glVertex3f(34.9, -5.0, -59.9);
        glVertex3f(20.0, -5.0, -59.9);
        glVertex3f(20.0, -10.0, -59.9);
        glVertex3f(34.9, -10.0, -59.9);



        glEnd();



         glBegin(GL_QUADS);
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex3f(20.0, -5.0, -40.0);
        glVertex3f(20.0, -10.0, -40.0);
        glVertex3f(20.0, -10.0, -59.9);
        glVertex3f(20.0, -5.0, -59.9);
        glEnd();

                 glBegin(GL_QUADS);
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex3f(34.9, -5.0, -40.0);
        glVertex3f(34.9, -10.0, -40.0);
        glVertex3f(34.9, -10.0, -59.9);
        glVertex3f(34.9, -5.0, -59.9);
        glEnd();
        //meja

        glBegin(GL_QUADS);
        glColor3f(1.0f, 1.0f, 0.0f);
        glVertex3f(35.0, 0.0, -30.0);
        glVertex3f(35.0, -10.0, -30.0);
        glVertex3f(25.0, -10.0, -30.0);
        glVertex3f(25.0, 0.0, -30.0);


        glEnd();

        glBegin(GL_QUADS);
        glColor3f(1.0f, 1.0f, 0.0f);
        glVertex3f(35.0, 0.0, -30.0);
        glVertex3f(35.0, -10.0, -30.0);
        glVertex3f(25.0, -10.0, -30.0);
        glVertex3f(25.0, 0.0, -30.0);


        glEnd();

        glBegin(GL_QUADS);
        glColor3f(1.0f, 1.0f, 0.0f);
        glVertex3f(35.0, 0.0, -30.0);
        glVertex3f(35.0, 0.0, -10.0);
        glVertex3f(25.0, 0.0, -10.0);
        glVertex3f(25.0, 0.0, -30.0);


        glEnd();

        glBegin(GL_QUADS);
        glColor3f(1.0f, 1.0f, 0.0f);
        glVertex3f(35.0, 0.0, -10.0);
        glVertex3f(35.0, -10.0, -10.0);
        glVertex3f(25.0, -10.0, -10.0);
        glVertex3f(25.0, 0.0, -10.0);


        glEnd();

        glBegin(GL_QUADS);
        glColor3f(1.0f, 1.0f, 0.0f);
        glVertex3f(35.0, 0.0, -10.0);
        glVertex3f(35.0, -4.0, -10.0);
        glVertex3f(35.0, -4.0, -17.0);
        glVertex3f(35.0, 0.0, -17.0);


        glEnd();

        glBegin(GL_QUADS);
        glColor3f(1.0f, 1.0f, 0.0f);
        glVertex3f(25.0, 0.0, -10.0);
        glVertex3f(25.0, -4.0, -10.0);
        glVertex3f(25.0, -4.0, -17.0);
        glVertex3f(25.0, 0.0, -17.0);


        glEnd();

        //lukisan

        glBegin(GL_QUADS);
        glColor3f(0.5f, 0.5f, 1.0f);
        glVertex3f(-29.9, 5.0, -10.0);
        glVertex3f(-29.9, 20.0, -10.0);
        glVertex3f(-29.9, 20.0, -40.0);
        glVertex3f(-29.9, 5.0, -40.0);

        glEnd();





        //lemari

        glBegin(GL_QUADS);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex3f(-30.0, -10.0, -50.0);
        glVertex3f(-20.0, -10.0, -50.0);
        glVertex3f(-20.0, 10.0, -50.0);
        glVertex3f(-30.0, 10.0, -50.0);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex3f(-20.0, -10.0, -50.0);
        glVertex3f(-20.0, 10.0, -50.0);
        glVertex3f(-20.0, 10.0, -59.9);
        glVertex3f(-20.0, -10.0, -59.9);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex3f(-30.0, 10.0, -50.0);
        glVertex3f(-20.0, 10.0, -50.0);
        glVertex3f(-20.0, 10.0, -59.9);
        glVertex3f(-30.0, 10.0, -59.9);
        glEnd();

         glBegin(GL_QUADS);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex3f(-29.9, -10.0, -50.0);
        glVertex3f(-29.9, 10.0, -50.0);
        glVertex3f(-29.9, 10.0, -59.9);
        glVertex3f(-29.9, -10.0, -59.9);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex3f(-30.0, -10.0, -59.9);
        glVertex3f(-20.0, -10.0, -59.9);
        glVertex3f(-20.0, 10.0, -59.9);
        glVertex3f(-30.0, 10.0, -59.9);
        glEnd();

        //jendela
        glBegin(GL_QUADS);
        glColor3f(1.0f, 0.5f, 0.5f);
        glVertex3f(2.0, -5.0, 30.1);
        glVertex3f(2.0, 20.0, 30.1);
        glVertex3f(-5.0, 20.0, 30.1);
        glVertex3f(-5.0, -5.0, 30.1);


        glEnd();

        glBegin(GL_QUADS);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f(1.0, -4.0, 30.2);
        glVertex3f(1.0, 19.0, 30.2);
        glVertex3f(-4.0, 19.0, 30.2);
        glVertex3f(-4.0, -4.0, 30.2);


        glEnd();

        glBegin(GL_QUADS);
        glColor3f(1.0f, 0.5f, 0.5f);
        glVertex3f(35.1, -5.0, 5);
        glVertex3f(35.1, 20.0, 5);
        glVertex3f(35.1, 20.0, -2);
        glVertex3f(35.1, -5.0, -2);


        glEnd();

        glBegin(GL_QUADS);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f(35.2, -4.0, 4);
        glVertex3f(35.2, 19.0, 4);
        glVertex3f(35.2, 19.0, -1);
        glVertex3f(35.2, -4.0, -1);


        glEnd();


        glBegin(GL_QUADS);
        glColor3f(1.0f, 0.5f, 0.5f);
        glVertex3f(-30.1, -5.0, 5);
        glVertex3f(-30.1, 20.0, 5);
        glVertex3f(-30.1, 20.0, -2);
        glVertex3f(-30.1, -5.0, -2);


        glEnd();

        glBegin(GL_QUADS);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f(-30.2, -4.0, 4);
        glVertex3f(-30.2, 19.0, 4);
        glVertex3f(-30.2, 19.0, -1);
        glVertex3f(-30.2, -4.0, -1);


        glEnd();












    glPopMatrix();
}
void pintu()
{
        glBegin(GL_QUADS);
        glColor3f(1.0f, 0.5f, 0.5f);
        glVertex3f(-18.0, -10.0, 30.1);
        glVertex3f(-18.0, 15.0, 30.1);
        glVertex3f(-8.0, 15.0, 30.1);
        glVertex3f(-8.0, -10.0, 30.1);


        glEnd();


}
void tampil(void)
{
    glPushMatrix();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    gluLookAt(0.0f, 3.0f, 100.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
    glRotatef(xrot, 0, 1, 0);
    glRotatef(yrot, 1, 0, 0);
    rumah();
    pintu();
    jalan_rumah();
    glEnd();
    glPopMatrix();
    glutSwapBuffers();

}


void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'w':
    case 'W':
        glTranslatef(0.0, 0.0, 3.0);
        break;
    case 'd':
    case 'D':
        glTranslatef(3.0, 0.0, 0.0);
        break;
	case 's':
    case 'S':
        glTranslatef(0.0, 0.0, -3.0);
        break;
    case 'a':
    case 'A':
        glTranslatef(-3.0, 0.0, 0.0);
        break;
    case 'q':
    case 'Q':

        break;
	case '7':
        glTranslatef(0.0, 3.0, 0.0);
        break;
	case '9':
        glTranslatef(0.0, -3.0, 0.0);
        break;
    case '2':
        glRotatef(2.0, 1.0, 0.0, 0.0);
        break;
    case '8':
        glRotatef(-2.0, 1.0, 0.0, 0.0);
        break;
    case '6'://putar kanan
        glRotatef(2.0, 0.0, 1.0, 0.0);
        break;
    case '4'://putar kiri
        glRotatef(-2.0, 0.0, 1.0, 0.0);
        break;
    case '1':
        glRotatef(2.0, 0.0, 0.0, 1.0);
        break;
    case '3':
        glRotatef(-2.0, 0.0, 0.0, 1.0);
        break;
    case '5':
        if (is_depth)
        {
            is_depth = 0;
            glDisable(GL_DEPTH_TEST);
        }
        else
        {
            is_depth = 1;
            glEnable(GL_DEPTH_TEST);
        }
    }
    tampil();

}

void mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        mouseDown = true;
        xdiff = xrot = x;
        ydiff = yrot = y;
    }
    else {
        mouseDown = false;
    }
}

void mouseMotion(int x, int y)
{
    if (mouseDown)
    {
        xrot = x;
        yrot = y;

        glutPostRedisplay();
    }
}

void ukuran(int lebar, int tinggi)
{
    if (tinggi == 0) tinggi = 1;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(50.0, lebar / tinggi, 5.0, 500.0);
    glTranslatef(0.0, -5.0, -150.0);
    glMatrixMode(GL_MODELVIEW);
}
