/*
 * function: FLDMMDL_BLACT_AddActorMmdlPalette
 * address:  0x0219C7B4
 * packet:   pkt_ov021_0219C7B4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FLDMMDL_GetMmdlSys  0x0216D67C  thumb  ov010
 *   FLDMMDL_GetObjCodeParam  0x0216E3C4  thumb  ov010
 *   FLDMMDL_ACMD_GetDrawPos  0x02197CCC  thumb  ov021
 *   FLDMMDL_BLACT_AddActorPosPalette  0x0219C780  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
typedef struct { int x, y, z; } V3;
extern void *FLDMMDL_GetMmdlSys(void *a0);
extern void *FLDMMDL_GetObjCodeParam(void *p);
typedef signed int     s32;
extern void FLDMMDL_ACMD_GetDrawPos(u8 *p, s32 *out);
extern u32 FLDMMDL_BLACT_AddActorPosPalette(u32 a, V3 *b, int c, u32 d, u16 e, u16 g);

void FLDMMDL_BLACT_AddActorMmdlPalette(u32 a, u16 e, u16 g)
{
    u32 o = (u32)FLDMMDL_GetMmdlSys((void *)a);
    u8 *d = FLDMMDL_GetObjCodeParam((void *)a);
    V3 v;
    FLDMMDL_ACMD_GetDrawPos((u8 *)a, (s32 *)(&v));
    FLDMMDL_BLACT_AddActorPosPalette(o, &v, d[7], d[9], e, g);
}
