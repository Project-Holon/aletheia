/*
 * function: ZKNSEARCH_MAIN_ShowLayerSetB
 * address:  0x021BC5C8
 * packet:   pkt_021BC5C8
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BG_SYS_SetVisibleLayer  0x0204047C  arm  arm9
 * blocker: +0006 THM_CALL BG_SYS_SetVisibleLayer       -> unresolved: 0204047C (arm, from name) has no witness outside 021BC5C8..021BC5DC
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void BG_SYS_SetVisibleLayer(int idx, unsigned short val);

void ZKNSEARCH_MAIN_ShowLayerSetB(void)
{
    BG_SYS_SetVisibleLayer(0, 0);
    BG_SYS_SetVisibleLayer(1, 1);
}

