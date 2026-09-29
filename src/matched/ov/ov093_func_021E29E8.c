/*
 * unit:     yes
 * function: func_021E29E8, func_021E2A2C
 * address:  0x021E29E8
 * packet:   pkt_ov093_021E29E8
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
 *   func_021D5C44  0x021D5C44  thumb  ov093
 *   func_021D7B2C  0x021D7B2C  thumb  ov093
 *   _u32_div_f     0x0209C2B0  arm
 *   func_021D76BC  0x021D76BC  thumb  ov093
 *   d_021F24AC     0x021F24AC  data   ov093  a4
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern int func_021D775C(int key);
extern void *func_021C7CF4(void *a, int b);
extern int func_021D5C44(void *m);
extern u32 func_021D7B2C(u32 a, u32 b);
extern int func_021D76BC(int key, u32 v);
extern int d_021F24AC[];

void func_021E29E8(int a, void *b, int c)
{
    u32 r;

    if (c == func_021D775C(3)) {
        r = func_021D7B2C(0x78, func_021D5C44(func_021C7CF4(b, (u8)func_021D775C(4)))) / 100;
        if (r == 0)
            r = 1;
        func_021D76BC(0x30, r);
    }
}

int *func_021E2A2C(int *p)
{
    *p = 1;
    return d_021F24AC;
}
