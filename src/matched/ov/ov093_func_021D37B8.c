/*
 * function: func_021D37B8
 * address: 0x021D37B8
 * packet: pkt_ov093_021D37B8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B9934 0x021B9934 thumb ov093
 *   func_021D56A0 0x021D56A0 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 *func_021B9934(char *p, int i);
extern u16 func_021D56A0(u8 *p, u32 i, u8 n);
int func_021D37B8(u32 *a, int b, u32 *c)
{
    u8 *m;

    m = func_021B9934((char *)a[1], (u8)c[0]);
    func_021D56A0(m, (u8)c[1], c[2]);
    return 1;
}
