/*
 * function: GSYNC_DOWNLOAD_CleanupOnce
 * address: 0x021D5D58
 * packet: pkt_ov123_021D5D58
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   DWC_NdCleanupAsync 0x021C5B80 arm ov114
 */
#include "../include/Obj13976.h"
extern int DWC_NdCleanupAsync(void);
int GSYNC_DOWNLOAD_CleanupOnce(char *p){int ok;if(!((struct Obj13976 *)p)->fC4){ok=0;((struct Obj13976 *)p)->fB0=0;if(!DWC_NdCleanupAsync())return ok;}return 1;}
