/*
 * function: ISS_SYS_CreateZone
 * address:  0x0202B63C
 * packet:   pkt_0202B59C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Builds the +0x1c sub-object from the object's u16 id.
 *
 * Promoted out of src/pending: the callee ISS_ZONE_SYS_Create acquired an EXACT
 * manifest entry, so the THM_CALL field now resolves through the `matched`
 * class.  Every byte is hard; the listing extent is two bytes longer than the
 * code because of the Thumb alignment pad the front end emits after `pop`.
 *
 * symbols:
 *   ISS_ZONE_SYS_Create  0x0202BE68  thumb
 */
#include "../include/Obj00563.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Obj;

extern u8 *ISS_ZONE_SYS_Create(u32 heapId);

void ISS_SYS_CreateZone(struct Obj *o)
{
    ((struct Obj00563 *)o)->f1C = (u32)ISS_ZONE_SYS_Create(((struct Obj00563 *)o)->f0);
}
