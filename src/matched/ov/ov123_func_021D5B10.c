/*
 * function: GSYNC_DOWNLOAD_AllocWork
 * address: 0x021D5B10
 * packet: pkt_ov123_021D5B10
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_02034714 0x02034714 arm
 *   sGsyncDownloadFileName 0x021DAA40 data ov123 a1
 *   sGsyncDownloadAssertText 0x021DAA54 data ov123 a1
 *   gGsyncDownloadWork 0x021DAC20 data ov123 a4
 */
#include "../include/Obj13974.h"
typedef unsigned short u16;
extern char sGsyncDownloadFileName[], sGsyncDownloadAssertText[];
extern char *gGsyncDownloadWork;
typedef unsigned int   u32;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02034714(const char *expr, u32 line, const char *file);
char *GSYNC_DOWNLOAD_AllocWork(int heap,int size)
{
    char *p;
    p=func_02030734(heap,0xd4,1,sGsyncDownloadFileName,0x88);
    if (gGsyncDownloadWork) func_02034714(sGsyncDownloadAssertText,0,sGsyncDownloadAssertText);
    gGsyncDownloadWork=p;
    ((struct Obj13974 *)p)->fB8=func_02030734(heap,size+0x40,0,sGsyncDownloadFileName,0x8c);
    ((struct Obj13974 *)p)->fBC=size;
    return p;
}
