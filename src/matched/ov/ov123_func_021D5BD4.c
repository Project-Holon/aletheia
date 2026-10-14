/*
 * function: GSYNC_DOWNLOAD_InitAsync
 * address: 0x021D5BD4
 * packet: pkt_ov123_021D5BD4
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   DWC_NdInitAsync 0x021C5928 arm ov114
 *   DWC_RAP_SetErrorHookCallback 0x02156DE0 thumb ov009
 *   GSYNC_DOWNLOAD_SetRequestMode 0x021D5AC0 thumb ov123
 *   GSYNC_DOWNLOAD_CleanupAsync 0x021D5BA8 thumb ov123
 *   sGsyncDownloadGameCode 0x021DAA58 data a1
 *   sGsyncDownloadPassword 0x021DAA60 data a1
 */
#include "../include/Obj22944.h"
extern char sGsyncDownloadGameCode[],sGsyncDownloadPassword[];
typedef unsigned int   u32;
extern void GSYNC_DOWNLOAD_SetRequestMode(void *unused, u32 mode);
extern int GSYNC_DOWNLOAD_CleanupAsync(char *);
extern int DWC_NdInitAsync(void (*callback)(int, int, int), char *gamecd, char *passwd);
extern void DWC_RAP_SetErrorHookCallback(int a, int b);
int GSYNC_DOWNLOAD_InitAsync(char *p){((struct Obj22944 *)p)->fB0=0;if(!DWC_NdInitAsync((void (*)(int,  int,  int))GSYNC_DOWNLOAD_SetRequestMode,sGsyncDownloadGameCode,sGsyncDownloadPassword))return 0;DWC_RAP_SetErrorHookCallback((int)GSYNC_DOWNLOAD_CleanupAsync,(int)p);return 1;}
