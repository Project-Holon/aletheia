/*
 * function: GSYNC_DOWNLOAD_FreeWork
 * address: 0x021D5B70
 * packet: pkt_ov123_021D5B70
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gGsyncDownloadWork 0x021DAC20 data ov123 a4
 *   DWC_RAP_SetErrorHookCallback 0x02156DE0 thumb ov009
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj22942.h"
extern char *gGsyncDownloadWork;
extern void DWC_RAP_SetErrorHookCallback(int a, int b);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
void GSYNC_DOWNLOAD_FreeWork(char *p){if(gGsyncDownloadWork){DWC_RAP_SetErrorHookCallback(0,0);func_020307B0(((struct Obj22942 *)p)->fB8);func_020307B0(p);gGsyncDownloadWork=0;}}
