/*
 * function: FLDMMDL_ACMD_JumpMove
 * address:  0x02198550
 * packet:   pkt_ov021_02198550
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_GetMoveCmdWork  0x0216D6D4  thumb  ov010
 *   FLDMMDL_MOVE_AddDirVectorPos  0x02163FC0  thumb  ov010
 *   FLDMMDL_MOVE_UpdateHeight  0x02164010  thumb  ov010
 *   FLDMMDL_MOVE_UpdateGridPosDir  0x02163E7C  thumb  ov010
 *   FLDMMDL_SetMoveBit  0x0216D568  thumb  ov010
 *   d_021DDBD4     0x021DDBD4  data   ov021  a4
 *   FLDMMDL_SetDrawOffset  0x0216D8C0  thumb  ov010
 *   FLDMMDL_MOVE_UpdateOldGridPos  0x02163F10  thumb  ov010
 *   FLDMMDL_SetDrawStatus  0x0216D674  thumb  ov010
 *   FLDMMDL_IncAcmdSeq  0x0216D7CC  thumb  ov010
 *   func_020061E4  0x020061E4  thumb
 * Addresses are Black-image addresses.
 */
#include "../include/Obj01032.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
typedef struct { int x, y, z; } Vec;

extern void *FLDMMDL_GetMoveCmdWork(void *p);
extern void FLDMMDL_MOVE_AddDirVectorPos(int a, int dir, int amt);
extern int FLDMMDL_MOVE_UpdateHeight(int a);
extern void FLDMMDL_MOVE_UpdateGridPosDir(int a, int b);
extern void *FLDMMDL_SetMoveBit(void *p, u32 v);
extern int *d_021DDBD4[];
extern void FLDMMDL_SetDrawOffset(u32, Vec *);
extern int FLDMMDL_MOVE_UpdateOldGridPos(int a0);
extern void FLDMMDL_SetDrawStatus(void *p, u16 v);
extern void FLDMMDL_IncAcmdSeq(u8 *p);
extern void func_020061E4(u32);

int FLDMMDL_ACMD_JumpMove(u32 a)
{
    u8 *h;

    h = FLDMMDL_GetMoveCmdWork((void *)a);
    if (((struct Obj01032 *)h)->f0 != 0) {
        FLDMMDL_MOVE_AddDirVectorPos(a, ((struct Obj01032 *)h)->fC, ((struct Obj01032 *)h)->f0);
        FLDMMDL_MOVE_UpdateHeight(a);
        if (((struct Obj01032 *)h)->f4 >= 0x10000) {
            ((struct Obj01032 *)h)->f4 = 0;
            FLDMMDL_MOVE_UpdateGridPosDir(a, ((struct Obj01032 *)h)->fC);
            FLDMMDL_SetMoveBit((void *)a, 0x20);
        }
        ((struct Obj01032 *)h)->f4 += (((struct Obj01032 *)h)->f0 < 0) ? -((struct Obj01032 *)h)->f0 : ((struct Obj01032 *)h)->f0;
    }
    ((struct Obj01032 *)h)->fA += ((struct Obj01032 *)h)->f8;
    if (((struct Obj01032 *)h)->fA > 0xF00) {
        ((struct Obj01032 *)h)->fA = 0xF00;
    }
    {
        Vec v;
        u16 k;
        int i;
        k = ((struct Obj01032 *)h)->fA / 256;
        i = ((struct Obj01032 *)h)->fF;
        v.x = 0;
        v.y = d_021DDBD4[i][k];
        v.z = 0;
        FLDMMDL_SetDrawOffset(a, &v);
    }
    ((struct Obj01032 *)h)->fD = ((struct Obj01032 *)h)->fD - 1;
    if (((struct Obj01032 *)h)->fD > 0) {
        return 0;
    }
    {
        Vec v = { 0, 0, 0 };
        FLDMMDL_SetDrawOffset(a, &v);
    }
    FLDMMDL_SetMoveBit((void *)a, 0x540);
    FLDMMDL_MOVE_UpdateOldGridPos(a);
    FLDMMDL_SetDrawStatus((void *)a, 0);
    FLDMMDL_IncAcmdSeq((u8 *)a);
    func_020061E4(0x67B);
    return 1;
}
