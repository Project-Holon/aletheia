/*
 * function: ZUKAN_SEARCH_SCREEN_Tick
 * address:  0x021BC890
 * packet:   pkt_021BC890
 * region:   ov211
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BG_SYS_ChangeScale  0x02041F6C  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

typedef unsigned short u16;
extern void BG_SYS_ChangeScale(u32 which, u32 op, u32 value);

void ZUKAN_SEARCH_SCREEN_Tick(void)
{
    BG_SYS_ChangeScale(3, 4, 0x80);
    BG_SYS_ChangeScale(3, 7, 0x80);
    BG_SYS_ChangeScale(7, 4, 0x80);
    BG_SYS_ChangeScale(7, 7, 0x80);
}
