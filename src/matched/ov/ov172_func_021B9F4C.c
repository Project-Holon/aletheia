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
 *   TOUCHPANEL_GetPointCont 0x02035CB8 arm
 */
typedef unsigned int u32;
extern u32 func_02035D20(u32 *outA, u32 *outB);
extern u32 TOUCHPANEL_GetPointCont(u32 *outA, u32 *outB);
int func_021B9F4C(int a, int b, int mode)
{
    u32 x, y;
    int dx, dy, d;
    if (mode == 0) func_02035D20(&x, &y);
    else TOUCHPANEL_GetPointCont(&x, &y);
    if (y >= 104) {
        dx = 128 - x;
        dy = 104 - y;
        d = dx * dx + dy * dy;
        if (d > 256 && d < 5184) return 1;
    }
    return 0;
}
