/*
 * function: func_021D3734
 * address: 0x021D3734
 * packet: pkt_ov093_021D3734
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021B9934 0x021B9934 thumb ov093
 *   func_021D5640 0x021D5640 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 *func_021B9934(char *p, int i);
extern void func_021D5640(u8 *, u8, u8);
int func_021D3734(u32 *a, int b, u32 *c)
{
    u8 *m;
    u8 k, n;
    k = c[1];
    n = c[2];
    m = func_021B9934((char *)a[1], (u8)c[0]);
    func_021D5640(m, k, n);
    return 1;
}
