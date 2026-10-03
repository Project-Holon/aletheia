/*
 * function: func_021D37DC
 * address: 0x021D37DC
 * packet: pkt_ov093_021D37DC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B9934 0x021B9934 thumb ov093
 *   func_021D5DC0 0x021D5DC0 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 *func_021B9934(char *p, int i);
typedef signed char s8;
extern u8 func_021D5DC0(s8 *, int, u8);
int func_021D37DC(u32 *a, int b, u32 *c)
{
    u8 *m;

    m = func_021B9934((char *)a[1], (u8)c[0]);
    func_021D5DC0((s8 *)m, c[1], c[2]);
    return 1;
}
