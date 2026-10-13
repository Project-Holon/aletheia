/*
 * function: FLDEFF_NAMIPOKE_SPLASH_Draw
 * address:  0x021AD738
 * packet:   pkt_ov021_021AD738
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_EFFECT_GetFieldMapData  0x021ABE18  thumb  ov021
 *   FIELD_G3DOBJ_GetObjectTrans  0x021C6658  thumb  ov021
 *   FIELD_EFFECT_GetObjectPos  0x021AC1B8  thumb  ov021
 */
typedef unsigned short u16;

typedef unsigned char  u8;
extern unsigned int FIELD_EFFECT_GetFieldMapData(u8 *p);
typedef unsigned int   u32;
extern int FIELD_G3DOBJ_GetObjectTrans(u32 a, u32 b);
extern void FIELD_EFFECT_GetObjectPos(int a, int b);

typedef struct S {
    int pad0[4];
    u16 h10;
    u16 pad12;
    int pad14;
    int *p18;
} S;

void FLDEFF_NAMIPOKE_SPLASH_Draw(int a, S *s)
{
    FIELD_EFFECT_GetObjectPos(a, FIELD_G3DOBJ_GetObjectTrans(FIELD_EFFECT_GetFieldMapData((u8 *)(*s->p18)), s->h10));
}
