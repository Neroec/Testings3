#include <cmath>

#include "GameManager.h"

/**
 * Определяет, произошла ли коллизия по Y
 * @param marioWidth ширина Марио
 * @param marioX координата X Марио
 * @param objectWidth ширина объекта
 * @param objectX координата X объекта
 * @returns true - если произошла, false - иначе
 */
bool xCollision(int marioWidth, int marioX, int objectWidth, int objectX)
{
    // Ширина всегда больше 0
    if (marioWidth <= 0 || objectWidth <= 0)
        return false;
 
    // Расстояние между центрами по X
    int dx = abs((marioX + marioWidth / 2) - (objectX + objectWidth / 2));

    // Расстояние между объектами по X
    int distanceX = dx - marioWidth / 2 - objectWidth / 2;

    // Если объекты соприкоснулись по X
    if (distanceX <= 0) {
        return true;
    }

    return false;
}
