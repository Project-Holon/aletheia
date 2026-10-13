/*
 * function: FLDMMDL_ACMD_DeleteDrawSys
 * address:  0x02197C4C
 * packet:   pkt_02197C4C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   FLDMMDL_SysGetBlActCont  0x0216D520  thumb  ov010
 *   FLDMMDL_BLACT_Exit  0x0219C5D0  thumb  ov021
 *   FLDMMDL_SysGetG3dObjCont  0x0216D528  thumb
 *   FLDMMDL_G3DOBJ_Delete  0x0219D488  thumb  ov021
 *   FLDMMDL_SysSetDrawInit  0x0216D95C  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 FLDMMDL_SysGetBlActCont(void *p);
extern u32 FLDMMDL_SysGetG3dObjCont(u32);
extern u32 FLDMMDL_SysSetDrawInit(u32, u32);
extern void FLDMMDL_BLACT_Exit(u32 a);
extern void FLDMMDL_G3DOBJ_Delete(u32 a);

int FLDMMDL_ACMD_DeleteDrawSys(u32 a, u32 b, u32 c, u32 d)
{
if (FLDMMDL_SysGetBlActCont((void *)a) != 0) {
    FLDMMDL_BLACT_Exit(a);
}
if (FLDMMDL_SysGetG3dObjCont(a) != 0) {
    FLDMMDL_G3DOBJ_Delete(a);
}
return FLDMMDL_SysSetDrawInit(a, 0);
}

