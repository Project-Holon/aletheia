/*
 * unit:     yes
 * function: func_021E7760, func_021E7810
 * address:  0x021E7760
 * packet:   pkt_ov093_021E7760
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
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   d_021F2714     0x021F2714  data   ov093  a4
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int func_021D775C(int key);
extern u8 *func_021C88A4(int a, int k, int c);
extern void func_021C88C8(int a, u8 *p);
extern int d_021F2714[];

void func_021E7760(int a, int b, int c)
{
    u8 *p;

    if (c == func_021D775C(3)) {
        p = func_021C88A4(b, 0xe, c);
        *(int *)(p + 4) = 2;
        *(s8 *)(p + 0xc) = -1;
        p[0xf] = 1;
        p[0x10] = c;
        p[0xe] = 1;
        func_021C88C8(b, p);
        p = func_021C88A4(b, 0xe, c);
        *(int *)(p + 4) = 4;
        *(s8 *)(p + 0xc) = -1;
        p[0xf] = 1;
        p[0x10] = c;
        p[0xe] = 1;
        func_021C88C8(b, p);
        p = func_021C88A4(b, 0xe, c);
        *(int *)(p + 4) = 1;
        *(s8 *)(p + 0xc) = 2;
        p[0xf] = 1;
        p[0x10] = c;
        p[0xe] = 1;
        func_021C88C8(b, p);
        p = func_021C88A4(b, 0xe, c);
        *(int *)(p + 4) = 3;
        *(s8 *)(p + 0xc) = 2;
        p[0xf] = 1;
        p[0x10] = c;
        p[0xe] = 1;
        func_021C88C8(b, p);
        p = func_021C88A4(b, 0xe, c);
        *(int *)(p + 4) = 5;
        *(s8 *)(p + 0xc) = 2;
        p[0xf] = 1;
        p[0x10] = c;
        p[0xe] = 1;
        func_021C88C8(b, p);
    }
}

int *func_021E7810(int *p)
{
    *p = 1;
    return d_021F2714;
}
