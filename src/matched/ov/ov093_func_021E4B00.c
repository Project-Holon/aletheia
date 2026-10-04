/*
 * function: func_021E4B00
 * address:  0x021E4B00
 * packet:   pkt_ov093_021E4B00
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
 *   func_021D67B8  0x021D67B8  thumb  ov093
 *   func_021D5778  0x021D5778  thumb  ov093
 *   func_021D5584  0x021D5584  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int func_021D775C(int key);
extern u8 *func_021C7CF4(u8 *s, int k);
extern u16 func_021D67B8(u8 *q);
extern int func_021D5778(u8 *q, int w);
extern int func_021D5584(u8 *q, int t);
extern u8 *func_021C88A4(u8 *p, int a, int b);
extern void func_021C8838(void *p, int a, int b);
struct S;
extern void func_021C8860(struct S *p, u32 val);
extern void func_021C88C8(void *a, void *b);

void func_021E4B00(int a0, u8 *s, int k)
{
    u8 v;
    u8 *q;
    int w;
    int t;
    u8 n;
    u8 *e;

    if (k == func_021D775C(3)) {
        v = func_021D775C(6);
        q = func_021C7CF4(s, v);
        w = func_021D67B8(q);
        t = func_021D5778(q, w);
        if (t != 4) {
            n = func_021D5584(q, t);
            if (n > 4)
                n = 4;
            if (n != 0) {
                e = func_021C88A4(s, 10, k);
                e[5] = v;
                e[4] = n;
                e[6] = t;
                func_021C8838(e + 8, 2, 641);
                func_021C8860((struct S *)(e + 8), v);
                func_021C8860((struct S *)(e + 8), w);
                func_021C8860((struct S *)(e + 8), n);
                func_021C88C8(s, e);
            }
        }
    }
}
