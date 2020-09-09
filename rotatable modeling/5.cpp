#include <gl/glut.h>
#include <math.h>
#define PI 3.1415926

float theta = 0.0;

void trigger(void)//Idle回调函数，用于控制机器人整体旋转的角度，直接拷贝
{
	theta = theta + 0.05;
	if (theta > 360.0)
		theta = 0.0;
	glutPostRedisplay();
}

void createCoordinates(float length)//该函数创建x，y和z轴，直接拷贝
{
	glLineWidth(2.0);//指定轴的宽度
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

void createHead(void)//请完善创建头部模型的代码，含脸部和左右耳
{
	glColor3f(0,0,1);
	glutSolidSphere(5,50,50);	//提示1：蓝色的脸部，调用glutSolidSphere函数，半径为5个单位

	glPushMatrix();
		glTranslatef(-4,0,0);
		glColor3f(1,0,0);
		glutSolidSphere(2,50,50);//提示2：红色的左耳，调用glutSolidSphere函数，半径为2个单位，并相对于世界坐标系原点向负x轴方向平移4个单位
	glPopMatrix();

	glPushMatrix();
		glTranslatef(4,0,0);
		glColor3f(1,0,0);
		glutSolidSphere(2,50,50);	
	glPopMatrix();
	//提示3：红色的左耳，调用glutSolidSphere函数，半径为2个单位，并相对于世界坐标系原点向正x轴方向平移4个单位


}

void createBody(void)//请完善创建躯干模型的代码
{


	glTranslatef(0,-12,0);
	glPushMatrix();
		glColor3f(0,0,1);
		glScalef(2,3,1);
		glutWireCube(5);
	glPopMatrix();

	//提示1：蓝色躯干，相对于世界坐标系原点向y轴负方向平移12个单位
	//提示2：蓝色躯干，x方向10个单位长，y方向15个单位长，z方向5个单位长。
	//提示3：调用glutWireCube函数，边长为5个单位；调用glScalef函数进行立方体的缩放，x轴方向放大2倍，y轴方向放大3倍，z轴方向不变。

}

void createLeftHandTop(void)//请完善创建左手上臂模型的代码
{
	glPushMatrix();
		glTranslatef(-9,0,0);
		glPushMatrix();
			glRotatef(-45,0,0,1);
			glColor3f(0,0,1);
			glScalef(0.25,2,0.25);
			glutWireCube(5);
		glPopMatrix();
		
	
//提示1：蓝色左手上臂，相对于躯干向x轴负方向平移9个单位
//提示2：蓝色左手上臂，用长方体模拟，长10个单位长，宽和高各为1.25个单位
//提示3：调用glutWireCube函数，边长为5个单位；调用glScalef函数进行立方体的缩放，x轴方向缩小为原来的1/4，y轴方向放大2倍，z轴方向缩小为原来的1/4。
//提示4：蓝色左手上臂，在做相对于躯干的平移之前，绕z轴逆时针旋转45度
}

void createLeftHandBottom(void) //请完善创建左手下臂的代码
{
		glTranslatef(-7.5,-7.5,0);
		glRotatef(-45,0,0,1);
		glColor3f(0,0,1);
		glScalef(0.25,2,0.25);
		glutWireCube(5);
	glPopMatrix();
//提示1：蓝色左手下臂，相对于左手上臂x轴和y轴负方向各平移7.5个单位
//提示2：蓝色左手下臂，用长方体模拟，长10个单位长，宽和高各为1.25个单位
//提示3：调用glutWireCube函数，边长为5个单位；调用glScalef函数进行立方体的缩放，x轴方向缩小为原来的1/4，y轴方向放大2倍，z轴方向缩小为原来的1/4。
//提示4：蓝色左手下臂，在做相对于左手上臂的平移之前，绕z轴逆时针旋转45度
}

void createRightHand(void)//请完善创建右手模型的代码
{


	
	glPushMatrix();
		glTranslatef(9,0,0);
		glPushMatrix();
			glRotatef(45,0,0,1);
			glColor3f(0,0,1);
			glScalef(0.25,2,0.25);
			glutWireCube(5);
		glPopMatrix();

//提示1：蓝色右手，相对于躯干向x轴正方向平移9个单位
//提示2：蓝色右手，用长方体模拟，长10个单位长，宽和高各为1.25个单位
//提示3：调用glutWireCube函数，边长为5个单位；调用glScalef函数进行立方体的缩放，x轴方向缩小为原来的1/4，y轴方向放大2倍，z轴方向缩小为原来的1/4。
//提示4：蓝色右手，在做相对于躯干的平移之前，绕z轴顺时针旋转45度
}

void createRightHandBottom(void) //请完善创建右手下臂的代码
{
	
		glTranslatef(7.5,-7.5,0);
		glRotatef(45,0,0,1);
		glColor3f(0,0,1);
		glScalef(0.25,2,0.25);
		glutWireCube(5);
		glPopMatrix();
}

void createLeftFoot(void)//请完善创建左脚模型的代码
{
	glPushMatrix();
		glTranslatef(-3,-13,0);
		glColor3f(0,0,1);
		glScalef(0.25,2,0.25);
		glutWireCube(5);
	glPopMatrix();
//提示1：蓝色左脚，相对于躯干向x轴负方向平移3个单位，向y轴负方向平移13个单位
//提示2：蓝色左脚，用长方体模拟，长10个单位长，宽和高各为1.25个单位
//提示3：调用glutWireCube函数，边长为5个单位；调用glScalef函数进行立方体的缩放，x轴方向缩小为原来的1/4，y轴方向放大2倍，z轴方向缩小为原来的1/4。
}

void createRightFoot(void)//请完善创建右脚模型的代码
{
	glPushMatrix();
		glTranslatef(3,-13,0);
		glColor3f(0,0,1);
		glScalef(0.25,2,0.25);
		glutWireCube(5);
	glPopMatrix();
//提示1：蓝色右脚，相对于躯干向x轴正方向平移3个单位，向y轴负方向平移13个单位
//提示2：蓝色右脚，用长方体模拟，长10个单位长，宽和高各为1.25个单位
//提示3：调用glutWireCube函数，边长为5个单位；调用glScalef函数进行立方体的缩放，x轴方向缩小为原来的1/4，y轴方向放大2倍，z轴方向缩小为原来的1/4。
}

void createRobot(void)//创建整个机器人的函数，该函数不用变，直接拷贝
{
	glRotatef(theta,0.0,1.0,0.0);//使得机器人整体旋转
	createHead();//调用创建头部的子函数

	glColor3f(0.0,0.0,1.0);//指定绘制躯干和四肢的颜色
	createBody();//调用创建躯干的子函数
	createLeftHandTop();//调用创建左手上臂的子函数
	createLeftHandBottom();//调用创建左手下臂的子函数
	createRightHand();//调用创建右手的子函数
	createRightHandBottom();
	createLeftFoot();//调用创建左脚的子函数
	createRightFoot();//调用创建右脚的子函数
}

void display(void)//显示回调子函数，该函数不用变，直接拷贝
{
	glClearColor(0.0,0.0,0.0,0.0);
	//注意，同时清除了色彩缓冲区和深度缓冲区
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-40.0,40.0,-40.0,40.0,1,200);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0,0.0,30.0,0.0,0.0,0.0,0.0,1.0,0.0);
	//gluLookAt(30.0,30.0,30.0,0.0,0.0,0.0,0.0,1.0,0.0); 试一下不同的观察角度
	
    createCoordinates(20);//调用创建x,y和z坐标轴的子函数
	createRobot();//调用创建机器人的子函数

	glFlush();
}

void main(int argc, char** argv)//main函数部分不用变，直接拷贝
{
	glutInit(&argc,argv);
	//注意设置了GLUT_DEPTH模式
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);

	glutInitWindowSize(500,500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Orthogonal projection");

	glutDisplayFunc(display);
	glutIdleFunc(trigger);

	//允许进行深度测试，用于处理头部建模时的脸和耳朵的相对空间位置关系
	//试一下，如果不启用深度测试的话，在机器人整体旋转时，观察脸和耳朵
	glEnable(GL_DEPTH_TEST);

	glutMainLoop();
}