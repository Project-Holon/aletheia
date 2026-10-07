/*
 * function: func_021DDEA4
 * address:  0x021DDEA4
 * packet:   pkt_ov093_021DDEA4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   func_021D7B60  0x021D7B60  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_021C7CF4(int *p, int i);
extern int func_021D59B4(u8 *p, int k);
extern u32 func_021D7B60(void *p, u32 b);

int func_021DDEA4(void *a, int b, u32 n)
{
    void *m;
    u32 v;

    m = func_021C7CF4(a, b);
    if (func_021D59B4(m, 0x11) == 0x52 && n > 2)
        n >>= 1;
    if (n == 0)
        n = 1;
    if ((u32)func_021D59B4(m, 0xe) > 1) {
        v = func_021D59B4(m, 0xd);
        if (v <= func_021D7B60(m, n))
            return 1;
    }
    return 0;
}
