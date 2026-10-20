#ifndef GAME_OV009_SOCL_RESOLVE_H
#define GAME_OV009_SOCL_RESOLVE_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of socl_resolve.c, prototypes copied from their definitions. */

unsigned long SOCL_Resolve(char *hostname);
unsigned long SOCL_InetAtoH(char *hostname);
int SOCL_SetResolver(unsigned long dns1, unsigned long dns2);
unsigned long SOCL_GetHostID(void);
/* END mkheaders: generated region */

#endif
