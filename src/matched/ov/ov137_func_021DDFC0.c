/*
 * function: func_021DDFC0
 * address: 0x021DDFC0
 * packet: pkt_ov137_021DDFC0
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021DCF50 0x021DCF50 thumb ov137
 *   UNION_APP_GetMemberCount 0x021841A4 thumb ov022
 *   func_021DD924 0x021DD924 thumb ov137
 */
#include "../include/Obj06535.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_021DCF50(u8 *p);
extern int UNION_APP_GetMemberCount(u8 *);
extern void func_021DD924(char *);
int func_021DDFC0(char *p,int state) {if(((struct Obj06535 *)p)->f481C){if(((struct Obj06535 *)p)->f481C!=(u32)UNION_APP_GetMemberCount(func_021DCF50((u8 *)p))) ((struct Obj06535 *)p)->f481C=0;}((struct Obj06535 *)p)->f118=21;((struct Obj06535 *)p)->f124=0;func_021DD924(p);return state;}
