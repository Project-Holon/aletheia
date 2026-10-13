/*
 * function: DWC_RAP_StopVchat
 * address:  0x021563D0
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Calls the ov013 routine when the word at +0x76c of the module pointer is set.
 *
 * symbols:
 *   g_021A8264  0x021A8264  data
 *   VCT_MAIN_HangUp  0x021AF13C  thumb  ov013

 */
#include "../include/Obj18651.h"
#include "../include/G__anon_Work.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

void DWC_RAP_StopVchat(void)
{
    extern struct _anon_Work *g_021A8264;
    void VCT_MAIN_HangUp(void);
    if (((struct Obj18651 *)((char *)g_021A8264))->f76C) VCT_MAIN_HangUp();
}
