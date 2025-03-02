/*
Program to check if collision occurs for two Axis Aligned Bounding Boxes
* author: Anurag Bhattacharyya
*/

#include <iostream>
#include <cmath>

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

struct box
{
    vec3f point1, point2, point3, point4, point5, point6, point7, point8;
    box(vec3f p1, vec3f p2, 
        vec3f p3, vec3f p4, 
        vec3f p5, vec3f p6, 
        vec3f p7, vec3f p8): 
        point1(p1), point2(p2), 
        point3(p3), point4(p4), 
        point5(p5), point6(p6),
        point7(p7), point8(p8)
        {
            boxCoords.push_back(p1);
            boxCoords.push_back(p2);
            boxCoords.push_back(p3);
            boxCoords.push_back(p4);
            boxCoords.push_back(p5);
            boxCoords.push_back(p6);
            boxCoords.push_back(p7);
            boxCoords.push_back(p8);

            calculateSizes();
        };
    
    std::vector<vec3f> boxCoords;
    vec3f minCoords();
    vec3f maxCoords();
    void calculateSizes();
    bool checkCollision(box &inputBox);
    float xSize;
    float ySize;
    float zSize;
};

bool box::checkCollision(box &inputBox)
{
    vec3f max_coords = maxCoords();
    vec3f min_coords = minCoords();

    // max and min coords of input box
    vec3f max_coords_other = inputBox.maxCoords();
    vec3f min_coords_other = inputBox.minCoords();

    /*
    std::cout << min_coords.x_ - min_coords_other.x_ <<std::endl;
    std::cout << min_coords.y_ - min_coords_other.y_ <<std::endl;
    std::cout << min_coords.z_ - min_coords_other.z_ <<std::endl;
    std::cout << xSize + inputBox.xSize << std::endl;
    std::cout << ySize + inputBox.ySize << std::endl;
    std::cout << zSize + inputBox.zSize << std::endl;
    */

    if((std::abs(min_coords.x_ - min_coords_other.x_) < xSize + inputBox.xSize) &&
        (std::abs(min_coords.y_ - min_coords_other.y_) < ySize + inputBox.ySize) &&
        (std::abs(min_coords.z_ - min_coords_other.z_) < zSize + inputBox.zSize))
        {
            return true;
        }
    else
    {
        return false;
    }
}

void box::calculateSizes()
{
    vec3f max_coords = maxCoords();
    vec3f min_coords = minCoords();

    xSize = max_coords.x_ - min_coords.x_;
    ySize = max_coords.y_ - min_coords.y_;
    zSize = max_coords.z_ - min_coords.z_;

}

vec3f box::minCoords()
{
    float minX, minY, minZ;
    vec3f minCoordinates;
    for(unsigned int i = 0; i< boxCoords.size(); i++)
    {
        vec3f coords = boxCoords[i];
        if(i==0)
        {
            minX = coords.x_;
            minY = coords.y_;
            minZ = coords.z_;
        }

        minX = std::min(coords.x_, minX);
        minY = std::min(coords.y_, minY);
        minZ = std::min(coords.z_, minZ);


    }
    minCoordinates.x_ = minX;
    minCoordinates.y_ = minY;
    minCoordinates.z_ = minZ;
    return minCoordinates;
}

vec3f box::maxCoords()
{
    float maxX, maxY, maxZ;
    vec3f maxCoordinates;
    for(unsigned int i = 0; i< boxCoords.size(); i++)
    {
        vec3f coords = boxCoords[i];
        if(i==0)
        {
            maxX = coords.x_;
            maxY = coords.y_;
            maxZ = coords.z_;
        }

        maxX = std::max(coords.x_, maxX);
        maxY = std::max(coords.y_, maxY);
        maxZ = std::max(coords.z_, maxZ);


    }
    maxCoordinates.x_ = maxX;
    maxCoordinates.y_ = maxY;
    maxCoordinates.z_ = maxZ;
    return maxCoordinates;
}

void decision(bool input)
{
    if(input){std::cout << "Collision detected"<< std::endl;}
    else{std::cout << "No collision detected"<< std::endl;}
}



int main()
{

    box box1
    (
        vec3f(1 ,1, 1), vec3f(2, 1, 1), vec3f(1, 1, 0), vec3f(2, 1, 0),
        vec3f(1 ,2, 1), vec3f(2, 2, 1), vec3f(1, 2, 0), vec3f(2, 2, 0)

    );

    box box2
    (
        vec3f(4 ,2, 1), vec3f(5, 2, 1), vec3f(4, 2, 0), vec3f(5, 2, 0),
        vec3f(4 ,3, 1), vec3f(5, 3, 1), vec3f(4, 3, 0), vec3f(5, 3, 0)

    );

    box box3
    (
        vec3f(1.5 ,1.5, 1.5), vec3f(5, 1.5, 1.5), vec3f(1.5, 1.5, 0.5), vec3f(5, 1.5, 0.5),
        vec3f(1.5 ,3, 1.5), vec3f(5, 3, 1.5), vec3f(1.5, 3, 0.5), vec3f(5, 3, 0.5)

    );

    
    decision(box1.checkCollision(box3)) ;
    
    
    return 1;
}
