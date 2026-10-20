#ifndef GAME_OV009_GPIOPERATION_H
#define GAME_OV009_GPIOPERATION_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of gpioperation.c, prototypes copied from their definitions. */

#include "../ov009/gpi_types.h"

int gpiFailedOpCallback(void **connection, const GPIOperation *operation);
int gpiAddOperation(void **connection, int type, void *data, GPIOperation **op, int blocking, void (*callback)(void **, void *, void *), void *param);
void gpiDestroyOperation(void **connection, GPIOperation *operation);
void gpiRemoveOperation(void **connection, GPIOperation *operation);
int gpiFindOperationByID(void **connection, GPIOperation **operation, int id);
int gpiOperationsAreBlocking(char *p);
int gpiProcessOperation(void **connection, GPIOperation *operation, char *input);
/* END mkheaders: generated region */

#endif
