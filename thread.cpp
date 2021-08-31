#include <iostream>
#include <thread>
#include <chrono>

void foo() {
    std::this_thread::sleep_for(std::chrono::seconds(1));
}

int main()
{
    std::thread th1(foo);
    std::thread::id id1=th1.get_id();

	std::thread th2(foo);
	std::thread::id id2 = th2.get_id();

    std::thread th3;
    //检查std::thread对象是否标识活动的执行线程。
    std::cout << "id1=" << id1 << "\tid2=" << id2 
        <<"\nth1.joinable="<< th1.joinable()<<"\tth2.joinable=" << th2.joinable()<< "\tth3.joinable=" << th3.joinable()<<std::endl;

    th1.join();
    th2.join();//join之后joinable为false
	std::cout <<"th1.joinable=" << th1.joinable() << "\tth2.joinable=" << th2.joinable() << "\tth3.joinable=" << th3.joinable() << std::endl;

}
