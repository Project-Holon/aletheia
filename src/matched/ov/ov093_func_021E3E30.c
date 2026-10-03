/*
 * function: func_021E3E30
 * address:  0x021E3E30
 * packet:   pkt_ov093_021E3E30
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
 *   func_021D76BC  0x021D76BC  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int func_021D775C(int key);
extern void *func_021C7CF4(int *p, int i);
extern int func_021D76BC(int key, u32 val);

void func_021E3E30(int u, void *a, int b, int *p)
{
    int x;

    if (b == func_021D775C(3)) {
        if (*p >= 2) {
            func_021C7CF4(a, b);
            x = p[1];
            if (x != 0)
                x *= 2;
            func_021D76BC(0x37, x);
            *p = 3;
        }
    }
}
