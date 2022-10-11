#ifndef _ItemChange_h
#define _ItemChange_h
#endif

#include <string>
#include <iostream>
using namespace std;

struct itemstr{
    string itemName;
    string owner;
    string contact;
};

void addItem(itemstr *item, int num){
    cout<<"请输入放入物品的名称："<<endl;
    string name;
    cin>>name;
    cout<<"请输入物品主人的姓名："<<endl;
    string ownerName;
    cin>>ownerName;
    cout<<"请输入联系方式："<<endl;
    string contactWay;
    cin>>contactWay;

    item[num].itemName = name;
    item[num].owner = ownerName;
    item[num].contact = contactWay;
    cout<<"物品已成功添加\n"<<endl;
}

void removeItem(itemstr *item, int itemNum, int num){
    for(int i=itemNum;i<num;i++){
        item[i].itemName = item[i+1].itemName;
        item[i].owner = item[i+1].owner;
        item[i].contact = item[i+1].contact;
    }
    cout<<"物品已取出\n"<<endl;
}

int searchItem(itemstr *item, int num){
    cout<<"请输入查找物品的名称："<<endl;
    string name;
    cin>>name;
    cout<<"请输入物品主人的姓名："<<endl;
    string ownerName;
    cin>>ownerName;

    int i=0;
    while(true){
        if(item[i].itemName==name && item[i].owner==ownerName){
            cout<<"查找到物品：\n"<<item[i].itemName<<"\t"<<item[i].owner<<"\t"<<item[i].contact<<endl;
            return i;
        }
        i++;
        if(i>=num){
            cout<<"未查找到该物品信息\n"<<endl;
            return -1;
        }
    }


}

void listItem(itemstr *item, int num){
    cout<<"物品名称\t"<<"物品主人\t"<<"联系方式"<<endl;
    for(int i=0;i<num;i++){
        cout<<item[i].itemName<<"\t"<<item[i].owner<<"\t"<<item[i].contact<<endl;
    }
    cout<<endl;
}