/*
 * function: CTVT_TALK_SetMicMode
 * address:  0x021B9574
 * packet:   pkt_021B6100
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail call passing the field at +0x10.
 *
 * symbols:
 *   CTVT_MIC_SetMode  0x021BA094  thumb  ov172
 *
 * evidence: CTVT_MIC_SetMode is ov172's own code (a 2-byte "bx lr" right after
 * the "pop {r4, pc}" at 0x021BA092), inside ov172's window, so only ov172 can
 * be resident there when this pool word is used.  Its start is seeded in
 * layout/function_starts.txt from this pointer word, the only reference;
 * it attests as sole-ref/code from ov172's own listing.  The old hint ov217
 * named a different overlay's function mapped over the same address.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj24090.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void CTVT_MIC_SetMode(int v);

void CTVT_TALK_SetMicMode(int unused, char *p)
{
    CTVT_MIC_SetMode(((struct Obj24090 *)p)->f10);
}
