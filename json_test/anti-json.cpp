#include"json.hpp"
using json = nlohmann::json;

#include<iostream>
#include<vector>
#include<map>

using namespace std;

string func1() {
    //无序的
    json js;
    js["msg_type"] = 2; 
    js["from"] = "Beijing";
    js["to"] = "Nanjing";
    js["msg"] = "hello, world";

    string sendBuf = js.dump();

    return sendBuf;
}

string func2() {
    json js;
    js["id"] = {1, 2, 3, 4, 5}; //key对应的值可以是一个元素，或者一个数组
    js["name"] = "Song Yaxuan";
    // 添加msg的对象
    js["msg"]["Song Yaxuan"] = "hello world";
    js["msg"]["Liu Yaowen"] = "I am in Chongqing";

    //上面的两句等同于下面一次性添加
    //js["msg"] = {{"Song Yaxuan", "hello world"},{"Liu Yaowen", "I am in Chongqing"}};
    return js.dump();
}

// json 序列化示例代码
string func3() {
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
    return sendBuf;
}

#define func_1       0
#define func_2       0
#define func_3       1

int main() {

#if func_1
    //把json字符串转化成数据对象(看作容器)
    string buf = func1();
    json jsbuf = json::parse(buf);
    cout << jsbuf["msg_type"] << endl;
    cout << jsbuf["from"] << endl;
    cout << jsbuf["to"] << endl;;
    cout << jsbuf["msg"] << endl;
    return 0;
#elif func_2

    string buf = func2();

    json jsbuf = json::parse(buf);

    cout << jsbuf["id"] << endl;
    cout << jsbuf["name"] << endl;
    cout << jsbuf["msg"] << endl;

    auto arr = jsbuf["id"];
    cout << arr[2] << endl;
    string name = jsbuf["name"];
    cout << name << endl;
    auto msgjs = jsbuf["msg"];
    cout << msgjs["Song Yaxuan"] << endl;
    cout << msgjs["Liu Yaowen"] << endl;



#elif func_3

    string buf = func3();
    json jsbuf = json::parse(buf);

    vector<int> vec = jsbuf["list"];
    for (auto &v: vec ) {
        cout << v << " ";
    }
    cout << endl;

    map<int, string> mymap = jsbuf["path"];
    for (auto &p : mymap) {
        cout << p.first << ": " <<  p.second << endl;
    }

#endif
}