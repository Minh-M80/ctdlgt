#include<bits/stdc++.h>


void hienThiVaTinhTong(Queue &q){
    Data sum;
    sum.thuc=0;
    sum.ao=0;
    int i=1;
    while(!isEmpty(q)){
        Data sp;
        deQueue(q,sp);
        cout<<"So phuc"<<i<<":";
        printData(sp);
        sum.thuc +=sp.thuc;
        sum.ao+=sp.ao;
        i++;
        cout<<"Tong cac so phuc la:";
        printData(sum);
    }
}