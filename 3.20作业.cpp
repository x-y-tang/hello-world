#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
class DateTime {
private:
  int year, month, day;
  int hour, minute, second;
public:
  DateTime();
  ~DateTime();
  void showTime();
  void showMoon();  //��ҵ������ǰ����ת��Ϊũ����ʾ���� 
};
int main() {
  DateTime dt;
  std::cout << &dt << std::endl;
  //std::cout << &dt1 << std::endl;
  dt.showTime();
  dt.showMoon();
  return 0;
}
DateTime::DateTime()
{
  year = 2020; month = 3; day = 20;
  hour = 11; minute = 27; second = 55;
}
DateTime::~DateTime() 
{
  //std::cout << this << " Go die, Ha~Ha~" << std::endl;
}
void DateTime::showTime()
{
    printf("��ǰʱ�䣺%d/%d/%d %d:%d:%d\n", year, month, day, hour, minute, second);
}
void DateTime::showMoon()
{
    int currentYear = this->year;
    int currentMonth = this->month;
    int currentDay = this->day;
    int nTheDate = 0;
    int nisEnd = 0, flag = 0, n = 0, k = 0, nBit = 0, i = 0;
    char m_Lunar[100] = {0}, m_LunarDay[50] = {0}, m_zodiak[50] = {0};
    /*�������*/
    const char *m_TianGan[] = {"��","��","��","��","��","��","��","��","��","��"};
    /*��֧����*/
    const char *m_DiZhi[] = {"��","��","��","î","��","��","��","δ","��","��","��","��"};
    /*��������*/
    const char *m_ShuXiang[] = {"��","ţ","��","��","��","��","��","��","��","��","��","��"};
    /*ũ��������*/
    const char *m_DayName[] = {"*","��һ","����","����","����","����",
          "����","����","����","����","��ʮ",
          "ʮһ","ʮ��","ʮ��","ʮ��","ʮ��",
          "ʮ��","ʮ��","ʮ��","ʮ��","��ʮ",
          "إһ","إ��","إ��","إ��","إ��",
          "إ��","إ��","إ��","إ��","��ʮ"};
     /*ũ���·���*/
    const char *m_MonthName[] = {"*","��","��","��","��","��","��","��","��","��","ʮ","ʮһ","��"};
    /*����ÿ��ǰ�������*/
    const int m_DayAdd[12] = {0,31,59,90,120,151,181,212,243,273,304,334};
    /*ũ������*/
    const int m_LunarData[100]= {2635,333387,1701,1748,267701,694,2391,133423,1175,396438
                                 ,3402,3749,331177,1453,694,201326,2350,465197,3221,3402
                                 ,400202,2901,1386,267611,605,2349,137515,2709,464533,1738
                                 ,2901,330421,1242,2651,199255,1323,529706,3733,1706,398762
                                 ,2741,1206,267438,2647,1318,204070,3477,461653,1386,2413
                                 ,330077,1197,2637,268877,3365,531109,2900,2922,398042,2395
                                 ,1179,267415,2635,661067,1701,1748,398772,2742,2391,330031
                                 ,1175,1611,200010,3749,527717,1452,2742,332397,2350,3222
                                 ,268949,3402,3493,133973,1386,464219,605,2349,334123,2709
                                 ,2890,267946,2773,592565,1210,2651,395863,1323,2707,265877};
    /*---���㵽��ʼʱ��1921��2��8�յ�������1921-2-8(���³�һ)---*/
    nTheDate = (currentYear - 1921) *365 + (currentYear - 1921)/4  + m_DayAdd[currentMonth - 1] + currentDay - 31 - 7;
    if((!(currentYear % 4)) && (currentMonth > 2))
        nTheDate = nTheDate + 1;
    /*--����ũ����ɡ���֧���¡���---*/
    nisEnd = 0;
    flag = 0;
    while (nisEnd != 1) {
        if (m_LunarData[flag] < 4095)  k = 11;
        else  k = 12;
        n = k;
        while (n >= 0) {
             //m_LunarData(flag)�ĵ�n��������λ��ֵ
            nBit = m_LunarData[flag];
            for (i = 1; i < n + 1; i++)  nBit = nBit / 2;
            nBit = nBit % 2;
            if (nTheDate <= (29 + nBit)) {
                nisEnd = 1;
                break;
            }
            nTheDate = nTheDate - 29 - nBit;
            n = n - 1;
        }
        if (nisEnd)  break;
        flag = flag + 1;
    }
    currentYear = 1921 + flag;
    currentMonth = k - n + 1;
    currentDay = nTheDate;
    if (k == 12) {
        if (currentMonth == m_LunarData[flag] / 65536 + 1)  currentMonth = 1 - currentMonth;
        else if (currentMonth > m_LunarData[flag] / 65536 + 1)  currentMonth = currentMonth - 1;
    }
    /*--����ũ����ɡ���֧������*/
    sprintf(m_zodiak, "%s", m_ShuXiang[((currentYear - 4) % 60) % 12]);
    sprintf(m_Lunar, "%s%s�� ��%s�꡿", m_TianGan[((currentYear - 4) % 60) % 10], m_DiZhi[((currentYear - 4) % 60) % 12], m_zodiak);
    /*--����ũ���¡���*/
    if (currentMonth < 1)
        sprintf(m_LunarDay ,"��%s", m_MonthName[-1 * currentMonth]);
    else
        strcpy(m_LunarDay, m_MonthName[currentMonth]);
    strcat(m_LunarDay,"��");
    strcat(m_LunarDay, m_DayName[currentDay]);
    printf("%s",m_Lunar);
    printf("%s",m_LunarDay);
    printf("   %d:%d:%d\n", this->hour, this->minute, this->second);
}

