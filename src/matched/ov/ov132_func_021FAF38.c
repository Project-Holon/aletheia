/*
 * function: func_021FAF38
 * address:  0x021FAF38
 * packet:   pkt_021FAF38
 * region:   ov132
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * blocker resolved: func_0201134C was matched in arm9 (src/matched/
 * func_0201134C.c, shard pkt_0201134C); the call now attests as `matched`.
 * The symbols: line had it as `arm`; it is Thumb and now says so.
 *
 * symbols:
 *   func_0201134C  0x0201134C  thumb
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj08157.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern int func_0201134C(void *);

int func_021FAF38(void *a, u8 *p)
{
    int v = func_0201134C(((struct Obj08157 *)p)->f4);
    if (((struct Obj08157 *)p)->f10 >= (u32)v)
        return 0;
    ((struct Obj08157 *)p)->f14 = (u16)(v - ((struct Obj08157 *)p)->f10);
    return 1;
}
