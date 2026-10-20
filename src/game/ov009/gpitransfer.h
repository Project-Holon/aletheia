#ifndef GAME_OV009_GPITRANSFER_H
#define GAME_OV009_GPITRANSFER_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of gpitransfer.c, prototypes copied from their definitions. */

struct GPITransferID;

int gpiSendTransferReply(void **connection, struct GPITransferID *transferID, void *peer, int result, char *msg);
void gpiHandleTransferMessage(void **connection, void *peer, int unused, char *headers, char *buffer, int len);
/* END mkheaders: generated region */

#endif
