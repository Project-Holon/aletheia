/*
 * unit:     yes
 * function: func_021E74E4, func_021E7548
 * address:  0x021E74E4
 * packet:   pkt_ov093_021E74E4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   d_021F279C     0x021F279C  data   ov093  a4
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int func_021D775C(int key);
extern u8 *func_021C88A4(int a, int k, int c);
extern void func_021C8838(u8 *p, int a, int b);
extern void func_021C8860(u8 *p, u32 v);
extern void func_021C88C8(int a, u8 *p);
extern int d_021F279C[];

void func_021E74E4(int a, int b, int c)
{
    u8 k;
    u8 *p;

    if (c == func_021D775C(3)) {
        if (func_021D775C(0x46) == 0) {
            k = func_021D775C(4);
            p = func_021C88A4(b, 0x10, c);
            p[4] = 1;
            p[5] = k;
            func_021C88C8(b, p);
            p = func_021C88A4(b, 4, c);
            func_021C8838(p + 4, 2, 0xc3);
            func_021C8860(p + 4, k);
            func_021C88C8(b, p);
        }
    }
}

int *func_021E7548(int *p)
{
    *p = 1;
    return d_021F279C;
}
