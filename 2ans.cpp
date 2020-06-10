#include <iostream>
#include <functional>
static constexpr int N = 10;
int array[] = {
    3, 1, 4, 1, 5, 9, 2, 6, 5, 3 
};
void map(std::function<int(int)> func){
    for(int i = 0; i < N; i++){
        array[i] = func(array[i]);
    }
}
int main(void){
    // 配列の数値を表示する関数.  
    auto display = [](int x)->int{
        std::cout << x << std::endl;
        return x;
    };
    // もとの配列に2を足す lambda 式 plus_two を作成
    auto plus_two = [](int i) { return i + 2; };
    map(display);
    std::cout << std::endl;

    map(plus_two);
    map(display);
    std::cout << std::endl;

    // もとの配列に対して6で割ったときのあまりを求めるlambda 式 mod_six を作成
    auto mod_six = [](int i) { return i % 6; };
    map(mod_six);
    map(display);
    std::cout << std::endl;

    return 0;
}
