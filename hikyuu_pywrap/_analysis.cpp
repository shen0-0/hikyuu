/*
 *  Copyright (c) 2023 hikyuu.org
 *
 *  Created on: 2023-10-10
 *      Author: fasiondog
 */

#include <boost/python.hpp>
#include <hikyuu/analysis/combinate.h>
#include "pybind_utils.h"

using namespace boost::python;
using namespace hku;

namespace py = boost::python;

static py::list combinate_index(object seq) {
    size_t total = len(seq);
    std::vector<size_t> index_list(total);
    for (size_t i = 0; i < total; ++i) {
        index_list[i] = i;
    }

    py::list result;
    std::vector<std::vector<size_t>> comb = combinateIndex(index_list);
    for (size_t i = 0, count = comb.size(); i < count; i++) {
        py::list tmp = vector_to_py_list<std::vector<size_t>>(comb[i]);
        result.append(tmp);
    }
    return result;
}

void export_analysis() {
    def("combinate_index", combinate_index, R"(combinate_index(seq)

    获取序列组合的下标索引, 输入序列的长度最大不超过15，否则抛出异常

    :param seq: 可迭代的 python 对象
    :rtype: list

    )");

    def("combinate_ind", combinate_ind);
}