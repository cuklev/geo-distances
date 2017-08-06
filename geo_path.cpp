// Copyright (C) 2017, Kristiyan Tsaklev
// See LICENSE

#include "geo_path.hpp"

void GeoPath::calc_distances() {
	distance_sums.resize(coords.size());
	distance_sums[0] = 0;
	for(unsigned i = 1; i < coords.size(); ++i)
		distance_sums[i] = radian_distance(coords[i - 1], coords[i]);
}

GeoPath::GeoPath()
	: coords()
	, distance_sums() {
	}

GeoPath::GeoPath(const std::vector<GeoCoords>& coords)
	: coords(coords) {
		calc_distances();
	}

GeoPath::GeoPath(std::vector<GeoCoords>&& coords)
	: coords(coords) {
		calc_distances();
	}

double GeoPath::get_path_length() {
	return distance_sums.back();
}

double GeoPath::get_path_length(int i, int j) {
	return distance_sums[j] - distance_sums[i];
}

double GeoPath::get_direct_distance() {
	return radian_distance(coords.front(), coords.back());
}

double GeoPath::get_direct_distance(int i, int j) {
	return radian_distance(coords[i], coords[j]);
}
