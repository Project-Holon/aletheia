/*
 * function: func_022000D0
 * address: 0x022000D0
 * packet: pkt_ov186_022000D0
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021FCC80 0x021FCC80 thumb ov186
 *   func_0201F868 0x0201F868 thumb
 *   func_021FBDA4 0x021FBDA4 thumb ov186
 */
#include "../include/Obj06639.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021FCC80(char *),func_0201F868(void *),func_021FBDA4(int,unsigned);
void func_022000D0(u8 *p) { func_021FCC80(*(char * *)&((struct Obj06639 *)p)->f68); *(u32 *)&((struct Obj06639 *)p)->f68=0; func_0201F868(((struct Obj06639 *)p)->f64); *(u32 *)&((struct Obj06639 *)p)->f64=0; func_021FBDA4(((struct Obj06639 *)p)->f28,21); }
