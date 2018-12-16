//这里只是部分代码块
//创建vector并初始化
{
    vector<int> vetInt;
    for(int i = 0; i < 500; i++){
        vetInt.emplace_back(i);
    }
    int capacity = vecInt.capacity();   //512
    int size = vecInt.size();                  //500
}

//1、赋值新的数组
vecInt = {1,2,3,4,5,6,7,8,9,0);
int capacity = vecInt.capacity();   //512
int size = vecInt.size();           //10

//2、clear()方法
vecInt.clear();
int capacity = vecInt.capacity();   //512
int size = vecInt.size();           //0

//3、erase()方法
for(auto it = vecInt.begin(); it!=vecInt.end(); it++)
{
    it = vecInt.erase(iter);//erase自动返回下一个元素的迭代器
}
int capacity = vecInt.capacity();   //512
int size = vecInt.size();           //0

//4、swap()方法
vector<int>().swap(vecInt);
int capacity = vecInt.capacity();   //0
int size = vecInt.size();           //0

