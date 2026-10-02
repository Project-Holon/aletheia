/*
 * function: func_021D3B28
 * address: 0x021D3B28
 * packet: pkt_ov093_021D3B28
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT* (two bytes alignment padding)
 * symbols:
 *   func_021B9934 0x021B9934 thumb ov093
 *   func_021D5734 0x021D5734 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct UtilWork;
extern int func_021B9934(char *, u8);
extern void func_021D5734(int, u8, u16, u8, u32);
int func_021D3B28(u32 *a, int *b, const u32 *c)
{
    int x;
    x = func_021B9934((char *)a[1], c[0]);
    func_021D5734(x, c[1], c[4], c[2], c[3]);
    return 1;
}
