/*
 * function: WF2DMAP_MAP_DeleteGrid
 * address: 0x021C47E4
 * packet: pkt_ov127_021C47E4
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Extent remainder: 2-byte zero padding, filed getters 021C47F8/47FC,
 * and separately filed follower WF2DMAP_MAP_CopyEntries.c.
 * symbols:
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj23033.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern u32 func_020307B0(void *p);
void WF2DMAP_MAP_DeleteGrid(u8 *p) { func_020307B0(((struct Obj23033 *)p)->f4);func_020307B0(p); }
