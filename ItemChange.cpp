#include "ItemChange.h"

int main()
{
    cout<<"欢迎使用“你帮我助”疫情物品交换软件！\n"<<endl;
    cout<<"输入数字选择功能："<<endl;
    cout<<"1-放入物品"<<endl;
    cout<<"2-显示物品列表"<<endl;
    cout<<"3-查找物品"<<endl;
    cout<<"4-退出系统\n"<<endl;

    int command=0;
    itemstr item[500];
    int num=0;

    while(true){
        cin>>command;
        switch(command){
            case 1:
                addItem(item, num);
                num++;
                break;
            case 2:
                listItem(item, num);
                break;
            case 3:
                int itemNum = searchItem(item, num);
                if(itemNum!=-1){
                    cout<<"是否需要取出物品？(y/n)"<<endl;
                    string flag;
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
            case 4: return 0;
            default: cout<<"数字超出范围，请重新输入："<<endl;
        }
        cout<<"输入数字选择功能："<<endl;
    }

    return 0;
}