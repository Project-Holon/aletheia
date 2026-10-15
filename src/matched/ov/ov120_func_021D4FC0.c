/*
 * function: GTSNEGO_DISP_ShowSubPlanes
 * address:  0x021D4FC0
 * packet:   pkt_021D4FC0
 * region:   ov120
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   GTSNEGO_DISP_ShowPartySelect  0x021D588C  thumb
 *   BG_SYS_SetSubVisiblePlanes  0x020435F4  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void GTSNEGO_DISP_ShowPartySelect(u8 *p);
extern void BG_SYS_SetSubVisiblePlanes(u32 planes);

void GTSNEGO_DISP_ShowSubPlanes(u8 *p)
{
    GTSNEGO_DISP_ShowPartySelect(p);
    BG_SYS_SetSubVisiblePlanes(0x1f);
}
