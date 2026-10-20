#ifndef GAME_OV009_SOCL_STARTUP_H
#define GAME_OV009_SOCL_STARTUP_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of socl_startup.c, prototypes copied from their definitions. */

#include "../ov009/socl_command_types.h"

int SOCL_Startup(SOCLConfig *socl_config);
int SOCLi_StartupSOCL(void);
void SOCLi_SetMyIP(void);
void SOCLi_DhcpTimeout(void);
int SOCL_LinkIsOn(void);
/* END mkheaders: generated region */

#endif
