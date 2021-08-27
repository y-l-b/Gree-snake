#include <stdio.h>
#include <windows.h>
#include <time.h>

//*贪吃蛇
  // 身体使用链表来实现

// 定义方向
typedef enum
{
	UP = 1,		// 0001
	DOWN = 2,	// 0010
	LEFT = 4,	// 0100
	RIGHT = 8	// 1000
} Direction;

// 链表的基础结构
typedef struct S_Snake_Item
{
	int X;
	int Y;
	Direction Direction;
	struct S_Snake_Item* Next;
} Snake_Item;

// 新建蛇身体
Snake_Item* new_Snake_Item(const Snake_Item const* snake_Item) {
	Snake_Item* newData = (Snake_Item*)malloc(sizeof(Snake_Item));
	if (newData != NULL)
		copy_Snake_Item(snake_Item, newData);
	return newData;
}

//释放蛇身体
void delete_Snake_Item(Snake_Item* snake_Item)
{
	free(snake_Item);
}

// 复制蛇身体
BOOL copy_Snake_Item(const Snake_Item const* source_snake_Item, Snake_Item* target_snake_Item)
{
	if (source_snake_Item != NULL)
	{
		target_snake_Item->X = source_snake_Item->X;
		target_snake_Item->Y = source_snake_Item->Y;
		target_snake_Item->Direction = source_snake_Item->Direction;
		target_snake_Item->Next = source_snake_Item->Next;
		return TRUE;
	}
	return FALSE;
}

// 比对蛇的身体
BOOL Compared_Snake_Item(Snake_Item* Head_snake_Item, Snake_Item* Next_snake_Item)
{
	for (int i = 0; i < Next_snake_Item->Next - 1; i++)
	{
		Head_snake_Item = Next_snake_Item->Next;
	}
	while (Next_snake_Item->Next != NULL)
	{
		Next_snake_Item = Next_snake_Item->Next;
	}
	if (Head_snake_Item == Next_snake_Item)
	{
		return TRUE;
	}
	return FALSE;

}

//*菜单

// 纪录菜单条目和带来的影响
struct {
	// 要显示的条目
	char* Text;
	// 会带来的config中的影响
	int Offset;
} menu[] = { {"简单",0},{"普通",10},{"困难",100},{"传说",1000} };

// 在全局变量中增加一个偏移量,这个偏移量将会影响自动事件
//*加载用户的配置
  // 使用结构体 config 来包装所有的共享变量

// 纪录全局共享变量的结构
struct {
	// 用于控制蛇速度的变量
	int Offset;
	// 用于纪录菜单的条目数量
	int Menu_Count;
	// 用于纪录游戏状态
	enum {
		// 游戏初始化
		GameInit,
		// 打印游戏菜单
		GamePrintMenu,
		// 等待用户选择
		GameWaitUser,
		// 游戏已经启动
		GameStart,
		// 游戏已经暂停
		GamePause,
		// 游戏胜利了
		GameEnd_Victory = 10,
		// 游戏失败了
		GameEnd_Failed = 11
	} GameStatus;
	// 标记地图的起始位置
	struct {
		// 标记地图的起始位置(Y坐标)
		int Y;
		// 标记地图的起始位置(X坐标)
		int X;
	} startPoint;
	// 标记地图的长宽
	struct {
		enum {
			Height = 30,
			Width = 50
		};
	} Side;

} config = { 1, sizeof(menu) / 8, GameInit,{0,0}};


// 关联菜单和 config 的条目
BOOL Select_Menu(int index) {
	if (index < config.Menu_Count)
	{
		int Menu_Map[] = { menu[index].Offset };
		int* Map[] = { &config.Offset };

		for (int i = 0; i < (sizeof(Map) / 4); i++)
		{
			Map[i] = Menu_Map[i];
		}
		return TRUE;
	}
	return FALSE;
}

//*绘制界面
  //初始化界面信息
void csh_map()
{
	int i, j;
	char map[Height][Width];
	for (i = 0; i < Height; i++)
	{
		for (j = 0; i < Width; j++)
		{
			map[i][j] = "#";
		}
	}
	for (i = 0; i < Height - 1; i++)
	{
		for (j = 0; i < Width - 1; j++)
		{
			map[i][j] = " ";
		}
	}
 }
  // 开始绘制界面
void Draw_Map()
{

}
// 缓存上一次打印的界面信息,利用API来只更新局部,避免屏幕闪烁
//*计算蛇的初始位置和食物的初始位置
//*创建一个循环监视器
  //*蛇的自动移动[应该由游戏规则操控的部分,为了在每一次循环中获得新的内容]
	// 关于游戏内的自动事件,都被包装在渲染函数内
  //*有没有事件发生(蛇撞到了墙面,或者撞到了自己,或者吃了东西)[判断游戏结束的条件]
	// 我们使用变量或者宏来确定和控制墙的边界
  //*有没有用户的操作[检查和用户的交互]


int main()
{

}
//int speed;
//char map[30][50];
//
//void Snake_date();
//void Food_date();
//void Map();
//void print_map();
//
//struct SNAKE
//{
//	int x;
//	int y;
//	int size;
//	int dir;
//}SNAKE[50];
//
//struct FOOD
//{
//	int x;
//	int y;
//	int flag;
//}FOOD;
//
//void Map()
//{
//	int i, j;
//	for (i = 0; i < 30; i++) //绘制边界
//		for (j = 0; j < 50; j++)
//		{
//			map[i][j] = '#';
//		}
//	for (i = 1; i < 29; i++) //绘制可移动的位置
//		for (j = 1; j < 49; j++)
//		{
//			map[i][j] = ' ';
//		}
//	map[SNAKE[0].x][SNAKE[0].y] = 'X';
//	for (i = 1; i < SNAKE[5].size; i++)
//		for (j = 1; j < SNAKE[5].size; j++)
//		{
//			map[SNAKE[i].x][SNAKE[j].y] = 'H';
//		}
//
//}
//
//void Snake_date()
//{
//	int i;
//	SNAKE[5].dir = RIGHT;
//	SNAKE[5].size = 5;
//	for (i = 0; i < 5; i++)
//	{
//		SNAKE[i].y = 7 - i;
//	}
//	for (i = 0; i < 5; i++)
//	{
//		SNAKE[i].x = 1;
//	}
//}
//
//void Food_date()
//{
//	srand((unsigned)time(NULL));
//	// TODO: 这里有可能将食物生成在线上
//	FOOD.x = rand() % 50;
//	FOOD.y = rand() % 50;
//	FOOD.flag = 1;
//}
//
//
//void print_map()
//{
//	int i,j;
//
//	if (FOOD.flag == 1)
//	{
//		if (map[FOOD.x][FOOD.y] == ' ')
//		{
//			map[FOOD.x][FOOD.y] = '*';
//		}
//	}
//		for (i = 0; i < 30; i++)
//		{
//			for (j = 0; j < 50; j++)
//			{
//				printf("%c", map[i][j]);
//			}
//			printf("\n");
//		}
//
//
//}
//
//void Snake_move()
//{
//	switch (getchar())
//	{
//		case 'w':
//		case 'W':
//			SNAKE[5].dir = UP;
//			break;
//		case 's':
//		case 'S':
//			SNAKE[5].dir = DOWN;
//			break;
//		case 'a':
//		case 'A':
//			SNAKE[5].dir = LEFT;
//			break;
//		case 'd':
//		case 'D':
//			SNAKE[5].dir = RIGHT;
//			break;
//	}
//}
//
//int main()
//{
//	Selct_Menu(3);
//	Snake_date();
//	Food_date();
//	Map();
//	print_map();
//}






