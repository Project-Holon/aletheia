/*
 * function: GAME_BEACON_SetZone
 * address:  0x0202735C
 * packet:   pkt_0202735C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAME_BEACON_Work     0x02146940  data
 *   GAME_BEACON_SetInfoZone  0x0202737C  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;


extern char *GAME_BEACON_Work;
extern void GAME_BEACON_SetInfoZone(u32 *p, u32 a1, u32 a2);

void GAME_BEACON_SetZone(u32 a0, u32 a1)
{
    GAME_BEACON_SetInfoZone((u32 *)(GAME_BEACON_Work + 4), a0, a1);
    *(u8 *)(GAME_BEACON_Work + 0x62) = 1;
}
