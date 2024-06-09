#include"json.hpp"
using json = nlohmann::json;

#include<iostream>
#include<vector>
#include<map>

using namespace std;

void func1() {
    //无序的
    json js;
    js["msg_type"] = 2; 
    js["from"] = "Beijing";
    js["to"] = "Nanjing";
    js["msg"] = "hello, world";

    string sendBuf = js.dump();

    cout << sendBuf.c_str() << endl;
}

void func2() {
    json js;
    js["id"] = {1, 2, 3, 4, 5}; //key对应的值可以是一个元素，或者一个数组
    js["name"] = "Song Yaxuan";
    // 添加msg的对象
    js["msg"]["Song Yaxuan"] = "hello world";
    js["msg"]["Liu Yaowen"] = "I am in Chongqing";

    //上面的两句等同于下面一次性添加
    js["msg"] = {{"Song Yaxuan", "hello world"},{"Liu Yaowen", "I am in Chongqing"}};
    cout << js << endl;
}

// json 序列化示例代码
void func3() {
    json js;
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(5);

    js["list"] = vec;

    map<int, string> m;
    m.insert({1, "Song Yaxuan"});
    m.insert({2, "Liu Yaowen"});
    m.insert({3, "Ma Jiaqi"});
    js["path"] = m;

    string sendBuf = js.dump(); //把json数据对象转化成序列化json字符串
    cout << js << endl;
    cout << sendBuf << endl;
}

int main() {
    //func1();
    //func2();
    func3();

    return 0;
}