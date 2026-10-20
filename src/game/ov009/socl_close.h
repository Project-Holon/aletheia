#ifndef GAME_OV009_SOCL_CLOSE_H
#define GAME_OV009_SOCL_CLOSE_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of socl_close.c, prototypes copied from their definitions. */

int SOCL_IsClosed(int s);
int SOCL_IsReleased(int s);
int SOCL_Close(int s);
int SOCLi_CloseCallBack(void *arg);
void SOCLi_FreeCommandPipe(unsigned char *pipe);
void SOCLi_TrashSocket(void);
/* END mkheaders: generated region */

#endif
