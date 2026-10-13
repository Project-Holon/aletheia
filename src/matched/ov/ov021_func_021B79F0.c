/*
 * function: FIELD_RAIL_UpdateCamera
 * address:  0x021B79F0
 * packet:   pkt_ov021_021B79F0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_RAIL_WORK_IsActive  0x021B91AC  thumb
 *   FIELD_RAIL_WORK_HasStepped  0x021B8048  thumb
 *   FIELD_RAIL_SETTING_GetCamera  0x021B8820  thumb
 *   FIELD_RAIL_SETTING_GetCameraFunc  0x021B8870  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;
typedef unsigned int u32;

struct Info { char pad00[0x10]; u32 f10; char pad14[0x28]; u32 f3C; };
struct Sub { u16 f0; u16 pad2; struct Info *f4; char pad08[0x1C]; void *f24; };
typedef void (*Cb)(void *);
struct Obj { char pad00[2]; u16 f2; u16 f4; char pad06[0xE]; struct Sub *f14; u32 f18; };

extern int FIELD_RAIL_WORK_IsActive(u32 a);
typedef unsigned char  u8;
extern u8 FIELD_RAIL_WORK_HasStepped(u8 *p);
extern u32 *FIELD_RAIL_SETTING_GetCamera(void *p);
extern Cb FIELD_RAIL_SETTING_GetCameraFunc(void *p, u32 v);

int FIELD_RAIL_UpdateCamera(struct Obj *o, int flag)
{
    struct Sub *t;
    Cb cb;

    cb = 0;
    t = o->f14;
    if (o->f2 == 0)
        return 0;
    if (o->f4 == 0)
        return 0;
    if (t == 0)
        return 0;
    if (FIELD_RAIL_WORK_IsActive((u32)t) == 0)
        return 0;
    if (FIELD_RAIL_WORK_HasStepped((u8 *)t) == 0 && o->f18 == 0 && flag == 0)
        return 0;
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
    o->f18 = 0;
    return 1;
}
