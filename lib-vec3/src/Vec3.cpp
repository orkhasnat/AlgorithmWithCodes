#include "Vec3.h"

#include <cmath>

#include "Util.h"

Vec3::Vec3(double x, double y, double z) : m_Values{x, y, z} {}

Vec3::Vec3(double v) : Vec3{v, v, v} {}

Vec3::Vec3() : Vec3{0.0, 0.0, 0.0} {}

double& Vec3::x() { return m_Values[0]; }
double& Vec3::y() { return m_Values[1]; }
double& Vec3::z() { return m_Values[2]; }

bool Vec3::operator==(const Vec3& other) const {
    return (DoubleEq(m_Values[0], other.m_Values[0]) &&
            DoubleEq(m_Values[1], other.m_Values[1]) &&
            DoubleEq(m_Values[2], other.m_Values[2]));
}

bool Vec3::operator!=(const Vec3& other) const { return !(*this == other); }

Vec3 Vec3::operator-() const {
    return Vec3{-m_Values[0], -m_Values[1], -m_Values[2]};
}
double Vec3::operator[](size_t index) const { return m_Values[index]; }
double& Vec3::operator[](size_t index) { return m_Values[index]; }

Vec3& Vec3::operator+=(const Vec3& other) {
    m_Values[0] += other.m_Values[0];
    m_Values[1] += other.m_Values[1];
    m_Values[2] += other.m_Values[2];
    return *this;
}

Vec3& Vec3::operator*=(const double t) {
    m_Values[0] *= t;
    m_Values[1] *= t;
    m_Values[2] *= t;
    return *this;
}

Vec3& Vec3::operator/=(const double t) {
    m_Values[0] /= t;
    m_Values[1] /= t;
    m_Values[2] /= t;
    return *this;
}

Vec3 Vec3::operator+(const Vec3& other) const {
    return Vec3{m_Values[0] + other.m_Values[0],
                m_Values[1] + other.m_Values[1],
                m_Values[2] + other.m_Values[2]};
}

Vec3 Vec3::operator+(double t) const {
    return Vec3{m_Values[0] + t, m_Values[1] + t, m_Values[2] + t};
}

Vec3 Vec3::operator-(const Vec3& other) const {
    return Vec3{m_Values[0] - other.m_Values[0],
                m_Values[1] - other.m_Values[1],
                m_Values[2] - other.m_Values[2]};
}

Vec3 Vec3::operator-(double t) const {
    return Vec3{m_Values[0] - t, m_Values[1] - t, m_Values[2] - t};
}

Vec3 Vec3::operator*(const Vec3& other) const {
    return Vec3{m_Values[0] * other.m_Values[0],
                m_Values[1] * other.m_Values[1],
                m_Values[2] * other.m_Values[2]};
}

Vec3 Vec3::operator*(double t) const {
    return Vec3{m_Values[0] * t, m_Values[1] * t, m_Values[2] * t};
}

Vec3 Vec3::operator/(const Vec3& other) const {
    return Vec3{m_Values[0] / other.m_Values[0],
                m_Values[1] / other.m_Values[1],
                m_Values[2] / other.m_Values[2]};
}

Vec3 Vec3::operator/(double t) const {
    return Vec3{m_Values[0] / t, m_Values[1] / t, m_Values[2] / t};
}

double Vec3::LengthSquared() const {
    return (m_Values[0] * m_Values[0]) + (m_Values[1] * m_Values[1]) +
           (m_Values[2] * m_Values[2]);
}

double Vec3::Length() const { return sqrt(this->LengthSquared()); }

double Vec3::Dot(const Vec3& v1, const Vec3& v2) {
    return v1.m_Values[0] * v2.m_Values[0] + v1.m_Values[1] * v2.m_Values[1] +
           v1.m_Values[2] * v2.m_Values[2];
}

double Vec3::Dot(const Vec3& other) const {
    return m_Values[0] * other.m_Values[0] + m_Values[1] * other.m_Values[1] +
           m_Values[2] * other.m_Values[2];
}

Vec3 Vec3::Cross(const Vec3& v1, const Vec3& v2) {
    double a =
        v1.m_Values[1] * v2.m_Values[2] - v1.m_Values[2] * v2.m_Values[1];
    double b =
        v1.m_Values[2] * v2.m_Values[0] - v1.m_Values[0] * v2.m_Values[2];
    double c =
        v1.m_Values[0] * v2.m_Values[1] - v1.m_Values[1] * v2.m_Values[0];
    return Vec3{a, b, c};
}

Vec3 Vec3::Cross(const Vec3& other) const {
    double a =
        m_Values[1] * other.m_Values[2] - m_Values[2] * other.m_Values[1];
    double b =
        m_Values[2] * other.m_Values[0] - m_Values[0] * other.m_Values[2];
    double c =
        m_Values[0] * other.m_Values[1] - m_Values[1] * other.m_Values[0];
    return Vec3{a, b, c};
}

bool Vec3::NearZero() const {
    return abs(m_Values[0]) <= K_EPSILON && abs(m_Values[1]) <= K_EPSILON &&
           abs(m_Values[2]) <= K_EPSILON;
}

Vec3 Vec3::Random() {
    double a = RandomDouble(0.0, 1.0);
    double b = RandomDouble(0.0, 1.0);
    double c = RandomDouble(0.0, 1.0);
    return Vec3(a, b, c);
}

Vec3 Vec3::Random(double min, double max) {
    double a = RandomDouble(min, max);
    double b = RandomDouble(min, max);
    double c = RandomDouble(min, max);
    return Vec3(a, b, c);
}

Vec3 operator+(double t, const Vec3& v) { return Vec3{v + t}; }

Vec3 operator-(double t, const Vec3& v) { return Vec3{v - t}; }

Vec3 operator*(double t, const Vec3& v) { return Vec3{v * t}; }

Vec3 operator/(double t, const Vec3& v) { return Vec3{v / t}; }

Vec3 UnitVector(const Vec3& v) {
    return Vec3{v / v.Length()};
}

double Angle(const Vec3& vec1, const Vec3& vec2) {
    double dot = Vec3::Dot(vec1, vec2);
    double len1 = vec1.Length();
    double len2 = vec2.Length();
    return acos(dot / (len1 * len2));
}
