/*
 * function: func_021FA57C
 * address: 0x021FA57C
 * packet: pkt_ov132_021FA57C
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02040618 0x02040618 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern void func_02040618(unsigned, unsigned, unsigned);
void func_021FA57C(void *unused, int x)
{
    u16 v = ((x << 7) / 256) + 64;
    func_02040618(4, 0, v);
    func_02040618(6, 0, v);
    func_02040618(5, 0, v);
}
