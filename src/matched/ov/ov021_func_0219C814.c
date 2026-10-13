/*
 * function: FLDMMDL_BLACT_AddActorMmdlOrReserve
 * address:  0x0219C814
 * packet:   pkt_ov021_0219C814
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   FLDMMDL_GetMmdlSys  0x0216D67C  thumb  ov010
 *   FLDMMDL_SysGetBlActCont  0x0216D520  thumb  ov010
 *   FLDMMDL_GetObjCodeParam  0x0216E3C4  thumb  ov010
 *   FLDMMDL_BLACT_FindRes  0x0219CBD4  thumb  ov021
 *   FLDMMDL_BLACT_AddActorMmdlByCode  0x0219C7EC  thumb  ov021
 *   FLDMMDL_BLACT_ReserveActor  0x0219CFB0  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;

extern void *FLDMMDL_GetMmdlSys(void *a0);
extern u32 FLDMMDL_SysGetBlActCont(void *p);
extern void *FLDMMDL_GetObjCodeParam(void *p);
extern int FLDMMDL_BLACT_FindRes(u32 a, u32 b, u32 c, u32 d);
extern u16 FLDMMDL_BLACT_AddActorMmdlByCode(u32, u32);
extern void FLDMMDL_BLACT_ReserveActor(u32, u32, u16 *, u16 *, u32, u32, u32);

int FLDMMDL_BLACT_AddActorMmdlOrReserve(u32 a, u16 *b)
{
    u32 m = FLDMMDL_SysGetBlActCont(FLDMMDL_GetMmdlSys((void *)a));
    u16 *p = FLDMMDL_GetObjCodeParam((void *)a);
    u16 loc[2];
    FLDMMDL_BLACT_FindRes(m, *p, (u32)(&loc[1]), (u32)(&loc[0]));
    if (loc[1] != 0xFFFF && (2 & loc[0]) == 0) {
        *b = FLDMMDL_BLACT_AddActorMmdlByCode(a, *p);
        return 1;
    }
    *b = 0xFFFF;
    FLDMMDL_BLACT_ReserveActor(m, a, p, b, 0, 0, 0);
    return 0;
}
