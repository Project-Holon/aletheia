/*
 * function: WIFICLUB_StateCountdownToLobby
 * address: 0x021C16EC
 * packet: pkt_ov099_021C16EC
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Extent remainder: two-byte alignment padding.
 * symbols:
 *   WIFICLUB_UpdateTalkStream 0x021BA928 thumb ov099
 *   WIFICLUB_ClearTalkWindow 0x021BA8EC thumb ov099
 */
#include "../include/Obj00008.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern int WIFICLUB_UpdateTalkStream(void *);
extern void WIFICLUB_ClearTalkWindow(char *);
int WIFICLUB_StateCountdownToLobby(char *p,int ret){if(!WIFICLUB_UpdateTalkStream(p))return ret;if(--((struct Obj00008 *)p)->f1E0==0){((struct Obj00008 *)p)->f1D0=0;((struct Obj00008 *)p)->f1CC=26;WIFICLUB_ClearTalkWindow(p);}return ret;}
