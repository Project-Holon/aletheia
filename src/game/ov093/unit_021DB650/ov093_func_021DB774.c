/*
 * function: func_021DB774
 * address:  0x021DB774
 * packet:   pkt_ov093_021DB774
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 */
#include "../../../matched/include/Obj21330.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern int func_021D775C(int key);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C8838(void *p, int a, int b);
struct S;
extern void func_021C8860(struct S *p, u32 v);
extern void func_021C88C8(void *a, void *b);

void func_021DB774(void *a, void *p, int id, int *s)
{
    u8 *r;

    if (id == func_021D775C(2) && s[2] != 0) {
        func_021D775C(2);
        r = (u8 *)func_021C88A4(p, 4, id);
        ((struct Obj21330 *)r)->f0 |= 0x800000;
        func_021C8838(r + 4, 2, 0x389);
        func_021C8860((struct S *)(r + 4), id);
        func_021C8860((struct S *)(r + 4), func_021D775C(0x12));
        func_021C88C8(p, r);
        s[2] = 0;
    }
}
