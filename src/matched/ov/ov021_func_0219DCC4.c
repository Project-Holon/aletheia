/*
 * function: FLDMMDL_RAIL_MOVE_AcWalk1
 * address:  0x0219DCC4
 * packet:   pkt_ov021_0219DCC4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FLDMMDL_RAIL_GetRailWork  0x0219E348  thumb  ov021
 *   FLDMMDL_RAIL_UpdateRailWork  0x0219E354  thumb  ov021
 *   FIELD_RAIL_WORK_GetPos  0x021B8028  thumb  ov021
 *   FIELD_RAIL_WORK_IsMoving  0x021B8040  thumb  ov021
 *   FLDMMDL_SetPos  0x0216D89C  thumb  ov010
 *   FLDMMDL_SetMoveBit  0x0216D568  thumb  ov010
 *   FLDMMDL_SetDrawStatus  0x0216D674  thumb  ov010
 *   FLDMMDL_IncAcmdSeq  0x0216D7CC  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *FLDMMDL_RAIL_GetRailWork(void *a);
extern void FLDMMDL_RAIL_UpdateRailWork(u32 a);
extern void FIELD_RAIL_WORK_GetPos();
extern u8 FIELD_RAIL_WORK_IsMoving(u8 *p);
extern void FLDMMDL_SetPos();
extern void *FLDMMDL_SetMoveBit(void *p, u32 v);
extern void FLDMMDL_SetDrawStatus(void *p, u16 v);
extern void FLDMMDL_IncAcmdSeq(u8 *p);

int FLDMMDL_RAIL_MOVE_AcWalk1(u32 o)
{
    u32 a;
    u8 buf[12];

    a = (u32)FLDMMDL_RAIL_GetRailWork((void *)o);
    FLDMMDL_RAIL_UpdateRailWork(o);
    FIELD_RAIL_WORK_GetPos(a, buf);
    FLDMMDL_SetPos(o, buf);
    if (FIELD_RAIL_WORK_IsMoving((u8 *)a)) {
        return 0;
    }
    FLDMMDL_SetMoveBit((void *)o, 0x440);
    FLDMMDL_SetDrawStatus((void *)o, 0);
    FLDMMDL_IncAcmdSeq((u8 *)o);
    return 0;
}
