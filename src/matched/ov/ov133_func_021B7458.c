/*
 * function: func_021B7458
 * address: 0x021B7458
 * packet: pkt_ov133_021B7458
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B8FF4 0x021B8FF4 thumb ov133
 */
typedef signed short s16;
typedef unsigned int   u32;
extern u32 func_02005728(u32 range);
extern int func_021B8FF4(s16, s16, int, float);
void func_021B7458(void *unused, int *p)
{
    do {
        p[0] = func_02005728(240) + 8;
        p[1] = func_02005728(128) + 32;
    } while (func_021B8FF4(p[0] - 128, p[1] - 80, 84, 0.739130437374115f) == 1);
}
