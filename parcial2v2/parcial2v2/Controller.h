/*
 * Controller.h
 *
 *  Created on: 29 jun. 2020
 *      Author: franc
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_
#include "LinkedList.h"

int controller_saveAsText(char* path , LinkedList* auxBicicleta);
int controller_loadFromText(char* path , LinkedList* bicicleta);

#endif /* CONTROLLER_H_ */

