#ifndef GAME_OV009_SOCL_CREATE_H
#define GAME_OV009_SOCL_CREATE_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of socl_create.c, prototypes copied from their definitions. */

struct SOCLSocketParam;

int SOCL_CreateSocket(struct SOCLSocketParam *param);
int SOCLi_CreateSocketCallBack(void *arg);
void *SOCLi_StartupSocket(void *param);
/* END mkheaders: generated region */

#endif
