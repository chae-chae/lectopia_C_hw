#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning (disable: 4996)

#define TRUE 1
#define FALSE 0
#define RESIDENT_NUMBER_LENGTH  13 /* 주민등록번호 길이*/

int availabilityCheck(char *resident_number);
int checkLengthCharacter(char *resident_number);
int checkDate(char *resident_number);
int checkIdentification(char *resident_number);
int checkGender(char *resident_number);
int checkYear (int year);
int inputCheck(int *yp, int *mp, int *dp, int *gp);
int getDate(char *number);
int getGen(char *number);

int main()
{
    
    /* 테스트할 주민등록번호 저장 배열*/
    char resident_number[][20]={"0402291000008", "870401102321", "00031541949179",
        "0003154194917", "801203#201122", "7804155328845", "7804150328840",
        "9612241068382", "9902292194322", "0230174326176", "8811391042219",
        "8100122042213", "8112002042213", "9210101069415", "0802294012345",
        "8806311069417","8807311069418" };
    int i, count;
    /* 검사할 주민등록번호의 개수 계산*/
    count = sizeof(resident_number)/ sizeof(resident_number[0]);
    for(i=0; i<count; i++) /* 주민등록번호 유효성 검사를 반복적으로 수행 함*/
    {
        if(availabilityCheck(resident_number[i]) == TRUE)
        {
            printf("(+) 주민번호%s는(은) 유효한 번호입니다.\n", resident_number[i]);
        }
        else
        {
            printf("(-) 주민번호%s는(은) 유효하지 않은 번호입니다.\n", resident_number[i]);
        }
    }
    
    return 0;
}
/*----------------------------------------------------------------
 availabilityCheck()함수: 주민등록번호 유효성 검사 함수
 전달인자: 유효성 검사할 주민등록번호(문자열)
 리턴값: 유효하면TRUE, 유효하지 않으면FALSE 리턴
 ------------------------------------------------------------------*/
int availabilityCheck(char resident_number[]){
    int clc, cd, cg, ci;
    clc = checkLengthCharacter(resident_number);
    cd = checkDate(resident_number);
    cg = checkGender(resident_number);
    ci = checkIdentification(resident_number);
    if (clc && cd && cg && ci) {
        return TRUE;
    } else {
        return FALSE;
    }
}
/*-------------------------------------------------------------------------
 checkLengthCharacter()함수: 주민등록번호 길이 및 문자 유효성검사 함수
 전달인자: 검사할 주민등록번호(문자열)
 리턴값: 주민등록번호의 길이가 맞고 숫자문자로만 구성되어 있으면TRUE,
 길이가 짧거나 길고, 숫자 문자가 아닌 문자가 섞여 있으면FALSE 리턴
 --------------------------------------------------------------------------*/
int checkLengthCharacter(char *resident_number){//완료
    int len,i;
    len = (int)strlen(resident_number);
    if(len != RESIDENT_NUMBER_LENGTH) { return FALSE; }
    for(i = 0; i < len; i++){
        if(!(resident_number[i] >= '0' && resident_number[i] <='9')){
            return FALSE;
        }
    }
    return TRUE;
}
/*----------------------------------------------------------------
 checkDate()함수: 첫6자리(연,월,일)의 유효성 검사 함수
 전달인자: 유효성 검사할 주민등록번호(문자열)
 리턴값: 유효한 날짜이면TRUE, 유효하지 않은 날짜이면FALSE 리턴
 ------------------------------------------------------------------*/
int checkDate(char resident_number[]){
    //윤년 평년/ 일에 31,30,28,29
    //연도는 00~99 가능.
    //월은 12, 31;
    //0,1 / 2,3 / 4,5 전부 atoi 검사하면 될 것같음.
    int year, month, day, res, gen;
    year = getDate(resident_number);
    month = getDate(resident_number+2);
    day = getDate(resident_number+4);
    gen = getGen(resident_number+6);
    res = inputCheck(&year, &month, &day, &gen);
    if (res == FALSE) {
        return FALSE;
    } else {
    return TRUE;
    }
}
/*----------------------------------------------------------------------
 checkGender()함수: 7번째 자리의 성별식별번호 유효성 검사함수
 전달인자: 유효성 검사할 주민등록번호(문자열)
 리턴값: 성별식별번호가'1'~'4'이면TRUE, 그 외 숫자 문자이면FALSE 리턴
 -----------------------------------------------------------------------*/
int checkGender(char *resident_number){
    if(resident_number[6]>='1'&&resident_number[6]<='4'){
        return TRUE;
    }
    return FALSE;
}
/*------------------------------------------------------------------------
 checkIdentification()함수: 주민등록번호 끝자리(인식자) 유효성 검사 함수
 전달인자: 유효성 검사할 주민등록번호(문자열)
 리턴값: 유효한 인식자이면TRUE, 유효하지 않은 인식자이면 FALSE 리턴
 -------------------------------------------------------------------------*/
int checkIdentification(char *resident_number){
    int sum = 0;
    for(int i = 0; i < 12; i++){
        sum += resident_number[i]-'0';
    }
    if(sum%10 == resident_number[12]-'0'){
        return TRUE;
    }else{
        return FALSE;
    }
}
/*----------------------------------------------------------------
 checkYear ()함수: 년도의 윤,평년 여부 검사
 전달인자: 윤,평년 검사할 년도
 리턴값: 윤년이면 TRUE, 평년이면FALSE 리턴
 ------------------------------------------------------------------*/
int checkYear(int year){
    if (year%4 != 0){
        return FALSE; //0이면 평년
    } else if (year%100 != 0){
        return TRUE;
    } else if (year%400 == 0){
        return TRUE;
    } else {
        return FALSE;
    }
}
int inputCheck(int *yp, int *mp, int *dp, int *gp){
    int m;
    int endofmonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    m = *mp - 1;
    if (*gp == 1 || *gp == 2) { // 1.2면 1900년대사람
        *yp += 1900;
    } else {// 34면 2000년대사람
        *yp += 2000;
    }
//    printf("yp %d\n", *yp);
    if (*mp <= 0 || *dp <= 0) {
        return FALSE; //날짜가 0이나 음수면 틀림
    }
    if (*mp > 12) {
        return FALSE; // 13월이상 이면
    }
    if (*mp != 2) { //2월이 아니면
        if (*dp > endofmonth[m]) { //엔옵몬배열안에 각 달-1한 방번호에 최대일이 들어있음 그거랑 입력한 일이랑 비교해서 입력일이 더 크면
            return FALSE; // 잘못한거니까
        }
    }
    if (checkYear(*yp) == 1) { //윤년입력햇는데
        if (*mp == 2 && *dp > 29) { // 2월이면 날짜가 29일이 넘으면 잘못한거니까
            return FALSE;
        }
    }
    if (checkYear(*yp) == 0) { //평년입력햇는데
        if (*mp == 2 && *dp > 28) { //2월인데 날짜가 28일이 넘으면 잘못한거니까
            return FALSE;
        }
    }
    return TRUE; // - 제대로 됐다
}
int getDate(char *number){
    char temp[2];
    for(int i = 0; i < 2; i++){
        temp[i] = number[i];
    }
    return atoi(temp);
}
int getGen(char *number){
    char temp[1];
    for(int i = 0; i < 1; i++){
        temp[i] = number[i];
    }
    return atoi(temp);
}
