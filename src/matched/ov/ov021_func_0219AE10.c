/*
 * function: FLDMMDL_MOVECODE_RoutePatrolSwapStepLookForPlayer
 * address:  0x0219AE10
 * packet:   pkt_ov021_0219AE10
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FLDMMDL_GetEventType  0x0216D5A8  thumb  ov010
 *   FLDMMDL_GetDirDisp  0x0216D5F8  thumb  ov010
 *   FLDMMDL_GetParam  0x0216D63C  thumb  ov010
 *   EVENT_TRAINER_EYE_GetPlayerDistance  0x021AE198  thumb  ov021
 *   FLDMMDL_ACMD_ConvertCodeByDir  0x02197E7C  thumb  ov021
 *   FLDMMDL_SetLocalAcmd  0x0216D438  thumb  ov010
 *   FLDMMDL_OnMoveBitMove  0x0216DA44  thumb
 */

typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned short u16;
extern u16 FLDMMDL_GetEventType(u8 *p);
extern u16 FLDMMDL_GetDirDisp(void *p);
extern int FLDMMDL_GetParam(char *a0, int a1);
extern int EVENT_TRAINER_EYE_GetPlayerDistance(int a, int b, int c, int d);
extern int FLDMMDL_ACMD_ConvertCodeByDir(int a, int b);
extern void FLDMMDL_SetLocalAcmd(char *a0, int a1);
extern void FLDMMDL_OnMoveBitMove(u32);

int FLDMMDL_MOVECODE_RoutePatrolSwapStepLookForPlayer(char *a, u8 *b)
{
    u32 c;
    if (FLDMMDL_GetEventType((u8 *)a) == 10) {
        c = FLDMMDL_GetDirDisp((void *)a);
        if (EVENT_TRAINER_EYE_GetPlayerDistance((int)a, c, FLDMMDL_GetParam((char *)a, 0), 0) != -1) {
            FLDMMDL_SetLocalAcmd(a, FLDMMDL_ACMD_ConvertCodeByDir(c, 0x30));
            FLDMMDL_OnMoveBitMove((u32)a);
            b[0] = 1;
            return 1;
        }
    }
    b[0] = 2;
    return 1;
}
