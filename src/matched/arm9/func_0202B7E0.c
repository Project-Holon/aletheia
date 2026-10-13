/*
 * function: ISS_SYS_OnZoneChangeSwitch
 * address:  0x0202B7E0
 * packet:   pkt_0202B7BC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 *
 * Parked: every concrete byte is right; the only unresolved relocation site(s)
 * target 0202C0C8, which has no witness outside this range (no outside branch names it,
 * not a manifest entry, not in layout/runtime_arm9.txt).
 * status:   EXACT
 *
 * The callee is an unlabelled Thumb thunk, so its ISA has to be declared here;
 * without the `symbols:` line the name convention defaults it to ARM and the
 * `matched` class refuses the EXACT entry at 0x0202C0C8 on the ISA mismatch.
 *
 * symbols:
 *   sub_0202C0C8  0x0202C0C8  thumb

 * Closed by the `matched` class: 0x0202C0C8 was filed as an EXACT entry this wave (pkt_0202C148).
 */
#include "../include/Obj08804.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void sub_0202C0C8(void *p);

void ISS_SYS_OnZoneChangeSwitch(u8 *p, u32 b)
{
    sub_0202C0C8(((struct Obj08804 *)p)->f20);
}
