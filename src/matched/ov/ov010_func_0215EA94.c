/*
 * function: func_0215EA94
 * address: 0x0215EA94
 * packet: pkt_ov010_0215EA94
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020120F4 0x020120F4 thumb
 *   func_0201296C 0x0201296C thumb
 *   func_021587B0 0x021587B0 thumb ov010
 *   func_02159058 0x02159058 thumb ov010
 */
#include "../include/Obj12311.h"
typedef unsigned short u16;
typedef unsigned int   u32;
struct BigObj;
struct Ctx;
extern void *func_020120F4(const struct Ctx *p);
extern u32 func_0201296C(const struct BigObj *p);
extern int func_021587B0(int a0, int a1, int a2, int a3);
extern int func_02159058(int a, int b, int c, int d, u16 e);
int func_0215EA94(void *a,void *b,void *c)
{
 int h;
 int t;
 func_0201296C(func_020120F4(((struct Obj12311 *)c)->f8));
 h = ((struct Obj12311 *)c)->fC;
 t = func_021587B0((int)a,0x2715,0,0);
 func_02159058(t,h,0,0,0);
 return 0;
}
