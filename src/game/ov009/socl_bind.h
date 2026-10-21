#ifndef GAME_OV009_SOCL_BIND_H
#define GAME_OV009_SOCL_BIND_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of socl_bind.c, prototypes copied from their definitions. */

int SOCL_Bind(sptr s, unsigned short local_port);
int SOCL_Connect(int s, unsigned short remote_port, unsigned long remote_ip);
int SOCLi_BindCallBack(void *arg);
/* END mkheaders: generated region */

#endif
