/*
 * function: WIFICLUB_StateWaitKeyReturnToLobby
 * address: 0x021BFA00
 * packet: pkt_ov099_021BFA00
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Extent ends with two-byte alignment padding at 0x021BFA26.
 * symbols:
 *   KEY_GetTrg 0x020362DC arm
 *   WIFICLUB_DisableTouchBar 0x021C2408 thumb ov099
 *   WIFICLUB_ClearTalkWindow 0x021BA8EC thumb ov099
 */
#include "../include/Obj00008.h"
extern unsigned int KEY_GetTrg(void);
extern void WIFICLUB_DisableTouchBar(char *);
extern void WIFICLUB_ClearTalkWindow(char *);
int WIFICLUB_StateWaitKeyReturnToLobby(char *p, int ret) {
 if (KEY_GetTrg()) { ((struct Obj00008 *)p)->f1CC=11; WIFICLUB_DisableTouchBar(p); WIFICLUB_ClearTalkWindow(p); }
 return ret;
}
