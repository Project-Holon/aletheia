/*
 * function: func_021B8B78
 * address: 0x021B8B78
 * packet: pkt_ov133_021B8B78
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MUSICAL_MCSS_GetIndex 0x021F50F4 thumb ov112
 *   func_021BA184 0x021BA184 thumb ov133
 *   func_021BA258 0x021BA258 thumb ov133
 *   func_021BA208 0x021BA208 thumb ov133
 */
#include "../include/Obj23314.h"
extern int MUSICAL_MCSS_GetIndex(unsigned int); extern unsigned char *func_021BA184(void *); extern int func_021BA258(unsigned char *); extern unsigned char *func_021BA208(unsigned char *);
int func_021B8B78(unsigned char *p,unsigned int id) {int key=MUSICAL_MCSS_GetIndex(id);unsigned char *q=func_021BA184(((struct Obj23314 *)p)->f1824);while(q){if(key==MUSICAL_MCSS_GetIndex(func_021BA258(q)))return 1;q=func_021BA208(q);}return 0;}
