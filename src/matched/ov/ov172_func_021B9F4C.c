/*
 * function: func_021B9F4C
 * address: 0x021B9F4C
 * packet: pkt_ov172_021B9F4C
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: Two bytes of zero alignment padding follow the return.
 * symbols:
 *   func_02035D20 0x02035D20 arm
 *   func_02035CB8 0x02035CB8 arm
 */
typedef unsigned int u32;
extern int func_02035D20(u32 *, u32 *);
extern int func_02035CB8(u32 *, u32 *);
int func_021B9F4C(int a, int b, int mode)
{
    u32 x, y;
    int dx, dy, d;
    if (mode == 0) func_02035D20(&x, &y);
    else func_02035CB8(&x, &y);
    if (y >= 104) {
        dx = 128 - x;
        dy = 104 - y;
        d = dx * dx + dy * dy;
        if (d > 256 && d < 5184) return 1;
    }
    return 0;
}
