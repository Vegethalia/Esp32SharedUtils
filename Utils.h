#include <string>
#include <math.h>

#define EARTH_RADIUS_METERS 6371000

class Utils {
public:
	template<typename ... Args>
	static std::string string_format(const std::string& format, Args ... args)
	{
		size_t size = snprintf(nullptr, 0, format.c_str(), args ...) + (size_t)1; // Extra space for '\0'
		std::unique_ptr<char[]> buf(new char[size]);
		snprintf(buf.get(), size, format.c_str(), args ...);
		return std::string(buf.get(), buf.get() + size - 1); // We don't want the '\0' inside
	}

	static float DistanceBetween2Points(float Lat1, float Lon1, float Lat2, float Lon2, float unit_conversion)
	{
		float dLat = radians(Lat2 - Lat1);
		float dLon = radians(Lon2 - Lon1);

		float a = sin(dLat / 2.0f) * sin(dLat / 2.0f) +
			cos(radians(Lat1)) * cos(radians(Lat2)) *
			sin(dLon / 2.0f) * sin(dLon / 2.0f);

		float d = 2.0f * atan2(sqrt(a), sqrt(1.0f - a));

		return d * EARTH_RADIUS_METERS * unit_conversion;
	}


};
