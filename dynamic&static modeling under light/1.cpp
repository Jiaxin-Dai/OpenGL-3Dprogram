
#include <GL/glut.h>
#include <math.h>
#define PI 3.1415926

GLfloat light0_pos[4] = {20.0, 0.0, 0.0, 1.0};//第0号光源的位置；
GLfloat light1_pos[4] = {-20.0, 40.0, 0.0, 1.0};//第1号光源的位置；
GLfloat light2_pos[4] = {60.0, 20.0, 0.0, 1.0};//第2号光源的位置；
GLfloat light3_pos[4] = {30.0, 40.0, 0.0, 1.0};//第3号光源的位置；

GLfloat thetaObject = 0.0;//用于控制对象旋转的角度
GLfloat thetaLight = 0.0;//用于控制光源旋转的角度

//几何体的材质属性结构体
typedef struct materialStruct {
	GLfloat ambient[4];
	GLfloat diffuse[4];
	GLfloat specular[4];
	GLfloat shininess;
	GLfloat emission[4];
	} materialStruct;

//光源属性的结构体
typedef struct lightingStruct {
	GLfloat ambient[4];
	GLfloat diffuse[4];
	GLfloat specular [4];
	} lightingStruct;

//圆锥体的材质属性
materialStruct coneMaterials = {
	{0.0, 0.0, 0.0, 1.0},
	{0.1, 0.5, 0.8, 1.0},
	{0.0, 0.0, 0.0, 1.0},
	50.0,
	{0.0, 0.0, 0.0, 1.0},
};

//圆环的材质属性
materialStruct torusMaterials = {
	{0.0, 0.0, 0.0, 1.0},
	{0.1, 0.5, 0.8, 1.0},
	{0.0, 0.8, 0.8, 1.0},
	50.0,
	{0.0, 0.0, 0.0, 0.0},
};

//大球体的材质属性
materialStruct earthMaterials = {
	{0.7, 0.7, 0.7, 1.0},
	{0.1, 0.5, 0.8, 1.0},
	{1.0, 1.0, 1.0, 1.0},
	100.0,
	{0.0, 0.0, 0.0, 1.0},
};

//小球体的材质属性
materialStruct moonMaterials = {
	{0.8, 0.8, 0.2, 1.0},
	{0.1, 0.5, 0.8, 1.0},
	{0.0, 0.0, 0.0, 1.0},
	50.0,
	{0.3, 0.2, 0.2, 0.0},
};

//光源的属性
lightingStruct whiteLighting = {
	{0.1, 0.1, 0.1, 1.0},
	{1.0, 1.0, 1.0, 1.0},
	{1.0, 1.0, 1.0, 1.0}
	};

materialStruct *currentMaterials;
lightingStruct *currentLighting;
/*----------------------------------------------------*/

void myIdle(void)//用于控制几何体和光源的旋转角度，直接拷贝本段代码
{
	thetaObject += 0.5;
	thetaLight -= 0.5;//0.5
	if (thetaObject > 360.0) thetaObject = 0.0;
	if (thetaLight < -360.0) thetaLight = 0.0;
	glutPostRedisplay();
}

//创建世界坐标系的三个坐标轴，x轴红色，y轴绿色，z轴蓝色，轴长由参数length决定
void createCoordinates(float length)
{
	glDisable(GL_LIGHTING);
	glLineWidth(0.5);

	glBegin(GL_LINES);//红色x轴
	glColor3f(1,0,0);
	glVertex3f(0,0,0);
	glVertex3f(length,0,0);

	glColor3f(0.0,1.0,0.0);//绿色y轴
	glVertex3f(0,0,0);
	glVertex3f(0,length,0);
	
	glColor3f(0.0,0.0,1.0);//蓝色z轴
	glVertex3f(0,0,0);
	glVertex3f(0,0,length);
	glEnd();
	glEnable(GL_LIGHTING);
	//写出你的代码
}

//该函数绘制一个小球体来标识光源的位置，
//具体调用该函数时，形式参数light_pos取值可以是前述light0_pos到light4_pos之一，
//具体根据需要模拟的光源来选择。
void simulateLight(GLfloat* light_pos)
{
	glDisable(GL_LIGHTING);//禁用光照计算
	
	
	glPushMatrix(); //设置光源0的位置
		glColor3f(1,0,0);
		glRotatef(thetaLight,0,1,0);
		glLightfv(GL_LIGHT0, GL_POSITION, light_pos);             
		glTranslatef(light0_pos[0],light0_pos[1],light0_pos[2]);
		glutSolidSphere(0.5,8,8);
	glPopMatrix();

	glPushMatrix(); //设置光源0的位置
		glColor3f(1,1,1);
		glRotatef(thetaLight,0,1,0);
		glLightfv(GL_LIGHT0, GL_POSITION, light_pos);             
		glTranslatef(light1_pos[0],light1_pos[1],light1_pos[2]);
		glutSolidSphere(0.5,8,8);
	glPopMatrix();
	
	glPushMatrix(); //设置光源2的位置
		glColor3f(0,1,0);
		glLightfv(GL_LIGHT2, GL_POSITION, light2_pos);         
		glTranslatef(light2_pos[0],light2_pos[1],light2_pos[2]);
		glutSolidSphere(0.5,8,8);
	glPopMatrix();

	glPushMatrix(); //设置光源3的位置
		glColor3f(0,0,1);
		glTranslatef(30,0,0);
		glRotatef(thetaLight,0,1,0);
		glTranslatef(-30,0,0);
		glLightfv(GL_LIGHT3, GL_POSITION, light3_pos);           
		glTranslatef(light3_pos[0],light3_pos[1],light3_pos[2]);
		glutSolidSphere(0.5,8,8);
	glPopMatrix();


	glEnable(GL_LIGHTING);//启用光照效果
	//写出你的代码
}

//启用光照效果，并设置第0,1,2,3号光源的属性
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

	//写出你的代码
}

//设置材质属性，方便后面设置具体的几何体时调用该函数
void setMaterials(materialStruct * currentMaterials)
{
	glMaterialfv(GL_FRONT, GL_AMBIENT, currentMaterials->ambient);// 设置材质对环境光的色彩反射属性
	glMaterialfv(GL_FRONT, GL_DIFFUSE, currentMaterials->diffuse);// 设置材质对漫反射光的色彩反射属性
	glMaterialfv(GL_FRONT, GL_SPECULAR, currentMaterials->specular);// 设置材质对镜面光的色彩反射属性
	glMaterialf(GL_FRONT, GL_SHININESS, currentMaterials->shininess);// 设置材质对镜面光反射时的辉度系数

	//写出你的代码
}

//创建大小逐渐变化的一些列球体，这些球体的中心在如下参数曲线上：
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
	//写出你的代码
}

//显示回调函数，完成Level1到Level7
void display(void)
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(30.0,30.0,30.0,0.0,0.0,0.0,0.0,1.0,0.0);

	simulateLight(light0_pos); //开启灯光0
	simulateLight(light1_pos); //开启灯光1  
	simulateLight(light2_pos); //开启灯光2
	simulateLight(light3_pos); //开启灯光3


	//写出你的代码
	glTranslatef(0,-10,0);


	createCoordinates(50);

	glPushMatrix();//绘制圆锥体
		setMaterials(&coneMaterials);
		glRotatef(-90,1,0,0);
		glutSolidCone(5,20,64,64);
	glPopMatrix();

	glPushMatrix();//绘制圆环
		setMaterials(&torusMaterials); 
		glTranslatef(0,30,0);
		glRotatef(thetaObject,0,1,0);
		glutSolidTorus(5,10,64,64);
	glPopMatrix();

	glPushMatrix();
		setMaterials(&earthMaterials);
		glRotatef(thetaObject,0,1,0);
		glTranslatef(20,20,20);
		glutSolidSphere(6,64,64);//绘制大球体

		setMaterials(&moonMaterials);
		glRotatef(thetaObject,0,1,0);
		glTranslatef(10,0,10);
		glutSolidSphere(3,64,64);//绘制小球
	glPopMatrix();
	
	setMaterials(&coneMaterials);
	
	createManySphere(6*PI);

	    
	glutSwapBuffers();
}

void myReshape(int w, int h)//窗口重绘回调函数，代码直接拷贝
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


void main(int argc, char **argv)//主函数，代码直接拷贝
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