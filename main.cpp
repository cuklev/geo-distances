// Copyright (C) 2017, Kristiyan Tsaklev
// See LICENSE

#include "geo_coords.hpp"
#include "geo_path.hpp"
#include<iostream>
#include<vector>

int main() {
	GeoCoords p1 = {
		.latitude = 0,
		.longitude = 0,
	};

	std::vector<GeoCoords> points = {p1};

	for(int i = 0; i < 100; ++i) {
		p1.latitude += 0.1;
		points.push_back(p1);
	}

	GeoPath path(points);
	std::cout << path.get_path_length() << '\n';
	std::cout << path.get_direct_distance() << '\n';
}
