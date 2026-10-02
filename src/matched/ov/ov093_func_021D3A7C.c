/*
 * function: func_021D3A7C
 * address: 0x021D3A7C
 * packet: pkt_ov093_021D3A7C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT* (two bytes alignment padding)
 * symbols:
 *   func_021B9934 0x021B9934 thumb ov093
 *   func_021D5FE4 0x021D5FE4 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct UtilWork;
extern int func_021B9934(char *, u8);
extern void func_021D5FE4(int, u32);
int func_021D3A7C(u32 *a, int *b, u32 *c)
{
    int x;
    x = func_021B9934((char *)a[1], c[0]);
    func_021D5FE4(x, c[1]);
    return 1;
}
