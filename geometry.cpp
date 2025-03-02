#include <iostream>
#include <vector>
#include <cmath>
/*
*  Program to check whether a point like inside or on boundary or a triangle
or outside the triangle
*
*/
struct vec3f
{
    float x_;
    float y_;
    float z_;
    vec3f(): x_(0), y_(0), z_(0){};
    vec3f(float x, float y, float z): x_(x), y_(y), z_(z){};

    float dotProduct(vec3f vectorInput);
    vec3f operator-(vec3f const &vectorInput);
    vec3f operator+(vec3f const &vectorInput);
    vec3f operator*(float &scalar);
    void showPoint();
    vec3f normalize();
    

};

vec3f vec3f::normalize()
{
    vec3f normalizedCoords;
    float norm = std::sqrt(x_ * x_ + y_ * y_ + z_ * z_);
    normalizedCoords.x_ = x_/norm;
    normalizedCoords.y_ = y_/norm;
    normalizedCoords.z_ = z_/norm;

    return normalizedCoords;
}

void vec3f::showPoint()
{
    std::cout << x_ << " " << y_ << " " << z_<< std::endl;
}

vec3f vec3f::operator-(vec3f const &vectorInput)
{
    vec3f subtract;
    subtract.x_ = x_ - vectorInput.x_;
    subtract.y_ = y_ - vectorInput.y_;
    subtract.z_ = z_ - vectorInput.z_;
    return subtract;
}

vec3f vec3f::operator+(vec3f const &vectorInput)
{
    vec3f subtract;
    subtract.x_ = x_ + vectorInput.x_;
    subtract.y_ = y_ + vectorInput.y_;
    subtract.z_ = z_ + vectorInput.z_;
    return subtract;
}

vec3f vec3f::operator*(float &scalar)
{
    vec3f multiplied;
    multiplied.x_ = scalar * x_;
    multiplied.y_ = scalar * y_;
    multiplied.z_ = scalar * z_;
    return multiplied;
}


float vec3f::dotProduct(vec3f vectorInput)
{
    return vectorInput.x_ * x_ + vectorInput.y_ * y_ + vectorInput.z_ * z_;
}
class triangle
{
public:    
    triangle(vec3f, vec3f, vec3f);
    std::vector<vec3f> coords;
    bool isInside(vec3f p);
    float det(vec3f, vec3f, vec3f);
private:
};

float triangle::det(vec3f p1, vec3f p2, vec3f p3)
{
    float DET = p1.x_*(p2.y_*p3.z_ - p3.y_*p2.z_) - p2.x_*(p1.y_*p3.z_ - p3.y_*p1.z_) + p3.x_*(p1.y_*p2.z_ - p2.y_*p1.z_);
    return DET;
}

bool triangle::isInside(vec3f point)
{

    float DET = det(coords[0], coords[1], coords[2]);

    float r = det(point, coords[1], coords[2]) / DET ;
    float s = det(coords[0], point, coords[2]) / DET ;
    float t = det(coords[0], coords[1],  point) / DET ;

    std::cout << r << " "<<  s <<" "<< t<< " " << DET<< std::endl;
    std::cout << r+s+t<< std::endl;
    if(r<=1 && r>=0 && s<=1 && s>=0 && t<=1 && t>=0){return true;}
    else{return false;}



}

triangle::triangle(vec3f p1, vec3f p2, vec3f p3)
{
    coords.push_back(p1);
    coords.push_back(p2);
    coords.push_back(p3);
}

void shout(bool val)
{
    if(val){std::cout << "Inside triangle" << std::endl;}
    else{std::cout << "Outside triangle" << std::endl;}
}

int main()
{
    triangle face
    (
        vec3f(1.0, 1.0, 1.0), vec3f(2.0, 1.0, 1.0), vec3f(2.0, 2.0, 1.0)
    );

    shout(face.isInside(vec3f(2.0, 2.0, 1.0)));


}