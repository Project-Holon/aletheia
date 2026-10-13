/*
 * function: FIELD_COMM_ACTOR_AddMmdl
 * address:  0x02194434
 * packet:   pkt_ov021_02194434
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   sCommActorMmdlHeader     0x021D3F68  data  ov021  a4
 *   FLDMMDL_AddMmdl  0x0216CE60  thumb  ov010
 *   FIELD_COMM_ACTOR_SetMoveWork  0x02194588  thumb  ov021
 *   FIELD_COMM_ACTOR_ConvertDir  0x021945A0  thumb  ov021
 *   FLDMMDL_InitPosition  0x0216E014  thumb  ov010
 *   FLDMMDL_SetStatusBitHeightGetOff  0x0216DB4C  thumb  ov010
 *   FLDMMDL_SetStatusBitAttrGetOff  0x0216DC98  thumb  ov010
 *   FLDMMDL_SetStatusBitZoneDeleteOff  0x0216DB80  thumb  ov010
 *   FLDMMDL_SetStatusBitFellowHit  0x0216DAE0  thumb  ov010
 *   FLDMMDL_SetMoveBitSysPauseOff  0x0216DC64  thumb  ov010
 *   FLDMMDL_SetMoveBitAttrEffectOff  0x0216DCCC  thumb  ov010
 */
#include "../include/Obj19625.h"

typedef unsigned short u16;
typedef struct { unsigned w[9]; } T;

extern T sCommActorMmdlHeader;

extern void *FLDMMDL_AddMmdl(void *a, void *b, int c);
typedef unsigned int   u32;
extern void FIELD_COMM_ACTOR_SetMoveWork(u32 a, u32 b, u32 c, u32 d, u32 e);
extern int FIELD_COMM_ACTOR_ConvertDir(int x);
extern void FLDMMDL_InitPosition(void *a, int *p, int b);
extern int FLDMMDL_SetStatusBitHeightGetOff(void *a0, int a1);
extern int FLDMMDL_SetStatusBitAttrGetOff(void *a0, int a1);
extern void FLDMMDL_SetStatusBitZoneDeleteOff(unsigned int *p, unsigned int v);
extern void FLDMMDL_SetStatusBitFellowHit(unsigned int *p, unsigned int v);
extern int FLDMMDL_SetMoveBitSysPauseOff(void *a0, int a1);
extern int FLDMMDL_SetMoveBitAttrEffectOff(void *a0, int a1);

void *FIELD_COMM_ACTOR_AddMmdl(unsigned char *a, int x, u16 *q, int d, int e, int f)
{
    void *m = ((struct Obj19625 *)a)->f4;
    T local = sCommActorMmdlHeader;
    void *o;

    *(u16 *)((unsigned char *)&local + 2) = x;
    o = FLDMMDL_AddMmdl(m, &local, 0);
    FIELD_COMM_ACTOR_SetMoveWork((u32)o, (u32)q, d, e, f);
    FLDMMDL_InitPosition(o, (int *)d, FIELD_COMM_ACTOR_ConvertDir(*q));
    FLDMMDL_SetStatusBitHeightGetOff(o, 1);
    FLDMMDL_SetStatusBitAttrGetOff(o, 1);
    FLDMMDL_SetStatusBitZoneDeleteOff(o, 1);
    FLDMMDL_SetStatusBitFellowHit(o, 0);
    FLDMMDL_SetMoveBitSysPauseOff(o, 1);
    FLDMMDL_SetMoveBitAttrEffectOff(o, 1);
    return o;
}
