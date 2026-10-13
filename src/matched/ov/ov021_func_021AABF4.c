/*
 * function: EFFECT_ENCOUNT_MakeSearchArea
 * address:  0x021AABF4
 * packet:   pkt_ov021_021AABF4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb  ov021
 *   FLDMMDL_GetGridNowX  0x0216D83C  thumb  ov010
 *   FLDMMDL_GetGridNowZ  0x0216D86C  thumb  ov010
 *   func_02005728  0x02005728  thumb
 *   sSearchAreaOffsets     0x021D8E76  data  a1
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

struct Mon {
    u8 pad00[7];
    u8 lo : 7;
    u8 b7 : 1;
};

struct Ctx {
    void *f00;
    int f04;
    void *f08;
    struct Mon *f0C;
};

struct Area {
    s16 x;
    s16 y;
    s16 mx;
    s16 my;
    s16 bx;
    s16 by;
    u16 ox;
    u16 oy;
    s16 x0;
    s16 y0;
    s16 x1;
    s16 y1;
};

struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
extern void *FIELD_PLAYER_GetMmdl(u8 *p);
extern int FLDMMDL_GetGridNowX(void *o);
extern int FLDMMDL_GetGridNowZ(void *o);
extern u32 func_02005728(u32 v);
extern const s8 sSearchAreaOffsets[][4];

void EFFECT_ENCOUNT_MakeSearchArea(struct Ctx *ctx, void *unused, struct Area *a)
{
    void *o = FIELD_PLAYER_GetMmdl(FIELDMAP_GetFieldPlayer(ctx->f00));
    const s8 *t;
    s16 x0;
    s16 x1;
    s16 y0;
    s16 y1;

    a->x = FLDMMDL_GetGridNowX(o);
    a->y = FLDMMDL_GetGridNowZ(o);
    a->mx = a->x % 32;
    a->my = a->y % 32;
    a->bx = a->x / 32;
    a->by = a->y / 32;
    a->ox = a->x - a->mx;
    a->oy = a->y - a->my;
    if (ctx->f0C->lo != 2)
        t = sSearchAreaOffsets[func_02005728(4) + 1];
    else
        t = sSearchAreaOffsets[0];
    x0 = a->mx + t[0];
    if (x0 < 0)
        x0 = 0;
    x1 = a->mx + t[1];
    if (x1 >= 32)
        x1 = 31;
    y0 = a->my + t[2];
    if (y0 < 0)
        y0 = 0;
    y1 = a->my + t[3];
    if (y1 >= 32)
        y1 = 31;
    a->x0 = x0 + a->ox;
    a->x1 = x1 + a->ox;
    a->y0 = y0 + a->oy;
    a->y1 = y1 + a->oy;
}
