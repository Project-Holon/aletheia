/*
 * function: func_021E8190
 * address:  0x021E8190
 * packet:   pkt_ov093_021E8190
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D5444  0x021D5444  thumb  ov093
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern void *func_021C7CF4(void *a, int b);
extern u16 func_021D5444(void *p);
extern int func_021D775C(int key);
extern int func_021D59B4(void *p, int k);
extern void *func_021C88A4(void *a, int k, int b);
extern void func_021C8838(void *l, int a, int b);
extern void func_021C8860(void *l, u32 v);
extern void func_021C88C8(void *a, void *b);

void func_021E8190(int a, void *b, int c)
{
    int f;
    u8 *p;
    void *m;

    m = func_021C7CF4(b, c);
    if (func_021D5444(m) == 0x288 && c == func_021D775C(3)) {
        f = func_021D59B4(m, 0x13) == 0;
        p = func_021C88A4(b, 0x39, c);
        p[4] = c;
        p[5] = f;
        func_021C8838(p + 8, 2, 0xde);
        func_021C8860(p + 8, c);
        func_021C88C8(b, p);
    }
}
