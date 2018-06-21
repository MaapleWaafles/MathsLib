#pragma once
#include "Vector2.h"
#include <math.h>
#include <vector>
using std::vector;
class AABB
{
public:
	AABB();
	AABB(const Vector2& min, const Vector2& max) : minimum(min), maximum(max) {}
	~AABB();

	Vector2 minimum, maximum;
	Vector2 center() const;
	Vector2 extents() const;
	std::vector<Vector2> corners() const;
	void fit(const Vector2* points, unsigned int count);
	void Vfit(const std::vector<Vector2>& points);
	bool VecOverlaps(const Vector2& p) const;
	bool AABBoverlaps(const AABB& other) const;
	Vector2 closestPoint(const Vector2& p) const;

	float min(float a, float b) const {
		return a < b ? a : b;
	}
	float max(float a, float b) const {
		return a > b ? a : b;
	}
	float clamp(float t, float a, float b){
		return max(a, min(b, t));
	}
	Vector2 m_min(const Vector2& a, const Vector2& b) const {
		return { min(a.x, b.x), min(a.y, b.y) };
	}
	Vector2 m_max(const Vector2& a, const Vector2&  b) const{
		return { max(a.x, b.x), max(a.y, b.y) };
	}
	Vector2 vclamp(const Vector2& t, const Vector2& a, const Vector2& b) const{
		return m_max(a, m_min(b, t));
	}
};

 