#ifndef GAME_OV009_GPICALLBACK_H
#define GAME_OV009_GPICALLBACK_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of gpicallback.c, prototypes copied from their definitions. */

#include "../ov009/gpi_types.h"

int gpiCallErrorCallback(void **connection, int result, int fatal);
int gpiAddCallback(void **connection, GPICallback callback, void *arg, GPIOperation *operation, int type);
void gpiCallCallback(void **connection, GPICallbackData *data);
int gpiProcessCallbacks(void **connection, int blockingOperationID);
/* END mkheaders: generated region */

#endif
