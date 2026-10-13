/*
 * function: MUSICAL_PROGRAM_GetBaseProgramId
 * address:  0x02157364
 * packet:   pkt_02157364
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Recursive MATCH unblocker: callee of func_021F8D88 (ov132) +0008. Coherent
 * Thumb leaf in ov010 (ARM code in ov009), so the ov010 shard makes that site
 * attest as `matched` -- the earlier `arm` declaration was wrong.
 */
#include "../include/Obj18732.h"
#include "../include/Obj18733.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

u8 MUSICAL_PROGRAM_GetBaseProgramId(char *a0)
{
    return ((struct Obj18733 *)(((struct Obj18732 *)a0)->fC))->f0;
}
