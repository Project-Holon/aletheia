/*
 * function: func_021D3A40
 * address: 0x021D3A40
 * packet: pkt_ov093_021D3A40
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT* (two bytes alignment padding)
 * symbols:
 *   func_021B9934 0x021B9934 thumb ov093
 *   func_021D6744 0x021D6744 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct UtilWork;
extern u8 *func_021B9934(char *p, int i);
extern void func_021D6744(u8 *p, u8 a, int f, u8 b, u16 c, u16 d);
int func_021D3A40(u32 *a, int *b, const u32 *c)
{
    u8 *x;
    x = func_021B9934((char *)a[1], (u8)c[0]);
    func_021D6744(x, c[1], c[2], c[3], c[4], c[5]);
    return 1;
}
