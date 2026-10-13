/*
 * function: ISS_SYS_EnterZone
 * address:  0x0202B744
 * packet:   pkt_0202B6F8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Promoted out of src/pending: both callees, ISS_SYS_GetZoneId and ISS_ZONE_SYS_Start,
 * now have EXACT manifest entries, so the two THM_CALL fields resolve through
 * the `matched` class and every byte is hard.
 *
 * symbols:
 *   ISS_SYS_GetZoneId  0x0202B804  thumb
 *   ISS_ZONE_SYS_Start  0x0202BEDC  thumb
 */
#include "../include/Obj15840.h"

typedef unsigned char u8;
typedef unsigned int  u32;

struct Obj;
extern unsigned short ISS_SYS_GetZoneId(struct Obj *o);
extern void ISS_ZONE_SYS_Start(int a, int b);

void ISS_SYS_EnterZone(u8 *o)
{
    ISS_ZONE_SYS_Start(((struct Obj15840 *)o)->f1C, ISS_SYS_GetZoneId((struct Obj *)o));
}
