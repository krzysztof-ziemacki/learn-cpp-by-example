#include <algorithm>
#include <cassert>
#include <format>
#include <iostream>
#include <iterator>
#include <cmath>
#include <numeric>
#include <ranges>
#include <vector>

auto generate_next_row(const std::vector<int> &last_row)
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

auto generate_triangle(int number_of_rows)
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

int main()
{
    auto triangle = generate_triangle(15);     
    show_triangle(std::cout, triangle);
}
