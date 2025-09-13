#pragma once

#include <iostream>
#include <stdexcept>
#include <cmath>
#include <sstream>

class Complex {
    private:
        float re;
        float im;

    public:
        Complex() : re(0.0f), im(0.0f) {}
        Complex(float r, float i) : re(r), im(i) {}
        Complex(float r) : re(r), im(0.0f) {}

        float Re() const { return re; }
        float Im() const { return im; }

        /*** OPERATORS ***/

        Complex operator+(const Complex& other) const {
            return Complex(re + other.Re(), im + other.Im());
        }
        Complex operator-(const Complex& other) const {
            return Complex(re - other.Re(), im - other.Im());
        }
        Complex operator*(const Complex& other) const {
            return Complex(re * other.Re() - im * other.Im(),
                           re * other.Im() + im * other.Re());
        }
        Complex operator*(float scalar) const {
            return Complex(re * scalar, im * scalar);
        }
        Complex operator/(const Complex& other) const {
            float denom = other.Re() * other.Re() + other.Im() * other.Im();
            if (denom == 0.0f) {
                throw std::runtime_error("Division by zero in complex division");
            }
            return Complex( (re * other.Re() + im * other.Im()) / denom,
                           (im * other.Re() - re * other.Im()) / denom);
        }
        Complex operator-() const {
            return Complex(-re, -im);
        }
        Complex operator++() {
            re += 1.0f;
            return *this;
        }
        Complex operator--() {
            re -= 1.0f;
            return *this;
        }
        Complex operator+=(const Complex& other) {
            re += other.Re();
            im += other.Im();
            return *this;
        }
        Complex operator-=(const Complex& other) {
            re -= other.Re();
            im -= other.Im();
            return *this;
        }
        Complex operator*=(const Complex& other) {
            float r = re * other.Re() - im * other.Im();
            float i = re * other.Im() + im * other.Re();
            re = r;
            im = i;
            return *this;
        }
        Complex operator/=(const Complex& other) {
            float denom = other.Re() * other.Re() + other.Im() * other.Im();
            if (denom == 0.0f) {
                throw std::runtime_error("Division by zero in complex division");
            }
            float r = (re * other.Re() + im * other.Im()) / denom;
            float i = (im * other.Re() - re * other.Im()) / denom;
            re = r;
            im = i;
            return *this;
        }
        Complex operator=(const Complex& other) {
            re = other.Re();
            im = other.Im();
            return *this;
        }
        bool operator==(const Complex& other) const {
            return re == other.Re() && im == other.Im();
        }
        bool operator!=(const Complex& other) const {
            return !(*this == other);
        }

        /*** UTILS ***/

        float abs() const {
            return std::sqrt(re * re + im * im);
        }
        friend std::ostream& operator<<(std::ostream& os, const Complex& c) {
            os << c.Re() << (c.Im() >= 0 ? "+" : "") << c.Im() << "i";
            return os;
        }
}; 
