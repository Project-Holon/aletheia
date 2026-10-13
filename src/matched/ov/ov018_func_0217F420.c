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
 *   KEY_GetTrg 0x020362DC arm
 */
extern unsigned int KEY_GetTrg(void);
int EVENT_COMM_COMMON_IsKeyTrg(void)
{
    if (KEY_GetTrg() & 0xf3) return 1;
    return 0;
}
