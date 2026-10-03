/*
 * function: func_021E58D8
 * address:  0x021E58D8
 * packet:   pkt_ov093_021E58D8
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
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   func_021E5958  0x021E5958  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021D775C(int key);
extern void *func_021C7CF4(int a, int b);
extern int func_021D59B4(u8 *p, int k);
extern int func_021E5958(u16 v);
extern void *func_021C88A4(void *a, int k, int b);
extern void func_021C8838(void *p, int a, int b);
extern void func_021C8860(void *p, u32 v);
extern void func_021C88C8(void *a, void *b);

void func_021E58D8(int a, int b, int c)
{
    u8 *m;
    u8 k;
    int n;

    if (c == func_021D775C(3)) {
        k = func_021D775C(6);
        n = func_021D59B4(func_021C7CF4(b, k), 0x10);
        if (func_021E5958(n) == 0) {
            m = (u8 *)func_021C88A4((void *)b, 0x1f, c);
            m[6] = c;
            *(u16 *)(m + 4) = n;
            func_021C8838(m + 0xc, 2, 0x26b);
            func_021C8860(m + 0xc, c);
            func_021C8860(m + 0xc, k);
            func_021C8860(m + 0xc, *(u16 *)(m + 4));
            func_021C88C8((void *)b, m);
        }
    }
}
