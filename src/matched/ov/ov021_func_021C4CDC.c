/*
 * function: FLDEFF_SPLASH_DrawModelObj
 * address:  0x021C4CDC
 * packet:   pkt_ov021_021C4CDC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Copies the owner's current position into map-object slot id.
 *
 * symbols:
 *   FIELD_EFFECT_GetFieldMapData  0x021ABE18  thumb  ov021
 *   FIELD_G3DOBJ_GetObjectTrans  0x021C6658  thumb  ov021
 *   FIELD_EFFECT_GetObjectPos  0x021AC1B8  thumb  ov021
 *   FIELD_G3DOBJ_DrawObject  0x021C67F4  thumb  ov021
 */

typedef unsigned short u16;
typedef unsigned int u32;

typedef struct { int x, y, z; } V3;

typedef struct {
    u32 *owner;
    u32 f4;
    u32 f8;
    u32 fC;
    u16 id;
} S;

typedef unsigned char  u8;
extern u32 FIELD_EFFECT_GetFieldMapData(u8 *p);
extern int FIELD_G3DOBJ_GetObjectTrans(u32 a, u32 b);
extern void FIELD_EFFECT_GetObjectPos(void *a, V3 *v);
extern void FIELD_G3DOBJ_DrawObject(u32 o, u16 id);

void FLDEFF_SPLASH_DrawModelObj(void *a, S *s)
{
    u16 id = s->id;
    u32 o = FIELD_EFFECT_GetFieldMapData((u8 *)(*s->owner));
    V3 *dst = (V3 *)FIELD_G3DOBJ_GetObjectTrans(o, id);
    V3 t;

    FIELD_EFFECT_GetObjectPos(a, &t);
    *dst = t;
    FIELD_G3DOBJ_DrawObject(o, id);
}
