// Copyright (C) 2017, Kristiyan Tsaklev
// See LICENSE

#include "read_path.hpp"
#include "geo_coords.hpp"

#include<vector>

GeoPath read_path(std::istream& in) {
	std::vector<GeoCoords> points;

	while(in) {
		double lat, lng;
		in >> lat >> lng;
		points.push_back({
			.latitude = lat,
			.longitude = lng,
		});
	}

	return GeoPath(std::move(points));
}
