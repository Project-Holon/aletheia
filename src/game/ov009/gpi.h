#ifndef GAME_OV009_GPI_H
#define GAME_OV009_GPI_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of gpi.c, prototypes copied from their definitions. */

#include "../ov009/gpi_types.h"

int gpiInitialize(void **connection, int productID, int namespaceID, int partnerID);
void gpiDestroy(void **connection);
int gpiResetProfile(void *unused, GPIProfile *profile, void *unused3);
int gpiReset(GPConnection *connection);
int gpiProcessConnectionManager(void **connection);
int gpiProcess(void **connection, int blockingOperationID);
/* END mkheaders: generated region */

#endif
