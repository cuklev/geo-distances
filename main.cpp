// Copyright (C) 2017, Kristiyan Tsaklev
// See LICENSE

#include "geo_path.hpp"
#include "read_path.hpp"
#include<iostream>
#include<vector>

int main() {
	auto path = read_path(std::cin);

	auto path_length = path.get_path_length();
	auto direct_distance = path.get_direct_distance();

	std::cout << "Traversed: " << path_length << '\n';
	std::cout << "Direct: " << path_length << '\n';
	std::cout << "Efficiency: " << direct_distance / path_length * 100 << "%\n";
}
