/*
 * function: WIFICLUB_StateShowSaveNotice
 * address: 0x021BED08
 * packet: pkt_ov099_021BED08
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Extent ends with two-byte alignment padding at 0x021BED3A.
 * symbols:
 *   WIFICLUB_ClearTalkWindow 0x021BA8EC thumb ov099
 *   APP_ENV_IsRunOnTwl 0x0202EB0C thumb
 *   WIFICLUB_ShowNoticeWindow 0x021BAB04 thumb ov099
 */
#include "../include/Obj13699.h"
extern void WIFICLUB_ClearTalkWindow(char *);
extern unsigned int APP_ENV_IsRunOnTwl(void);
extern void WIFICLUB_ShowNoticeWindow(void *p, int message);
int WIFICLUB_StateShowSaveNotice(char *p,int ret) {
 WIFICLUB_ClearTalkWindow(p);
 if (APP_ENV_IsRunOnTwl()) WIFICLUB_ShowNoticeWindow(p,44);
 else WIFICLUB_ShowNoticeWindow(p,19);
 ((struct Obj13699 *)p)->f1CC=8;
 ((struct Obj13699 *)p)->f1E8=0;
 return ret;
}
