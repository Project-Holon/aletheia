/*
 * function: func_021F38C4
 * address:  0x021F38C4
 * packet:   pkt_ov045_021F38C4
 * region:   ov045
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201210C  0x0201210C  thumb
 *   func_02188CF0  0x02188CF0  thumb  ov021
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EC4  0x02012EC4  thumb
 *   func_0200B3A4  0x0200B3A4  thumb
 *   func_021F3908  0x021F3908  thumb
 *   func_02188CA4  0x02188CA4  thumb  ov021
 *   func_021A6DC4  0x021A6DC4  thumb  ov021
 */

typedef unsigned int   u32;
typedef unsigned char  u8;
struct Big;
struct Ctx;
extern void *func_0201210C(const struct Ctx *p);
extern int func_02188CF0(u32 a);
extern void *func_02188C80(void *p);
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012EC4(struct Big *p);
extern void *func_0200B3A4(void *p, int n);
extern int func_021F3908(char *a0, int a1);
extern u32 func_02188CA4(u8 *p);
extern void func_021A6DC4(u32 *b, void *a);

void func_021F38C4(void *a0, int a1)
{
    void *r6;
    int r4;
    void *p;

    r6 = func_0201210C(a0);
    r4 = func_02188CF0((u32)r6);
    p = func_0200B3A4(func_02012EC4(func_020120F4(func_02188C80(r6))), 9);
    if (a1 < 8 && r4 == 2) {
        if (func_021F3908(p, a1)) {
            func_021A6DC4((u32 *)func_02188CA4(r6), r6);
        }
    }
}
