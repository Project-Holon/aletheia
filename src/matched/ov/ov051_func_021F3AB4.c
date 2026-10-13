/*
 * function: FIELD_GIMMICK_D06_EventStoneBlocked
 * address:  0x021F3AB4
 * packet:   pkt_ov051_021F3AB4
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
 *   FLDEFF_D06DENKI_FollowStartEnding  0x021C90AC  thumb
 *   FLDEFF_D06DENKI_FollowIsEnded  0x021C90D0  thumb
 */
#include "../include/Obj07660.h"

extern void *FIELDMAP_GetFieldPlayer(unsigned char *p);
extern void *FIELD_PLAYER_GetMmdl(unsigned char *p);
extern int FLDMMDL_CheckPossibleAcmd(void *a);
extern int FLDMMDL_ACMD_ConvertCodeByDir(int a, int b);
extern void FLDMMDL_SetAcmd(void *a, int b);
typedef unsigned int   u32;
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern int FLDMMDL_CheckEndAcmd(void *a);
extern void FLDMMDL_EndAcmd(void *a);
extern void FLDEFF_D06DENKI_FollowStartEnding(int a);
extern int FLDEFF_D06DENKI_FollowIsEnded(int a);

int FIELD_GIMMICK_D06_EventStoneBlocked(int a, int *s, int *t)
{
    void *r6;

    r6 = FIELD_PLAYER_GetMmdl(FIELDMAP_GetFieldPlayer(*(void **)(t[3] + 8)));
    switch (*s) {
    case 0:
        if (FLDMMDL_CheckPossibleAcmd(r6) == 1) {
            FLDMMDL_SetAcmd(r6, FLDMMDL_ACMD_ConvertCodeByDir(((struct Obj07660 *)t)->f0, 0x1c));
            GFL_USE_PlaySeDefaultVolume(0x55a);
            *s = *s + 1;
        }
    case 1:
        FLDEFF_D06DENKI_FollowStartEnding(((int *)t[2])[1]);
        *s = *s + 1;
        break;
    case 2:
        if (FLDEFF_D06DENKI_FollowIsEnded(((int *)t[2])[1]) == 0)
            break;
        *s = *s + 1;
    case 3:
        if (FLDMMDL_CheckEndAcmd(r6) == 1) {
            FLDMMDL_EndAcmd(r6);
            return 1;
        }
        break;
    }
    return 0;
}
