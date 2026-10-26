#ifndef GAME_OV016_USBAP_H
#define GAME_OV016_USBAP_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of usbap.c, prototypes copied from their definitions. */

int DWCi_USBAPlBegin(void (*callback)(int));
int DWCi_USBAPlEnd(void);
void DWCi_USBAPlSetCallback(void (*v)(int));
/* END mkheaders: generated region */

#endif
