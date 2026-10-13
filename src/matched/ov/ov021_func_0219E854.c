/*
 * unit:     yes
 * function: FLDMMDL_RAIL_StayReturn, FLDMMDL_RAIL_LookAroundInitAll, FLDMMDL_RAIL_LookAroundInitUL, FLDMMDL_RAIL_LookAroundInitUR, FLDMMDL_RAIL_LookAroundInitDL, FLDMMDL_RAIL_LookAroundInitDR, FLDMMDL_RAIL_LookAroundInitUDL, FLDMMDL_RAIL_LookAroundInitUDR, FLDMMDL_RAIL_LookAroundInitULR, FLDMMDL_RAIL_LookAroundInitDLR, FLDMMDL_RAIL_LookAroundInitUD, FLDMMDL_RAIL_LookAroundInitLR, FLDMMDL_RAIL_LookAroundMove, FLDMMDL_RAIL_LookAroundDelete, FLDMMDL_RAIL_WanderInitAll, FLDMMDL_RAIL_WanderInitUD, FLDMMDL_RAIL_WanderMove, FLDMMDL_RAIL_WanderDelete, FLDMMDL_RAIL_ShuttleInit, FLDMMDL_RAIL_ShuttleMove, FLDMMDL_RAIL_ShuttleDelete
 * address:  0x0219E854
 * packet:   pkt_ov021_0219E854
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_GetMoveProcWork  0x0216D69C  thumb  ov010
 *   FLDMMDL_RAIL_AcquireRailWork  0x0219EAB8  thumb  ov021
 *   FLDMMDL_RAIL_LookAroundInit  0x0219EB18  thumb  ov021
 *   FLDMMDL_RAIL_LookAroundMoveBody  0x0219EB4C  thumb  ov021
 *   FLDMMDL_RAIL_LookAroundDeleteBody  0x0219EB90  thumb  ov021
 *   FLDMMDL_RAIL_WanderInit  0x0219EBA0  thumb  ov021
 *   FLDMMDL_RAIL_WanderMoveBody  0x0219EBF4  thumb  ov021
 *   FLDMMDL_RAIL_WanderDeleteBody  0x0219ED7C  thumb  ov021
 *   FLDMMDL_RAIL_ShuttleInitBody  0x0219ED8C  thumb  ov021
 *   FLDMMDL_RAIL_ShuttleMoveBody  0x0219EDC4  thumb  ov021
 *   FLDMMDL_RAIL_ShuttleDeleteBody  0x0219EF04  thumb  ov021
 * Addresses are Black-image addresses.
 * FLDMMDL_RAIL_StayReturn is followed by twenty unlabelled tail-call thunks (pool
 * word plus `bx r3`), eleven of them passing a state index 0..10 to
 * FLDMMDL_RAIL_LookAroundInit; the unit covers the whole 228-byte run.
 */

typedef unsigned int u32;

extern void *FLDMMDL_GetMoveProcWork(void *p);
extern int FLDMMDL_RAIL_AcquireRailWork(u32 a, u32 b);
extern int FLDMMDL_RAIL_LookAroundInit();
extern int FLDMMDL_RAIL_LookAroundMoveBody(u32 o);
extern int FLDMMDL_RAIL_LookAroundDeleteBody(u32 *a);
extern void FLDMMDL_RAIL_WanderInit(u32 o, u32 k);
extern int FLDMMDL_RAIL_WanderMoveBody(u32 o);
extern int FLDMMDL_RAIL_WanderDeleteBody(u32 *a);
extern int FLDMMDL_RAIL_ShuttleInitBody();
extern int FLDMMDL_RAIL_ShuttleMoveBody(u32 o);
extern int FLDMMDL_RAIL_ShuttleDeleteBody(u32 *a);

int FLDMMDL_RAIL_StayReturn(u32 o)
{
    return FLDMMDL_RAIL_AcquireRailWork((u32)FLDMMDL_GetMoveProcWork((void *)o), o);
}

int FLDMMDL_RAIL_LookAroundInitAll(u32 o) { return FLDMMDL_RAIL_LookAroundInit(o, 0); }
int FLDMMDL_RAIL_LookAroundInitUL(u32 o) { return FLDMMDL_RAIL_LookAroundInit(o, 1); }
int FLDMMDL_RAIL_LookAroundInitUR(u32 o) { return FLDMMDL_RAIL_LookAroundInit(o, 2); }
int FLDMMDL_RAIL_LookAroundInitDL(u32 o) { return FLDMMDL_RAIL_LookAroundInit(o, 3); }
int FLDMMDL_RAIL_LookAroundInitDR(u32 o) { return FLDMMDL_RAIL_LookAroundInit(o, 4); }
int FLDMMDL_RAIL_LookAroundInitUDL(u32 o) { return FLDMMDL_RAIL_LookAroundInit(o, 5); }
int FLDMMDL_RAIL_LookAroundInitUDR(u32 o) { return FLDMMDL_RAIL_LookAroundInit(o, 6); }
int FLDMMDL_RAIL_LookAroundInitULR(u32 o) { return FLDMMDL_RAIL_LookAroundInit(o, 7); }
int FLDMMDL_RAIL_LookAroundInitDLR(u32 o) { return FLDMMDL_RAIL_LookAroundInit(o, 8); }
int FLDMMDL_RAIL_LookAroundInitUD(u32 o) { return FLDMMDL_RAIL_LookAroundInit(o, 9); }
int FLDMMDL_RAIL_LookAroundInitLR(u32 o) { return FLDMMDL_RAIL_LookAroundInit(o, 10); }
int FLDMMDL_RAIL_LookAroundMove(u32 o) { return FLDMMDL_RAIL_LookAroundMoveBody(o); }
int FLDMMDL_RAIL_LookAroundDelete(u32 *o) { return FLDMMDL_RAIL_LookAroundDeleteBody(o); }
void FLDMMDL_RAIL_WanderInitAll(u32 o) { FLDMMDL_RAIL_WanderInit(o, 0); }
void FLDMMDL_RAIL_WanderInitUD(u32 o) { FLDMMDL_RAIL_WanderInit(o, 9); }
int FLDMMDL_RAIL_WanderMove(u32 o) { return FLDMMDL_RAIL_WanderMoveBody(o); }
int FLDMMDL_RAIL_WanderDelete(u32 *o) { return FLDMMDL_RAIL_WanderDeleteBody(o); }
int FLDMMDL_RAIL_ShuttleInit(u32 o) { return FLDMMDL_RAIL_ShuttleInitBody(o); }
int FLDMMDL_RAIL_ShuttleMove(u32 o) { return FLDMMDL_RAIL_ShuttleMoveBody(o); }
int FLDMMDL_RAIL_ShuttleDelete(u32 *o) { return FLDMMDL_RAIL_ShuttleDeleteBody(o); }
