#include "AABS.h"

Vector2 AABS::closestPoint(const Vector2 & p) const
{
	// distance from center
	Vector2 toPoint = p - center;
	// if outside of radius bring it back to the radius
	if (toPoint.magnitude() > radius * radius) {
		 toPoint = toPoint.normalise() * radius;
	}
	return center + toPoint;
}

void AABS::VSfit(const Vector2 * points, unsigned int count)
{
	// invalidate extents
	Vector2 min = { FLT_MAX, FLT_MAX };
	Vector2 max = { FLT_MIN, FLT_MIN };
	// find min and max of the points
	for (unsigned int i = 0; i < count; ++i, ++points) {
		min = m_min(min, *points);
		max = m_max(max, *points);
	}
	// put a circle around the min/max box
	center = (min + max) * 0.5f;
	radius = center.distance(max);
}

void AABS::Vfit(const std::vector<Vector2>& points)
{
	// invalidate extents
	Vector2 min = { FLT_MAX, FLT_MAX };
	Vector2 max = { FLT_MIN, FLT_MIN };
	// find min and max of the points
	for (auto& p : points) {
		min = m_min(min, p);
		max = m_max(max, p);
	}
	// put a circle around the min/max box
	center = (min + max) * 0.5f;
	radius = center.distance(max);
}

bool AABS::vecOverlaps(const Vector2 & p) const
{
	Vector2 toPoint = p - center;
	return toPoint.magnitude() <= (radius * radius);
}

bool AABS::aabsOverlaps(const AABS & other) const
{
	Vector2 diff = other.center - center;
	// compare distance between spheres to combined radii
	float r = radius + other.radius;
	return diff.magnitude() <= (r * r);

}

bool AABS::collOverlap(const AABB & aabb) const
{
	auto diff = aabb.closestPoint(center) - center;
	return diff.dot(diff) <= (radius * radius);
}
