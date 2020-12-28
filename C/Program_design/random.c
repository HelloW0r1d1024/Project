#include<sys/types.h>
#include<sys/timeb.h>
// 重新生成种子并播种
unsigned int seed_generator() {
    unsigned int seed_val;
    struct _timeb timeBuf;
    // 检索当前时间，存入timeBuf.time中。// 当前时间的值从1970年1月1日开始以秒计算
    _ftime(&timeBuf);   //timeBuf.millitm中还存入了当前那一秒所度过的毫秒数

    // 毫秒数与秒数相加，再与毫秒数做一次异或运算 &0xFFFF取低16位
    seed_val = ((((unsigned int)timeBuf.time & 0xFFFF) +
                (unsigned int)timeBuf.millitm) ^
                (unsigned int)timeBuf.millitm);
    srand(seed_val);

    return seed_val;
}
