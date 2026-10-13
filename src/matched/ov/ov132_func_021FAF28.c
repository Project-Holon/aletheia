/*
 * function: func_021FAF28
 * address:  0x021FAF28
 * packet:   pkt_021FAF28
 * region:   ov132
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * blocker resolved: VM_GetU32 was matched in arm9 (src/matched/
 * VM_GetU32.c, shard pkt_0201134C); the +0006 call now attests as
 * `matched`.  The symbols: line had it as `arm`; it is Thumb and now says so.
 *
 * symbols:
 *   VM_GetU32  0x0201134C  thumb
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj14099.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct Cursor;
extern u32 VM_GetU32(struct Cursor *p);

int func_021FAF28(void *a, u8 *p)
{
    ((struct Obj14099 *)p)->f14 = (u16)VM_GetU32(((struct Obj14099 *)p)->f4);
    return 1;
}
