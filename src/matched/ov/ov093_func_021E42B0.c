/*
 * function: func_021E42B0
 * address:  0x021E42B0
 * packet:   pkt_ov093_021E42B0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021B9A40  0x021B9A40  thumb  ov093
 *   func_021B9A5C  0x021B9A5C  thumb  ov093
 *   func_021C82C4  0x021C82C4  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int func_021D775C(int key);
extern unsigned char func_021B9A40(unsigned int x);
extern u8 func_021B9A5C(u32 x);
extern int func_021C82C4(int a, int b, int c);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88C8(void *a, void *b);

void func_021E42B0(int a0, u8 *s, int k, int *pf)
{
    int v;
    u32 i;
    u8 *e;

    if (k == func_021D775C(3)) {
        v = func_021B9A5C(func_021B9A40(k));
        if (func_021C82C4((int)s, v, 9) != 0 || func_021C82C4((int)s, v, 10) != 0) {
            e = func_021C88A4((char *)s, 0x1a, k);
            e[7] = v;
            e[4] = 3;
            for (i = 1; i < 3; i++)
                e[4 + i] = 0;
            if (e[4] > 2)
                e[6] |= 2;
            if (e[4] > 2)
                e[6] |= 4;
            func_021C88C8(s, e);
            *pf = 1;
        }
    }
}
