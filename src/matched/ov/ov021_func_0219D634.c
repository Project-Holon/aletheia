/*
 * function: FLDMMDL_G3DOBJ_AddObj
 * address:  0x0219D634
 * packet:   pkt_ov021_0219D634
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_GetObjCodeParam  0x0216E3C4  thumb  ov010
 *   FLDMMDL_GetMmdlSys  0x0216D67C  thumb  ov010
 *   FLDMMDL_SysGetG3dObjCont  0x0216D528  thumb  ov010
 *   FLDMMDL_G3DOBJ_FindResIdx  0x0219D558  thumb  ov021
 *   FLDMMDL_GetObjCodeParamMdlRes  0x0216E3CC  thumb  ov010
 *   FLDMMDL_G3DOBJ_LoadRes  0x0219D584  thumb  ov021
 *   FIELD_G3DOBJ_AddObject  0x021C6590  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned char  u8;
extern void *FLDMMDL_GetObjCodeParam(void *p);
extern void *FLDMMDL_GetMmdlSys(void *a0);
extern u32 FLDMMDL_SysGetG3dObjCont(u8 *p);
extern u16 FLDMMDL_G3DOBJ_FindResIdx(u8 *s, u16 k);
extern u8 *FLDMMDL_GetObjCodeParamMdlRes(u8 *p);
extern u32 FLDMMDL_G3DOBJ_LoadRes(u32, u32 *, u32, u16 *);
extern u32 FIELD_G3DOBJ_AddObject(u32, u32, u32, u32);

u32 FLDMMDL_G3DOBJ_AddObj(u32 a)
{
    u16 *p;
    u32 b;
    u32 *s;
    u32 r;
    p = FLDMMDL_GetObjCodeParam((void *)a);
    b = (u32)FLDMMDL_GetMmdlSys((void *)a);
    s = (u32 *)FLDMMDL_SysGetG3dObjCont((u8 *)b);
    r = FLDMMDL_G3DOBJ_FindResIdx((u8 *)s, *p);
    if (r == 0xFFFF) {
        r = FLDMMDL_G3DOBJ_LoadRes(b, s, *p, (u16 *)FLDMMDL_GetObjCodeParamMdlRes((u8 *)p));
    }
    return FIELD_G3DOBJ_AddObject(s[1], r, 0, 0);
}
