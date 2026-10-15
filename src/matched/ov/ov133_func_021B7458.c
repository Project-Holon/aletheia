/*
 * function: DUP_FITTING_RandomPos
 * address: 0x021B7458
 * packet: pkt_ov133_021B7458
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   DUP_FITTING_HitCircle 0x021B8FF4 thumb ov133
 */
typedef signed short s16;
typedef unsigned int   u32;
extern u32 func_02005728(u32 range);
extern int DUP_FITTING_HitCircle(int x, int y, int radius, float scale);
void DUP_FITTING_RandomPos(void *unused, int *p)
{
    do {
        p[0] = func_02005728(240) + 8;
        p[1] = func_02005728(128) + 32;
    } while (DUP_FITTING_HitCircle((s16)(p[0] - 128), (s16)(p[1] - 80), 84, 0.739130437374115f) == 1);
}
