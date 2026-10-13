/*
 * function: FLDEFF_KEMURI_Update
 * address:  0x021AC66C
 * packet:   pkt_ov021_021AC66C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_EFFECT_DeleteObject  0x021AC154  thumb  ov021
 *   FIELD_G3DOBJ_IncAnimeFrame  0x021C6694  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

typedef struct X { u32 f0; u32 f4; u16 f8; } X;

extern int FIELD_G3DOBJ_IncAnimeFrame(u32 *a, int idx, int v);
extern void FIELD_EFFECT_DeleteObject(u32 a);

void FLDEFF_KEMURI_Update(u32 a, X *x)
{
    if (FIELD_G3DOBJ_IncAnimeFrame((u32 *)x->f4, x->f8, 0x1000) == 0)
        FIELD_EFFECT_DeleteObject(a);
}
