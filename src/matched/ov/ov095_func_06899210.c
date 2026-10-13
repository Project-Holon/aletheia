/*
 * function: HAND_SIDE_LuckyChantBlockCritical
 * address: 0x06899210
 * packet: pkt_ov095_06899210
 * region: ov095
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_06899230 0x06899230 thumb ov095
 *   func_06899240 0x06899240 thumb ov095
 *   func_06899250 0x06899250 thumb ov095
 */
typedef unsigned char u8;
extern int func_06899230(int);
extern int func_06899240(u8);
extern void func_06899250(int, int);
void HAND_SIDE_LuckyChantBlockCritical(int a0, int a1, int value)
{
    if (value == func_06899240(func_06899230(4))) {
        func_06899250(0x41, 1);
    }
}
