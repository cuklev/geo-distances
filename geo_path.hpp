// Copyright (C) 2017, Kristiyan Tsaklev
// See LICENSE

#ifndef __GEO_PATH_HPP
#define __GEO_PATH_HPP

#include "geo_coords.hpp"
#include<vector>

class GeoPath {
	private:
		std::vector<GeoCoords> coords;
		std::vector<double> distance_sums;

		void calc_distances();

	public:
		GeoPath();
		GeoPath(const std::vector<GeoCoords>&);
		GeoPath(std::vector<GeoCoords>&&);

		void add_point(const GeoCoords&);
		void add_points(const std::vector<GeoCoords>&);

		double get_path_length();
		double get_path_length(int, int);

		double get_direct_distance();
		double get_direct_distance(int, int);
};

#endif
