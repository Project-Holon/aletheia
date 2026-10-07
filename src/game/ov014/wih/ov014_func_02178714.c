/*
 * function: func_02178714
 * address: 0x02178714
 * packet: pkt_ov014_02178714
 * region: ov014
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   g_021797A8 0x021797A8 data ov014 a4
 *   func_02082D44 0x02082D44 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern u8 *g_021797A8;
extern void func_02082D44(void *src, void *dst, int n);
void func_02178714(u16 value, void *src)
{
    *(u16 *)(g_021797A8 + 0x1eb2) = value;
    func_02082D44(src, g_021797A8 + 0x140a, 6);
}
