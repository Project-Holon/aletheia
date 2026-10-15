/*
 * function: ZUKAN_SEARCH_SCREEN_Delete
 * address: 0x021BC6CC
 * packet: pkt_ov211_021BC6CC
 * region: ov211
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * volatile: hardware halfword clear at 021BC6DA to04000050 and021BC6DE to04001050.
 * symbols:
 *   ZUKAN_SEARCH_SCREEN_UnregisterVBlank 0x021BC30C thumb ov211
 *   ZUKAN_SEARCH_SCREEN_DeleteBg 0x021BC43C thumb ov211
 *   BG_SYS_SetMainVisiblePlanes 0x02043534 arm
 *   BG_SYS_SetSubVisiblePlanes 0x020435F4 arm
 */
extern void ZUKAN_SEARCH_SCREEN_UnregisterVBlank(unsigned char *),ZUKAN_SEARCH_SCREEN_DeleteBg(void),BG_SYS_SetMainVisiblePlanes(unsigned),BG_SYS_SetSubVisiblePlanes(unsigned);
int ZUKAN_SEARCH_SCREEN_Delete(unsigned char *p){ZUKAN_SEARCH_SCREEN_UnregisterVBlank(p);ZUKAN_SEARCH_SCREEN_DeleteBg();*(volatile unsigned short *)0x04000050=0;*(volatile unsigned short *)0x04001050=0;BG_SYS_SetMainVisiblePlanes(0);BG_SYS_SetSubVisiblePlanes(0);return 6;}
