#ifndef __GEO_COORDS_HPP
#define __GEO_COORDS_HPP

struct GeoCoords {
	double latitude;
	double longitude;
};

double radian_distance(const GeoCoords&, const GeoCoords&);

#endif
