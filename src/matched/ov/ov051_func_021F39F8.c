/*
 * function: FIELD_GIMMICK_D06_EventSlideStone
 * address:  0x021F39F8
 * packet:   pkt_ov051_021F39F8
 * region:   ov051
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb
 *   FLDMMDL_CheckPossibleAcmd  0x0216D3CC  thumb
 *   FLDMMDL_ACMD_ConvertCodeByDir  0x02197E7C  thumb
 *   FLDMMDL_SetAcmd  0x0216D410  thumb
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   FLDMMDL_CheckEndAcmd  0x0216D454  thumb
 *   FLDMMDL_EndAcmd  0x0216D480  thumb
 *   FLDEFF_D06DENKI_FollowFreezeLoop  0x021C909C  thumb
 */
#include "../include/Obj01876.h"

extern void *FIELDMAP_GetFieldPlayer(unsigned char *p);
extern void *FIELD_PLAYER_GetMmdl(unsigned char *p);
extern int FLDMMDL_CheckPossibleAcmd(void *a);
extern int FLDMMDL_ACMD_ConvertCodeByDir(int a, int b);
extern void FLDMMDL_SetAcmd(void *a, int b);
typedef unsigned int   u32;
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern int FLDMMDL_CheckEndAcmd(void *a);
extern void FLDMMDL_EndAcmd(void *a);
extern void FLDEFF_D06DENKI_FollowFreezeLoop(int a);

int FIELD_GIMMICK_D06_EventSlideStone(int a, int *s, int *t)
{
    void *r6;

    r6 = FIELD_PLAYER_GetMmdl(FIELDMAP_GetFieldPlayer(*(void **)(t[3] + 8)));
    switch (*s) {
    case 0:
        if (FLDMMDL_CheckPossibleAcmd(r6) == 1) {
            FLDMMDL_SetAcmd(r6, FLDMMDL_ACMD_ConvertCodeByDir(((struct Obj01876 *)t)->f0, 0x1c));
            GFL_USE_PlaySeDefaultVolume(0x6ce);
            *s = *s + 1;
        }
        break;
    case 1:
        if (FLDMMDL_CheckPossibleAcmd(*(void **)t[2]) == 1) {
            if (t[1] > 0) {
                int v = 8;
                if (t[1] <= 1)
                    v = 0x10;
                else if (t[1] <= 2)
                    v = 0x10;
                else if (t[1] <= 4)
                    v = 0xc;
                FLDMMDL_SetAcmd(*(void **)t[2], FLDMMDL_ACMD_ConvertCodeByDir(((struct Obj01876 *)t)->f0, v));
                t[1] = t[1] - 1;
            } else {
                GFL_USE_PlaySeDefaultVolume(0x6a3);
                *s = *s + 1;
            }
        }
        break;
    case 2:
        if (FLDMMDL_CheckEndAcmd(r6) == 1) {
            FLDMMDL_EndAcmd(*(void **)t[2]);
            FLDMMDL_EndAcmd(r6);
            FLDEFF_D06DENKI_FollowFreezeLoop(((int *)t[2])[1]);
            return 1;
        }
        break;
    }
    return 0;
}
