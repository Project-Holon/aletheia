/*
 * function: FLDMMDL_BLACT_AddActorMmdlByCode
 * address:  0x0219C7EC
 * packet:   pkt_ov021_0219C7EC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FLDMMDL_GetMmdlSys  0x0216D67C  thumb  ov010
 *   FLDMMDL_SysGetBlActCont  0x0216D520  thumb  ov010
 *   FLDMMDL_BLACT_FindRes  0x0219CBD4  thumb  ov021
 *   FLDMMDL_BLACT_AddActorMmdl  0x0219C74C  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void *FLDMMDL_GetMmdlSys(void *a0);
extern u32 FLDMMDL_SysGetBlActCont(void *p);
extern int FLDMMDL_BLACT_FindRes(u32 a, u32 b, u32 c, u32 d);
extern void FLDMMDL_BLACT_AddActorMmdl(u32 a, u16 e);

void FLDMMDL_BLACT_AddActorMmdlByCode(u32 a, u32 b)
{
    u16 t[2];
    FLDMMDL_BLACT_FindRes(FLDMMDL_SysGetBlActCont(FLDMMDL_GetMmdlSys((void *)a)), b, (u32)(&t[1]), (u32)(&t[0]));
    FLDMMDL_BLACT_AddActorMmdl(a, t[1]);
}
