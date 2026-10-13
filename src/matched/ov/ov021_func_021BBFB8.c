/*
 * function: FLDEFF_REFLECT_SetMMdl
 * address:  0x021BBFB8
 * packet:   pkt_ov021_021BBFB8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   gReflectTaskHeader  0x021D9B64  data
 *   FLDMMDL_SysGetBlActCont  0x0216D520  thumb  ov010
 *   FLDMMDL_BLACT_GetBbActSys  0x0219C9DC  thumb  ov021
 *   FIELD_EFFECT_GetResource  0x021ABEA0  thumb  ov021
 *   FIELD_EFFECT_AddObject  0x021ABFA8  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned int   u32;

typedef struct Arg { u32 a; u32 b; u32 c; u32 d; u32 e; } Arg;

extern u32 FLDMMDL_SysGetBlActCont(void *p);
extern u32 FLDMMDL_BLACT_GetBbActSys(u8 *p);
extern int FIELD_EFFECT_GetResource(u32 a, u32 b);
extern void FIELD_EFFECT_AddObject(u32 a, u8 *b, u32 c, u32 d, Arg *e, u32 f);
extern u8 gReflectTaskHeader[];

void FLDEFF_REFLECT_SetMMdl(u32 a, u32 b, u32 c, u32 d)
{
    Arg s;

    s.b = d;
    s.c = b;
    s.d = a;
    s.e = FLDMMDL_BLACT_GetBbActSys((u8 *)FLDMMDL_SysGetBlActCont((void *)a));
    s.a = FIELD_EFFECT_GetResource(c, 6);
    FIELD_EFFECT_AddObject(c, gReflectTaskHeader, 0, 0, &s, 0);
}
