/*
 * function: func_021DF204
 * address: 0x021DF204
 * packet: pkt_ov137_021DF204
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021E19C0 0x021E19C0 thumb ov137
 *   func_021E0A44 0x021E0A44 thumb ov137
 *   GFL_NET_SYSTEM_GetCurrentAid 0x02039338 arm
 */
#include "../include/Obj04542.h"
#include "../include/Obj23757.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021E19C0(char *,int);
extern u8 *func_021E0A44(void *);
extern u16 GFL_NET_SYSTEM_GetCurrentAid(void);
int func_021DF204(char *p) { func_021E19C0(p,0x4000); *(u8 * *)&((struct Obj04542 *)p)->f28=func_021E0A44(p); if(((struct Obj23757 *)(*(u8 * *)&((struct Obj04542 *)p)->f28))->fC!=GFL_NET_SYSTEM_GetCurrentAid()) ((struct Obj04542 *)p)->f0=30; return 0; }
