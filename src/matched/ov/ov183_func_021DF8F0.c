/*
 * function: func_021DF8F0
 * address: 0x021DF8F0
 * packet: pkt_ov183_021DF8F0
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020061E4 0x020061E4 thumb
 */
typedef unsigned short u16;
extern void func_020061E4(int);
int func_021DF8F0(int x, int y)
{
    int ok = ((unsigned)(x - 80) <= 88) & ((unsigned)(y - 32) <= 56);
    if (ok) func_020061E4(0x703);
    return ok;
}
