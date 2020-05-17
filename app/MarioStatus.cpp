#include "GameManager.h"

/**
 * Определяет новый статус (спрайт) Марио
 * @param xVelocity скорость по X
 * @param yVelocity скорость по Y
 * @param oldStatus старый статус
 * @returns новый статус
 */
string marioStatus(int xVelocity, int yVelocity, string oldStatus)
{
    string newStatus = oldStatus;

    if (yVelocity == 0) {
        if (xVelocity != 0 ) {
            if (xVelocity > 0) {
                if (oldStatus != "StopRight") newStatus = "StopRight";
                else newStatus = "MoveRight";
            } else {
                if (oldStatus != "StopLeft") newStatus = "StopLeft";
                else newStatus = "MoveLeft";
            }
        } else {
            if (oldStatus == "MoveRight") newStatus = "StopRight";
            else if (oldStatus == "MoveLeft") newStatus = "StopLeft";
        }
    } else {
        if (xVelocity != 0) {
            if (xVelocity > 0) newStatus = "MoveRight";
            else newStatus = "MoveLeft";
        } else {
            if (oldStatus == "StopRight" || oldStatus == "MoveRight") newStatus = "MoveRight";
            else newStatus = "MoveLeft";
        }
    }

    if (newStatus != "StopRight" && newStatus != "StopLeft" && newStatus != "MoveRight" && newStatus != "MoveLeft")
        newStatus = "StopRight";

    return newStatus;
}
