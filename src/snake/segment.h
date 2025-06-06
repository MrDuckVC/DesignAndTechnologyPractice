#pragma once

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Texture.hpp>

#include "orientation.h"

class Segment {
 public:
    enum class Type {
        Head,
        Body,
        Tail,
        Turn
    };

    Segment(sf::Vector2f pos, float size, Segment::Type type, Orientation::dirNum direction = Orientation::Stop);
    Segment(const Segment& segment);

    const Segment::Type& getType() const;
    Segment& setType(Segment::Type other);

    const Orientation::dirNum& getDirection() const;
    Segment& setDirection(Orientation::dirNum other);

    sf::Vector2f position() const;
    Segment& setPosition(const sf::Vector2f& pos);

    const float getDegrees() const;
    Segment& setRotation(float degrees0);

    Segment& setTexture(sf::Texture* texture);

    const sf::Drawable* getRectToDraw() const;

 private:
    float centre0;
    int textureSegmentWidth0;

    sf::RectangleShape rect0;

    Type type0;
    Orientation::dirNum direction0;

    void updateTextureRect();
};
