#pragma once
#include <cmath>

struct vect
{
	float x, y, z;
	vect() { x = y = z = 0; }
	vect(float x, float y, float z) : x(x), y(y), z(z) {}
	vect& operator+=(vect rhs) {
		x += rhs.x;
		y += rhs.y;
		z += rhs.z;
		return *this;
	}
	vect& operator-=(vect rhs) {
		x -= rhs.x;
		y -= rhs.y;
		z -= rhs.z;
		return *this;
	}
	vect& operator*=(float rhs) {
		x *= rhs;
		y *= rhs;
		z *= rhs;
		return *this;
	}
	vect& operator/=(float rhs) {
		x /= rhs;
		y /= rhs;
		z /= rhs;
		return *this;
	}
	vect operator+(vect rhs) { return vect(*this) += rhs; }
	vect operator-(vect rhs) { return vect(*this) -= rhs; }
	vect operator*(float rhs) { return vect(*this) *= rhs; }
	friend vect operator*(float lhs, vect rhs) { return rhs * lhs; }
	vect operator/(float rhs) { return vect(*this) /= rhs; }
	float operator*(vect rhs) {
		return x*rhs.x + y*rhs.y + z*rhs.z;
	}
	vect operator^(vect rhs) {
		return vect(y*rhs.z - z*rhs.y, z*rhs.x - x*rhs.z, x*rhs.y - y*rhs.x);
	}
	float sqrl() {
		return x*x + y*y + z*z;
	}
	float length() {
		return sqrt(sqrl());
	}
	vect& normalize() {
		return (*this) /= length();
	}
	vect norm() {
		return vect(*this).normalize();
	}
	bool operator==(vect rhs) {
		return x == rhs.x && y == rhs.y && z == rhs.z;
	}
	bool operator!=(vect rhs) { return !((*this) == rhs); }
};