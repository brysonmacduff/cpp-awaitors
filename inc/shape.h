#include <ostream>
#include <vector>

namespace Geometry
{
class Shape
{
    static constexpr float DEGREES_2PI = 360.0;

    public:
        Shape() = delete;
        // default constructor
        Shape(int side_count);
        // elaborate constructor for receiving angles
        Shape(const std::vector<float>& angles);
        // copy constructor
        Shape(const Shape& shape);
        int GetSideCount() const;
        Shape& operator=(const Shape& rhs);
        bool operator==(const Shape& rhs) const;
        std::vector<float>::iterator AnglesBegin();
        std::vector<float>::iterator AnglesEnd();

        friend std::ostream& operator<<(std::ostream& stream, const Shape& shape)
        {
            stream << "Side Count: " << shape.side_count << " | ";
            stream << "Angles: [ ";

            for(auto it = shape.angles.begin(); it != shape.angles.end(); ++it)
            {
                stream << *it << " ";
            }

            stream << "]";

            return stream;
        }

    private:
        int side_count;
        std::vector<float> angles;
        
};
}