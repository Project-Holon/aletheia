/*
 * function: BSUBWAY_SCR_SavePlayDataMembers
 * address:  0x021C9CAC
 * packet:   pkt_ov021_021C9CAC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Like 0x021C9BCC with a reset of the +0x70 object and without the +0x32 block.
 *
 * symbols:
 *   GDS_PROFILE_SetFieldRecField  0x0200D914  thumb
 *   GDS_PROFILE_ClearFieldRecCount03  0x0200DA14  thumb
 *   GDS_PROFILE_SetFieldRecFlag1  0x0200D868  thumb
 * Addresses are Black-image addresses.
 */
#include "../include/Obj02733.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u8  pad0[0xc];
    u16 lo  : 5;
    u16 sel : 3;
    u16 hi  : 8;
} Sel;

struct Blk3C;
extern void GDS_PROFILE_SetFieldRecField(struct Blk3C *p, u32 id, const void *src);
extern void GDS_PROFILE_ClearFieldRecCount03(struct Blk3C *p);
extern void GDS_PROFILE_SetFieldRecFlag1(struct Blk3C *p, u32 v);

void BSUBWAY_SCR_SavePlayDataMembers(u8 *p)
{
    u8 v = p[9];

    GDS_PROFILE_SetFieldRecField((struct Blk3C *)(((struct Obj02733 *)p)->f70), 0, &v);
    GDS_PROFILE_ClearFieldRecCount03((struct Blk3C *)(((struct Obj02733 *)p)->f70));
    GDS_PROFILE_SetFieldRecField((struct Blk3C *)(((struct Obj02733 *)p)->f70), 5, p + 0x1e);
    GDS_PROFILE_SetFieldRecFlag1((struct Blk3C *)(((struct Obj02733 *)p)->f70), 1);
    if (p[9] == 2 || p[9] == 7) {
        v = ((Sel *)p)->sel;
        GDS_PROFILE_SetFieldRecField((struct Blk3C *)(((struct Obj02733 *)p)->f70), 9, &v);
        GDS_PROFILE_SetFieldRecField((struct Blk3C *)(((struct Obj02733 *)p)->f70), 6, p + 0x628 + ((Sel *)p)->sel * 0x14);
        GDS_PROFILE_SetFieldRecField((struct Blk3C *)(((struct Obj02733 *)p)->f70), 7, p + 0x664 + ((Sel *)p)->sel);
    }
}
