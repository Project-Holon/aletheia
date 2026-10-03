/*
 * function: func_021D3918
 * address: 0x021D3918
 * packet: pkt_ov093_021D3918
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021B9934 0x021B9934 thumb ov093
 *   func_021D6238 0x021D6238 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 *func_021B9934(char *p, int i);
struct UtilSlots; extern void func_021D6238(struct UtilSlots *, int);
int func_021D3918(u32 *a, int b, u32 *c)
{
    u8 *m;

    m = func_021B9934((char *)a[1], (u8)c[0]);
    func_021D6238((struct UtilSlots *)m, c[1]);
    return 1;
}
