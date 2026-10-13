/*
 * function: PLACE_NAME_LETTER_DeleteBmp
 * address:  0x021BD264
 * packet:   pkt_021BD264
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Pattern-generated from the ov021 family.
 *
 * symbols:
 *   BMP_Delete  0x020437AC  arm
 * Addresses are Black-image addresses.
 */
#include "../include/Obj06054.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;
struct Obj020437AC;
extern void BMP_Delete(struct Obj020437AC *p);

void PLACE_NAME_LETTER_DeleteBmp(u8 *p)
{
    u32 v = ((struct Obj06054 *)p)->f8;
    if (v != 0) {
        BMP_Delete((struct Obj020437AC *)v);
        ((struct Obj06054 *)p)->f8 = 0;
    }
}
