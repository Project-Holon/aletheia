/*
 * function: func_021F3FC0
 * address: 0x021F3FC0
 * packet: pkt_ov041_021F3FC0
 * region: ov041
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F3F44 0x021F3F44 thumb ov041
 *   func_021F3F70 0x021F3F70 thumb ov041
 *   d_021F4660 0x021F4660 data a1
 */

extern int func_021F3F44(int x);
extern int func_021F3F70(int, int);
extern const unsigned char d_021F4660[];
int func_021F3FC0(unsigned int a, int i)
{
    return func_021F3F70(func_021F3F44(a), d_021F4660[i]);
}
