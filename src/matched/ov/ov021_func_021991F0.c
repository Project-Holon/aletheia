/*
 * function: FLDMMDL_ACMD_StepMove
 * address:  0x021991F0
 * packet:   pkt_ov021_021991F0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FLDMMDL_GetMoveCmdWork  0x0216D6D4  thumb  ov010
 *   FLDMMDL_MOVE_AddVectorPos  0x02163F8C  thumb  ov010
 *   FLDMMDL_SetMoveBit  0x0216D568  thumb  ov010
 *   FLDMMDL_MOVE_UpdateOldGridPos  0x02163F10  thumb  ov010
 *   FLDMMDL_SetDrawStatus  0x0216D674  thumb  ov010
 *   FLDMMDL_IncAcmdSeq  0x0216D7CC  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void *FLDMMDL_GetMoveCmdWork(void *p);
extern u32 FLDMMDL_MOVE_AddVectorPos(u32, int *);
extern void *FLDMMDL_SetMoveBit(void *p, u32 v);
extern int FLDMMDL_MOVE_UpdateOldGridPos(int a0);
extern void FLDMMDL_SetDrawStatus(void *p, u16 v);
extern u32 FLDMMDL_IncAcmdSeq(u32);

int FLDMMDL_ACMD_StepMove(u32 a)
{
    int *p;

    p = FLDMMDL_GetMoveCmdWork((void *)a);
    FLDMMDL_MOVE_AddVectorPos(a, p + 1);
    p[0] = p[0] - 1;
    if (p[0] > 0) {
        return 0;
    }
    FLDMMDL_SetMoveBit((void *)a, 1088);
    FLDMMDL_MOVE_UpdateOldGridPos(a);
    FLDMMDL_SetDrawStatus((void *)a, 0);
    FLDMMDL_IncAcmdSeq(a);
    return 1;
}
