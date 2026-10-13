/*
 * function: WIFICLUB_StateStartMessageDismiss
 * address: 0x021BFAD0
 * packet: pkt_ov099_021BFAD0
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Extent ends with two-byte alignment padding at 0x021BFB02.
 * symbols:
 *   DWC_RAP_GetTargetFriendIndex 0x02156A3C thumb ov009
 *   WIFICLUB_SetPartnerNameWord 0x021BA874 thumb ov099
 *   WIFICLUB_ShowStreamedMessage 0x021BAAB8 thumb ov099
 *   WIFICLUB_SetOwnStatusAndPublish 0x021C18C8 thumb ov099
 */
#include "../include/Obj22051.h"
extern int DWC_RAP_GetTargetFriendIndex(void);
extern void WIFICLUB_SetPartnerNameWord(void *,int);
extern void WIFICLUB_ShowStreamedMessage(char *,int,int);
extern void WIFICLUB_SetOwnStatusAndPublish(char *,int,int);
int WIFICLUB_StateStartMessageDismiss(char *p,int ret) {
 WIFICLUB_SetPartnerNameWord(p,DWC_RAP_GetTargetFriendIndex());
 WIFICLUB_ShowStreamedMessage(p,11,0);
 WIFICLUB_SetOwnStatusAndPublish(p,4,4);
 ((struct Obj22051 *)p)->f1CC=15;
 return ret;
}
