/*
 * function: func_021D3794
 * address: 0x021D3794
 * packet: pkt_ov093_021D3794
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B9934 0x021B9934 thumb ov093
 *   func_021D5674 0x021D5674 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_021B9934(char *, u8);
extern void func_021D5674(u8 *, u8, u8);
int func_021D3794(u32 *a, int b, u32 *c)
{
    int m;

    m = func_021B9934((char *)a[1], c[0]);
    func_021D5674((u8 *)m, c[1], c[2]);
    return 1;
}
