#include<sys/types.h>
#include<sys/timeb.h>
// �����������Ӳ�����
unsigned int seed_generator() {
    unsigned int seed_val;
    struct _timeb timeBuf;
    // ������ǰʱ�䣬����timeBuf.time�С�// ��ǰʱ���ֵ��1970��1��1�տ�ʼ�������
    _ftime(&timeBuf);   //timeBuf.millitm�л������˵�ǰ��һ�����ȹ��ĺ�����

    // ��������������ӣ������������һ��������� &0xFFFFȡ��16λ
    seed_val = ((((unsigned int)timeBuf.time & 0xFFFF) +
                (unsigned int)timeBuf.millitm) ^
                (unsigned int)timeBuf.millitm);
    srand(seed_val);

    return seed_val;
}
