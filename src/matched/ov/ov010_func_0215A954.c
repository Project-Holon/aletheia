/*
 * function: func_0215A954
 * address: 0x0215A954
 * packet: pkt_ov010_0215A954
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021909E4 0x021909E4 thumb ov021
 *   func_0215A920 0x0215A920 thumb ov010
 */
#include "../include/Obj04148.h"
#include "../include/Obj12286.h"
typedef unsigned char u8;
typedef unsigned short u16;
struct Handle;
extern int func_021909E4(struct Handle *h);
extern int func_0215A920(int a0);
int func_0215A954(u8 *a) {
 u8 *p;
 int v;
 p = *(u8 * *)&((struct Obj12286 *)a)->f20 + 52;
 v = func_021909E4(((struct Obj04148 *)p)->f1C);
 if (v == -1) return 0;
 func_0215A920((int)p);
 if (v != -2) **(u16 * *)&((struct Obj04148 *)p)->f8 = v;
 else **(u16 * *)&((struct Obj04148 *)p)->f8 = 65534;
 return 1;
}
