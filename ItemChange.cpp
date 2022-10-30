// 在疫情期间，各个小区居民发挥互助精神，进行物品交换，互通有无。
// 本程序允许添加物品的信息，删除物品的信息，显示物品列表，也允许查找物品的信息。
// 作者：杨桦
// 学号：520021910227

#include "ItemChange.h"

int main()
{
    cout<<"欢迎使用“你帮我助”疫情物品交换软件！\n"<<endl;
    cout<<"输入数字选择功能："<<endl;
    cout<<"1-放入物品"<<endl;
    cout<<"2-显示物品列表"<<endl;
    cout<<"3-查找物品"<<endl;
    cout<<"4-退出系统\n"<<endl;

    int command=0; //用户输入的指令
    itemstr item[500]; //结构体数组储存物品数据
    int num=0; //库中物品数量

    while(true){
        cin>>command;
        switch(command){
            case 1: //放入物品
                addItem(item, num);
                num++;
                break;
            case 2: //显示物品列表
                listItem(item, num);
                break;
            case 3: //查找物品//若存在则可取出
            {
                int itemNum = searchItem(item, num);
                if(itemNum!=-1){
                    cout<<"是否需要取出物品？(y/n)"<<endl;
                    string flag; //记录用户选择
                    cin>>flag;
                    if(flag=="y"){
                        removeItem(item, itemNum, num);
                        num--;
                    }
                    else{
                        cout<<endl;
                    }
                }
                break;
            }
            case 4: return 0;
            default: cout<<"数字超出范围，请重新输入："<<endl;
        }
        cout<<"输入数字选择功能："<<endl;
    }

    return 0;
}