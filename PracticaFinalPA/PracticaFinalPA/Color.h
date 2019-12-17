//
// Created by rcabido on 7/11/19.
//

#ifndef ENGINE_HERENCIA_COLOR_H
#define ENGINE_HERENCIA_COLOR_H


class Color {

private:
    float red;
    float green;
    float blue;
public:
    Color(float redToSet = 0.0, float greenToSet = 0.0, float blueToSet = 0.0) : red(redToSet), green(greenToSet),
                                                                                 blue(blueToSet) {}

    float getRed() const { return this->red; }

    float getGreen() const { return this->green; }

    float getBlue() const { return this->blue; }

    void setRed(const float &redToSet) { this->red = (redToSet >= 0.0 && redToSet <= 1.0 ? redToSet : this->red); }

    void setGreen(const float &greenToSet) {
        this->red = (greenToSet >= 0.0 && greenToSet <= 1.0 ? greenToSet : this->green);
    }

    void setBlue(const float &blueToSet) {
        this->red = (blueToSet >= 0.0 && blueToSet <= 1.0 ? blueToSet : this->blue);
    }
};


#endif //ENGINE_HERENCIA_COLOR_H
