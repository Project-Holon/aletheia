/*
 * function: func_02162958
 * address: 0x02162958
 * packet: pkt_ov010_02162958
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021628E4 0x021628E4 thumb ov010
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern u16 *func_021628E4(void *c, void *a, int key);
u16 func_02162958(void *c, void *a, int key)
{
    u16 *r = func_021628E4(c, a, key);
    if (r != 0) return *r;
    return 0xffff;
}
