/**
 * *********************************************************
 * Trabalho 1: Boneco Michelin
 *
 * Descrição: Desenhar boneco Michelin utilizando primitivas
 *
 * Alunos: Silvana Trindade e Maurício André Cinelli
 * *********************************************************
 */
#include <GL/glut.h>

/**
 * Vetores para a iluminação
 */
const GLfloat light_ambient[]  = { 0.3f, 0.3f, 0.3f, 0.5f };
const GLfloat light_diffuse[]  = { 0.5f, 0.5f, 0.5f, 1.0f };
const GLfloat light_position[] = { 2.0f, 6.0f, 10.0f, 0.0f };

void draw();
void drawTorus(GLdouble innerRadius, GLdouble outerRadius,GLfloat *position, GLfloat *rotation, GLfloat *scale);
void drawAllTorus(int n, GLdouble *innerRadius, GLdouble *outerRadius, GLfloat positions[][3], GLfloat rotations[][3], GLfloat scales[][3]);

/**
 * Desenha o Michelin
 */
void draw()
{

	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(90, 1, 0.1, 7);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// gluLookAt(0,-2,-0.1,0,0,0,0,1,0);//muda direção de visão
	// gluLookAt(0,3,-0.01,0,0,0,0,1,0);//muda direção de visão
	// gluLookAt(-2.5,1,-1.5,0,0,0,0,1,0);//muda direção de visão
	gluLookAt(0.6,0.6,-1.8,0,0,0,0,1,0);//muda direção de visão
	// gluLookAt(-0.5,-0.8,-1.8,0,0,0,0,1,0);//muda direção de visão
	// gluLookAt(-1.5,0.4,-0.5,0,0,0,0,1,0);//muda direção de visão
	// gluLookAt(0.01,0.0,-2,0,0,0,0,1,0);//muda direção de visão
	// gluLookAt(2,-0.8,0,0,0,0,0,1,0);//muda direção de visão

	glColor3f(1.0, 1.0, 1.0);

	/**
	 * Cabeça base
	 */
	GLUquadric *t = gluNewQuadric();

	glPushMatrix();
	glScalef(0.9,0.5,0.9);
	glTranslatef(0,1.4,0);
	gluSphere(t,0.3,32,32);
	glPopMatrix();

	/**
	 * Cabeça topo
	 */
	GLUquadric *t2 = gluNewQuadric();

	glPushMatrix();
	glScalef(1,0.9,1);
	glTranslatef(0,0.85,0);
	gluSphere(t2,0.2,32,32);
	glPopMatrix();

	/**
	 * Cabeça bico
	 */
	GLUquadric *t3 = gluNewQuadric();

	glPushMatrix();
	glScalef(1,0.5,1);
	glTranslatef(0,1.82,0);
	gluSphere(t3,0.09,32,32);
	glPopMatrix();

	/**
	 * torax topo
	 */
	GLUquadric *p = gluNewQuadric();

	glPushMatrix();
	glScalef(1,0.3,1);
	glTranslatef(0,1.6,0);
	gluSphere(p,0.48,32,32);
	glPopMatrix();

	/**
	 * canela esquerdo
	 */
	GLUquadric *w = gluNewQuadric();
	glPushMatrix();
	glTranslatef(-0.23,-1.12,0.02);
	glRotatef(0,0,1.0,0);
	glRotatef(0,0,0,1.0);
	glRotatef(90,1.0,0,0);
	gluCylinder(w,0.1f,0.1,0.1,30,30);
	glPopMatrix();

	/**
	 * bota esquerda
	 */
	glPushMatrix();
	glTranslatef(-0.24,-1.3,-0.08);
	glRotatef(0,0,1.0,0);
	glRotatef(0,0,0,1.0);
	glRotatef(0,1.0,0,0);
	glScalef(1,0.5,1.1);
	glutSolidCube(0.3);
	glPopMatrix();

	GLUquadric *p4 = gluNewQuadric();

	glPushMatrix();
	glScalef(0.35,0.20,0.45);
	glTranslatef(-0.67,-6.5,-0.41);
	gluSphere(p4,0.48,32,32);
	glPopMatrix();


	/**
	 * pé direito
	 */

	 /**
	 * canela direita
	 */
	GLUquadric *w2 = gluNewQuadric();
	glPushMatrix();
	glTranslatef(0.61,-1.0,0.02);
	glRotatef(0,0,1.0,0);
	glRotatef(20,0,0,1.0);
	glRotatef(90,1.0,0,0);
	gluCylinder(w2,0.1f,0.1,0.1,30,30);
	glPopMatrix();

	/**
	 * bota direita
	 */
	glPushMatrix();
	glTranslatef(0.66,-1.16,-0.03);
	glRotatef(-10,0,1.0,0);
	glRotatef(1,1.0,0,0);
	glRotatef(20,0,0,1.0);
	glScalef(1,0.5,1.1);
	glutSolidCube(0.3);
	glPopMatrix();

	GLUquadric *p42 = gluNewQuadric();

	glPushMatrix();
	glRotatef(0,0,1.0,0);
	glRotatef(30,0,0,1.0);
	glRotatef(-10,1.0,0,0);
	glScalef(0.35,0.20,0.45);
	glTranslatef(0.04,-6.50,-0.92);
	gluSphere(p42,0.48,32,32);
	glPopMatrix();

	GLUquadric *bolaOlho1 = gluNewQuadric();

	glPushMatrix();
	glScalef(0.2,0.3,0.2);
	glTranslatef(-0.13,2.6,-0.77);
	gluSphere(bolaOlho1,0.3,32,32);
	glPopMatrix();

	GLUquadric *bolaOlho2 = gluNewQuadric();

	glPushMatrix();
	glScalef(0.2,0.3,0.2);
	glTranslatef(0.4,2.6,-0.67);
	gluSphere(bolaOlho2,0.3,32,32);
	glPopMatrix();

	glColor3f(0, 0, 0);

	GLUquadric *iris1 = gluNewQuadric();

	glPushMatrix();
	glScalef(0.15,0.25,0.15);
	glTranslatef(-0.15,3.15,-1.25);
	gluSphere(iris1,0.2,32,32);
	glPopMatrix();

	GLUquadric *iris2 = gluNewQuadric();

	glPushMatrix();
	glScalef(0.15,0.25,0.15);
	glTranslatef(0.6,3.15,-1.115);
	gluSphere(iris1,0.2,32,32);
	glPopMatrix();

	glColor3f(1.0, 1.0, 1.0);

	/**
	 * Mão direita
	 */
	
	/**
	 * pulso
	 */
	GLUquadric *pulsoD = gluNewQuadric();
	glPushMatrix();
	glTranslatef(0.61,1.0,0.02);
	glRotatef(0,0,1.0,0);
	glRotatef(20,0,0,1.0);
	glRotatef(90,1.0,0,0);
	gluCylinder(pulsoD,0.1f,0.1,0.1,30,30);
	glPopMatrix();

	GLdouble innerRadius[] = {
		//torax
		0.1,
		0.1,
		0.1,
		0.1,
		//perna direita
		0.1,
		0.1,
		0.1,
		0.1,
		0.1,
		//perna esquerda
		0.1,
		0.1,
		0.1,
		0.1,
		0.1,
		//braço direito
		0.1,
		0.1,
		0.1,
		0.1,
		//braço esquerdo
		0.1,
		0.1,
		0.1,
		0.1,
		//pescoço
		0.1,
		//frente bota
		//0.08,
		0.01,
		0.01
	};

	GLdouble outerRadius[] = {
		//torax
		0.4,
		0.4,
		0.4,
		0.01,
		//perna direita
		0.19,
		0.19,
		0.16,
		0.15,
		0.14,
		//perna esquerda
		0.19,
		0.19,
		0.16,
		0.15,
		0.14,
		//braço direito
		0.22,
		0.21,
		0.21,
		0.21,
		//braço esquerdo
		0.22,
		0.21,
		0.21,
		0.21,
		//pescoço
		0.22,
		//frente bota
		//0.055,
		0.12,
		0.12
	};

	GLfloat positions[][3] = {
		// torax
		{0,-0.05,0},
		{0,0.13,0},
		{0,0.33,0},
		{0,0.48,0},

		// perna direita
		{0.24,-0.27,0},
		{0.32,-0.46,0},
		{0.39,-0.64,0},
		{0.47,-0.80,0},
		{0.55,-0.98,0},

		// perna esquerda
		{-0.25,-0.28,0},
		{-0.25,-0.50,0},
		{-0.25,-0.69,0},
		{-0.25,-0.90,0},
		{-0.25,-1.10,0},

		//braço direito
		{0.45,0.43,-0.3},
		{0.54,0.47,-0.37},
		{0.584,0.52,-0.41},
		{0.63,0.59,-0.42},

		//braço esquerdo
		{-0.49,0.38,0},
		{-0.57,0.275,0},
		{-0.65,0.14,-0.03},
		{-0.72,0.04,-0.05},

		//pescoço
		{0,0.60,0},

		//frente bota
		//{-0.230,-1.305,-0.21},
		{-0.24,-1.353,-0.24},
		{0.70,-1.20,-0.25}
	};

	GLfloat rotations[][3] = {
		//torax
		{90,0,0},
		{90,0,0},
		{90,0,0},
		{90,0,0},

		//perna direita
		{90,0,20},
		{90,0,20},
		{90,0,25},
		{90,0,25},
		{90,0,25},

		//perna esquerda
		{90,0,0},
		{90,0,0},
		{90,0,0},
		{90,0,0},
		{90,0,0},

		//braço direito
		{-35,155,40},
		{-45,155,40},
		{-60,155,20},
		{-60,155,10},

		//braço esquerdo
		{-40,90,0},
		{-90,10,-20},
		{-70,10,-25},
		{-50,40,-30},

		//pescoço
		{90,0,0},

		//frente bota
		{90,0,0},
		{90,0,15}
	};

	GLfloat scales[][3] = {
		//Torax
		{0.97,0.97,1.05},
		{1.0,1.0,1.15},
		{1.0,1.0,1.15},
		{0.96,0.96,1.1},
		//Perna direita
		{0.94,0.94,1.3},
		{0.88,0.88,1.15},
		{0.8,0.8,1.15},
		{0.9,0.9,1.15},
		{0.85,0.85,0.85},
		// Perna esquerda
		{0.94,0.94,1.3},
		{0.88,0.88,1.15},
		{0.8,0.8,1.15},
		{0.9,0.9,1.15},
		{0.85,0.85,0.85},
		// Braço direito
		{0.45,0.45,0.8},
		{0.41,0.41,0.7},
		{0.36,0.36,0.57},
		{0.28,0.28,0.3},
		// Braço esquerdo
		{0.45,0.45,0.9},
		{0.41,0.41,0.9},
		{0.36,0.36,0.8},
		{0.36,0.36,0.8},
		//pescoço
		{0.8,0.8,0.4},
		//frente bota
		{1.18,1.2,2},
		{1.18,1.2,2}
	};

	drawAllTorus(25, innerRadius, outerRadius, positions, rotations, scales);

	glutSwapBuffers();
}

void drawAllTorus(int n, GLdouble *innerRadius, GLdouble *outerRadius, GLfloat positions[][3], GLfloat rotations[][3], GLfloat scales[][3])
{
	for (int i = 0; i < n; i++)
	{
		drawTorus(innerRadius[i], outerRadius[i], positions[i], rotations[i], scales[i]);
	}
}

void drawTorus(GLdouble innerRadius, GLdouble outerRadius,GLfloat *position, GLfloat *rotation, GLfloat *scale)
{
	glPushMatrix();

	// glEnable(GL_NORMALIZE);

	glTranslatef(position[0],position[1],position[2]);

	glRotatef(rotation[1],0,1.0,0);
	glRotatef(rotation[2],0,0,1.0);
	glRotatef(rotation[0],1.0,0,0);

	glScalef(scale[0], scale[1], scale[2]);

	// glutWireTorus(innerRadius,outerRadius,40,50);
	glutSolidTorus(innerRadius,outerRadius,100,100);
	glPopMatrix();
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(600,700);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Michelin");
	glutDisplayFunc(draw);
	glClearColor(28/255.0f, 91/255.0f, 162/255.0f, 0);//adicionando cor ao plano de fundo

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	glEnable(GL_COLOR_MATERIAL);

	glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);

	glEnable(GL_LIGHTING);

	glutMainLoop();
	return 0;
}