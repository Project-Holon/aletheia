/*
 * function: GSYNC_DOWNLOAD_SetAttr
 * address: 0x021D5C64
 * packet: pkt_ov123_021D5C64
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   STD_TSNPrintf 0x0208D80C arm
 *   DWC_NdSetAttr 0x021C5C04 arm ov114
 *   sGsyncDownloadAttrFormat 0x021DAA74 data a1
 *   sGsyncDownloadAssertText 0x021DAA54 data ov123 a1
 */
#include "../include/Obj22946.h"
extern const char sGsyncDownloadAttrFormat[],sGsyncDownloadAssertText[];
extern int STD_TSNPrintf(char *,int,const char *,...);
extern int DWC_NdSetAttr(char *attr1, char *attr2, char *attr3);
int GSYNC_DOWNLOAD_SetAttr(char *p,void *arg,int value){char buf[20];int ok=0;((struct Obj22946 *)p)->fB0=0;STD_TSNPrintf(buf,20,sGsyncDownloadAttrFormat,value);if(DWC_NdSetAttr(arg,buf,(char *)sGsyncDownloadAssertText))ok=1;return ok;}
