/*
 * function: FLDEFF_SPLASH_UnloadModel
 * address:  0x021C4BC4
 * packet:   pkt_ov021_021C4BC4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Applies the record's two parameters to the owner's map object.
 *
 * symbols:
 *   FIELD_EFFECT_GetFieldMapData  0x021ABE18  thumb  ov021
 *   FIELD_G3DOBJ_DeleteObject  0x021C6628  thumb  ov021
 *   FIELD_G3DOBJ_DeleteResource  0x021C6580  thumb  ov021
 */

typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u32 owner;
    u16 h4;
    u16 h6;
} S;

extern u32 FIELD_EFFECT_GetFieldMapData(unsigned char *p);
extern void FIELD_G3DOBJ_DeleteObject(u32 o, u16 v);
typedef unsigned char  u8;
extern void FIELD_G3DOBJ_DeleteResource(u8 *p, int i);

void FLDEFF_SPLASH_UnloadModel(S *s)
{
    u32 o = FIELD_EFFECT_GetFieldMapData((unsigned char *)s->owner);

    FIELD_G3DOBJ_DeleteObject(o, s->h6);
    FIELD_G3DOBJ_DeleteResource((u8 *)o, s->h4);
}
