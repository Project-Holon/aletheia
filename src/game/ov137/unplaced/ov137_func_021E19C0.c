/*
 * function: func_021E19C0
 * address:  0x021E19C0
 * packet:   pkt_ov137_021E19C0
 * region:   ov137
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02039338   0x02039338  arm
 *   func_021E1604   0x021E1604  thumb  ov137
 *   func_021DCBC4   0x021DCBC4  thumb  ov137
 */
#include "../../../matched/include/Obj04542.h"

typedef unsigned short u16;
extern u16 func_02039338(void);
extern void func_021E1604(char *, int);
typedef unsigned int   u32;
extern void func_021DCBC4(void *p, u32 a, const void *b, u32 c);

void func_021E19C0(char *r4, int r5)
{
    struct {
        int a;
        int b;
        short h[6];
    } buf;
    int i;

    if (func_02039338() != 0)
        return;
    func_021E1604(r4, r5);
    buf.a = ((struct Obj04542 *)r4)->f11C;
    buf.b = ((struct Obj04542 *)r4)->f33C;
    for (i = 0; i < ((struct Obj04542 *)r4)->f30; i++) {
        int v = *(int *)(r4 + 0x2FC + i * 0xB4);
        buf.h[i] = (short)(v / 4096);
    }
    func_021DCBC4((void *)(((struct Obj04542 *)r4)->fDC), 0x2808, &buf, 0x14);
}
