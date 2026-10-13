/*
 * function: GAME_BEACON_GetMyInfo
 * address:  0x020267E4
 * packet:   pkt_020267E4
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   MI_CpuCopy8    0x02082D44  arm
 *   GAME_BEACON_Work     0x02146940  data  a4
 */

typedef unsigned char u8;

extern void MI_CpuCopy8(const void *, void *, unsigned int);
extern u8 *GAME_BEACON_Work;

void GAME_BEACON_GetMyInfo(void *p)
{
    MI_CpuCopy8(GAME_BEACON_Work + 4, p, 0x5C);
}
