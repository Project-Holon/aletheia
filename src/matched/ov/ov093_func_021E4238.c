/*
 * function: func_021E4238
 * address:  0x021E4238
 * packet:   pkt_ov093_021E4238
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D5BB0  0x021D5BB0  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int func_021D775C(int key);
extern u8 *func_021C7CF4(u8 *s, int k);
extern int func_021D5BB0(u8 *q, u32 n);
extern u8 *func_021C88A4(u8 *p, int a, int b);
extern void func_021C88C8(void *a, void *b);
extern void func_021C8838(void *p, int a, int b);
extern void func_021C8860(u8 *p, u32 v);

void func_021E4238(int a0, u8 *s, int k, int *pf)
{
    u8 v;
    u8 *e;
    u8 *e2;

    if (k == func_021D775C(3)) {
        v = func_021D775C(4);
        if (func_021D5BB0(func_021C7CF4(s, v), 7) != 0 || *pf != 0) {
            e = func_021C88A4(s, 0x16, k);
            e[8] = v;
            *(int *)(e + 4) = 7;
            func_021C88C8(s, e);
            e2 = func_021C88A4(s, 4, k);
            func_021C8838(e2 + 4, 2, 526);
            func_021C8860(e2 + 4, v);
            func_021C88C8(s, e2);
        }
    }
}
