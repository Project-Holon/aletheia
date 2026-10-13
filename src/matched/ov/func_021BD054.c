/*
 * function: FIELD_PLACE_NAME_DeleteMsgData
 * address:  0x021BD054
 * packet:   pkt_021BD054
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
 *   MSGDATA_Delete  0x02045C04  arm
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00575.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;
struct Rec;
extern u32 MSGDATA_Delete(struct Rec *rec);

void FIELD_PLACE_NAME_DeleteMsgData(u8 *p)
{
    u32 v = ((struct Obj00575 *)p)->f14;
    if (v != 0) {
        MSGDATA_Delete((struct Rec *)v);
        ((struct Obj00575 *)p)->f14 = 0;
    }
}
