// cpp-template headers
#include "shape.h"

// standard library headers
#include <iostream>

using namespace Geometry;

Shape::Shape(int side_count)
{
    this->side_count = side_count;
    this->angles = std::vector<float>(side_count);

    for(auto it = angles.begin(); it != angles.end(); ++it)
    {
        *(it) = DEGREES_2PI/static_cast<float>(side_count);
    }
}

Shape::Shape(const std::vector<float>& angles)
{
    side_count = angles.size();
    this->angles = std::vector<float>();
    std::copy(angles.begin(),angles.end(),std::back_inserter(this->angles));
}

Shape::Shape(const Shape& shape)
{
    this->side_count = shape.side_count;
    angles = std::vector<float>();
    std::copy(shape.angles.begin(),shape.angles.end(),std::back_inserter(angles));
}

int Shape::GetSideCount() const
{
    return side_count;
}

Shape& Shape::operator=(const Shape& rhs)
{
    if(this == &rhs)
    {
        return *this;
    }

    side_count = rhs.side_count;
    angles = std::vector<float>();
    std::copy(rhs.angles.begin(),rhs.angles.end(),std::back_inserter(angles));
    return *this;
}

bool Shape::operator==(const Shape& rhs) const
{
    if(rhs.side_count != side_count)
    {
        return false;
    }

    for(int i = 0; i < side_count; ++i)
    {
        if(angles[i] != rhs.angles[i])
        {
            return false;
        }
    }

    return true;
}

std::vector<float>::iterator Shape::AnglesBegin()
{
    return angles.begin();
}

std::vector<float>::iterator Shape::AnglesEnd()
{
    return angles.end();
}