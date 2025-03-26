#pragma once

#include <iostream>
#include <vector>

std::vector<std::vector<int>> generate_triangle(int number_of_rows);

template<typename T>
std::ostream& operator << (std::ostream &output_stream, const std::vector<std::vector<T>> &triangle);

void show_triangle(std::ostream &output_stream, const std::vector<std::vector<int>> &triangle);

void check_triangle_properties(const std::vector<std::vector<int>> &triangle);