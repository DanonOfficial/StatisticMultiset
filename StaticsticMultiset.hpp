#pragma once

#include "exceptions/WrongAppend.h"

namespace statisticMultiset {

    template<class T>
    void StatisticMultiset<T>::updateMinMax(const T &num) {
        if (data.size() > 0 && max < num) {
            max = num;
        }
        if (data.size() > 0 && min > num) {
            min = num;
        }
        if (data.size() == 0) {
            min = num;
            max = num;
        }
    }

    template<class T>
    void StatisticMultiset<T>::addNums(const T &num) {
        updateMinMax(num);
        data.insert(num);
    }

    template<class T>
    void StatisticMultiset<T>::addNums(const std::multiset<T> &numbers) {
        for (auto const &i : numbers) {
            updateMinMax(i);
            data.insert(i);
        }
    }

    template<class T>
    void StatisticMultiset<T>::addNums(const std::vector<T> &numbers) {
        for (auto const &i : numbers) {
            updateMinMax(i);
            data.insert(i);
        }
    }

    template<class T>
    void StatisticMultiset<T>::addNums(const std::list<T> &numbers) {
        for (auto const &i : numbers) {
            updateMinMax(i);
            data.insert(i);
        }
    }

    template<class T>
    void StatisticMultiset<T>::addNums(const StatisticMultiset &numbers) {
        if(this == &numbers){
            throw error::WrongAppend("You are trying to append multiset to himself");
        }
        for (auto const &i : numbers.data) {
            updateMinMax(i);
            data.insert(i);
        }
    }

    template<class T>
    void StatisticMultiset<T>::addNumsFromFile(const char *filename) {
        std::ifstream in(filename);
        if (!in) {
            throw error::NoFileError("Here is no file with name" + std::to_string(*filename));
        } else {
            while (in) {
                T read;
                in >> read;
                data.insert(read);
            }
        }
    }

    template<class T>
    T StatisticMultiset<T>::getMax() const {
        return max;
    }

    template<class T>
    T StatisticMultiset<T>::getMin() const {
        return min;
    }

    template<class T>
    float StatisticMultiset<T>::getAvg() const {
        float res = 0;
        for (auto &i : data) {
            res += i;
        }
        return res / data.size();
    }

    template<class T>
    int StatisticMultiset<T>::getCountAbove(float threshold) const {
        int res = 0;
        for (auto &i : data) {
            if (i > threshold) {
                res++;
            }
        }
        return res;
    }

    template<class T>
    int StatisticMultiset<T>::getCountUnder(float threshold) const {
        int res = 0;
        for (auto &i : data) {
            if (i < threshold) {
                res++;
            }
        }
        return res;
    }
}