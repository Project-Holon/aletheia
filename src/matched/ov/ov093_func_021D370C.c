/*
 * function: func_021D370C
 * address: 0x021D370C
 * packet: pkt_ov093_021D370C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021B9934 0x021B9934 thumb ov093
 *   func_021D5608 0x021D5608 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 *func_021B9934(char *p, int i);
struct UtilWork; extern void func_021D5608(struct UtilWork *, u8, u8);
int func_021D370C(u32 *a, int b, u32 *c)
{
    u8 *m;
    u8 k, n;
    k = c[1];
    n = c[2];
    m = func_021B9934((char *)a[1], (u8)c[0]);
    func_021D5608((struct UtilWork *)m, k, n);
    return 1;
}
