/*
 * function: func_021743E4
 * address: 0x021743E4
 * packet: pkt_ov011_021743E4
 * region: ov011
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_0203D1E8 0x0203D1E8 arm
 *   func_021780FC 0x021780FC thumb ov014
 */
typedef unsigned int u32;
u32 func_020399A8(void);
void func_0203D1E8(u32 unused, void *arg);
void func_021780FC(int a);
void func_021743E4(int a, int b, void *c, signed char *p)
{
    p[0x93d]++;
    if (p[0x93c] == 0) {
        func_0203D1E8(func_020399A8(), 0);
        func_021780FC(1);
    }
}
