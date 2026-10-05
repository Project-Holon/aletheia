/*
 * function: func_0216B970
 * address: 0x0216B970
 * packet: pkt_ov010_0216B970
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0200E458 0x0200E458 thumb
 *   func_0200E47C 0x0200E47C thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u16 func_0200E458(const u16 *, int);
extern u32 func_0200E47C(const u16 *, int);
u32 func_0216B970(const u16 *p, int index)
{
    u32 x = func_0200E458(p, index);
    x += func_0200E47C(p, index);
    if (x > 999999) x = 999999;
    return x;
}
