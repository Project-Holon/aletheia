/*
 * function: STA_ACT_AUDIENCE_SetBgScroll
 * address: 0x021FA57C
 * packet: pkt_ov132_021FA57C
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BG_SYS_FillScrollArea 0x02040618 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern void BG_SYS_FillScrollArea(unsigned, unsigned, unsigned);
void STA_ACT_AUDIENCE_SetBgScroll(void *unused, int x)
{
    u16 v = ((x << 7) / 256) + 64;
    BG_SYS_FillScrollArea(4, 0, v);
    BG_SYS_FillScrollArea(6, 0, v);
    BG_SYS_FillScrollArea(5, 0, v);
}
