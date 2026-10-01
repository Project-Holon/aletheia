/*
 * unit: yes
 * function: func_021BA120, func_021BA158, func_021BA15C, func_021BA170
 * address: 0x021BA120
 * packet: pkt_ov172_021BA120
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0208B528 0x0208B528 arm
 *   func_0208B4B8 0x0208B4B8 arm
 */
typedef unsigned int u32;
extern int func_0208B528(void);
extern void *func_0208B4B8(void);
int func_021BA120(u32 *p)
{
    if (p[2] == 0) return 1;
    if (func_0208B528() == 0) {
        p[0] = (u32)func_0208B4B8() - p[1] + 4;
        if (p[0] > 51200) p[0] = 51200;
        p[2] = 0;
        return 1;
    }
    return 0;
}
u32 func_021BA158(u32 *p) { return p[2]; }
u32 func_021BA15C(u32 *p)
{
    if (p[0] > 2048) return p[0] - 2048;
    return 0;
}
u32 func_021BA170(u32 *p) { return p[1]; }
