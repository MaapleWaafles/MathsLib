#include "AABB.h"


AABB::AABB()
{
}

AABB::~AABB()
{

}

Vector2 AABB::center() const
{
	return (minimum + maximum) * 0.5f;
}

Vector2 AABB::extents() const
{
	return { abs(maximum.x - minimum.y) * 0.5f, abs(maximum.x - minimum.y) * 0.5f};
}

std::vector<Vector2> AABB::corners() const
{
	std::vector<Vector2> corner(4);
	corner[0] = minimum;
	corner[1] = { minimum.x, maximum.y };
	corner[2] = maximum;
	corner[3] = { maximum.x, minimum.y };
	return corner;
}

void AABB::fit(const Vector2* points, unsigned int count) {
	// invalidate the extents
	minimum = { FLT_MAX, FLT_MAX };
	maximum = { FLT_MIN, FLT_MIN };
	// find min and max of the points
	for (unsigned int i = 0;
		i < count;
		++i, ++points) {
		minimum = m_min(minimum, *points);
		maximum = m_max(maximum, *points);
	}
}

void AABB::Vfit(const std::vector<Vector2>& points) {
	// invalidate the extents
	minimum = { FLT_MAX, FLT_MAX };
	maximum = { FLT_MIN, FLT_MIN };
	// find min and max of the points
	for (auto& p : points) {
		minimum = m_min(minimum, p);
		maximum = m_max(maximum, p);
	}
}

bool AABB::VecOverlaps(const Vector2 & p) const
{
	return !(p.x < minimum.x || p.y < minimum.y || p.x > maximum.x || p.y > maximum.y);
}

bool AABB::AABBoverlaps(const AABB & other) const
{
	return !(maximum.x < other.minimum.x || maximum.y < other.minimum.y || minimum.x > other.maximum.x || minimum.y > other.maximum.y);
}

Vector2 AABB::closestPoint(const Vector2 & p) const
{
	return vclamp(p, minimum, maximum);
} 
