#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <iostream>
#include <vector>

using namespace std;

bool xCollision(int marioWidth, int marioX, int objectWidth, int objectX);
bool yCollision(int marioHeight, int marioY, int objectHeight, int objectY);

vector<int> objectsCollision(int marioWidth, int marioHeight, int marioX, int marioY, int marioXVelocity, int marioYVelocity, vector<int> objects);
vector<int> coinsCollision(int marioWidth, int marioHeight, int marioX, int marioY, vector<int> objects);
string marioStatus(int xVelocity, int yVelocity, string oldStatus);
vector<int> objectsStorage(int stage);

#endif // GAMEMANAGER_H
