/*
 * function: func_021F6D7C
 * address: 0x021F6D7C
 * packet: pkt_ov215_021F6D7C
 * region: ov215
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MCSS_CheckPaletteFade 0x0201600C thumb
 */
#include "../include/Obj25762.h"

extern int MCSS_CheckPaletteFade(void *);
int func_021F6D7C(char *p){if(MCSS_CheckPaletteFade(((struct Obj25762 *)p)->f34)==0)return 1;return 0;}
