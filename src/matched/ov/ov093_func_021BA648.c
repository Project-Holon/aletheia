/*
 * function: func_021BA648
 * address: 0x021BA648
 * packet: pkt_ov093_021BA648
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BA710 0x021BA710 thumb ov093
 */
#include "../include/Obj13286.h"

typedef unsigned char u8;
extern u8 func_021BA710(int, int);
struct Rec534;
extern void func_0201AC2C(const struct Rec534 *src, struct Rec534 *dst);
void func_021BA648(char *p, u8 k, void *dst)
{
 int i;
 void *q;
 i = func_021BA710(((struct Obj13286 *)p)->f46C, k);
 q = *(void **)(*(char * *)&((struct Obj13286 *)p)->f0 + i * 4 + 0x24);
 if (q != 0) func_0201AC2C(dst, q);
}
