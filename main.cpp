#include <iostream>
#include "StatisticMultiset.h"

int main() {
    statisticMultiset::StatisticMultiset<int> a;
    a.addNums(10);
    a.addNums(24);
    a.addNums(4511);
    a.addNums(3);
    a.addNums(-2);
    std::cout << a.getMax() << " " << a.getMin() << std::endl;
    return 0;
}