#include <stdio.h>
#include <windows.h>
#include <time.h>

//*̰����
  // ����ʹ��������ʵ��

// ���巽��
typedef enum
{
	UP = 1,		// 0001
	DOWN = 2,	// 0010
	LEFT = 4,	// 0100
	RIGHT = 8	// 1000
} Direction;

// ����Ļ����ṹ
typedef struct S_Snake_Item
{
	int X;
	int Y;
	Direction Direction;
	struct S_Snake_Item* Next;
} Snake_Item;

// �½�������
Snake_Item* new_Snake_Item(const Snake_Item const* snake_Item) {
	Snake_Item* newData = (Snake_Item*)malloc(sizeof(Snake_Item));
	if (newData != NULL)
		copy_Snake_Item(snake_Item, newData);
	return newData;
}

//�ͷ�������
void delete_Snake_Item(Snake_Item* snake_Item)
{
	free(snake_Item);
}

// ����������
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

// �ȶ��ߵ�����
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

//*�˵�

// ��¼�˵���Ŀ�ʹ�����Ӱ��
struct {
	// Ҫ��ʾ����Ŀ
	char* Text;
	// �������config�е�Ӱ��
	int Offset;
} menu[] = { {"��",0},{"��ͨ",10},{"����",100},{"��˵",1000} };

// ��ȫ�ֱ���������һ��ƫ����,���ƫ��������Ӱ���Զ��¼�
//*�����û�������
  // ʹ�ýṹ�� config ����װ���еĹ������

// ��¼ȫ�ֹ�������Ľṹ
struct {
	// ���ڿ������ٶȵı���
	int Offset;
	// ���ڼ�¼�˵�����Ŀ����
	int Menu_Count;
	// ���ڼ�¼��Ϸ״̬
	enum {
		// ��Ϸ��ʼ��
		GameInit,
		// ��ӡ��Ϸ�˵�
		GamePrintMenu,
		// �ȴ��û�ѡ��
		GameWaitUser,
		// ��Ϸ�Ѿ�����
		GameStart,
		// ��Ϸ�Ѿ���ͣ
		GamePause,
		// ��Ϸʤ����
		GameEnd_Victory = 10,
		// ��Ϸʧ����
		GameEnd_Failed = 11
	} GameStatus;
	// ��ǵ�ͼ����ʼλ��
	struct {
		// ��ǵ�ͼ����ʼλ��(Y����)
		int Y;
		// ��ǵ�ͼ����ʼλ��(X����)
		int X;
	} startPoint;
	// ��ǵ�ͼ�ĳ���
	struct {
		enum {
			Height = 30,
			Width = 50
		};
	} Side;

} config = { 1, sizeof(menu) / 8, GameInit,{0,0}};


// �����˵��� config ����Ŀ
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

//*���ƽ���
  //��ʼ��������Ϣ
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
  // ��ʼ���ƽ���
void Draw_Map()
{

}
// ������һ�δ�ӡ�Ľ�����Ϣ,����API��ֻ���¾ֲ�,������Ļ��˸
//*�����ߵĳ�ʼλ�ú�ʳ��ĳ�ʼλ��
//*����һ��ѭ��������
  //*�ߵ��Զ��ƶ�[Ӧ������Ϸ����ٿصĲ���,Ϊ����ÿһ��ѭ���л���µ�����]
	// ������Ϸ�ڵ��Զ��¼�,������װ����Ⱦ������
  //*��û���¼�����(��ײ����ǽ��,����ײ�����Լ�,���߳��˶���)[�ж���Ϸ����������]
	// ����ʹ�ñ������ߺ���ȷ���Ϳ���ǽ�ı߽�
  //*��û���û��Ĳ���[�����û��Ľ���]


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
//	for (i = 0; i < 30; i++) //���Ʊ߽�
//		for (j = 0; j < 50; j++)
//		{
//			map[i][j] = '#';
//		}
//	for (i = 1; i < 29; i++) //���ƿ��ƶ���λ��
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
//	// TODO: �����п��ܽ�ʳ������������
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






