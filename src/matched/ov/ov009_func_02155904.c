/*
 * function: DWC_RAP_EndCancel
 * address:  0x02155904
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Sets 0xd through DWC_RAP_SetState when the word at +0x754 is 0xc, else 0xb.
 *
 * symbols:
 *   DWC_RAP_SetState  0x02155374  thumb  ov009
 *   g_021A8264  0x021A8264  data

 */
#include "../include/Obj18648.h"
#include "../include/G__anon_Work.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

void DWC_RAP_EndCancel(void)
{
    extern struct _anon_Work *g_021A8264;
    void DWC_RAP_SetState(int v);
    if (((struct Obj18648 *)((char *)g_021A8264))->f754 == 0xc) {
        DWC_RAP_SetState(0xd);
        return;
    }
    DWC_RAP_SetState(0xb);
}
