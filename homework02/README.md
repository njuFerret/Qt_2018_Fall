## 作业：homework02 

实验任务：

一组学生成绩数据如下所示，编写一个控制台应用程序，可以将下列数据分别以姓名、课程1、课程2、课程3排序并按照示例格式输出。

表1.示例数据表

| 学号     |姓名  |课程1|课程2|课程3|
|:--------:|:----:|:---:|:---:|:---:|
|1403880031|阮小七|79   |91   |78   |
|1403880026|李俊  |89   |80   |91   |
|1403880014|武松  |88   |84   |82   |
|1403880042|韩滔  |77   |93   |81   |
|...       |...   |...  |...  |...  |


示例输出如下所示：

``` bash

排序后输出，当前排序第 1 列：
学号            姓名            课程1   课程2   课程3   
1403880014      武松            88      84      82      
1403880026      李俊            89      80      91      
1403880031      阮小七          79      91      78      
1403880042      韩滔            77      93      81      
------------------------------------------------
排序后输出，当前排序第 2 列：
学号            姓名            课程1   课程2   课程3  
1403880026      李俊            89      80      91     
1403880014      武松            88      84      82      
1403880031      阮小七          79      91      78      
1403880042      韩滔            77      93      81    
------------------------------------------------
排序后输出，当前排序第 3 列：
学号            姓名            课程1   课程2   课程3  
1403880026      李俊            89      80      91      
1403880014      武松            88      84      82      
1403880031      阮小七          79      91      78      
1403880042      韩滔            77      93      81    
------------------------------------------------
...
```
作业2：

截止时间：**2018年10月18日中午12:00**

设成绩数据保存于以空格为分隔符的数据文件中，数据格式如上表1所示。前两列为固定列，
第1列为学号，第2列为姓名。第3~N列为课程成绩列，数据行数、列数不定。
数据总列数小于16列。

1. 设数据文件名为data.txt(请在此下载：[https://github.com/njuFerret/Qt_2018_Fall/raw/master/homework02/data.txt]( https://github.com/njuFerret/Qt_2018_Fall/raw/master/homework02/data.txt ))，请从数据文件导入数据后实现实验一任务；
2. 排序后的数据以文本文件(UTF-8编码)形式保存，文件名为sorted_data.txt，保存格式同示例输出。
3. 请编写实现类，实现如下方式调用。
4. (附加题）每位同学的成绩添加一列平均分，根据前面的课程，求出其平均分后，进行排序

```cpp

#include <QDebug>
#include <QVector>
#include <QTextStream>
#include <QFile>

namespace SK {
enum SortKind{
    col01    =   0x00000001<<0,         //!< 第1列
    col02    =   0x00000001<<1,         //!< 第2列
    col03    =   0x00000001<<2,         //!< 第3列
    col04    =   0x00000001<<3,         //!< 第4列
    col05    =   0x00000001<<4,         //!< 第5列
    col06    =   0x00000001<<5,         //!< 第6列
    col07    =   0x00000001<<6,         //!< 第7列
    col08    =   0x00000001<<7,         //!< 第8列
    col09    =   0x00000001<<8,         //!< 第9列
    col10    =   0x00000001<<9,         //!< 第10列
    col11    =   0x00000001<<10,        //!< 第11列
    col12    =   0x00000001<<11,        //!< 第12列
    col13    =   0x00000001<<12,        //!< 第13列
    col14    =   0x00000001<<13,        //!< 第14列
    col15    =   0x00000001<<14,        //!< 第15列
    col16    =   0x00000001<<15,        //!< 第16列
    col17    =   0x00000001<<16,        //!< 第17列
    col18    =   0x00000001<<17,        //!< 第18列
    col19    =   0x00000001<<18,        //!< 第19列
    col20    =   0x00000001<<19,        //!< 第20列
    col21    =   0x00000001<<20,        //!< 第21列
    col22    =   0x00000001<<21,        //!< 第22列
    col23    =   0x00000001<<22,        //!< 第23列
    col24    =   0x00000001<<23,        //!< 第24列
    col25    =   0x00000001<<24,        //!< 第25列
    col26    =   0x00000001<<25,        //!< 第26列
    col27    =   0x00000001<<26,        //!< 第27列
    col28    =   0x00000001<<27,        //!< 第28列
    col29    =   0x00000001<<28,        //!< 第29列
    col30    =   0x00000001<<29,        //!< 第30列
    col31    =   0x00000001<<30,        //!< 第31列
    col32    =   0x00000001<<31,        //!< 第32列
};
}


typedef struct{
    // 请补全结构定义
} studData;

QDebug operator<< (QDebug d, const studData &data) {
    // 请补全运算符重载函数，使其可以直接输出studData结构
    return d;
}

// 比较类，用于std::sort第三个参数
class myCmp {
public:
    myCmp(int selectedColumn) { this->currentColumn = selectedColumn; }
    bool operator() (const studData& d1,const studData& d2);
private:
    int currentColumn;
};

bool myCmp::operator()(const studData &d1, const studData &d2)
{
    bool result = false;
    quint32 sortedColumn = 0x00000001<<currentColumn;
    switch (sortedColumn) {
    case SK::col01:
    // ...
    // 请补全运算符重载函数
    // ...
    //
    }
    return result;

}


class ScoreSorter
{
public:
    ScoreSorter(QString dataFile);
    // ...
    // 请补全该类，使其实现上述要求
    // ...    
}

// 请补全
ScoreSorter::ScoreSorter(QString dataFile){
}


void myMessageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    // 自定义qDebug
}

int main()
{
    qInstallMessageHandler(myMessageOutput);
    QString datafile = "data.txt";

    // 如果排序后文件已存在，则删除之
    QFile f("sorted_"+datafile);
    if (f.exists()){
        f.remove();
    }

    ScoreSorter s(datafile); 
    s.readFile(); 
    s.doSort();
    return 0;
}
```
