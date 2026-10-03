/*
 * unit:     yes
 * function: func_021E75E0, func_021E7628
 * address:  0x021E75E0
 * packet:   pkt_ov093_021E75E0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The call result is bound to `r` before `k = 0x1fd`: with the constant
 * assigned first it is hoisted above the call into a callee-saved register.
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021D70A8  0x021D70A8  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   d_021F28B8     0x021F28B8  data   ov093  a4
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int func_021D775C(int key);
extern u8 *func_021C88A4(int a, int k, int c);
extern u16 func_021D70A8(void *p);
extern void func_021C88C8(int a, u8 *p);
extern int d_021F28B8[];

void func_021E75E0(int a, int b, int c)
{
    u8 *p;
    int k, r;

    if (c == func_021D775C(3)) {
        p = func_021C88A4(b, 0x2e, c);
        p[6] = func_021D775C(6);
        r = func_021D70A8((void *)a);
        k = 0x1fd;
        if (r == k)
            k += 0x8e;
        else
            k += 0x8f;
        *(u16 *)(p + 4) = k;
        func_021C88C8(b, p);
    }
}

int *func_021E7628(int *p)
{
    *p = 2;
    return d_021F28B8;
}
