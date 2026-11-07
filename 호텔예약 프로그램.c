#include <stdio.h> 
#include <string.h>
#include <windows.h>

int answer; 
char id[20], password[20], id_ok, password_ok, pwok[];
static int roomok1 = 0, roomok2 = 0, roomok3 = 0, price = 55, w, a1, a2, a3;

int main(){   
	system("title 호텔 예약 프로그램"); 
	system("color 8f");	
	printf("\n\n안녕하십니까?");
	Sleep(800);
	printf("\n\n세광호텔에 오신것을 환영합니다!!! ");
	Sleep(800);
	system("cls");
	Sleep(200);
	start();
}

int start(){
	system("color 70");
	printf("\n");
	printf("    ■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
	printf("    ■                                                ■\n");
	printf("    ■      ■  ■   ■■   ■■■  ■■■  ■        ■\n");
	printf("    ■      ■  ■  ■  ■    ■    ■      ■        ■\n");
	printf("    ■      ■■■  ■  ■    ■    ■■■  ■        ■\n");
	printf("    ■      ■  ■  ■  ■    ■    ■      ■        ■\n");
	printf("    ■      ■  ■   ■■     ■    ■■■  ■■■    ■\n"); 
	printf("    ■                                                ■\n"); 
	printf("    ■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
	printf("    ■                                                ■\n");
	printf("    ■    호텔을 예약하시려면 로그인을 해야합니다.    ■\n");
	printf("    ■                                                ■\n");
	printf("    ■                                                ■\n");
	printf("    ■            [   로그인 하기  = 1  ]             ■\n");
	printf("    ■                                                ■\n");
	printf("    ■            [  프로그램 종료 = 2  ]             ■\n");
	printf("    ■                                                ■\n");
	printf("       숫자를 입력하세요  >>> ");
	scanf("%d", &answer);
	if(answer == 1){
		system("cls");
		login();
	} else if(answer == 2){
		system("title 호텔 예약 프로그램 [종료]");
		system("cls");
		printf("\n\n[호텔 예약 프로그램이 종료되었습니다.]\n\n");
		return 0;
	} else {
		system("cls");
		start();
	}
}

int login(){
	system("title 호텔 예약 프로그램 [로그인]");
	printf("\n\n                         [       로그인       ]");
	printf("\n\n                   비밀번호는 꼭 기억하세요!!!");
	printf("\n\n\n       아이디를 입력하세요(20자 이내) >>> ");
	scanf("%s", id);
	printf("\n\n     비밀번호를 입력하세요(20자 이내) >>> ");
	scanf("%s", password);
	id_ok=strlen(id);
	password_ok=strlen(password);
	if(id_ok>20 || password_ok>20){
		system("cls");
		login();
	} else {
		system("cls");
		hotelmain();
	} 
} 

int hotelmain(){   
	system("title 호텔 예약 프로그램");
	int firstroom = 901, limits = 910, lastroom = 909, floor = 9, room;
	int num = 0, i, answer1, search = 0, roomnum;
	static int allroom[80], roomnum1, roomnum2, roomnum3, score = 1;  
	printf("    %s님, 반갑습니다.  방은 최대 3개까지 예약가능합니다.\n\n", id);
	printf("    ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
	printf("    ■                                         영재호텔 방 현황               □: 예약가능  ■: 예약불가  ■\n");
	printf("    ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
	printf("    ■                                                                                                    ■");
	while(floor>0) {
		printf("\n    ■  %d층  : ", floor);
		for(room = firstroom; room < limits; room++){
			printf("  %d호 ", room);
			if(room == roomnum1){
				printf("■");
			} else if(room == roomnum2){
				printf("■");
			} else if(room == roomnum3){
				printf("■");
			} else {
				printf("□");
			}
			
			allroom[num] = room;
			num++;
			
			if(room == lastroom){  
				printf(" ■\n    ■                                                                                                    ■");
				firstroom = firstroom-100;
				limits = limits-100;
				lastroom = lastroom-100;
			}
		}
		floor--; 
	}
	printf("\n    ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n\n");
	printf("      예약하실 방의 호수를 입력하세요(ex:101)  >>> ");
	scanf("%d", &roomnum);
	for (i = 0; i < 81; i++){
		if(roomnum == allroom[i]){
			search = 1;	
			break;
		}
	}	
	if(roomnum == roomnum1||roomnum2||roomnum3) {
		printf("\n     이 방은 이미 예약을 완료했습니다."); 
		Sleep(1000);	
		hotelchange();
	}
	if(search == 1){
		printf("\n   %d호를 예약하시겠습니까? (예:1 , 아니오:2) >>> ", roomnum);
		scanf("%d", &answer1);
		if(answer1 == 1) {
			hotel1(); 
			if(score == 1){
				roomnum1 = roomnum;
				roomok1 = roomnum;
				score++;
				hotel2();
			} else if(score == 2) {
				roomnum2 = roomnum;
				roomok2 = roomnum;
				score++;
				hotel2();
			} else if(score == 3) {
				roomnum3 = roomnum;
				roomok3 = roomnum;
				score++;
				hotel2();
			} else {
				hotel3();
				return 0;
			} 
		} else if(answer1 == 2) {
			hotelchange(); 	
		} else {
		hotelchange();	
		}
	} else {
		hotelchange();	
	}
}

int hotelchange(){
	system("cls");
	hotelmain();
}

int hotel1(){ 
	system("cls");
	printf("\n\n                         [     비밀번호 확인     ]");
	printf("\n\n    설정했던 비밀번호를 입력하세요 >>> ");
	scanf("%s", pwok);
	if(strcmp(password, pwok) == 0) {
		printf("\n\n\n  비밀번호 확인이 완료되었습니다.", password, pwok);
		Sleep(1000);
		system("cls");
	}
    else{
    	printf("\n\n\n  비밀번호가 틀립니다. 다시 예약해 주세요.", password, pwok);
    	Sleep(1000);
    	system("cls");
    	hotelmain();
	}
}

int hotel2(){   
	char answer2;
	system("cls");
	printf("\n\n[방을 더 예약하시겠습니까?]\n\n");
	printf("예:y, 아니오:n  >>> "); 
	scanf("%c", &answer2); 
	switch(answer2){
		case 'y':
			hotelchange();
		case 'n':
			hotel3();
			return 0;
		default:
			hotel2();
	}
}

int hotel3(){   
	system("title 호텔 예약 프로그램 [정산]");
	system("cls");
	printf("\n\n[ %s님의 예약이 완료되었습니다. ]\n\n", id);
 	Sleep(1000);
	system("cls");
	printf("     〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓   \n\n");
	printf("      예약하신 방은 다음과 같습니다.  \n\n");
	printf("     〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓   \n\n");
	w = roomok1;
	hotelpriceset();
	printf("             %d호 ▶ %d $         \n\n", roomok1, price);
	a1 = price;
	w = roomok2;
	hotelpriceset();
	printf("             %d호 ▶ %d $         \n\n", roomok2, price);
	a2 = price;
	w = roomok3;
	hotelpriceset();
	printf("             %d호 ▶ %d $         \n\n", roomok3, price);
	a3 = price;
	printf("     〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓 \n\n");
	printf("       정산금액 ▶ %d $            \n\n", a1 + a2 + a3);
	printf("     〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓\n\n\n\n");
	printf("   저희 영재호텔을 이용해 주셔서 감사합니다.\n\n");
	printf("   아무 키를 누르시면 프로그램이 종료됩니다...");
	getch();
	system("exit");
	return 0;
}

int hotelpriceset(){
	if(w == 0) price = 0;
	else if(w < 400) price = 60;
	else if(w < 700) price = 120;
	else if(w < 1000) price = 180;
}

