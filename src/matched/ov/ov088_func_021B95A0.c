/*
 * function: func_021B95A0
 * address:  0x021B95A0
 * packet:   pkt_ov088_021B95A0
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0203064C  0x0203064C  arm
 *   func_0203159C  0x0203159C  arm
 *   func_02082BCC  0x02082BCC  arm
 */
#include "../include/Obj20810.h"

typedef unsigned short u16;

extern void func_0203064C(unsigned int a, unsigned int heap, unsigned int size);
typedef unsigned int   u32;
struct Obj0203159C;
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void  func_02082BCC(void *p, int v, int n);

int func_021B95A0(struct Obj0203159C *a0)
{
    char *p;

    func_0203064C(1, 0x16, 0x120000);
    p = func_0203159C(a0, 0x98, 0x16);
    func_02082BCC(p, 0, 0x98);
    ((struct Obj20810 *)p)->f2 = 0x16;
    return 1;
}
