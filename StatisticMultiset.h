//
// Created by danonofficial on 10.09.17.
//

#ifndef UPDATED_MULTISET_STATISTICMULTISET_H
#define UPDATED_MULTISET_STATISTICMULTISET_H

#include <set>
#include <vector>
#include <list>
#include <fstream>
#include "exceptions/NoFileError.h"

namespace statisticMultiset {
    template<class T>
    class StatisticMultiset {
    public:
        StatisticMultiset() = default;

        ~StatisticMultiset() = default;

        void updateMinMax(const T &num);

        void addNums(const T &num);

        void addNums(const std::multiset<T> &numbers);

        void addNums(const std::vector<T> &numbers);

        void addNums(const std::list<T> &numbers);

        void addNums(const StatisticMultiset &a_stat_set);

        void addNumsFromFile(const char *filename);

        T getMax() const;

        T getMin() const;

        float getAvg() const;

        int getCountUnder(float threshold) const;

        int getCountAbove(float threshold) const;

    private:
        std::multiset<T> data;
        T max;
        T min;
    };
}

#include "StaticsticMultiset.hpp"


#endif //UPDATED_MULTISET_STATISTICMULTISET_H
