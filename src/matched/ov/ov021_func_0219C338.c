/*
 * function: FLDMMDL_MOVE_WallWalkStepOnce
 * address:  0x0219C338
 * packet:   pkt_ov021_0219C338
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   gWallWalkHandSwap     0x021D5384  data   a4
 *   gWallWalkBounceDir     0x021D5454  data   ov021  a4
 *   FLDMMDL_GetDirMove  0x0216D608  thumb  ov010
 *   FLDMMDL_MOVE_HitCheckWallWalkDir  0x0219C314  thumb  ov021
 *   FLDMMDL_ACMD_ConvertCodeByDir  0x02197E7C  thumb  ov021
 *   FLDMMDL_SetLocalAcmd  0x0216D438  thumb  ov010
 *   FLDMMDL_OnMoveBitMove  0x0216DA44  thumb
 *   FLDMMDL_MOVE_GetDirTableValue  0x021642A4  thumb  ov010
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 gWallWalkHandSwap[];
extern u32 gWallWalkBounceDir[][2];

extern u16 FLDMMDL_GetDirMove(void *p);
extern int FLDMMDL_MOVE_HitCheckWallWalkDir(int a, int *s, u32 c);
extern int FLDMMDL_ACMD_ConvertCodeByDir(int a, int b);
extern void FLDMMDL_SetLocalAcmd(char *a0, int a1);
extern void FLDMMDL_OnMoveBitMove(int a);
extern u16 FLDMMDL_MOVE_GetDirTableValue(int i);

int FLDMMDL_MOVE_WallWalkStepOnce(char *a, u32 *s, u32 c)
{
    u32 t;
    u32 k;
    u32 v;
    int r;

    k = s[2];
    t = FLDMMDL_GetDirMove((void *)a);
    r = FLDMMDL_MOVE_HitCheckWallWalkDir((int)a, (int *)(&t), k);
    if (t == 9) {
        t = FLDMMDL_GetDirMove((void *)a);
        FLDMMDL_SetLocalAcmd(a, (u16)((u32)FLDMMDL_ACMD_ConvertCodeByDir((u16)t, (u16)0x1c)));
        return 0;
    }
    if (r == 0) {
        v = (u32)FLDMMDL_ACMD_ConvertCodeByDir((u16)t, (u16)c);
        FLDMMDL_OnMoveBitMove((int)a);
        FLDMMDL_SetLocalAcmd(a, (u16)v);
        return 1;
    }
    if ((1 & r) && s[1] == 2) {
        t = FLDMMDL_MOVE_GetDirTableValue(FLDMMDL_GetDirMove((void *)a));
        k = gWallWalkHandSwap[k];
        s[2] = k;
        r = FLDMMDL_MOVE_HitCheckWallWalkDir((int)a, (int *)(&t), k);
        if (t == 9) {
            t = FLDMMDL_GetDirMove((void *)a);
            FLDMMDL_SetLocalAcmd(a, (u16)((u32)FLDMMDL_ACMD_ConvertCodeByDir((u16)t, (u16)0x1c)));
            return 0;
        }
        if (r == 0) {
            v = (u32)FLDMMDL_ACMD_ConvertCodeByDir((u16)t, (u16)c);
            FLDMMDL_OnMoveBitMove((int)a);
            FLDMMDL_SetLocalAcmd(a, (u16)v);
            return 1;
        }
    }
    if (r & 2) {
        t = gWallWalkBounceDir[t][k];
        r = FLDMMDL_MOVE_HitCheckWallWalkDir((int)a, (int *)(&t), k);
        if (t == 9) {
            t = FLDMMDL_GetDirMove((void *)a);
            FLDMMDL_SetLocalAcmd(a, (u16)((u32)FLDMMDL_ACMD_ConvertCodeByDir((u16)t, (u16)0x1c)));
            return 0;
        }
        if (r == 0) {
            v = (u32)FLDMMDL_ACMD_ConvertCodeByDir((u16)t, (u16)c);
            FLDMMDL_OnMoveBitMove((int)a);
            FLDMMDL_SetLocalAcmd(a, (u16)v);
            return 1;
        }
    }
    t = FLDMMDL_GetDirMove((void *)a);
    FLDMMDL_SetLocalAcmd(a, (u16)((u32)FLDMMDL_ACMD_ConvertCodeByDir((u16)t, (u16)0x1c)));
    return 0;
}
