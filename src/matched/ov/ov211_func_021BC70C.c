/*
 * function: ZUKAN_SEARCH_SCREEN_WaitWipeExit
 * address: 0x021BC70C
 * packet: pkt_ov211_021BC70C
 * region: ov211
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 */
extern unsigned WIPE_SYS_EndCheck(void);
int ZUKAN_SEARCH_SCREEN_WaitWipeExit(void){if(WIPE_SYS_EndCheck()==1)return 1;return 3;}
