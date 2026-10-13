/*
 * function: FLD_EXP_OBJ_Delete
 * address:  0x021BE2E0
 * packet:   pkt_ov021_021BE2E0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   FLD_EXP_OBJ_RemoveUnit  0x021BE418  thumb  ov021
 *   G3D_UTIL_Delete  0x02047E54  arm
 *   func_020307B0  0x020307B0  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u32 f00;
    u32 f04;
    u32 f08;
    u32 f0C;
} Slot;

typedef struct {
    u32 f00;
    u32 f04;
    Slot slots[4];
} Obj;

typedef unsigned char  u8;
extern void FLD_EXP_OBJ_RemoveUnit(u8 *p, u16 i);
struct Rec;
extern void G3D_UTIL_Delete(struct Rec *p);
extern u32 func_020307B0(void *p);

void FLD_EXP_OBJ_Delete(Obj *o)
{
    u16 i;

    for (i = 0; i < 4; i++) {
        if (o->slots[i].f00 != 0) {
            FLD_EXP_OBJ_RemoveUnit((u8 *)o, i);
        }
    }
    G3D_UTIL_Delete((struct Rec *)o->f04);
    func_020307B0(o);
}
