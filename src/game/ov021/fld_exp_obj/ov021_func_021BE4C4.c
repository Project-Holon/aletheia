/*
 * function: func_021BE4C4
 * address:  0x021BE4C4
 * packet:   pkt_ov021_021BE4C4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020489F4  0x020489F4  arm
 *   func_02048A18  0x02048A18  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    void *p;
    u32 x4;
    u32 x8;
    u16 idx;
    u16 he;
} Slot;

typedef struct {
    u32 x0;
    u32 res;
    Slot slots[4];
} Obj;

extern u32 func_020489F4(u8 *a0, int i);
extern u32 func_02048A18(u8 *a0, int i);

int func_021BE4C4(Obj *o, u32 i, int delta)
{
    int v;

    if (o->slots[i].p == 0) {
        return 0;
    }
    if (i >= 4) {
        return 0;
    }
    v = func_020489F4((u8 *)o->res, o->slots[i].idx);
    return (int)func_02048A18((u8 *)o->res, (u16)(v + delta));
}
