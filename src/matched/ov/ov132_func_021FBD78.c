/*
 * function: func_021FBD78
 * address: 0x021FBD78
 * packet: pkt_ov132_021FBD78
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * note: inferred extent ends with two zero padding bytes before the next labelled function.
 * symbols:
 *   VM_GetU32 0x0201134C thumb
 */
#include "../include/Obj03290.h"
typedef unsigned char u8;
typedef unsigned int   u32;
struct Cursor;
extern u32 VM_GetU32(struct Cursor *p);
int func_021FBD78(int unused, char *p)
{
    int a, b, c, d;
    a = VM_GetU32(((struct Obj03290 *)p)->f4);
    b = VM_GetU32(((struct Obj03290 *)p)->f4);
    c = VM_GetU32(((struct Obj03290 *)p)->f4);
    d = VM_GetU32(((struct Obj03290 *)p)->f4);
    ((struct Obj03290 *)p)->f18 = 0;
    if (a == 1) ((struct Obj03290 *)p)->f18 += 1;
    if (b == 1) ((struct Obj03290 *)p)->f18 += 2;
    if (c == 1) ((struct Obj03290 *)p)->f18 += 4;
    if (d == 1) ((struct Obj03290 *)p)->f18 += 8;
    return 0;
}
