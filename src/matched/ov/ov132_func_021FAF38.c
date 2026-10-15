/*
 * function: STA_ACT_SCRIPT_SetRemainingWait
 * address:  0x021FAF38
 * packet:   pkt_021FAF38
 * region:   ov132
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * blocker resolved: VM_GetU32 was matched in arm9 (src/matched/
 * VM_GetU32.c, shard pkt_0201134C); the call now attests as `matched`.
 * The symbols: line had it as `arm`; it is Thumb and now says so.
 *
 * symbols:
 *   VM_GetU32  0x0201134C  thumb
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj08157.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct Cursor;
extern u32 VM_GetU32(struct Cursor *p);

int STA_ACT_SCRIPT_SetRemainingWait(void *a, u8 *p)
{
    int v = VM_GetU32(((struct Obj08157 *)p)->f4);
    if (((struct Obj08157 *)p)->f10 >= (u32)v)
        return 0;
    ((struct Obj08157 *)p)->f14 = (u16)(v - ((struct Obj08157 *)p)->f10);
    return 1;
}
