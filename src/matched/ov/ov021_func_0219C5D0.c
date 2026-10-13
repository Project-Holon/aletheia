/*
 * function: FLDMMDL_BLACT_Exit
 * address:  0x0219C5D0
 * packet:   pkt_ov021_0219C5D0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FLDMMDL_SysGetBlActCont  0x0216D520  thumb  ov010
 *   FLDMMDL_BLACT_DeleteCodeChange  0x0219D2F4  thumb  ov021
 *   FLDMMDL_BLACT_DeleteReserve  0x0219CC80  thumb  ov021
 *   FLDMMDL_BLACT_DeleteAllRes  0x0219CAF4  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 *   FLDMMDL_SysSetBlActCont  0x0216D51C  thumb  ov010
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 FLDMMDL_SysGetBlActCont(void *p);
extern void FLDMMDL_BLACT_DeleteCodeChange(u8 *s);
extern void FLDMMDL_BLACT_DeleteReserve(u8 *o);
extern void FLDMMDL_BLACT_DeleteAllRes(u8 *s);
extern u32 func_020307B0(void *p);
extern void FLDMMDL_SysSetBlActCont(u8 *p, u32 v);

void FLDMMDL_BLACT_Exit(u32 a)
{
    u32 s = FLDMMDL_SysGetBlActCont((void *)a);
    FLDMMDL_BLACT_DeleteCodeChange((u8 *)s);
    FLDMMDL_BLACT_DeleteReserve((u8 *)s);
    FLDMMDL_BLACT_DeleteAllRes((u8 *)s);
    func_020307B0((void *)s);
    FLDMMDL_SysSetBlActCont((u8 *)a, 0);
}
