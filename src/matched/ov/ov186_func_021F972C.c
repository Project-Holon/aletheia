/*
 * function: func_021F972C, func_021F9750
 * unit: yes
 * extent: empty-return follower 0x021F9750; trailing two-byte padding.
 * address: 0x021F972C
 * packet: pkt_ov186_021F972C
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021FC4DC 0x021FC4DC thumb ov186
 */
#include "../include/Obj06625.h"
#include "../include/Obj06626.h"
#include "../include/Obj24789.h"
#include "../include/Obj24790.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Pair;struct PrintSys;
extern u32 func_021FC4DC(u8 *p);
void func_021F972C(char *p,char *q) { ((struct Obj06625 *)p)->f8=((struct Obj06626 *)q)->f4;((struct Obj06625 *)p)->f0=((struct Obj06626 *)q)->fC;((struct Obj06625 *)p)->fC=((struct Obj06626 *)q)->f8;((struct Obj06625 *)p)->f4=func_021FC4DC((u8 *)(((struct Obj06626 *)q)->f0));((struct Obj06625 *)p)->f10=((struct Obj24790 *)(*(char * *)&((struct Obj24789 *)(*(char * *)&((struct Obj06626 *)q)->f18))->fC))->f4; }
void func_021F9750(void) {}
