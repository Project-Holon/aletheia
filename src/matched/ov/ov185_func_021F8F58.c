/*
 * function: func_021F8F58
 * address: 0x021F8F58
 * packet: pkt_ov185_021F8F58
 * region: ov185
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BR_POKESEARCH_Close 0x021FFE70 thumb ov186
 *   BR_POKESEARCH_Destroy 0x021FFC6C thumb ov186
 *   func_020409B4 0x020409B4 arm
 *   func_021FD15C 0x021FD15C thumb ov186
 */
#include "../include/Obj04584.h"
#include "../include/Obj24759.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Pair;struct PrintSys;
extern void BR_POKESEARCH_Close(char *p);
extern void BR_POKESEARCH_Destroy(char *p);
extern void func_020409B4(unsigned);
extern void func_021FD15C(void *,int);
void func_021F8F58(char *p,char *q) { if(((struct Obj04584 *)p)->f0){BR_POKESEARCH_Close(((struct Obj04584 *)p)->f0);BR_POKESEARCH_Destroy(((struct Obj04584 *)p)->f0);((struct Obj04584 *)p)->f0=0;func_020409B4(4);if(((struct Obj04584 *)p)->f4){func_021FD15C(((struct Obj04584 *)p)->f4,((struct Obj24759 *)q)->fC);((struct Obj04584 *)p)->f4=0;}} }
