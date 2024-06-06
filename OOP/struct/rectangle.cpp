#include <iostream>

struct Rectangle{
    float length;
    float width;

    Rectangle(){
        length = 0;
        width = 0;
    }

    Rectangle(float length, float width) {
        if(length <= 0 || width <= 0){
            std::cout << "Length and width must be positive values!\n";
            this->length = 0;
            this->width = 0;
            return;
        }
        
        this->length = length;
        this->width = width;
    }

    bool setLength(float length){
        if(length <= 0){
            std::cout << "Length must be positive value!\n";
            return false;
        }

        this->length = length;
        return true;
    }

    bool setWidth(float width){
        if(width <= 0){
            std::cout << "Width must be positive value!\n";
            return false;
        }

        this->width = width;
        return true;
    }

    float getLength() {
        return length;
    }

    float getWidth() {
        return width;
    }
    
    float getPerimeter(){
        return 2 * (length + width);
    }

    float getArea(){
        return length * width;
    }

    bool isSquare(){
        return length == width;
    }
};

int main() {
    Rectangle rectangle(5, 3);

    std::cout << "Length: " << rectangle.getLength() << "\n";
    std::cout << "Width: " << rectangle.getWidth() << "\n";
    std::cout << "Perimeter: " << rectangle.getPerimeter() << "\n";
    std::cout << "Area: " << rectangle.getArea() << "\n";
    std::cout << "This rectangle is" << (rectangle.isSquare() ? " " : " NOT " ) << "a square!\n";

    std::cout << "\n---Changing parameters---\n\n";
    rectangle.setLength(4);
    rectangle.setWidth(4);

    std::cout << "Length: " << rectangle.getLength() << "\n";
    std::cout << "Width: " << rectangle.getWidth() << "\n";
    std::cout << "Perimeter: " << rectangle.getPerimeter() << "\n";
    std::cout << "Area: " << rectangle.getArea() << "\n";
    std::cout << "This rectangle is" << (rectangle.isSquare() ? " " : " NOT " ) << "a square!\n";

    return 0;
}