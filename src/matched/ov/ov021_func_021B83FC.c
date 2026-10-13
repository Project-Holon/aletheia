/*
 * function: FIELD_RAIL_WORK_GetLocationParts
 * address:  0x021B83FC
 * packet:   pkt_ov021_021B83FC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * note: Tbl.f2 is volatile: the original re-reads the count on every pass and the
 *       loop names o->f24 directly (no local for it).
 *
 * symbols:
 *   FIELD_RAIL_LINE_GetWidthAt  0x021B9280  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;
typedef int s32;

struct Ent { char pad[0x48]; };
struct Tbl { char pad00[2]; volatile u16 f2; char pad04[0x10]; struct Ent *f14; };
struct Obj {
    char pad00[4];
    struct Ent *f4;
    char pad08[4];
    s32 fC;
    s32 f10;
    s32 f14;
    char pad18[0xC];
    struct Tbl *f24;
};

typedef unsigned int   u32;
typedef unsigned char  u8;
extern int FIELD_RAIL_LINE_GetWidthAt(u8 *a, u32 arg2, u32 arg3, u8 *tbl);

void FIELD_RAIL_WORK_GetLocationParts(struct Obj *o, u16 *out0, u16 *out1, u16 *out2)
{
    s32 idx, i, m, n;

    m = FIELD_RAIL_LINE_GetWidthAt((u8 *)o->f4, 0, o->f10, (u8 *)o->f24);
    n = FIELD_RAIL_LINE_GetWidthAt((u8 *)o->f4, o->f10, o->f10, (u8 *)o->f24);
    if (m < n)
        m = n;
    idx = 0;
    for (i = 0; i < o->f24->f2; i++) {
        if (o->f4 == o->f24->f14 + i)
            idx = i;
    }
    *out0 = idx;
    *out1 = o->fC / 16;
    *out2 = o->f14 / 16 + m / 16;
}
