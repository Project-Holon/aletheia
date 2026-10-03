/*
 * function: func_0217443C
 * address: 0x0217443C
 * packet: pkt_ov011_0217443C
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
typedef unsigned char  u8;
void func_021780FC(u8 value);
void func_0217443C(int a, int b, void *c, signed char *p)
{
    p[0x93d]--;
    if (p[0x93d] == 0 && p[0x93c] == 0) {
        func_0203D1E8(func_020399A8(), (void *)1);
        func_021780FC(0);
    }
}
