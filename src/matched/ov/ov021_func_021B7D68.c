/*
 * function: FIELD_RAIL_UpdateCameraAtLocation
 * address:  0x021B7D68
 * packet:   pkt_ov021_021B7D68
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_RAIL_WORK_SetLocation  0x021B7EE4  thumb
 *   FIELD_RAIL_SETTING_GetCamera  0x021B8820  thumb
 *   FIELD_RAIL_SETTING_GetCameraFunc  0x021B8870  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;
typedef unsigned int u32;

struct Info { char pad00[0x10]; u32 f10; char pad14[0x28]; u32 f3C; };
struct Sub { u16 f0; u16 pad2; struct Info *f4; char pad08[0x1C]; void *f24; };
typedef void (*Cb)(void *);
struct Obj { char pad00[0x14]; struct Sub *f14; char pad18[4]; struct Sub *f1C; };

extern void FIELD_RAIL_WORK_SetLocation(struct Sub *s, void *r);
extern u32 *FIELD_RAIL_SETTING_GetCamera(void *p);
extern Cb FIELD_RAIL_SETTING_GetCameraFunc(void *p, u32 v);

void FIELD_RAIL_UpdateCameraAtLocation(struct Obj *o, void *r)
{
    Cb cb;
    struct Sub *keep;
    struct Sub *t;

    cb = 0;
    FIELD_RAIL_WORK_SetLocation(o->f1C, r);
    keep = o->f14;
    t = o->f1C;
    o->f14 = t;
    switch (t->f0) {
    case 0:
        if (t->f4->f3C == 0xFFFF)
            break;
        goto lookup;
    case 1:
        if (t->f4->f10 == 0xFFFF)
            break;
lookup:
        cb = FIELD_RAIL_SETTING_GetCameraFunc(t->f24, *FIELD_RAIL_SETTING_GetCamera(t->f24));
        break;
    }
    if (cb)
        cb(o);
    o->f14 = keep;
}
