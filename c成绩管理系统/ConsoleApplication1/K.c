#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LEN 1000
void creat(int a);//���뺯��
void show(void);//��ʾѧ����Ϣ����
void average(void);//��ƽ��������
void print(void);//���۲���ĩ��߷�����ͷּ��䲻�����ѧ���ĺ���
void rank(void);//ѧ����������
void search(void);//ͨ��ѧ�Ų���ѧ���ĺ���
void revamp(void);//�޸�ѧ����Ϣ�ĺ���
void expurgate(void);//ɾ��ĳѧ����Ϣ�ĺ���
struct student
{
    int num;
    char name[15];
    double scoreMath;
    double scoreEnglish;
    double scoreComputer;
    double total;
};//����ѧ���ɼ���Ϣ�ṹ
struct student students[LEN];//ѧ���ṹ���飬���ڴ洢ѧ���ɼ���Ϣ
int i, r;
float a, b, c;//aΪ��ѧ�ɼ���ռ�ٷֱȣ�bΪӢ��ɼ���ռ�ȣ� cΪ������ɼ���ռ��
int much;//��ǰѧ������
void save()   //д���ļ�
{
    FILE* fp;
    int i;
    if ((fp = fopen("D:\\student.txt", "wb")) == NULL)
    {
        printf("cannot open file\n");
        return;
    }
    for (i = 0; i < much; i++)
        if (fwrite(&students[i], sizeof(struct student), 1, fp) != 1)
            printf("file write error\n");
    fclose(fp);
}

int main()
{  
    int mode;//Ϊ�����ģʽѡ��
	 system("color b1");
    printf("������ѧ��������");
   scanf_s("%d",&much);
	system("color f5");
    printf("��������ѧ�ɼ���ռ��a:");
    scanf_s("%f", &a);
    printf("������Ӣ��ɼ���ռ��b:");
    scanf_s("%f", &b);
    printf("�����������ɼ���ռ��c:");
    scanf_s("%f", &c);
	system("color a1");
    printf("ģʽ1������ѧ����Ϣ\n");
    printf("ģʽ2����ʾ����ѧ����ѧ�ţ����Ƴɼ��������ɼ�\n");
    printf("ģʽ3��������Ƴɼ�ƽ���ּ������ɼ�ƽ����\n");
    printf("ģʽ4����������ɼ������ʣ���߷֣���ͷ�\n");
    printf("ģʽ5������\n");
    printf("ģʽ6������\n");
    printf("ģʽ7���޸�\n");
    printf("ģʽ8��ɾ��\n");
    printf("���������ü���ģʽ\n");
    scanf_s("%d", &r);
	 printf("����ѡ��ģʽ1����ѧ����Ϣ\n");
    for (i = 0; i < r; i++)
    {
        printf("��ѡ��1~8������ģʽ\n");
       
        scanf_s("%d", &mode);
        switch (mode)
        {
        case 1:creat(much); save(); break;//save()��Ϊ�˰���Ϣ�����������ļ���
        case 2:show(); break;
        case 3:average(); break;
        case 4:print(); break;
        case 5:rank(); break;
        case 6:search(); break;
        case 7:revamp(); break;
        case 8:expurgate(); break;
        }
    }
    return 0;
}
void creat(int much)
{
    for (i = 0; i < much; i++)
    {  system("color d0");
        printf("������ѧ��ѧ��: ");
        scanf_s("%d", &students[i].num);
        printf("������ѧ��������");
        scanf_s("%s", students[i].name,sizeof(students[i].name));
        printf("��������ѧ�ɼ���");
        scanf_s("%lf", &students[i].scoreMath);
        printf("������Ӣ��ɼ���");
        scanf_s("%lf", &students[i].scoreEnglish);
        printf("�����������ɼ���");
        scanf_s("%lf", &students[i].scoreComputer);
        students[i].total =( a * students[i].scoreMath) + (b * students[i].scoreEnglish) + (c * students[i].scoreComputer);
    }
}
void show(void)
{
    int i;
    for (i = 0; i < much; i++)
    {   system("color b5");
        printf("ѧ�ţ�%d\n", students[i].num);
        printf("������%s\n", students[i].name);
        printf("��ѧ�ɼ���%lf\n", students[i].scoreMath);
        printf("Ӣ��ɼ���%lf\n", students[i].scoreEnglish);
        printf("������ɼ���%lf\n", students[i].scoreComputer);
        printf("�����ɼ���%lf\n", students[i].total);
    }
}
void average(void)
{
    int i;
    double m, n, q, u, sum, aver1, aver2, aver3, aver4;
    for (i = 0, sum = 0; i < much; i++)
    {
        m = students[i].scoreMath;
        sum = m + sum;
    }
    aver1 = sum / much;
	system("color e5");
    printf("��ѧƽ���֣�%lf\n", aver1);
    for (i = 0, sum = 0; i < much; i++)
    {
        n = students[i].scoreEnglish;
        sum = n + sum;
    }
    aver2 = sum / much;

    printf("Ӣ��ƽ���֣�%lf\n", aver2);
    for (i = 0, sum = 0; i < much; i++)
    {
        q = students[i].scoreComputer;
        sum = q + sum;
    }
    aver3 = sum / much;

    printf("�����ƽ���֣�%lf\n", aver3);
    for (i = 0, sum = 0; i < much; i++)
    {
        u = students[i].total;
        sum = u + sum;
    }
    aver4 = sum / much;

    printf("����ƽ���֣�%lf\n", aver4);
}
void print(void)
{
    int i, j, k,t=0;
    double temp;
   int last;
   system("color d3");
    for (i = 0; i < much; i++)
    {
        if (students[i].total < 72)//�����ɼ�δ�ﵽ72Ϊ������ 
            printf("������%lf\n", students[i].total);
        else t++;
    }
    if (t == much)printf("û�в�����ѧ��\n\n");
    for (i = 0; i < much - 1; i++)
    {
        k = i;
        for (j = i + 1; j < much; j++)
            if (students[j].total < students[k].total)
                k = j;
        temp = students[k].total;
        students[k].total = students[i].total;
        students[i].total = temp;
    }
	
     last = much - 1;
	
    printf("��߷�%lf\n", students[last].total);

    printf("��ͷ�%lf\n", students[0].total);
  
}
void rank(void)
{
    int i, k, j, m;
    double temp;
    char n= students[0].name[0];
	system("color f5");
    for (i = 0; i < much - 1; i++)
    {
        k = i;
        for (j = i + 1; j < much; j++)
        {
            if (students[j].total < students[k].total)
                k = j;
            temp = students[k].total;
            students[k].total = students[i].total;
            students[i].total = temp;
            m = students[k].num;
            students[k].num = students[i].num;
            students[i].num = m;
            students[k].num = students[i].num;
            for (j = 0; students[i].name[j] != '\0'; j++)
            {
                n = students[k].name[j];
                students[k].name[j] = students[i].name[j];
                students[i].name[j] = n;
            }
            students[i].name[j+1] = '\0';
        }
        }

    for (i = 0; i < much; i++)
    {
        printf("%d %s %lf\n", students[i].num, students[i].name, students[i].total);
    }
}
void search(void)
{
    int i, num;
   system("color b4");
    printf("��������ҵ�ѧ��ѧ�ţ�");
    scanf_s("%d", &num);
	system("color b3");
    printf("The information of the %d student are as follows\n", num);		
    for (i = 0; i < much; i++)
    {
        if (num == students[i].num)
        {
            printf("ѧ�ţ�%d\n������%s\n��ѧ�ɼ���%lf\nӢ��ɼ���%lf\n������ɼ���%lf\n�����ɼ���%lf\n", students[i].num, students[i].name, students[i].scoreMath, students[i].scoreEnglish, students[i].scoreComputer, students[i].total);
            break;
        }
    }
}
void revamp(void)
{
    int i, num, mode,t=0;
    double m;
		system("color e8");
    printf("��������Ҫ�޸ĵ�ѧ��ѧ�ţ�");
    scanf_s("%d", &num);
    for (i = 0; i < much; i++)
    {
        if (num == students[i].num)
        {
            t = i;
            break;
        }
    }
    printf("ģʽ1���޸���ѧ�ɼ�\n");
    printf("ģʽ2���޸�Ӣ��ɼ�\n");
    printf("ģʽ3���޸ļ�����ɼ�\n");
    printf("��ѡ��");
    scanf_s("%d", &mode);
    switch (mode)
    {
    case 1:printf("�޸���ѧ�ɼ�"); printf("�������޸ĳɼ�Ϊ:"); scanf_s("%lf", &m); students[t].scoreMath=m; break;
    case 2:printf("�޸�Ӣ��ɼ�"); printf("�������޸ĳɼ�Ϊ:"); scanf_s("%lf", &m); students[t].scoreEnglish = m; break;
    case 3:printf("�޸ļ�����ɼ�"); printf("�������޸ĳɼ�Ϊ:"); scanf_s("%lf", &m); students[t].scoreComputer = m; break;
    }
}
void expurgate(void)
{
    int i, num, t=0;
	system("color d3");
    printf("��������Ҫɾ����ѧ��ѧ�ţ�");
    scanf_s("%d", &num);
    for (i = 0; i < much; i++)
    {
        if (num == students[i].num)
        {
            t = i;
            break;
        }
    }

    for (; t< much; t++)
        students[t] = students[t + 1];
	printf("�޸ĺ�ѧ����Ϣ����:\n");
	much=much-1;
    for (i = 0; i < much; i++)
    {   system("color b5");
        printf("ѧ�ţ�%d\n", students[i].num);
        printf("������%s\n", students[i].name);
        printf("��ѧ�ɼ���%lf\n", students[i].scoreMath);
        printf("Ӣ��ɼ���%lf\n", students[i].scoreEnglish);
        printf("������ɼ���%lf\n", students[i].scoreComputer);
        printf("�����ɼ���%lf\n", students[i].total);
    }
}
