/*
 * function: WIFICLUB_StateWaitVchatEnd
 * address: 0x021BFDA8
 * packet: pkt_ov099_021BFDA8
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Extent ends with two-byte alignment padding at 0x021BFDCE.
 * symbols:
 *   DWC_RAP_IsVchatActive 0x021563EC thumb ov009
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_HANDLE_SetTimingSyncRange 0x02039C68 arm
 */
#include "../include/Obj22052.h"
extern int DWC_RAP_IsVchatActive(void);
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Link;
extern void GFL_NET_HANDLE_SetTimingSyncRange(struct Link *, unsigned int, unsigned int);
int WIFICLUB_StateWaitVchatEnd(char *p, int ret) {
 if (!DWC_RAP_IsVchatActive()) { GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),24,10); ((struct Obj22052 *)p)->f1CC=172; }
 return ret;
}
