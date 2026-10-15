/*
 * function: COMM_TVT_SYS_ToggleHalfRes
 * address:  0x021BE08C
 * packet:   pkt_021B6100
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail call passing the inverted flag at +0x1c as the second argument.
 *
 * symbols:
 *   COMM_TVT_SYS_ApplyHalfRes  0x021BE07C  thumb
 *
 * Addresses are Black-image addresses.
 *
 * evidence: COMM_TVT_SYS_ApplyHalfRes is ov172's own code (a tail call to CTVT_COMM_SendSlotHit
 * right after COMM_TVT_SYS_GetHalfRes's bx lr), inside ov172's window, so only ov172
 * can be resident there when this pool word is used.  Its start is seeded in
 * layout/function_starts.txt from this pointer word, the only reference; it
 * attests as sole-ref/code from ov172's own listing.
 */
#include "../include/Obj24125.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void COMM_TVT_SYS_ApplyHalfRes(u32 *p, u32 v);

void COMM_TVT_SYS_ToggleHalfRes(void *p)
{
    u32 v = ((struct Obj24125 *)p)->f1C;
    if (v == 0) {
        v = 1;
    } else {
        v = 0;
    }
    COMM_TVT_SYS_ApplyHalfRes(p, v);
}
