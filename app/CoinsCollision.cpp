#include <cmath>

#include "GameManager.h"

/**
 * Изменяет вектор с монетками в зависимости от коллизии
 * @param marioWidth ширина Марио
 * @param marioHeight высота Марио
 * @param marioX координата X Марио
 * @param marioY координата Y Марио
 * @param objects вектор монеток
 * @returns новый вектор с монетками
 */
vector<int> coinsCollision(int marioWidth, int marioHeight, int marioX, int marioY, vector<int> objects)
{
    int i, j, count;
    j = 3, count = objects[0];

    // Размеры объектов
    int objectWidth, objectHeight;
    objectWidth = objects[1], objectHeight = objects[2];

    // Коллизии нет, если размеры не больше 0
    if (marioWidth <= 0 || marioHeight <= 0 || objectWidth <= 0 || objectHeight <= 0)
        return objects;

    // Для каждого объекта
    for (i = 0; i < count; i++) {
        // Если одновременная коллизия по двум координатам
        if (xCollision(marioWidth, marioX, objectWidth, objects[j])
         && yCollision(marioHeight, marioY, objectHeight, objects[j+1])) {

           // "Собираем" монетку
           objects.erase(objects.begin()+j);
           objects.erase(objects.begin()+j);

           j -= 2;
           count--;
           i--;
           objects[0] = count;

        }

        // Следующий объект
        j += 2;
    }

    return objects;
}
