/*
 * function: FLDMMDL_G3DOBJ_LoadRes
 * address:  0x0219D584
 * packet:   pkt_ov021_0219D584
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_SysGetResArcHandle  0x0216D518  thumb  ov010
 *   FIELD_G3DOBJ_InitResDesc  0x021C6AE0  thumb  ov021
 *   FIELD_G3DOBJ_SetResDescModel  0x021C6AF0  thumb  ov021
 *   FIELD_G3DOBJ_SetResDescAnimeArc  0x021C6AF8  thumb  ov021
 *   FIELD_G3DOBJ_AddResDescAnimeFile  0x021C6AFC  thumb  ov021
 *   FIELD_G3DOBJ_AddResourceDefaultPal  0x021C6574  thumb  ov021
 *   FLDMMDL_G3DOBJ_AddResEntry  0x0219D524  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned char  u8;
extern u32 FLDMMDL_SysGetResArcHandle(u8 *p);
extern void FIELD_G3DOBJ_InitResDesc(u32 a);
extern void FIELD_G3DOBJ_SetResDescModel(u32 *, u32, u16);
extern void FIELD_G3DOBJ_SetResDescAnimeArc(u32 *p, u32 v);
extern void FIELD_G3DOBJ_AddResDescAnimeFile(u32 *, u16);
extern u32 FIELD_G3DOBJ_AddResourceDefaultPal(u32, u32 *, u32);
extern u16 FLDMMDL_G3DOBJ_AddResEntry(u32 *s, u32 b, u32 a);

u32 FLDMMDL_G3DOBJ_LoadRes(u32 a, u32 *b, u32 c, u16 *d)
{
    u32 buf[9];
    u32 t;
    u32 r;
    int i;
    t = FLDMMDL_SysGetResArcHandle((u8 *)a);
    FIELD_G3DOBJ_InitResDesc((u32)buf);
    if (d[0] != 0xFFFF) {
        FIELD_G3DOBJ_SetResDescModel(buf, t, d[0]);
    }
    if (d[1] != 0xFFFF) {
        FIELD_G3DOBJ_SetResDescModel(buf, t, d[1]);
    }
    FIELD_G3DOBJ_SetResDescAnimeArc((u32 *)buf, t);
    for (i = 0; i < 3; i++) {
        if (d[i + 2] != 0xFFFF) {
            FIELD_G3DOBJ_AddResDescAnimeFile(buf, d[i + 2]);
        }
    }
    r = FIELD_G3DOBJ_AddResourceDefaultPal(b[1], buf, 0);
    FLDMMDL_G3DOBJ_AddResEntry(b, c, r);
    return r;
}
