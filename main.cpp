
#include "Multiset.h"
#include <iostream>
#include <cassert>
using namespace std;





//int main(){
//    Multiset h;
//    h.insert("ert");
//}

int main(){
   Multiset t1;
   
   //Empty Function works
   assert(t1.empty());
   assert(t1.size() == 0);
   assert(t1.uniqueSize() == 0);
   assert(t1.erase(123) == 0);
   assert(t1.eraseAll(123) == 0);
   
   //Insert Function works
   assert(t1.insert(1));
   assert(t1.insert(2));
   assert(t1.insert(1));
   
   //check size & uniqueSize & count functions
   assert(!t1.empty());
   assert(t1.size() == 3);
   assert(t1.uniqueSize() == 2);
   assert(t1.count(1)==2 && t1.count(2) == 1);
   
   //check erase Function
   assert(t1.erase(1) == 1);
   assert(t1.size() == 2);
   assert(t1.uniqueSize() == 2);
   assert(t1.erase(1) == 1);
   assert(t1.size() == 1);
   assert(t1.uniqueSize() ==1);
   assert(t1.eraseAll(2) == 1);
   
   //check eraseAll function
   assert(t1.insert(1));
   assert(t1.insert(2));
   assert(t1.insert(1));
   assert(t1.eraseAll(1) == 2);
   assert(t1.size() == 1);
   assert(t1.uniqueSize() ==1);
   t1.eraseAll(2);
   
   t1.insert(1);
   t1.insert(5);
   t1.insert(6);
   t1.insert(5);
   t1.insert(3);
   t1.insert(3);
   t1.insert(5);
   t1.insert(1);
   assert(t1.uniqueSize() == 4 && t1.size() == 8);
   
   
   ItemType value1, value2;
  
   
   
   
   //Check Get Function & Copy Constructor & Count Function
   //Multiset temp1 = t1;
   Multiset temp1(t1);
   for(int i = 0; i < t1.uniqueSize();i++){
       assert((t1.get(i, value1) == t1.count(value1)) ==  (temp1.get(i, value2) == temp1.count(value2)));
       value1 = value2;
   }
   assert(t1.size()==temp1.size() && t1.uniqueSize()==temp1.uniqueSize());
   
   
   
   
   //Check Copy Assingment Operator
   Multiset t2;
   t2.insert(23);
   t2.insert(33);
   t2.insert(88);
   t2.insert(99);
   t2.insert(24);
   t2.insert(2993);
   t2.insert(99);
   t2.insert(99);
   t2.insert(23);
   t2.insert(27);
   t2.insert(21);
   t2.insert(11);
   t2 = t1;
   for(int i = 0; i < t1.uniqueSize();i++){
       assert((t1.get(i, value1) == t1.count(value1)) == (temp1.get(i, value2) == temp1.count(value2)));
       value1 = value2;
   }
   assert(t1.size()==temp1.size() && t1.uniqueSize()==temp1.uniqueSize());

   
   
   
   //Check for aliasing on copy constructor
   t1 = t1;
   for(int i = 0; i < t1.uniqueSize();i++){
       assert((t1.get(i, value1) == t1.count(value1)) == (t1.get(i, value2) == t1.count(value2)));
       value1 = value2;
   }
   Multiset t3;
   t3.insert(23);
   t3.insert(33);
   t3.insert(88);
   t3.insert(99);
   t3.insert(24);
   t3.insert(2993);
   t3.insert(99);
   t3.insert(99);
   t3.insert(23);
   t3.insert(27);
   t3.insert(21);
   t3.insert(11);
   Multiset temp3(t3);
   
   
   //Check swap function (t1 = temp1; t3 = temp3)
   t1.swap(t3); //so t1 should = temp3. t3 should = temp1
   
   for(int i = 0; i < temp3.uniqueSize();i++){
       assert((t1.get(i, value1) == t1.count(value1)) == (temp3.get(i, value2) == temp3.count(value2)));
       value1 = value2;
   }
   assert(t1.size()==temp3.size() && t1.uniqueSize()==temp3.uniqueSize());
   
   for(int i = 0; i < temp1.uniqueSize();i++){
       assert((t3.get(i, value1) == t3.count(value1)) == (temp1.get(i, value2) == temp1.count(value2)));
       value1 = value2;
   }
   assert(t3.size()==temp1.size() && t3.uniqueSize()==temp1.uniqueSize());
   
   
   
   //Check Combine Function
   Multiset t4, t5, t6, temp6;
   temp6.insert(11);
   temp6.insert(22);
   temp6.insert(33);
   temp6.insert(44);
   temp6.insert(55);
   temp6.insert(66);
   temp6.insert(77);
   
   t4.insert(11);
   t4.insert(22);
   t4.insert(33);
   t4.insert(44);
   
   t5.insert(55);
   t5.insert(66);
   t5.insert(77);
   
   
   combine(t4, t5, t6);
   
   for(int i = 0; i < temp6.uniqueSize();i++){
       assert(t6.get(i, value1) == t6.count(value1) == temp6.get(i, value2) == temp6.count(value2));
       value1 = value2;
   }
   
   //Check Subtract Function
   Multiset t7, t8, t9, temp9;
   temp9.insert(22);
   temp9.insert(33);
   
   t7.insert(11);
   t7.insert(22);
   t7.insert(22);
   t7.insert(33);

   t8.insert(11);
   t8.insert(22);
   t8.insert(47);
   t8.insert(11);
   t8.insert(11);
   
   subtract(t7, t8, t9);
   
   for(int i = 0; i < temp9.uniqueSize();i++){
       assert(t9.get(i, value1) == t9.count(value1) == temp9.get(i, value2) == temp9.count(value2));
       value1 = value2;
   }
   
   //Check for Aliasing in both subtract & combine
   Multiset temp10, temp11;
   //temp 10: combination of 2 temp9
   temp10.insert(22);
   temp10.insert(22);
   temp10.insert(33);
   temp10.insert(33);

   combine(temp9, temp9, temp9);
   for(int i = 0; i < temp9.uniqueSize();i++){
       assert((temp9.get(i, value1) == temp9.count(value1)) == (temp10.get(i, value2) == temp10.count(value2)));
       value1 = value2;
   }
   
   //temp9 should be empty at the end
   subtract(temp9, temp9, temp9);
   for(int i = 0; i < temp9.uniqueSize();i++){
       assert((temp9.get(i, value1) == temp9.count(value1)) == (temp11.get(i, value2) == temp11.count(value2)));
       value1 = value2;
   }
   

   cout << "tests successful!!" << endl;
   
}































////
//
//#include "Multiset.h"
//#include <iostream>
//#include <cassert>
//using namespace std;
//
//void test()
//{
//    //    Multiset sms;
//    //    assert(sms.insert("cumin"));
//    //    assert(sms.insert("turmeric"));
//    //    assert(sms.contains("cumin"));
//    //    assert(sms.contains("turmeric"));
//    //    assert(sms.insert("cumin"));
//    //    assert(sms.insert("coriander"));
//    //    assert(sms.insert("cumin"));
//    //    assert(sms.insert("turmeric"));
//    //    assert(sms.size() == 6  &&  sms.uniqueSize() == 3);
//    //    assert(sms.count("turmeric") == 2);
//    //    assert(sms.count("cumin") == 3);
//    //    assert(sms.count("coriander") == 1);
//    //    assert(sms.count("cardamom") == 0);
//}
//
//void trivial()
//{
//    Multiset ulms;
//    assert(ulms.insert(20));
//    
//    assert(ulms.count(20) == 1);
//    
//}
//
//void test1()
//{
//    Multiset ulms;
//    assert(ulms.insert(20));
//    assert(ulms.insert(10));
//    assert(ulms.insert(20));
//    assert(ulms.insert(30));
//    assert(ulms.insert(20));
//    assert(ulms.insert(10));
//    assert(ulms.size() == 6  &&  ulms.uniqueSize() == 3);
//    assert(ulms.count(10) == 2);
//    assert(ulms.count(20) == 3);
//    assert(ulms.count(30) == 1);
//    assert(ulms.count(40) == 0);
//}
//
//void test2()
//{
//    
//    Multiset ulms;
//    assert(ulms.insert(20));
//    assert(ulms.insert(10));
//    assert(ulms.insert(20));
//    assert(ulms.insert(30));
//    assert(ulms.insert(20));
//    assert(ulms.insert(10));
//    assert(ulms.insert(5));
//    ulms.eraseAll(10);
//    ulms.erase(20);
//    ulms.erase(30);
//    ulms.erase(30);
//    ulms.erase(20);
//    ulms.erase(20);
//    ulms.erase(20);
//    assert(ulms.count(10) == 0);
//    assert(ulms.count(20) == 0);
//    assert(ulms.count(30) == 0);
//    assert(ulms.count(40) == 0);
//    
//    Multiset ms;
//    ms.insert(20);
//    ms.insert(30);
//    ms.insert(40);
//    ms.erase(40);
//    ms.erase(40);
//    ms.erase(30);
//    ms.erase(20);
//    ms.erase(20);
//    ms.erase(30);
//    assert(ms.count(40) == 0);
//    assert(ms.count(20) == 0);
//    assert(ms.empty());
//    
//}
//
//void test3()
//{
//    Multiset ulms;
//    assert(ulms.insert(20));
//    assert(ulms.insert(10));
//    assert(ulms.insert(20));
//    assert(ulms.insert(30));
//    assert(ulms.insert(20));
//    assert(ulms.insert(10));
//    ItemType str;
//    ulms.get(0, str);
//}
//
//void test4()
//{
//    Multiset ulms;
//    assert(ulms.insert(20));
//    assert(ulms.insert(10));
//    assert(ulms.insert(20));
//    assert(ulms.insert(30));
//    assert(ulms.insert(20));
//    assert(ulms.insert(10));
//    Multiset ms1;
//    ms1.insert(20);
//    ms1.insert(30);
//    ms1.insert(40);
//    ms1.swap(ulms);
//    assert(ulms.count(20) == 1);
//    assert(ulms.count(30) == 1);
//    assert(ulms.count(40) == 1);
//    assert(ms1.count(20) == 3);
//    assert(ms1.count(30) == 1);
//    assert(ms1.count(10) == 2);
//}
//
//void testbasic()
//{
//    Multiset ulms;
//    assert(ulms.insert(20));
//    assert(ulms.insert(10));
//    assert(ulms.insert(20));
//    assert(ulms.insert(30));
//    assert(ulms.insert(20));
//    assert(ulms.insert(10));
//    Multiset u = ulms;
//    assert(u.contains(20));
//    assert(u.contains(10));
//    assert(u.contains(20));
//    assert(u.contains(30));
//    assert(u.contains(20));
//    assert(u.contains(10));
//    
//}
//
//void testErase()
//{
//    Multiset ulms;
//    assert(ulms.insert(10));
//    assert(ulms.insert(20));
//    assert(ulms.insert(30));
//    assert(ulms.insert(40));
//    assert(ulms.insert(50));
//    assert(ulms.insert(60));
//    assert(ulms.contains(10));
//    assert(ulms.contains(20));
//    assert(ulms.contains(30));
//    assert(ulms.contains(40));
//    assert(ulms.contains(50));
//    assert(ulms.contains(60));
//    assert(ulms.erase(20));
//    assert(ulms.erase(30) == 1);
//    ulms.erase(30);
//    assert(ulms.contains(20) == 0);
//    //assert(ulms.contains(30));
//    assert(ulms.contains(40));
//    assert(ulms.contains(50));
//    assert(ulms.contains(60));
//    assert(ulms.contains(10));
//    
//}
//
//void testErase1()
//{
//    Multiset ulms;
//    assert(ulms.insert(20));
//    assert(ulms.insert(10));
//    assert(ulms.insert(20));
//    assert(ulms.insert(30));
//    assert(ulms.insert(20));
//    assert(ulms.insert(10));
//    assert(ulms.erase(30));
//}
//
//
//void testCombine()
//{
//    Multiset ulms;
//    assert(ulms.insert(1));
//    assert(ulms.insert(2));
//    assert(ulms.insert(3));
//    assert(ulms.insert(4));
//    assert(ulms.insert(5));
//    assert(ulms.insert(6));
//    assert(ulms.contains(1));
//    assert(ulms.contains(2));
//    assert(ulms.contains(3));
//    assert(ulms.contains(4));
//    assert(ulms.contains(5));
//    assert(ulms.contains(6));
//    
//    Multiset ms1;
//    ms1.insert(5);
//    ms1.insert(6);
//    ms1.insert(7);
//    assert(ms1.contains(5));
//    assert(ms1.contains(6));
//    assert(ms1.contains(7));
//    
//    //ms1.swap(ulms);
//    Multiset res;
//    combine(ulms, ms1, res);
//    assert(res.count(1) == 1);
//    assert(res.count(2) == 1);
//    assert(res.count(3) == 1);
//    assert(res.count(4) == 1);
//    assert(res.count(5) == 2);
//    assert(res.count(6) == 2);
//    assert(res.count(7) == 1);
//    
//}
//
//void epic()
//{
//    Multiset ms;
//    for(int i = 0; i<= 10; i++)
//        ms.erase(10);
//    assert(!ms.contains(10));
//    assert(!ms.count(20));
//    assert(ms.uniqueSize() == 0);
//    assert(ms.size() == 0);
//    ms.insert(10);
//    for(int i = 0; i<= 10; i++)
//        ms.erase(10);
//    assert(!ms.contains(10));
//    assert(!ms.count(20));
//    assert(ms.uniqueSize() == 0);
//    assert(ms.size() == 0);
//    ms.insert(10);
//    for(int i = 0; i<= 10; i++)
//        ms.eraseAll(10);
//    assert(!ms.contains(10));
//    assert(!ms.count(10));
//    assert(ms.uniqueSize() == 0);
//    assert(ms.size() == 0);
//    
//}
//
//
//void testComp()
//{
//    Multiset ulms;
//    Multiset ms1;
//    Multiset ms;
//    ms.insert(5);
//    ms.insert(6);
//    ms.insert(7);
//    combine(ulms, ms1, ms);
//    assert(ms.empty());
//    subtract(ulms, ms1, ms);
//    assert(ms.empty());
//}
//
//void testSub()
//{
//    Multiset ulms;
//    assert(ulms.insert(1));
//    assert(ulms.insert(2));
//    assert(ulms.insert(3));
//    assert(ulms.insert(4));
//    assert(ulms.insert(5));
//    assert(ulms.insert(6));
//    assert(ulms.contains(1));
//    assert(ulms.contains(2));
//    assert(ulms.contains(3));
//    assert(ulms.contains(4));
//    assert(ulms.contains(5));
//    assert(ulms.contains(6));
//    
//    Multiset ms1;
//    ms1.insert(5);
//    assert(ms1.insert(5));
//    ms1.insert(6);
//    ms1.insert(7);
//    assert(ms1.contains(5));
//    assert(ms1.contains(6));
//    assert(ms1.contains(7));
//    Multiset res;
//    subtract(ulms, ms1, res);
//    assert(res.count(1) == 1);
//    assert(res.count(2) == 1);
//    assert(res.count(3) == 1);
//    assert(res.count(4) == 1);
//    assert(res.count(5) == 0);
//    assert(res.count(6) == 0);
//    assert(res.count(7) == 0);
//    
//}
//
//void testGet()
//{
//    ItemType value;
//    Multiset ulms;
//    ulms.get(0, value);
//    assert(ulms.insert(1));
//    assert(ulms.insert(2));
//    assert(ulms.insert(3));
//    assert(ulms.insert(4));
//    assert(ulms.insert(5));
//    assert(ulms.insert(6));
//    for(int i = 0; i < ulms.uniqueSize(); i++)
//    {
//        ulms.get(i, value);
//        assert(value == i +1);
//    }
//}
//
//void aliasing()
//{
//    Multiset ulms;
//    assert(ulms.insert(1));
//    assert(ulms.insert(2));
//    assert(ulms.insert(3));
//    assert(ulms.insert(4));
//    assert(ulms.insert(5));
//    assert(ulms.insert(6));
//    assert(ulms.contains(1));
//    assert(ulms.contains(2));
//    assert(ulms.contains(3));
//    assert(ulms.contains(4));
//    assert(ulms.contains(5));
//    assert(ulms.contains(6));
//    //combine(ulms, ulms, ulms);
//    
//    Multiset ms1;
//    ms1.insert(5);
//    ms1.insert(6);
//    ms1.insert(7);
//    assert(ms1.contains(5));
//    assert(ms1.contains(6));
//    assert(ms1.contains(7));
//    
//    //ms1.swap(ulms);
//    Multiset res;
//    combine(ulms, ms1, res);
//    assert(res.count(1) == 1);
//    assert(res.count(2) == 1);
//    assert(res.count(3) == 1);
//    assert(res.count(4) == 1);
//    assert(res.count(5) == 2);
//    assert(res.count(6) == 2);
//    assert(res.count(7) == 1);
//    combine(ms1, ulms, ulms);
//    assert(ulms.count(1) == 1);
//    assert(ulms.count(2) == 1);
//    assert(ulms.count(3) == 1);
//    assert(ulms.count(4) == 1);
//    assert(ulms.count(5) == 2);
//    assert(ulms.count(6) == 2);
//    assert(ulms.count(7) == 1);
//    Multiset ulms1;
//    assert(ulms1.insert(1));
//    assert(ulms1.insert(2));
//    assert(ulms1.insert(3));
//    assert(ulms1.insert(4));
//    assert(ulms1.insert(5));
//    assert(ulms1.insert(6));
//    assert(ulms1.contains(1));
//    assert(ulms1.contains(2));
//    assert(ulms1.contains(3));
//    assert(ulms1.contains(4));
//    assert(ulms1.contains(5));
//    assert(ulms1.contains(6));
//    
//    Multiset ms2;
//    ms2.insert(5);
//    ms2.insert(6);
//    ms2.insert(7);
//    assert(ms2.contains(5));
//    assert(ms2.contains(6));
//    assert(ms2.contains(7));
//    subtract(ulms1, ms2, ms2);
//    assert(ms2.count(1) == 1);
//    assert(ms2.count(2) == 1);
//    assert(ms2.count(3) == 1);
//    assert(ms2.count(4) == 1);
//    assert(ms2.count(5) == 0);
//    assert(ms2.count(6) == 0);
//    combine(ms2,ms2,ms2);
//    assert(ms2.count(1) == 2);
//    assert(ms2.count(2) == 2);
//    assert(ms2.count(3) == 2);
//    assert(ms2.count(4) == 2);
//    subtract(ms2, ms2, ms2);
//    assert(ms2.count(1) == 0);
//    assert(ms2.count(2) == 0);
//    assert(ms2.count(3) == 0);
//    assert(ms2.count(4) == 0);
//    assert(ms2.count(5) == 0);
//    assert(ms2.count(6) == 0);
//}
//
//
//int main()
//{
//    test1();
//    test2();
//    test3();
//    test4();
//    testbasic();
//    testErase();
//    testErase1();
//    testCombine();
//    testComp();
//    testSub();
//    epic();
//    testGet();
//    aliasing();
//    cout << "Passed all tests" << endl;
//}
//
//
//
//
//
////#include "Multiset.h"
////
////#define CHECKTYPE(f, t) { auto p = (t)(f); (void)p; }
////
////void thisFunctionWillNeverBeCalled()
////{
////    Multiset();
////    (Multiset(Multiset()));
////    CHECKTYPE(&Multiset::operator=,  Multiset& (Multiset::*)(const ItemType&));
////    CHECKTYPE(&Multiset::empty,      bool (Multiset::*)() const);
////    CHECKTYPE(&Multiset::size,       int  (Multiset::*)() const);
////    CHECKTYPE(&Multiset::uniqueSize, int  (Multiset::*)() const);
////    CHECKTYPE(&Multiset::insert,     bool (Multiset::*)(const ItemType&));
////    CHECKTYPE(&Multiset::erase,      int  (Multiset::*)(const ItemType&));
////    CHECKTYPE(&Multiset::eraseAll,   int  (Multiset::*)(const ItemType&));
////    CHECKTYPE(&Multiset::contains,   bool (Multiset::*)(const ItemType&) const);
////    CHECKTYPE(&Multiset::count,      int  (Multiset::*)(const ItemType&) const);
////    CHECKTYPE(&Multiset::get,        int  (Multiset::*)(int, ItemType&) const);
////    CHECKTYPE(&Multiset::swap,       void (Multiset::*)(Multiset&));
////    CHECKTYPE(combine,  void (*)(const Multiset&, const Multiset&, Multiset&));
////    CHECKTYPE(subtract, void (*)(const Multiset&, const Multiset&, Multiset&));
////}
////
////int main()
////{}
//
////
////#include "Multiset.h"
////#include <iostream>
////#include <cassert>
////using namespace std;
//////
////void test()
////{
////    Multiset ulms;
////    assert(ulms.insert(20));
////    assert(ulms.insert(10));
////    assert(ulms.insert(20));
////    assert(ulms.insert(30));
////    assert(ulms.insert(20));
////    assert(ulms.insert(10));
////    assert(ulms.size() == 6  &&  ulms.uniqueSize() == 3);
////    assert(ulms.count(10) == 2);
////    assert(ulms.count(20) == 3);
////    assert(ulms.count(30) == 1);
////    assert(ulms.count(40) == 0);
////}
////
////int main()
////{
////    test();
////    cout << "Passed all tests" << endl;
////}
//
////int main()
////{
////    Multiset a;
////    Multiset b;
////    Multiset c;
////    b.insert(10);
////    b.insert(11);
////    b.insert(12);
////    b.insert(1);
////    a.insert(1);
////    a.insert(2);
////    a.insert(2);
////    a.insert(3);
////    combine(a, b, c);
////    cout << a.uniqueSize() << endl;
////    a.erase(1);
////    a.insert(4);
////    a.insert(5);
////    a.insert(5);
////    a.insert(5);
////    a.insert(7);
////    a.eraseAll(2);
////    swap(a,b);
//////    a.print();
////    ItemType x;
////    for(int i = 0; i < b.uniqueSize(); i++)
////    {
////        for(int k = 0; k < b.get(i, x); k++)
////        {
////            cout << x;
////        }
////    }
//////    b.print();
////    subtract(a, b, c);
//////    c.print();
////    if(a.contains(3))
////        cout << "contains worked" << endl;
////    cout << "count says " << a.count(2) << endl;
////    cout << "size()" << a.size() << endl;
////    cout << "uniqueSize()" << a.uniqueSize() << endl;
////    //unsigned long x;
////    a.get(1, x);
////    cout << x << endl;
////    cout << a.get(1, x) << endl;
////    if(a.empty())
////        cout << "empty is working fine" << endl;
////}
//
//
////#include "Multiset.h"
////#include <iostream>
////#include <cassert>
////using namespace std;
////
////void test()
////{
////    Multiset sms;
////    assert(sms.insert("cumin"));
////    assert(sms.insert("turmeric"));
////    assert(sms.insert("cumin"));
////    assert(sms.insert("coriander"));
////    assert(sms.insert("cumin"));
////    assert(sms.insert("turmeric"));
////    assert(sms.size() == 6  &&  sms.uniqueSize() == 3);
////    assert(sms.count("turmeric") == 2);
////    assert(sms.count("cumin") == 3);
////    assert(sms.count("coriander") == 1);
////    assert(sms.count("cardamom") == 0);
////}
////
////int main()
////{
////    test();
////    cout << "Passed all tests" << endl;
////}
//
//
//
//
//
//#include "Multiset.h"
//#include <iostream>
//#include <cassert>
//
//using namespace std;
//
//void test()
//{
//    cerr << "test A" << endl;
//    Multiset ms;
//    cerr << "test B" << endl;
//    ms.insert(IntWrapper(10));
//    cerr << "test C" << endl;
//    ms.insert(IntWrapper(20));
//    cerr << "test D" << endl;
//    Multiset ms2;
//    cerr << "test E" << endl;
//    ms2.insert(IntWrapper(30));
//    cerr << "test F" << endl;
//    ms2 = ms;
//    cerr << "test G" << endl;
//    ms2.insert(IntWrapper(40));
//    cerr << "test H" << endl;
//}
//
//int main()
//{
//    test();
//    cerr << "DONE" << endl;
//}
//
//
//

////#include <cassert>
////#include <iostream>
////#include "Multiset.h"
////using namespace std;
////int main(){
////    Multiset a;
////    assert(a.empty());
////    
////    a.insert("jeff");
////    a.insert("jeff");
////    a.insert("harry");
////    a.insert("jeff");
////    Multiset b;
////    
////    b = a;
////    
////    cout << "here" << endl;
////    string x;
////    cout << a.get(0,x) << endl;
////    cout << x << endl;
////    
////    cout << a.get(1,x) <<endl;
////    cout << x << endl;
////    
////    cout << a.get(2,x) <<endl;
////    cout << x << endl;
////    
////    a.eraseAll("jeff");
////    a.erase("harry");
////    a.erase("harry");
////    
////    cout << endl << "Total Size: " << a.size() << endl;
////    cout << "Unique Size: " << a.uniqueSize() << endl << endl;
////    return 0;
//    
////    Multiset ms1;
////    ms1.insert("cumin");
////    ms1.insert("cumin");
////    ms1.insert("cumin");
////    ms1.insert("turmeric");
////    Multiset ms2;
////    ms2.insert("coriander");
////    ms2.insert("cumin");
////    ms2.insert("cardamom");
////    ms1.swap(ms2);  // exchange contents of ms1 and ms2
////    assert(ms1.size() == 3  &&  ms1.count("coriander") == 1  &&
////           ms1.count("cumin") == 1  &&  ms1.count("cardamom") == 1);
////    assert(ms2.size() == 4  &&  ms2.count("cumin") == 3  &&
////           ms2.count("turmeric") == 1);
////
////
////}