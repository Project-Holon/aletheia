/*
 * function: func_021D3988
 * address: 0x021D3988
 * packet: pkt_ov093_021D3988
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021B9934 0x021B9934 thumb ov093
 *   func_021D66B0 0x021D66B0 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_021B9934(char *, u8);
extern void func_021D66B0(void *, u16);
int func_021D3988(u32 *a, int b, u32 *c)
{
    int m;

    m = func_021B9934((char *)a[1], c[0]);
    func_021D66B0((void *)m, c[1]);
    return 1;
}
