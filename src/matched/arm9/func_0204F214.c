/*
 * function: BILLBOARD_ReleaseImageVram
 * address:  0x0204F214
 * packet:   pkt_0204F150
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   NNS_GfdDefaultFuncFreeTexVram      0x020A8144  data
 *   NNS_GfdDefaultFuncFreePlttVram      0x020A814C  data
 *
 * The unguarded entry teardown: it runs the two function-pointer globals over
 * the entry's +0x20 and +0x24 words unconditionally (their addresses in the
 * pools are the two ABS32 relocations), then clears the entry and stamps 5
 * into +0x14.
 *
 * A different file from BILLBOARD_ReleaseImageVramIfUsed, which is the same body behind the
 * "entry is live" guard, and from BILLBOARD_DeleteImage, which does the same work
 * through two direct calls.  The three are consecutive in the image and call
 * 0x0204F5A8-free leaf helpers, so each stands alone.
 */
#include "../include/Obj06988.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void (*NNS_GfdDefaultFuncFreeTexVram)(u32 v);
extern void (*NNS_GfdDefaultFuncFreePlttVram)(u32 v);

void BILLBOARD_ReleaseImageVram(u8 *a0, int i)
{
    u32 off = i * 0x28;

    NNS_GfdDefaultFuncFreeTexVram(*(u32 *)(((struct Obj06988 *)a0)->f4 + off + 0x20));
    NNS_GfdDefaultFuncFreePlttVram(*(u32 *)(((struct Obj06988 *)a0)->f4 + off + 0x24));
    *(u32 *)(((struct Obj06988 *)a0)->f4 + off) = 0;
    *(u32 *)(((struct Obj06988 *)a0)->f4 + off + 0x14) = 5;
}
