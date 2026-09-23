#include <graphics.h> //图形界面库
#include <stdio.h>
#include <time.h>

#define N 3

int Mapx, Mapy, score;

int Map[N];//定义一个数组，存储黑块的位置

//随机产生生成黑块的坐标
void initblace()
{

	for (int i = 0;i < N;i++)
	{
		Map[i] = rand() % N;
		printf("%d\n", Map[i]);
	}
}

//根据随机存储在数组中的数据产生黑块
void drawblack()
{
	for (int i = 0;i < N;i++)
	{
		fillrectangle(Map[i] * 100, i * 120, Map[i] * 100 + 100, i * 120 + 120);
	}
}

//绘制界面
void draw()
{
	BeginBatchDraw();
	cleardevice();//清屏
	//设置线条填充
	setlinecolor(BLACK);
	setfillcolor(WHITE);//把填充色换为白色

	//根据4行5列，求得宽度：100，高度：120
	//left , top , right ,bottom
	for (int i = 0; i < 3; i++) //行
		for (int j = 0; j < 3; j++)	//列
		{
			fillrectangle(j * 100, i * 120, j * 100 + 100, i * 120 + 120); //绘制一个填充矩形
		}
	setfillcolor(BLACK);//把填充色换为黑色
	drawblack();//绘制黑块

	EndBatchDraw();
}

bool play()
{
	MOUSEMSG msg;//定义变量存储鼠标消息
	msg = GetMouseMsg();//捕获鼠标消息


	switch (msg.uMsg) {
	case WM_LBUTTONDOWN://鼠标左键按下

		//根据鼠标点击的坐标计算对应的下标
		Mapx = msg.x / 100;//100 是白块 黑块的宽度
		Mapy = msg.y / 120;//120 是白块 黑块的高度
		//Map[3]存储的是列号
		if (Map[2] == Mapx && Mapy == 2) {
			for (int i = 2;i > 0;i--) {
				Map[i] = Map[i - 1];
			}
			Map[0] = rand() % N;//随机生成一个新的数来补位
			score += 10;
			printf("你点击到了黑块\n");
		}
		else {
			printf("未点击到黑块\n");
			return true;
		}
		break;

	}
	return false;

}


int main()
{
	srand((unsigned)time(NULL));//用时间初始化种子

	//1.创建界面  width：宽度  height：高度     单位：px
	initgraph(300, 360);
	initblace();//初始化格子的位置
	while (1) {
		draw();//绘制界面中的方块
		play();
		}

	
	//卡屏
	//while (1);
	return 0;
}