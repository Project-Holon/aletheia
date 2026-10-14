/*
 * unit: no
 * function: GSYNC_STATE_StateFreeDownloadAndExit
 * address: 0x021D6F44
 * packet: pkt_ov123_021D6F44
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GSYNC_DOWNLOAD_ClearResult 0x021D5C0C thumb ov123
 *   GSYNC_DOWNLOAD_FreeWork 0x021D5B70 thumb ov123
 *   GSYNC_STATE_ChangeState 0x021D6EE0 thumb ov123
 *   GSYNC_STATE_StateSetErrorExit 0x021D706C thumb ov123
 */
#include "../include/Obj10443.h"
typedef unsigned char u8;
typedef unsigned int u32;
typedef signed short s16;
extern int GSYNC_DOWNLOAD_ClearResult(char *p);
extern void GSYNC_DOWNLOAD_FreeWork(char *p);
extern void GSYNC_STATE_ChangeState(u8 *,u32,int);
extern void GSYNC_STATE_StateSetErrorExit(char *);
void GSYNC_STATE_StateFreeDownloadAndExit(u8 *p){if(GSYNC_DOWNLOAD_ClearResult((char *)(((struct Obj10443 *)p)->f8))){GSYNC_DOWNLOAD_FreeWork((char *)(((struct Obj10443 *)p)->f8));((struct Obj10443 *)p)->f8=0;GSYNC_STATE_ChangeState(p,(u32)GSYNC_STATE_StateSetErrorExit,0x17c);}}
