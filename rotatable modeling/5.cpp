#include <gl/glut.h>
#include <math.h>
#define PI 3.1415926

float theta = 0.0;

void trigger(void)//Idle�ص����������ڿ��ƻ�����������ת�ĽǶȣ�ֱ�ӿ���
{
	theta = theta + 0.05;
	if (theta > 360.0)
		theta = 0.0;
	glutPostRedisplay();
}

void createCoordinates(float length)//�ú�������x��y��z�ᣬֱ�ӿ���
{
	glLineWidth(2.0);//ָ����Ŀ��
	glBegin(GL_LINES);
		glColor3f(1.0,0.0,0.0);
		glVertex3f(0.0,0.0,0.0);
		glVertex3f(length,0.0,0.0);
		
		glColor3f(0.0,1.0,0.0);
		glVertex3f(0.0,0.0,0.0);
		glVertex3f(0.0,length,0.0);
		
		glColor3f(0.0,0.0,1.0);
		glVertex3f(0.0,0.0,0.0);
		glVertex3f(0.0,0.0,length);
	glEnd();
}

void createHead(void)//�����ƴ���ͷ��ģ�͵Ĵ��룬�����������Ҷ�
{
	glColor3f(0,0,1);
	glutSolidSphere(5,50,50);	//��ʾ1����ɫ������������glutSolidSphere�������뾶Ϊ5����λ

	glPushMatrix();
		glTranslatef(-4,0,0);
		glColor3f(1,0,0);
		glutSolidSphere(2,50,50);//��ʾ2����ɫ�����������glutSolidSphere�������뾶Ϊ2����λ�����������������ϵԭ����x�᷽��ƽ��4����λ
	glPopMatrix();

	glPushMatrix();
		glTranslatef(4,0,0);
		glColor3f(1,0,0);
		glutSolidSphere(2,50,50);	
	glPopMatrix();
	//��ʾ3����ɫ�����������glutSolidSphere�������뾶Ϊ2����λ�����������������ϵԭ������x�᷽��ƽ��4����λ


}

void createBody(void)//�����ƴ�������ģ�͵Ĵ���
{


	glTranslatef(0,-12,0);
	glPushMatrix();
		glColor3f(0,0,1);
		glScalef(2,3,1);
		glutWireCube(5);
	glPopMatrix();

	//��ʾ1����ɫ���ɣ��������������ϵԭ����y�Ḻ����ƽ��12����λ
	//��ʾ2����ɫ���ɣ�x����10����λ����y����15����λ����z����5����λ����
	//��ʾ3������glutWireCube�������߳�Ϊ5����λ������glScalef������������������ţ�x�᷽��Ŵ�2����y�᷽��Ŵ�3����z�᷽�򲻱䡣

}

void createLeftHandTop(void)//�����ƴ��������ϱ�ģ�͵Ĵ���
{
	glPushMatrix();
		glTranslatef(-9,0,0);
		glPushMatrix();
			glRotatef(-45,0,0,1);
			glColor3f(0,0,1);
			glScalef(0.25,2,0.25);
			glutWireCube(5);
		glPopMatrix();
		
	
//��ʾ1����ɫ�����ϱۣ������������x�Ḻ����ƽ��9����λ
//��ʾ2����ɫ�����ϱۣ��ó�����ģ�⣬��10����λ������͸߸�Ϊ1.25����λ
//��ʾ3������glutWireCube�������߳�Ϊ5����λ������glScalef������������������ţ�x�᷽����СΪԭ����1/4��y�᷽��Ŵ�2����z�᷽����СΪԭ����1/4��
//��ʾ4����ɫ�����ϱۣ�������������ɵ�ƽ��֮ǰ����z����ʱ����ת45��
}

void createLeftHandBottom(void) //�����ƴ��������±۵Ĵ���
{
		glTranslatef(-7.5,-7.5,0);
		glRotatef(-45,0,0,1);
		glColor3f(0,0,1);
		glScalef(0.25,2,0.25);
		glutWireCube(5);
	glPopMatrix();
//��ʾ1����ɫ�����±ۣ�����������ϱ�x���y�Ḻ�����ƽ��7.5����λ
//��ʾ2����ɫ�����±ۣ��ó�����ģ�⣬��10����λ������͸߸�Ϊ1.25����λ
//��ʾ3������glutWireCube�������߳�Ϊ5����λ������glScalef������������������ţ�x�᷽����СΪԭ����1/4��y�᷽��Ŵ�2����z�᷽����СΪԭ����1/4��
//��ʾ4����ɫ�����±ۣ���������������ϱ۵�ƽ��֮ǰ����z����ʱ����ת45��
}

void createRightHand(void)//�����ƴ�������ģ�͵Ĵ���
{


	
	glPushMatrix();
		glTranslatef(9,0,0);
		glPushMatrix();
			glRotatef(45,0,0,1);
			glColor3f(0,0,1);
			glScalef(0.25,2,0.25);
			glutWireCube(5);
		glPopMatrix();

//��ʾ1����ɫ���֣������������x��������ƽ��9����λ
//��ʾ2����ɫ���֣��ó�����ģ�⣬��10����λ������͸߸�Ϊ1.25����λ
//��ʾ3������glutWireCube�������߳�Ϊ5����λ������glScalef������������������ţ�x�᷽����СΪԭ����1/4��y�᷽��Ŵ�2����z�᷽����СΪԭ����1/4��
//��ʾ4����ɫ���֣�������������ɵ�ƽ��֮ǰ����z��˳ʱ����ת45��
}

void createRightHandBottom(void) //�����ƴ��������±۵Ĵ���
{
	
		glTranslatef(7.5,-7.5,0);
		glRotatef(45,0,0,1);
		glColor3f(0,0,1);
		glScalef(0.25,2,0.25);
		glutWireCube(5);
		glPopMatrix();
}

void createLeftFoot(void)//�����ƴ������ģ�͵Ĵ���
{
	glPushMatrix();
		glTranslatef(-3,-13,0);
		glColor3f(0,0,1);
		glScalef(0.25,2,0.25);
		glutWireCube(5);
	glPopMatrix();
//��ʾ1����ɫ��ţ������������x�Ḻ����ƽ��3����λ����y�Ḻ����ƽ��13����λ
//��ʾ2����ɫ��ţ��ó�����ģ�⣬��10����λ������͸߸�Ϊ1.25����λ
//��ʾ3������glutWireCube�������߳�Ϊ5����λ������glScalef������������������ţ�x�᷽����СΪԭ����1/4��y�᷽��Ŵ�2����z�᷽����СΪԭ����1/4��
}

void createRightFoot(void)//�����ƴ����ҽ�ģ�͵Ĵ���
{
	glPushMatrix();
		glTranslatef(3,-13,0);
		glColor3f(0,0,1);
		glScalef(0.25,2,0.25);
		glutWireCube(5);
	glPopMatrix();
//��ʾ1����ɫ�ҽţ������������x��������ƽ��3����λ����y�Ḻ����ƽ��13����λ
//��ʾ2����ɫ�ҽţ��ó�����ģ�⣬��10����λ������͸߸�Ϊ1.25����λ
//��ʾ3������glutWireCube�������߳�Ϊ5����λ������glScalef������������������ţ�x�᷽����СΪԭ����1/4��y�᷽��Ŵ�2����z�᷽����СΪԭ����1/4��
}

void createRobot(void)//�������������˵ĺ������ú������ñ䣬ֱ�ӿ���
{
	glRotatef(theta,0.0,1.0,0.0);//ʹ�û�����������ת
	createHead();//���ô���ͷ�����Ӻ���

	glColor3f(0.0,0.0,1.0);//ָ���������ɺ���֫����ɫ
	createBody();//���ô������ɵ��Ӻ���
	createLeftHandTop();//���ô��������ϱ۵��Ӻ���
	createLeftHandBottom();//���ô��������±۵��Ӻ���
	createRightHand();//���ô������ֵ��Ӻ���
	createRightHandBottom();
	createLeftFoot();//���ô�����ŵ��Ӻ���
	createRightFoot();//���ô����ҽŵ��Ӻ���
}

void display(void)//��ʾ�ص��Ӻ������ú������ñ䣬ֱ�ӿ���
{
	glClearColor(0.0,0.0,0.0,0.0);
	//ע�⣬ͬʱ�����ɫ�ʻ���������Ȼ�����
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-40.0,40.0,-40.0,40.0,1,200);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0,0.0,30.0,0.0,0.0,0.0,0.0,1.0,0.0);
	//gluLookAt(30.0,30.0,30.0,0.0,0.0,0.0,0.0,1.0,0.0); ��һ�²�ͬ�Ĺ۲�Ƕ�
	
    createCoordinates(20);//���ô���x,y��z��������Ӻ���
	createRobot();//���ô��������˵��Ӻ���

	glFlush();
}

void main(int argc, char** argv)//main�������ֲ��ñ䣬ֱ�ӿ���
{
	glutInit(&argc,argv);
	//ע��������GLUT_DEPTHģʽ
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);

	glutInitWindowSize(500,500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Orthogonal projection");

	glutDisplayFunc(display);
	glutIdleFunc(trigger);

	//���������Ȳ��ԣ����ڴ���ͷ����ģʱ�����Ͷ������Կռ�λ�ù�ϵ
	//��һ�£������������Ȳ��ԵĻ����ڻ�����������תʱ���۲����Ͷ���
	glEnable(GL_DEPTH_TEST);

	glutMainLoop();
}