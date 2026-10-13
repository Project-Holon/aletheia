/*
 * function: EVENT_COMM_COMMON_IsKeyTrg
 * address: 0x0217F420
 * packet: pkt_ov018_0217F420
 * region: ov018
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020362DC 0x020362DC arm
 */
extern unsigned int func_020362DC(void);
int EVENT_COMM_COMMON_IsKeyTrg(void)
{
    if (func_020362DC() & 0xf3) return 1;
    return 0;
}
