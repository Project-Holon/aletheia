/*
 * function: func_021E5264
 * address:  0x021E5264
 * packet:   pkt_ov093_021E5264
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
 *   func_021E8A28  0x021E8A28  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 */
#include "../../../matched/include/Obj10093.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern int func_021D775C(int key);
extern void *func_021C88A4(char *p, int a, int b);
extern int func_021E8A28(u32 a, u32 b);
extern void func_021C8838(void *p, int a, int b);
struct S;
extern void func_021C8860(struct S *p, u32 val);
extern void func_021C88C8(void *a, void *b);

void func_021E5264(int a, void *b, int c)
{
    u8 *w;
    u8 k;

    if (c == func_021D775C(3)) {
        k = func_021D775C(6);
        w = func_021C88A4(b, 12, c);
        w[0xf] = c;
        ((struct Obj10093 *)w)->f4 = 0x1d;
        ((struct Obj10093 *)w)->f8 = func_021E8A28(k, 2);
        func_021C8838(w + 0x14, 2, 0x28b);
        func_021C8860((struct S *)(w + 0x14), c);
        func_021C8860((struct S *)(w + 0x14), k);
        func_021C88C8(b, w);
    }
}
