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
 *   func_021FFE70 0x021FFE70 thumb ov186
 *   func_021FFC6C 0x021FFC6C thumb ov186
 *   func_020409B4 0x020409B4 arm
 *   func_021FD15C 0x021FD15C thumb ov186
 */
#include "../include/Obj04584.h"
#include "../include/Obj24759.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Pair;struct PrintSys;
extern void func_021FFE70(char *p);
extern void func_021FFC6C(char *p);
extern void func_020409B4(unsigned);
extern void func_021FD15C(void *,int);
void func_021F8F58(char *p,char *q) { if(((struct Obj04584 *)p)->f0){func_021FFE70(((struct Obj04584 *)p)->f0);func_021FFC6C(((struct Obj04584 *)p)->f0);((struct Obj04584 *)p)->f0=0;func_020409B4(4);if(((struct Obj04584 *)p)->f4){func_021FD15C(((struct Obj04584 *)p)->f4,((struct Obj24759 *)q)->fC);((struct Obj04584 *)p)->f4=0;}} }
