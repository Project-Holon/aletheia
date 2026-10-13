/*
 * function: WIFICLUB_StateWaitKeyOrNetUp
 * address: 0x021C15C0
 * packet: pkt_ov099_021C15C0
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Extent remainder: two-byte alignment padding.
 * symbols:
 *   WIFICLUB_UpdateTalkStream 0x021BA928 thumb ov099
 *   WIFICLUB_IsNetStateConnected 0x021BF03C thumb ov099
 *   KEY_GetTrg 0x020362DC arm
 */
#include "../include/Obj00008.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern int WIFICLUB_UpdateTalkStream(void *);
extern int WIFICLUB_IsNetStateConnected(char *);
extern u32 KEY_GetTrg(void);
int WIFICLUB_StateWaitKeyOrNetUp(char *p,int ret){if(!WIFICLUB_UpdateTalkStream(p))return ret;if(WIFICLUB_IsNetStateConnected(p))((struct Obj00008 *)p)->f1CC=48;if(KEY_GetTrg()&3)((struct Obj00008 *)p)->f1CC=48;return ret;}
