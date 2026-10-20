#ifndef GAME_OV009_DWC_RELIABLE_H
#define GAME_OV009_DWC_RELIABLE_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of dwc_reliable.c, prototypes copied from their definitions. */

void DWCi_CleanupReliableQueue(char *p);
int DWCi_IsReliableQueueFree(void);
int DWCi_ProcessReliableQueue(void);
int DWCi_ProcessReliableQueueEx(int (*func)(void *, unsigned char *, int, int));
int DWCi_InsertReliableQueue(void *connection, unsigned char *buffer, int size);
/* END mkheaders: generated region */

#endif
