/*
 * function: FLDEFF_NAMIPOKE_SPLASH_LoadResources
 * address:  0x021AD410
 * packet:   pkt_ov021_021AD410
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_EFFECT_GetFieldMapData  0x021ABE18  thumb  ov021
 *   FIELD_EFFECT_GetArcHandle  0x021ABE24  thumb  ov021
 *   FIELD_G3DOBJ_InitResDesc  0x021C6AE0  thumb  ov021
 *   FIELD_G3DOBJ_SetResDescModel  0x021C6AF0  thumb  ov021
 *   FIELD_G3DOBJ_SetResDescAnimeArc  0x021C6AF8  thumb  ov021
 *   FIELD_G3DOBJ_AddResDescAnimeFile  0x021C6AFC  thumb  ov021
 *   FIELD_G3DOBJ_AddResourceDefaultPal  0x021C6574  thumb  ov021
 * Addresses are Black-image addresses.
 *
 * The buffer handle p is assigned after the FIELD_EFFECT_GetArcHandle call, but the
 * first FIELD_G3DOBJ_InitResDesc call takes the buffer itself, so a call lies between
 * the assignment and the first read of p. That keeps p a register variable
 * (r7) instead of a rematerialised address, and the repeated 0 argument is
 * rebuilt per call. See docs/idioms/a-call-between-a-buffer-handle-and-its-first-read-keeps-it-in-a-register.md.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 FIELD_EFFECT_GetFieldMapData(u8 *p);
extern u32 FIELD_EFFECT_GetArcHandle(u8 *p);
extern void FIELD_G3DOBJ_InitResDesc(u32 *a);
extern int FIELD_G3DOBJ_SetResDescModel(u32 a, u32 b, u32 c);
extern void FIELD_G3DOBJ_SetResDescAnimeArc(u32 *p, u32 v);
extern void FIELD_G3DOBJ_AddResDescAnimeFile(u32 a, u32 b);
extern int FIELD_G3DOBJ_AddResourceDefaultPal(u32 a, u32 b, u32 c);

void FLDEFF_NAMIPOKE_SPLASH_LoadResources(u32 *a)
{
    u32 buf[9];
    u16 *h = (u16 *)a;
    u32 r6;
    u32 r4;
    u32 p;
    r6 = FIELD_EFFECT_GetFieldMapData((u8 *)a[0]);
    r4 = FIELD_EFFECT_GetArcHandle((u8 *)a[0]);
    p = (u32)buf;
    FIELD_G3DOBJ_InitResDesc(buf);
    FIELD_G3DOBJ_SetResDescModel(p, r4, 0x37);
    FIELD_G3DOBJ_SetResDescAnimeArc((u32 *)p, r4);
    FIELD_G3DOBJ_AddResDescAnimeFile(p, 0x80);
    FIELD_G3DOBJ_AddResDescAnimeFile(p, 0x6c);
    h[2] = FIELD_G3DOBJ_AddResourceDefaultPal(r6, p, 0);
    FIELD_G3DOBJ_InitResDesc(buf);
    FIELD_G3DOBJ_SetResDescModel(p, r4, 0x3a);
    FIELD_G3DOBJ_SetResDescAnimeArc((u32 *)p, r4);
    FIELD_G3DOBJ_AddResDescAnimeFile(p, 0x6f);
    FIELD_G3DOBJ_AddResDescAnimeFile(p, 0x63);
    h[3] = FIELD_G3DOBJ_AddResourceDefaultPal(r6, p, 0);
    FIELD_G3DOBJ_InitResDesc(buf);
    FIELD_G3DOBJ_SetResDescModel(p, r4, 0x39);
    FIELD_G3DOBJ_SetResDescAnimeArc((u32 *)p, r4);
    FIELD_G3DOBJ_AddResDescAnimeFile(p, 0x6e);
    FIELD_G3DOBJ_AddResDescAnimeFile(p, 0x62);
    h[5] = FIELD_G3DOBJ_AddResourceDefaultPal(r6, p, 0);
    FIELD_G3DOBJ_InitResDesc(buf);
    FIELD_G3DOBJ_SetResDescModel(p, r4, 0x3b);
    FIELD_G3DOBJ_SetResDescAnimeArc((u32 *)p, r4);
    FIELD_G3DOBJ_AddResDescAnimeFile(p, 0x70);
    FIELD_G3DOBJ_AddResDescAnimeFile(p, 0x64);
    h[4] = FIELD_G3DOBJ_AddResourceDefaultPal(r6, p, 0);
    FIELD_G3DOBJ_InitResDesc(buf);
    FIELD_G3DOBJ_SetResDescModel(p, r4, 0x38);
    FIELD_G3DOBJ_SetResDescAnimeArc((u32 *)p, r4);
    FIELD_G3DOBJ_AddResDescAnimeFile(p, 0x6d);
    FIELD_G3DOBJ_AddResDescAnimeFile(p, 0x61);
    h[6] = FIELD_G3DOBJ_AddResourceDefaultPal(r6, p, 0);
}
