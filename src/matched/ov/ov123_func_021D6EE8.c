/*
 * function: GSYNC_STATE_StateWaitFade
 * address:  0x021D6EE8
 * packet:   pkt_021D6EE8
 * region:   ov123
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WIPE_SYS_EndCheck  0x020221A4  thumb
 *   GSYNC_STATE_ChangeState  0x021D6EE0  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int   u32;
typedef unsigned char  u8;
extern u32 WIPE_SYS_EndCheck(void);
extern void GSYNC_STATE_ChangeState(u8 *p, u32 v, int unused);

void GSYNC_STATE_StateWaitFade(char *p)
{
    if (WIPE_SYS_EndCheck() != 0)
        GSYNC_STATE_ChangeState((u8 *)p, 0, 0x157);
}
