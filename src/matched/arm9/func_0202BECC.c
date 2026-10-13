/*
 * function: ISS_ZONE_SYS_SwitchZone
 * address:  0x0202BECC
 * packet:   pkt_0202BECC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Guarded one-argument forward: only when the node's first word is set does
 * ISS_ZONE_SYS_BeginFade get called with the node itself.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/ISS_ZONE_SYS_SwitchZone.c \
 *       --func ISS_ZONE_SYS_SwitchZone --addr 0x0202BECC --thumb --cc 1.1p1

 * Closed by the `matched` class: 0x0202BF90 was filed as an EXACT entry this wave (pkt_0202BEBC), matched with the object spelled as a struct.
 *
 * symbols:
 *   ISS_ZONE_SYS_BeginFade  0x0202BF90  thumb
 */
#include "../include/Obj03440.h"

typedef unsigned char u8;
typedef unsigned int  u32;

struct Obj;
extern void ISS_ZONE_SYS_BeginFade(struct Obj *o, u32 key);

void ISS_ZONE_SYS_SwitchZone(u8 *p, u32 key)
{
    if (((struct Obj03440 *)p)->f0 != 0) {
        ISS_ZONE_SYS_BeginFade((struct Obj *)p, key);
    }
}
