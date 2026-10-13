/*
 * function: WIFICLUBACTOR_GetActorFacing
 * address:  0x021B9A60
 * packet:   pkt_ov099_021B9A60
 * region:   ov099
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 *
 * symbols:
 *   func_021C49A4  0x021C49A4  thumb  ov127
 *   func_021C4A8C  0x021C4A8C  thumb  ov127
 * Two ov127 calls, the second on the first one's answer.
 *
 * NOT EXACT.  MATCH: 16 bytes, the call sequence and the first relocation are
 * right; the second target 0x021C4A8C has no witness.  It is not a `func_` label
 * in any overlay listing, yet nine overlays overlap the address (ov016, ov021,
 * ov093, ov111, ov114, ov127, ov136, ov172, ov208), so a region hint cannot name
 * one either.  It turns EXACT as soon as 0x021C4A8C is labelled or matched.
 *
 * UNBLOCKED: 0x021C4A8C is now an EXACT entry in layout/matched/ov127;
 * the second call site resolves as matched, verdict promoted to EXACT.
 */
#include "../include/Obj18148.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

extern int func_021C49A4(u8 *p, unsigned int i);
extern unsigned char func_021C4A8C(int i);

unsigned char WIFICLUBACTOR_GetActorFacing(char *p)
{
    return func_021C4A8C(func_021C49A4(((struct Obj18148 *)p)->f0, 6));
}
