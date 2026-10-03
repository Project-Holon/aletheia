/*
 * function: func_021D3A20
 * address: 0x021D3A20
 * packet: pkt_ov093_021D3A20
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT* (two bytes alignment padding)
 * symbols:
 *   func_021B9934 0x021B9934 thumb ov093
 *   func_021D6730 0x021D6730 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct UtilWork;
extern u8 *func_021B9934(char *p, int i);
struct QK;
extern void func_021D6730(struct QK *p, u16 v);
int func_021D3A20(u32 *a, int *b, u32 *c)
{
    u8 *x;
    x = func_021B9934((char *)a[1], (u8)c[0]);
    func_021D6730((struct QK *)x, c[1]);
    return 1;
}
