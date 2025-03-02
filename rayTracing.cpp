#include <iostream>
#include <algorithm>
#include <cmath>
#include <cassert>


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


struct ray
{
    vec3f origin_;
    vec3f normalizedDirection_;
    ray(vec3f origin, vec3f normalizedDirection):origin_(origin), normalizedDirection_(normalizedDirection)
    {
        //check if ray is normalized or not
        float xComp = normalizedDirection_.x_;
        float yComp = normalizedDirection_.y_;
        float zComp = normalizedDirection_.z_;
        float qoi = xComp*xComp + yComp*yComp + zComp*zComp;
        //std::cout << qoi << std::endl;
        if(std::abs(qoi-1.0) >  1e-05){throw std::invalid_argument("direction not normalized");}

    };

};

struct sphere
{
    vec3f center_;
    float radius_;
    sphere(vec3f center, float radius):center_(center), radius_(radius){};
};

void checkIntersection(ray &sunlight, sphere &globe)
{
    vec3f L = globe.center_ - sunlight.origin_;

    // project L along the ray
    float tca = L.dotProduct(sunlight.normalizedDirection_);
    if(tca < 0){std::cout << " object behind the ray" << std::endl;}
    float d2 = L.dotProduct(L) - tca * tca;
    if(d2 > globe.radius_ ){std::cout << "ray not touching or intersecting" << std::endl;}
    float tch = std::sqrt(globe.radius_ * globe.radius_ - d2 * d2);

    float t0 = tca - tch;
    float t1 = tca + tch;

    vec3f intersectionPoint1 = sunlight.origin_ +  sunlight.normalizedDirection_ * t0;
    vec3f intersectionPoint2 = sunlight.origin_ +  sunlight.normalizedDirection_ * t1;

    if(t0>0 && t1>0 )
    {
        
        if(t0 == t1 )
        {
            std::cout << " ray touching the object " << std::endl;
        }
        std::cout << "Object in front of us and ray intersecting the object" << std::endl;
        intersectionPoint1.showPoint();
        intersectionPoint2.showPoint();
        
    }
    
    if(t0<0 && t1>0 ){std::cout << " ray origin inside the object " << std::endl;}
    if(t0<0 && t1<0 ){std::cout << " object behind the ray " << std::endl;}
}


int main()
{
    // define the object
    vec3f globe_center(2.0, 3.0, 4.0); 
    sphere globe(globe_center, 3.0);

    // define the ray
    vec3f rayOrigin(1.0, 1.0, 1.0); 
    vec3f rayDirection(1.0, 3.0, 2.0);
    ray sunlight(rayOrigin, rayDirection.normalize());

    checkIntersection(sunlight, globe);
    


    return 1;
}