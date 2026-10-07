/*
 * function: func_021E7388
 * address:  0x021E7388
 * packet:   pkt_ov093_021E7388
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 */
#include "../../../matched/include/Obj07835.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021D775C(int key);
extern void *func_021C7CF4(int *p, int i);
extern int func_021D59B4(u8 *p, int k);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C8838(void *p, int a, int b);
struct S;
extern void func_021C8860(struct S *p, u32 v);
extern void func_021C88C8(void *a, void *b);

void func_021E7388(int a, void *b, int c)
{
    u32 i;
    u32 n;
    u8 *m;

    if (c == func_021D775C(3)) {
        n = func_021D775C(5);
        for (i = 0; i < n; i++) {
            if (func_021D59B4(func_021C7CF4(b, (u8)func_021D775C(i + 6)), 0x10) != 0x36) {
                m = (u8 *)func_021C88A4(b, 0x1f, c);
                m[6] = func_021D775C(i + 6);
                ((struct Obj07835 *)m)->f4 = 0x56;
                func_021C8838(m + 0xc, 2, 0x195);
                func_021C8860((struct S *)(m + 0xc), m[6]);
                func_021C8860((struct S *)(m + 0xc), ((struct Obj07835 *)m)->f4);
                func_021C88C8(b, m);
            }
        }
    }
}
