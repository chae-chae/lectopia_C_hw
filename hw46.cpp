#include <stdio.h>
#pragma warning (disable:4996)

int inputYMD(int *yp, int *mp, int *dp);
int yearCheck(int year);
int inputCheck(int *yp, int *mp, int *dp, int []);
int totalDay(int *yp, int *mp, int *dp, int endofmonth[]);

int main(void){
    int endofmonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int year, month, date;
    int again, check;
    int tot, whatday;

    while (1) { //입력함수에서 문자받으면 0 리턴하니까 0아닌동안 돌자
        again = inputYMD(&year, &month, &date); //첨 입력받아봄
        if (again == 0) {
            return 0; //문자받으면 메인종료
        }
        check = inputCheck(&year, &month, &date, endofmonth); //재입력할지 말지 결정
        if (check == 2){ //2는 재입력이니까 컨티뉴로 다시 와일처음으로 돌아가야함
            continue;
        }//여기까지 넘어왔으면 무사히 입력다된것. 이제 요일 구하면 됨
        tot = totalDay(&year, &month, &date, endofmonth);
        whatday = tot % 7;
        printf("%d년 %d월 %d일은 ", year, month, date);
        switch (whatday) {
            case 0:
                printf("일요일입니다.\n");
                break;
            case 1:
                printf("월요일입니다.\n");
                break;
            case 2:
                printf("화요일입니다.\n");
                break;
            case 3:
                printf("수요일입니다.\n");
                break;
            case 4:
                printf("목요일입니다.\n");
                break;
            case 5:
                printf("금요일입니다.\n");
                break;
            case 6:
                printf("토요일입니다.\n");
                break;
            default:
                break;
        }
    }
    return 0;
}
int inputYMD(int *yp, int *mp, int *dp){
    printf("* 년 월 일을 입력하시오 : ");
    scanf("%d %d %d", yp, mp, dp);
    if (getchar() != '\n'){
        return 0; //문자들어오면 0리턴함. 메인에서 0인지 확인해서 0이면 메인종료하게
    }
    return 1; //숫자 잘 들어왔으면 일단 1리턴해서 계속하게하고 인풋체크함수에서 그게 제대로된건지 검사
}
int yearCheck(int year){
    if (year%4 != 0){
        return 0; //0이면 평년
    } else if (year%100 != 0){
        return 1;
    } else if (year%400 == 0){
        return 1;
    } else {
        return 0;
    }
}
int inputCheck(int *yp, int *mp, int *dp, int endofmonth[]){
    int m;
    m = *mp - 1;
    
    if (*yp <= 1899 || *mp <= 0 || *dp <= 0) {
        return 2; //날짜가 0이나 음수면 2리턴 - 다시 입력하게 해야함.
    }
    if (*mp > 12) {
        return 2; // 13월이상 이면 2리턴 - 재입력
    }
    if (*mp != 2) { //2월이 아니면
        if (*dp > endofmonth[m]) { //엔옵몬배열안에 각 달-1한 방번호에 최대일이 들어있음 그거랑 입력한 일이랑 비교해서 입력일이 더 크면
            return 2; // 잘못한거니까 재입력 2리턴
        }
    }
    if (yearCheck(*yp) == 1) { //윤년입력햇는데
        if (*mp == 2 && *dp > 29) { // 2월이면 날짜가 29일이 넘으면 잘못한거니까
            return 2;// 재입력
        }
    }
    if (yearCheck(*yp) == 0) { //평년입력햇는데
        if (*mp == 2 && *dp > 28) { //2월인데 날짜가 28일이 넘으면 잘못한거니까
            return 2; //재입력
        }
    }
    return 3; // 3리턴 - 제대로 됐다
}
int totalDay(int *yp, int *mp, int *dp, int endofmonth[]){
    int tot = 0;
    int i;
    
    for (i = 1900; i<*yp; i++) { //입력받은 년도 -1 년까지니까
        if (yearCheck(i) == 0) {//평년이면
            tot += 365;
        } else {//윤년이면
            tot += 366;
        }
    }
    for (i = 1; i<*mp; i++) { //입력받은 월 -1월까지 여기서 30일잇는지 31일잇는지 엔옵몬으로?
        tot += endofmonth[i-1]; //엔옵몬은 0번방부터 1월 있음
    }
    for (i = 1; i<=*dp; i++) { // 일 더하는것. 1일부터 입력받은 일까지
        tot += 1;
    }
    if ((yearCheck(*yp) == 1) && (*mp >= 3)) { //입력한게 윤년이고 3월이상이면
        tot += 1;
    }
    return tot;
}
