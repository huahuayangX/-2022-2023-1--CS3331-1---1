#ifndef _ItemChange_h
#define _ItemChange_h
#endif

#include <string>
#include <iostream>
using namespace std;

// 定义存储物品的结构体
struct itemstr{
    string itemName; //物品名称
    string owner; //物品主人姓名
    string contact; //物品主人联系方式
};

// 放入物品函数
// item:存储物品数据的结构体数组
// num:库中物品数量
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

// 取出物品函数
// item:存储物品数据的结构体数组
// itemNum:所要取出物品的编号
// num:库中物品数量
void removeItem(itemstr *item, int itemNum, int num){
    for(int i=itemNum;i<num;i++){
        item[i].itemName = item[i+1].itemName;
        item[i].owner = item[i+1].owner;
        item[i].contact = item[i+1].contact;
    }
    cout<<"物品已取出\n"<<endl;
}

// 查找物品函数
// item:存储物品数据的结构体数组
// num:库中物品数量
int searchItem(itemstr *item, int num){
    cout<<"请输入查找物品的名称："<<endl;
    string name;
    cin>>name;
    cout<<"请输入物品主人的姓名："<<endl;
    string ownerName;
    cin>>ownerName;

    int i=0;
    while(true){
        // 顺序遍历查找
        if(item[i].itemName==name && item[i].owner==ownerName){
            cout<<"查找到物品：\n"<<item[i].itemName<<"\t"<<item[i].owner<<"\t"<<item[i].contact<<endl;
            return i;
        }
        i++;
        // 若库中已遍历完成仍未找到物品则返回-1
        if(i>=num){
            cout<<"未查找到该物品信息\n"<<endl;
            return -1;
        }
    }


}

// 显示物品列表函数
// item:存储物品数据的结构体数组
// num:库中物品数量
void listItem(itemstr *item, int num){
    cout<<"物品名称\t"<<"物品主人\t"<<"联系方式"<<endl;
    for(int i=0;i<num;i++){
        cout<<item[i].itemName<<"\t"<<item[i].owner<<"\t"<<item[i].contact<<endl;
    }
    cout<<endl;
}