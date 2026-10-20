#ifndef GAME_OV175_SCIINTERFACE_H
#define GAME_OV175_SCIINTERFACE_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of sciinterface.c, prototypes copied from their definitions. */

#include "../ov175/sc_types.h"

int sciInterfaceCreate(SCInterface **theInterfaceOut);
int sciInterfaceInit(SCInterface *theInterface);
void sciInterfaceDestroy(SCInterface *theInterface);
void sciInterfaceSetSessionId(SCInterface *theInterface, const char *theSessionId);
void sciInterfaceSetConnectionId(SCInterface *theInterface, const char *theConnectionId);
char *sciGetServiceUrl(void);
/* END mkheaders: generated region */

#endif
