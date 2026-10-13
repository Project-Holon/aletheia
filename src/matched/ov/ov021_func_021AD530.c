/*
 * function: FLDEFF_NAMIPOKE_SPLASH_FreeResources
 * address:  0x021AD530
 * packet:   pkt_ov021_021AD530
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_EFFECT_GetFieldMapData  0x021ABE18  thumb  ov021
 *   FIELD_G3DOBJ_DeleteResource  0x021C6580  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

typedef struct X { u32 f0; u16 h4; u16 h6; u16 h8; u16 ha; u16 hc; } X;

extern u32 FIELD_EFFECT_GetFieldMapData(u8 *p);
extern void FIELD_G3DOBJ_DeleteResource(u8 *p, int i);

void FLDEFF_NAMIPOKE_SPLASH_FreeResources(X *x)
{
    u32 h = FIELD_EFFECT_GetFieldMapData((u8 *)x->f0);

    FIELD_G3DOBJ_DeleteResource((u8 *)h, x->h4);
    FIELD_G3DOBJ_DeleteResource((u8 *)h, x->h6);
    FIELD_G3DOBJ_DeleteResource((u8 *)h, x->ha);
    FIELD_G3DOBJ_DeleteResource((u8 *)h, x->h8);
    FIELD_G3DOBJ_DeleteResource((u8 *)h, x->hc);
}
