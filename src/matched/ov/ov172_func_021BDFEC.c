/*
 * function: COMM_TVT_SYS_GetTalkStatus
 * address:  0x021BDFEC
 * packet:   pkt_021B6100
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail call to func_021B9F98, second argument the field at +0x1e8.
 *
 * symbols:
 *   func_021B9F98  0x021B9F98  thumb
 *
 * Addresses are Black-image addresses.
 *
 * evidence: func_021B9F98 is ov172's own code ("ldr r0, [r1, #0x10]; bx lr"
 * after the pop at 0x021B9F94), inside ov172's window, so only ov172 can be
 * resident there when this pool word is used.  Its start is seeded in
 * layout/function_starts.txt from this pointer word, the only reference; it
 * attests as sole-ref/code from ov172's own listing.
 */
#include "../include/Obj24109.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern int func_021B9F98(int unused, int *p);

int COMM_TVT_SYS_GetTalkStatus(void *p)
{
    return func_021B9F98((int)p, (int *)(((struct Obj24109 *)p)->f1E8));
}
