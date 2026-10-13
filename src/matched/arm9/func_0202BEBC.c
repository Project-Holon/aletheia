/*
 * function: ISS_ZONE_SYS_Update
 * address:  0x0202BEBC
 * packet:   pkt_0202BEBC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Calls ISS_ZONE_SYS_StepFade when the object's +0 word is set.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ISS_ZONE_SYS_Update.c \
 *       --func ISS_ZONE_SYS_Update --addr 0x0202BEBC --thumb --cc 1.1p1
 *
 * symbols:
 *   ISS_ZONE_SYS_StepFade  0x0202BFF0  thumb
 */
#include "../include/Obj02602.h"

typedef unsigned char u8;
typedef unsigned int  u32;

struct Obj;
extern void ISS_ZONE_SYS_StepFade(struct Obj *o);

void ISS_ZONE_SYS_Update(u8 *p)
{
    if (((struct Obj02602 *)p)->f0 != 0) {
        ISS_ZONE_SYS_StepFade((struct Obj *)p);
    }
}
