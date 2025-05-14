#include <stdio.h>
 
 
void battle();//戦闘画面
void enter();
void detamy();
void detaenemy();
void myact();
 
int myhp = 30;
int mymp = 5;
int myattack = 2;
int myspeed = 1;
 
typedef struct {
	char name[20];
	int hp;
	int attack;
	int speed;
}enemy;
 
enemy level[4] = {
	{"スライム",5,1,0},//naem,hp,attack,speed
	{ "ゴブリン",12,2,3 },
	{"トロール",20,4,2 },
	{"ボスドラゴン",30,7,2 },
};
 
int starthp[4] = { 5,12,20,30 };
 
int count = 0;
int act;
int magic;
int escape = 0;
 
void enter() {
	while (getchar() != '\n') {
		puts("エンターキーを押してってば！");
		while (getchar() != '\n');
	}
}
 
int main(void)
{
	puts("-----------");
	puts("ゲーム開始");
	puts("-----------");
	puts("エンターキーを押して下さい。");
	enter();
	battle();
	return 0;
}
 
 
void detamy() {
	puts("\n-＜主人公＞-");
	printf(" HP: %d / 30\n MP : %d\n 攻撃力 : %d\n すばやさ : %d\n------------\n\n", myhp, mymp, myattack, myspeed);
}
 
void detaenemy() {
	printf("\n-＜%s＞-", level[count].name);
	printf("\n HP: %d / %d\n 攻撃力 : %d\n すばやさ : %d\n--------------\n", level[count].hp, starthp[count], level[count].attack, level[count].speed);
}
 
 
void battle() {
 
	printf("\n\n\n\n\n＿人人人人人人人人人人人人＿\n＞  %sが現れた！　＜\n￣Y^Y^Y^Y^Y^Y^Y^Y^Y^Y^Y^Y^￣\n\n\n\n", level[count].name);
	detamy();
	detaenemy();
	enter();
 
	while (escape == 0) {
 
		if (myspeed >= level[count].speed) {
			myact();
			if (level[count].hp <= 0) {
				printf("\n%sをたおした！\n", level[count].name);
				enter();
 
				if (count == 3) {
					puts("\n\n\n！すべてのモンスターがたおされました！\n");
					puts("　　　 ～ ゲームクリア ～\n\n\n");
					enter();
					enter();
					escape = 1;
					if (escape == 1) {
						break;
					}
				}
				else {
					//そのまま続行
				}
 
				puts("報酬としてMPの上限があがりました");
				mymp = 5 + 5 * (count + 1);
				printf("MP:%d→%d\n", mymp - 5, mymp);
				puts("MPが全回復しました");
				puts("呪文のレベルが上がりました");
 
 
				enter();
				count++;
				battle();
			}
			else {
				//そのまま続行
			}
			if (escape == 1) {
				break;
			}
			else {
				//そのまま続行
			}
 
			printf("\n\n\n\n！！！%sの攻撃！！！\n", level[count].name);
			myhp = myhp - level[count].attack;
			enter();
 
			printf("\n┌────────────────────────┐\n│　 主人公のHPが%d減った　│\n└────────────────────────┘\n", level[count].attack);
 
			if (myhp <= 0) {
				detamy();
				puts("\n\n\n   ゲームオーバー\n\n\n");
				enter();
				enter();
				escape = 1;
				if (escape == 1) {
					break;
				}
			}
			else {
				detamy();
				enter();
			}
		}
		else {
			printf("\n\n\n\n！！！%sの攻撃！！！\n", level[count].name);
			myhp = myhp - level[count].attack;
			enter();
 
			printf("\n┌────────────────────────┐\n│ 　主人公のHPが%d減った　│\n└────────────────────────┘\n", level[count].attack);
 
			if (myhp <= 0) {
				detamy();
				puts("\n\n\n   ゲームオーバー\n\n\n");
				enter();
				enter();
				escape = 1;
				if (escape == 1) {
					break;
				}
			}
			else {
				detamy();
				enter();
			}
 
			myact();
			if (level[count].hp <= 0) {
				printf("\n%sをたおした！\n", level[count].name);
				enter();
 
				if (count == 3) {
					puts("\n\n\n！すべてのモンスターがたおされました！\n");
					puts("　　　 ～ ゲームクリア ～\n\n\n");
					enter();
					enter();
					escape = 1;
					if (escape == 1) {
						break;
					}
				}
				else {
					//そのまま続行
				}
 
				puts("報酬としてMPの上限があがりました");
				mymp = 5 + 5 * (count + 1);
				printf("MP:%d→%d\n", mymp - 5, mymp);
				puts("MPが全回復しました");
				puts("呪文のレベルが上がりました");
				enter();
 
				count++;
				battle();
			}
			else {
				//そのまま続行
			}
		}
		if (escape == 1) {
			break;
		}
		else {
			//そのまま続行
		}
 
 
	}
 
 
}
 
void myact() {
	puts("\n\n\n\n！！！プレイヤーの攻撃！！！\n");
	puts("\n1.たたく\n2.呪文\n3.逃げる\n\n数字を入力してください>>");
	scanf_s("%d", &act);
 
	if (act == 1) {
		level[count].hp = level[count].hp - myattack;
		printf("\n┌────────────────────────┐\n  %sのHPが%d減った \n└────────────────────────┘\n", level[count].name, myattack);
		enter();
		detaenemy();
		enter();
	}
	else if (act == 2) {
		if (mymp == 0) {
			puts("\nMPがないので使えません");
			enter();
			puts("選択しなおしてください");
			enter();
			myact();
 
		}
		else {
			printf("\n\n1.HP回復（HP＋%d,MP－%d）\n2.すばやさUP（すばやさ＋2,MP－2）\n3.攻撃力UP（攻撃力＋2,MP－2）\n4.攻撃呪文（ダメージ%d,MP→0）\n", 3 + 2 * count, 3 + 2 * count, mymp);
			puts("\n数字を入力してください>>");
			scanf_s("%d", &magic);
			if (magic == 1) {
				if (mymp < 3 + 2 * count) {
					puts("MPが足りません\n選択しなおしてください");
					enter();
					enter();
					myact();
				}
				else {
					myhp += 3 + 2 * count;
					mymp -= 3 + 2 * count;
					printf("\n┌──────────────────┐\n│ 　HPが%d回復した　│\n└──────────────────┘\n", 3 + 2 * count);
					enter();
					detamy();
				}
 
			}
			else if (magic == 2) {
				if (mymp < 2) {
					puts("MPが足りません\n選択しなおしてください");
					enter();
					enter();
					myact();
				}
				else {
					myspeed += 2;
					mymp -= 2;
					puts("\n┌────────────────────────┐\n│ 　すばやさが2上昇した　│\n└────────────────────────┘\n");
					enter();
					detamy();
				}
 
			}
			else if (magic == 3) {
				if (mymp < 2) {
					puts("MPが足りません\n選択しなおしてください");
					enter();
					enter();
					myact();
				}
				else {
					myattack += 2;
					mymp -= 2;
					puts("\n┌──────────────────────┐\n│ 　攻撃力が2上昇した　│\n└──────────────────────┘\n");
					enter();
					detamy();
				}
 
			}
			else if (magic == 4) {
				printf("\n┌───────────────────────────┐\n  %sのHPが%d減った \n└───────────────────────────┘\n", level[count].name, mymp);
				level[count].hp -= mymp;
				mymp = 0;
				enter();
				detaenemy();
			}
			else {
				puts("そんな選択肢はないよ！");
				enter();
				enter();
				myact();
			}
		}
 
 
	}
	else if (act == 3) { //逃げる
		int select = 0;
		puts("\n\n本当に逃げますか？(逃げるとプログラムが終了します)");
		puts("\n1.YES\n2.NO");
		puts("数字を入力してください>>");
		scanf_s("%d", &select);
 
		if (select == 1) {
			puts("\n┌─────────────────────────────┐\n│　うまく逃げることができた！ │\n│ 戦闘はまだ早かったみたいだ… │\n│　 　 鍛錬を積もう！！！ 　　│\n└─────────────────────────────┘");
			enter();
			enter();
			enter();
			escape = 1;
		}
		else if (select == 2) {
			myact();
		}
		else {
			puts("1,2のどっちかを入力してよ！");
			enter();
			enter();
			myact();
		}
 
	}
	else {
		puts("1,2,3のどれかを入力してよ！");
		enter();
		enter();
		myact();
	}
}