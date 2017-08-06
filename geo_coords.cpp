// Copyright (C) 2017, Kristiyan Tsaklev
// See LICENSE

#include "geo_coords.hpp"
#include<cmath>

inline double to_radians(double degrees) {
	return degrees * M_PI / 180.;
}

double radian_distance(const GeoCoords& p1, const GeoCoords& p2) {
	auto a1 = to_radians(p1.longitude);
	auto g1 = to_radians(p1.latitude);
	auto a2 = to_radians(p2.longitude);
	auto g2 = to_radians(p2.latitude);
	auto cos_theta = cos(g1) * cos(g2) * cos(a1 - a2) + sin(g1) * sin(g2);
	return acos(cos_theta);
}
