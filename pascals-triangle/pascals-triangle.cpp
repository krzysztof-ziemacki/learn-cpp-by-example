#include <algorithm>
#include <cassert>
#include <format>
#include <iostream>
#include <iterator>
#include <cmath>
#include <numeric>
#include <ranges>
#include <vector>

#include "pascals-triangle.h"

std::vector<int> generate_next_row(const std::vector<int> &last_row)
{
    std::vector next_row{1};

    if (last_row.empty())
    {
        return next_row;
    }

    for (size_t idx = 0; idx < last_row.size() - 1; ++idx)
    {
        next_row.emplace_back(last_row[idx] + last_row[idx + 1]);
    }

    next_row.emplace_back(1);

    return next_row;
}

std::vector<std::vector<int>> generate_triangle(int number_of_rows)
{
    if (0 == number_of_rows)
    {
        return std::vector<std::vector<int>>{};
    }

    std::vector<std::vector<int>> triangle{{1}};
    for (int row_number = 1; row_number < number_of_rows; ++row_number)
    {
        triangle.push_back(generate_next_row(triangle.back()));
    }

    return triangle;
}

template<typename T>
std::ostream& operator << (std::ostream &output_stream, const std::vector<std::vector<T>> &triangle)
{
    for(const auto &row : triangle)
    {        
        std::ranges::copy(row, std::ostream_iterator<T>(output_stream, " "));        
        output_stream << '\n';
    }

    return output_stream;
}

void show_triangle(std::ostream &output_stream, const std::vector<std::vector<int>> &triangle)
{
    size_t final_row_size = triangle.back().size();
    
    // three spaces per row
    std::string spaces(final_row_size * 3, ' ');

    for(const auto &row : triangle)
    {
        output_stream << spaces;

        if(spaces.size() > 3) 
        {
            // shrinks the spaces bu three for each row
            spaces.resize(spaces.size() - 3);
        }

        for(const auto &element : row)
        {
            output_stream << std::format("{: ^{}}", element, 6);
        }

        output_stream << '\n';
    }
}

bool is_palindrome(const std::vector<int> &v)
{
    auto forward = v | std::views::take(v.size() / 2);
    auto backward = v | std::views::reverse | std::views::take(v.size() / 2);

    return std::ranges::equal(forward, backward);
}

void check_triangle_properties(const std::vector<std::vector<int>> &triangle)
{
    for(size_t row_number = 0; row_number < triangle.size(); ++row_number)
    {
        const auto &row = triangle[row_number];

        // each row starts with number 1
        assert(row.front() == 1);

        // each row ends with number 1
        assert(row.back() == 1);

        // n-th row has n+1 numbers
        assert(row.size() == row_number + 1);

        // all numbers are positive
        assert(std::ranges::all_of(row, [](auto x) { return x >= 0; }));

        auto negative = [](int x) { return x < 0; };
        auto negatives = row | std::ranges::views::filter(negative);
        assert(negatives.empty());

        // sum of numbers in n-th row is equal to 2 to the power of n
        assert(std::accumulate(row.begin(), row.end(), 0) == std::pow(2, row_number));

        // each row is palindrome
        assert(is_palindrome(row));
    }
}