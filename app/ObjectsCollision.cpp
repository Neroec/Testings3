#include <cmath>

#include "GameManager.h"

/**
 * Изменяет координаты и скорость Марио в зависимости ок коллизии
 * @param marioWidth ширина Марио
 * @param marioHeight высота Марио
 * @param marioX координата X Марио
 * @param marioY координата Y Марио
 * @param marioXVelocity скорость Марио по X
 * @param marioYVelocity скорость Марио по Y
 * @param objects вектор объектов
 * @returns вектор новых значений для Марио
 * ([0] - новый X, [1] - новый Y, [2] - новый yVelocity, [3] - сторона коллизии по Y)
 */
vector<int> objectsCollision(int marioWidth, int marioHeight, int marioX, int marioY, int marioXVelocity, int marioYVelocity, vector<int> objects)
{
    int i, j, count, sideX, sideY, distanceX, distanceY;
    j = 3, count = objects[0], sideX = 0, sideY = 0;

    // Размеры объектов
    int objectWidth, objectHeight;
    objectWidth = objects[1], objectHeight = objects[2];

    // Вектор новых координат, скорости по вертикали и стороны коллизии
    vector<int> collis = { marioX, marioY, marioYVelocity, 0};

    // Коллизии нет, если размеры не больше 0
    if (marioWidth <= 0 || marioHeight <= 0 || objectWidth <= 0 || objectHeight <= 0)
        return collis;

    // Для каждого объекта
    for (i = 0; i < count; i++) {
        // Если одновременная коллизия по двум координатам
        if (xCollision(marioWidth, marioX, objectWidth, objects[j])
         && yCollision(marioHeight, marioY, objectHeight, objects[j+1])) {

            // Расстояние между объектами
            distanceX = abs((marioX + marioWidth / 2) - (objects[j] + objectWidth / 2)) - marioWidth / 2 - objectWidth / 2;
            distanceY = abs((marioY + marioHeight / 2) - (objects[j+1] + objectHeight / 2)) - marioHeight / 2 - objectHeight / 2;

            // Определяем сторону коллизии по горизонтали
            // (1 - право объекта, 2 - лево)
            if (distanceX < 0 && marioYVelocity == 0) {
                if (distanceX - marioXVelocity >= 0) sideX = 1;
                else if (distanceX + marioXVelocity >= 0) sideX = 2;
            } else if (distanceX <= 0){
                if (distanceX - marioXVelocity >= 0) { sideX = 1; marioX++; distanceY = 0; }
                else if (distanceX + marioXVelocity >= 0) { sideX = 2; marioX--; distanceY = 0; }
            }

            // Определяем сторону коллизии по вертикали
            // (1 - верх объекта, 2 - низ)
            if (distanceY < 0) {
                if (distanceY + marioYVelocity >= 0) sideY = 1;
                else if (distanceY - marioYVelocity >= 0) sideY = 2;
            }

            // Меняем координаты по X
            switch(sideX) {
            case 1:
                marioX = marioX - distanceX;
                break;
            case 2:
                marioX = marioX + distanceX;
                break;
            }

            // Меняем координаты и скорость по Y
            switch(sideY) {
            case 1:
                marioY = marioY + distanceY;
                marioYVelocity = 0;
                break;
            case 2:
                marioY = marioY - distanceY;
                marioYVelocity = 0;
                break;
            }

            // Если объект в Марио
            if (objects[j] > marioX && objects[j] < marioX + marioWidth && marioXVelocity != 0 && marioYVelocity != 1) {
                marioX--;
            }

            // Сохраняем новые координаты
            collis[0] = marioX;
            collis[1] = marioY;

            // Сохраняем новую скорость по Y и сторону вертикальной коллизии
            collis[2] = marioYVelocity;
            collis[3] = sideY;

            // Обнуляем стороны коллизии
            sideX = 0;
            sideY = 0;
        }

        // Следующий объект
        j += 2;
    }

    return collis;
}
