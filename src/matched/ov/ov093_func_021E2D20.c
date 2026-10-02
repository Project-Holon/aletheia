/*
 * function: func_021E2D20
 * address:  0x021E2D20
 * packet:   pkt_ov093_021E2D20
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021D78AC  0x021D78AC  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int func_021D775C(int key);
extern u32 func_021D78AC(u32 range);
extern int func_021D76BC(int a, int b);

void func_021E2D20(int u, int a, int b)
{
    int x;
    u32 r;

    if (b == func_021D775C(3)) {
        x = 0x50;
        r = func_021D78AC(0x50);
        if (r < 0x28)
            x = 0x28;
        else if (r >= 0x46)
            x = 0x78;
        func_021D76BC(0x30, x);
    }
}
