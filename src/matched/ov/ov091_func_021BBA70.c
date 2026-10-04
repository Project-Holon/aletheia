/*
 * function: func_021BBA70
 * address: 0x021BBA70
 * packet: pkt_ov091_021BBA70
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045770 0x02045770 arm
 *   func_02028618 0x02028618 thumb
 *   func_02045334 0x02045334 arm
 */
#include "../include/Obj09931.h"
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
typedef unsigned int   u32;
struct Bmp;
struct Ctx;
extern void func_02028618(struct Ctx *ctx, const struct Bmp *bmp, u32 color);
extern void func_02045334(struct Descriptor *d);
void func_021BBA70(int a,int b) {func_02028618((struct Ctx *)(((struct Obj09931 *)b)->f14),(const struct Bmp *)((unsigned int)func_02045770((struct Descriptor *)((struct Obj09931 *)b)->f4)),15);func_02045334((struct Descriptor *)((struct Obj09931 *)b)->f4);}
