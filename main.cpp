// Copyright (C) 2017, Kristiyan Tsaklev
// See LICENSE

#include "geo_coords.hpp"
#include<iostream>

int main() {
	GeoCoords p1 = {
		.latitude = 0,
		.longitude = 0,
	};
	GeoCoords p2 = {
		.latitude = 90,
		.longitude = 0,
	};

	auto dist = radian_distance(p1, p2);
	std::cout << dist << '\n';
}
