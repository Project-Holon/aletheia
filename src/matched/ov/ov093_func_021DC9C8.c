/*
 * function: func_021DC9C8
 * address:  0x021DC9C8
 * packet:   pkt_ov093_021DC9C8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C83D4  0x021C83D4  thumb  ov093
 *   func_0201BEB8  0x0201BEB8  thumb
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021B9A24  0x021B9A24  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021D775C(int key);
extern int func_021C83D4(void *p);
extern int func_0201BEB8(u16 a, int b);
extern void *func_021C7CF4(void *p, int k);
extern int func_021D59B4(void *p, int k);
extern void *func_021C88A4(void *a, int k, int b);
extern void func_021C8838(void *p, int a, u16 b);
extern void func_021C8860(void *p, u32 v);
extern int func_021B9A24(int a, int b);
extern void func_021C88C8(void *a, void *b);

void func_021DC9C8(int a, void *b, int c)
{
    u8 *m;
    u8 k;

    if (c == func_021D775C(4) && func_021D775C(0x46) == 0 && func_021C83D4(b) == 0
        && func_0201BEB8(func_021D775C(0x12), 0) != 0) {
        k = func_021D775C(3);
        if (func_021D59B4(func_021C7CF4(b, k), 0x10) != 0x98) {
            m = (u8 *)func_021C88A4(b, 0x1f, c);
            *(u16 *)(m + 4) = 0x98;
            m[6] = k;
            func_021C8838(m + 0xc, 2, 0x1cf);
            func_021C8860(m + 0xc, m[6]);
            if (func_021B9A24(c, k) == 0)
                *(u32 *)m |= 2 << 22;
            func_021C88C8(b, m);
        }
    }
}
