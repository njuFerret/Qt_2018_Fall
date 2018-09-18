#include<QCoreApplication>
#include<QDebug>
#include<QList>
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
typedef quint32 doubleword;
typedef quint8 byte;
#define HHI(xxx) ((byte) ((doubleword)(xxx) >> 24))
#define LHI(xxx) ((byte) (((doubleword)(xxx) >>16)&255))
#define HLO(xxx) ((byte) (((doubleword)(xxx) >>8)&255))
#define LLO(xxx) ((byte) ((doubleword)(xxx) & 255))
int main(int argc,char *argv[])
{
    qint32 i=0x12345678,j;
    qDebug()<<"原始值:"<<QString("0x%1").arg(i,0,16,QLatin1Char(' '))<<"=="<<i;
    qDebug()<<QString("0x%1").arg(HHI(i),0,16,QLatin1Char(' '))<<"=="<<HHI(i);    //输出最高8位
    qDebug()<<QString("0x%1").arg(LHI(i),0,16,QLatin1Char(' '))<<"=="<<LHI(i);    //输出次高8位
    qDebug()<<QString("0x%1").arg(HLO(i),0,16,QLatin1Char(' '))<<"=="<<HLO(i);    //输出次低8位
    qDebug()<<QString("0x%1").arg(LLO(i),0,16,QLatin1Char(' '))<<"=="<<LLO(i);    //输出最低8位
    QList<quint8> values;
    values <<HHI(i)<<LHI(i)<<HLO(i)<<LLO(i);                                      //将结果存入QList<quint8>对象values中
    qDebug()<<"最高8位和次高8位的最大值:"<<MAX(QString("0x%1").arg(HHI(i),0,16,QLatin1Char(' ')),QString("0x%1").arg(LHI(i),0,16,QLatin1Char(' ')))<<MAX(HHI(i),LHI(i));
    qDebug()<<"次低8位和最低8位的最小值:"<<MIN(QString("0x%1").arg(HLO(i),0,16,QLatin1Char(' ')),QString("0x%1").arg(LLO(i),0,16,QLatin1Char(' ')))<<MIN(HLO(i),LLO(i));
    j=(HHI(i)<<16)+LHI(i)+(HLO(i)<<24)+(LLO(i)<<8);
    qDebug()<<"重新组合后数值:"<<QString("0x%1").arg(j,0,16,QLatin1Char(' '))<<"=="<<j;
    qDebug()<<"排序前为:"<<values;                                                 //将values中的数字输出
    std::sort(values.begin(),values.end(),std::greater<quint8>());                //将values中的数字按从大到小排序
    qDebug()<<"排序后为:"<<values;


}
