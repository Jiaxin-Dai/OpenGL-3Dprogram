
#include <GL/glut.h>
#include <math.h>
#define PI 3.1415926

GLfloat light0_pos[4] = {20.0, 0.0, 0.0, 1.0};//��0�Ź�Դ��λ�ã�
GLfloat light1_pos[4] = {-20.0, 40.0, 0.0, 1.0};//��1�Ź�Դ��λ�ã�
GLfloat light2_pos[4] = {60.0, 20.0, 0.0, 1.0};//��2�Ź�Դ��λ�ã�
GLfloat light3_pos[4] = {30.0, 40.0, 0.0, 1.0};//��3�Ź�Դ��λ�ã�

GLfloat thetaObject = 0.0;//���ڿ��ƶ�����ת�ĽǶ�
GLfloat thetaLight = 0.0;//���ڿ��ƹ�Դ��ת�ĽǶ�

//������Ĳ������Խṹ��
typedef struct materialStruct {
	GLfloat ambient[4];
	GLfloat diffuse[4];
	GLfloat specular[4];
	GLfloat shininess;
	GLfloat emission[4];
	} materialStruct;

//��Դ���ԵĽṹ��
typedef struct lightingStruct {
	GLfloat ambient[4];
	GLfloat diffuse[4];
	GLfloat specular [4];
	} lightingStruct;

//Բ׶��Ĳ�������
materialStruct coneMaterials = {
	{0.0, 0.0, 0.0, 1.0},
	{0.1, 0.5, 0.8, 1.0},
	{0.0, 0.0, 0.0, 1.0},
	50.0,
	{0.0, 0.0, 0.0, 1.0},
};

//Բ���Ĳ�������
materialStruct torusMaterials = {
	{0.0, 0.0, 0.0, 1.0},
	{0.1, 0.5, 0.8, 1.0},
	{0.0, 0.8, 0.8, 1.0},
	50.0,
	{0.0, 0.0, 0.0, 0.0},
};

//������Ĳ�������
materialStruct earthMaterials = {
	{0.7, 0.7, 0.7, 1.0},
	{0.1, 0.5, 0.8, 1.0},
	{1.0, 1.0, 1.0, 1.0},
	100.0,
	{0.0, 0.0, 0.0, 1.0},
};

//С����Ĳ�������
materialStruct moonMaterials = {
	{0.8, 0.8, 0.2, 1.0},
	{0.1, 0.5, 0.8, 1.0},
	{0.0, 0.0, 0.0, 1.0},
	50.0,
	{0.3, 0.2, 0.2, 0.0},
};

//��Դ������
lightingStruct whiteLighting = {
	{0.1, 0.1, 0.1, 1.0},
	{1.0, 1.0, 1.0, 1.0},
	{1.0, 1.0, 1.0, 1.0}
	};

materialStruct *currentMaterials;
lightingStruct *currentLighting;
/*----------------------------------------------------*/

void myIdle(void)//���ڿ��Ƽ�����͹�Դ����ת�Ƕȣ�ֱ�ӿ������δ���
{
	thetaObject += 0.5;
	thetaLight -= 0.5;//0.5
	if (thetaObject > 360.0) thetaObject = 0.0;
	if (thetaLight < -360.0) thetaLight = 0.0;
	glutPostRedisplay();
}

//������������ϵ�����������ᣬx���ɫ��y����ɫ��z����ɫ���᳤�ɲ���length����
void createCoordinates(float length)
{
	glDisable(GL_LIGHTING);
	glLineWidth(0.5);

	glBegin(GL_LINES);//��ɫx��
	glColor3f(1,0,0);
	glVertex3f(0,0,0);
	glVertex3f(length,0,0);

	glColor3f(0.0,1.0,0.0);//��ɫy��
	glVertex3f(0,0,0);
	glVertex3f(0,length,0);
	
	glColor3f(0.0,0.0,1.0);//��ɫz��
	glVertex3f(0,0,0);
	glVertex3f(0,0,length);
	glEnd();
	glEnable(GL_LIGHTING);
	//д����Ĵ���
}

//�ú�������һ��С��������ʶ��Դ��λ�ã�
//������øú���ʱ����ʽ����light_posȡֵ������ǰ��light0_pos��light4_pos֮һ��
//���������Ҫģ��Ĺ�Դ��ѡ��
void simulateLight(GLfloat* light_pos)
{
	glDisable(GL_LIGHTING);//���ù��ռ���
	
	
	glPushMatrix(); //���ù�Դ0��λ��
		glColor3f(1,0,0);
		glRotatef(thetaLight,0,1,0);
		glLightfv(GL_LIGHT0, GL_POSITION, light_pos);             
		glTranslatef(light0_pos[0],light0_pos[1],light0_pos[2]);
		glutSolidSphere(0.5,8,8);
	glPopMatrix();

	glPushMatrix(); //���ù�Դ0��λ��
		glColor3f(1,1,1);
		glRotatef(thetaLight,0,1,0);
		glLightfv(GL_LIGHT0, GL_POSITION, light_pos);             
		glTranslatef(light1_pos[0],light1_pos[1],light1_pos[2]);
		glutSolidSphere(0.5,8,8);
	glPopMatrix();
	
	glPushMatrix(); //���ù�Դ2��λ��
		glColor3f(0,1,0);
		glLightfv(GL_LIGHT2, GL_POSITION, light2_pos);         
		glTranslatef(light2_pos[0],light2_pos[1],light2_pos[2]);
		glutSolidSphere(0.5,8,8);
	glPopMatrix();

	glPushMatrix(); //���ù�Դ3��λ��
		glColor3f(0,0,1);
		glTranslatef(30,0,0);
		glRotatef(thetaLight,0,1,0);
		glTranslatef(-30,0,0);
		glLightfv(GL_LIGHT3, GL_POSITION, light3_pos);           
		glTranslatef(light3_pos[0],light3_pos[1],light3_pos[2]);
		glutSolidSphere(0.5,8,8);
	glPopMatrix();


	glEnable(GL_LIGHTING);//���ù���Ч��
	//д����Ĵ���
}

//���ù���Ч���������õ�0,1,2,3�Ź�Դ������
void setLight()
{
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	glEnable(GL_LIGHT2);
	glEnable(GL_LIGHT3);
	currentLighting = &whiteLighting;
	glLightfv(GL_LIGHT0, GL_AMBIENT, currentLighting->ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, currentLighting->diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, currentLighting->specular);

	glLightfv(GL_LIGHT1, GL_AMBIENT, currentLighting->ambient);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, currentLighting->diffuse);
	glLightfv(GL_LIGHT1, GL_SPECULAR, currentLighting->specular);

	glLightfv(GL_LIGHT2, GL_AMBIENT, currentLighting->ambient);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, currentLighting->diffuse);
	glLightfv(GL_LIGHT2, GL_SPECULAR, currentLighting->specular);

	glLightfv(GL_LIGHT3, GL_AMBIENT, currentLighting->ambient);
	glLightfv(GL_LIGHT3, GL_DIFFUSE, currentLighting->diffuse);
	glLightfv(GL_LIGHT3, GL_SPECULAR, currentLighting->specular);

	//д����Ĵ���
}

//���ò������ԣ�����������þ���ļ�����ʱ���øú���
void setMaterials(materialStruct * currentMaterials)
{
	glMaterialfv(GL_FRONT, GL_AMBIENT, currentMaterials->ambient);// ���ò��ʶԻ������ɫ�ʷ�������
	glMaterialfv(GL_FRONT, GL_DIFFUSE, currentMaterials->diffuse);// ���ò��ʶ���������ɫ�ʷ�������
	glMaterialfv(GL_FRONT, GL_SPECULAR, currentMaterials->specular);// ���ò��ʶԾ�����ɫ�ʷ�������
	glMaterialf(GL_FRONT, GL_SHININESS, currentMaterials->shininess);// ���ò��ʶԾ���ⷴ��ʱ�ĻԶ�ϵ��

	//д����Ĵ���
}

//������С�𽥱仯��һЩ�����壬��Щ��������������²��������ϣ�
//  x = 60+t*cos(t);y = 1.5*t;z = t*sin(t);
//  (0<=t<=6pi)
void createManySphere(float t)
{
	float i=0.1;
	for(t=0;t<=6*PI;t+=PI/16)
	{
		glPushMatrix();
			glTranslatef(60+t*cos(t),1.5*t,t*sin(t));
			glutSolidSphere(i+=0.04,30,30);
		glPopMatrix();
	}
	//д����Ĵ���
}

//��ʾ�ص����������Level1��Level7
void display(void)
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(30.0,30.0,30.0,0.0,0.0,0.0,0.0,1.0,0.0);

	simulateLight(light0_pos); //�����ƹ�0
	simulateLight(light1_pos); //�����ƹ�1  
	simulateLight(light2_pos); //�����ƹ�2
	simulateLight(light3_pos); //�����ƹ�3


	//д����Ĵ���
	glTranslatef(0,-10,0);


	createCoordinates(50);

	glPushMatrix();//����Բ׶��
		setMaterials(&coneMaterials);
		glRotatef(-90,1,0,0);
		glutSolidCone(5,20,64,64);
	glPopMatrix();

	glPushMatrix();//����Բ��
		setMaterials(&torusMaterials); 
		glTranslatef(0,30,0);
		glRotatef(thetaObject,0,1,0);
		glutSolidTorus(5,10,64,64);
	glPopMatrix();

	glPushMatrix();
		setMaterials(&earthMaterials);
		glRotatef(thetaObject,0,1,0);
		glTranslatef(20,20,20);
		glutSolidSphere(6,64,64);//���ƴ�����

		setMaterials(&moonMaterials);
		glRotatef(thetaObject,0,1,0);
		glTranslatef(10,0,10);
		glutSolidSphere(3,64,64);//����С��
	glPopMatrix();
	
	setMaterials(&coneMaterials);
	
	createManySphere(6*PI);

	    
	glutSwapBuffers();
}

void myReshape(int w, int h)//�����ػ�ص�����������ֱ�ӿ���
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w <= h)
        glOrtho(-40.0, 40.0, -40.0 * (GLfloat) h / (GLfloat) w,
            40.0 * (GLfloat) h / (GLfloat) w, -200.0, 200.0);
    else
        glOrtho(-40.0 * (GLfloat) w / (GLfloat) h,
            40.0 * (GLfloat) w / (GLfloat) h, -40.0, 40.0, -200.0, 200.0);
}


void main(int argc, char **argv)//������������ֱ�ӿ���
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1000, 500);
    glutCreateWindow("i'm dddddai");

    glutReshapeFunc(myReshape);
	glutIdleFunc(myIdle);
    glutDisplayFunc(display);

    glEnable(GL_DEPTH_TEST); 
    setLight();

    glutMainLoop();
}