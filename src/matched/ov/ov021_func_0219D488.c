/*
 * function: FLDMMDL_G3DOBJ_Delete
 * address:  0x0219D488
 * packet:   pkt_ov021_0219D488
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_SysGetG3dObjCont  0x0216D528  thumb  ov010
 *   FLDMMDL_G3DOBJ_DeleteResTable  0x0219D4EC  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 FLDMMDL_SysGetG3dObjCont(u8 *p);
extern void FLDMMDL_G3DOBJ_DeleteResTable(u8 *s);
extern u32 func_020307B0(void *p);

void FLDMMDL_G3DOBJ_Delete(u32 a)
{
    void *s = (void *)FLDMMDL_SysGetG3dObjCont((u8 *)a);
    FLDMMDL_G3DOBJ_DeleteResTable(s);
    func_020307B0(s);
}
