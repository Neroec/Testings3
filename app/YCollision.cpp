#include <math.h>

#include "GameManager.h"

/**
 * Определяет, произошла ли коллизия по Y
 * @param marioHeight высота Марио
 * @param marioY координата Y Марио
 * @param objectHeight высота объекта
 * @param objectY координата Y объекта
 * @returns true - если произошла, false - иначе
 */
bool yCollision(int marioHeight, int marioY, int objectHeight, int objectY)
{
    // Высота всегда больше 0
    if (marioHeight <= 0 || objectHeight <= 0)
        return false;

    // Расстояние между центрами по Y
    int dy = abs((marioY + marioHeight / 2) - (objectY + objectHeight / 2));

    // Расстояние между объектами по Y
    double distanceY = dy - marioHeight / 2 - objectHeight / 2;

    // Если объекты соприкоснулись по Y
    if (distanceY < 0) {
        return true;
    }

    return false;
}
