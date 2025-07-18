/** 
* @file test.cpp 
* @description programin calisma islemi 
* @course 1-b
* @assignment 1
* @date 24.07.2023
* @author Mert Çalışkan mert.caliskan3@ogr.sakarya.edu.tr
*/

#include<iostream>
#include <fstream>
#include <string>
#include<sstream>
#include "LinkedList.hpp"


using namespace std;



int main()
{
    system("cls");
    ifstream file("sayilar.txt");
    if (!file.is_open()) {
        cout << "Dosya acilamadi: " << endl;
        return 1;
    }

    int lineCount = 0;
    string line;
    while (getline(file, line))  //dosya satir sayisi bulunmasi
    {
        lineCount++;
    }

    LinkedList* dizi[lineCount][2]; //bagli listeleri tutacak veri yapisi

    for(int i=0;i<lineCount;i++) //bagli listeler olusturuldu
    {
        dizi[i][0] = new LinkedList();    //onlar basamagi listesi
        dizi[i][1] = new LinkedList(); //birler basamagi listesi
    }


    file.close();
    file.open("sayilar.txt");

    if (!file.is_open()) {
        cout << "Dosya acilamadi: " << endl;
        return 1;
    }


    int sayi;
    int linec=0;
    while (getline(file, line))   //onlar ve birlere elemanlari ekleme
    {  
        stringstream aa(line);
        while(aa>>sayi)
        {
            dizi[linec][0]->add(sayi/10); //onlar            
            dizi[linec][1]->add(sayi%10); // birler            
        }        
        linec++;
    }
    file.close();

    int a;
    int b;
    cout<<"AKonumu: "; //onlar
    cin>>a;
    cout<<"BKonumu: "; //birler
    cin>>b;
    //yer degistirme islemi
    if(a>=lineCount||b>=lineCount)
        cout<<"dizi boyutu asildi"<<endl;
    else
    {
        LinkedList* tmp =  dizi[a][0];    //a konumu onlari al
        LinkedList* tmp2 =  dizi[b][1];   //b konumu birleri al        
        dizi[a][0] = tmp2;  //degistir
        dizi[b][1] = tmp;


        int usttoplam=0;
        float ortalamaust =0;
        int index =0;
        float elemanSay=0;
        int nullsayisi = 0;
        while(true)
        {
            for(int i=0;i<lineCount;i++)
            {
                if(dizi[i][0]->getNode(index)!=NULL){
                    usttoplam+=dizi[i][0]->getNode(index)->data;
                    elemanSay++;
                }
                else
                {
                    nullsayisi++;
                }
            }
            index++;   //nodelerin sirasi
            if(elemanSay != 0)
            {
                ortalamaust += usttoplam/elemanSay;               
            }
            if(nullsayisi==lineCount && elemanSay == 0) //tum nodelerden null gelirse toplanacak node kalmamistir donguden cikilir            
            {
                break;
            }
            else
            {
                nullsayisi = 0;
                elemanSay = 0;
                usttoplam =0;
                
            }    
        }

        float alttoplam = 0;
        int elemanSayAlt = 0;
        int nullsayisiAlt= 0;
        float ortalamaalt = 0;
        int indexAlt = 0;

        while(true)
        {
            for(int i=0;i<lineCount;i++)
            {
                if(dizi[i][1]->getNode(indexAlt)!=NULL){
                    alttoplam+=dizi[i][1]->getNode(indexAlt)->data;
                    elemanSayAlt++;
                }
                else
                {
                    nullsayisiAlt++;
                }
            }
            indexAlt++;   //nodelerin sirasi
            if(elemanSayAlt != 0)
            {
                ortalamaalt += alttoplam/elemanSayAlt;               
            }
            if(nullsayisiAlt==lineCount && elemanSayAlt == 0) //tum nodelerden null gelirse toplanacak node kalmamistir donguden cikilir            
            {
                break;
            }
            else
            {
                nullsayisiAlt = 0;
                elemanSayAlt = 0;
                alttoplam =0;
                
            }    
        }
        
        cout<<"UST: "<<ortalamaust<<endl;
        
        cout<<"ALT: "<<ortalamaalt<<endl;

        cout<<endl;
         for(int i =0;i<lineCount;i++)
        {
            delete dizi[i][0]; //onlar listesi yok edildi
            delete dizi[i][1]; //birler listesi yok edildi
        }
    }
    
   

    return 0;
}