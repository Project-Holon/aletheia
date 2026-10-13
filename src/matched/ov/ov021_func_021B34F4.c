/*
 * function: SCRCMD_PROC_FLD_PollMessageEnd
 * address:  0x021B34F4
 * packet:   pkt_ov021_021B34F4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_PROC_FLD_PollMessageEnd 0x021B34F4 thumb
 *   PRINTSYS_PrintStreamGetState 0x0201CE30 thumb
 *   PRINTSYS_PrintStreamDelete 0x0201CE48 thumb
 *   PRINTSYS_PrintStreamShortWait 0x0201CE5C thumb
 *   KEY_GetCont 0x0203630C arm
 *   KEY_GetTrg 0x020362DC arm
 *   PRINTSYS_PrintStreamReleasePause 0x0201CE38 thumb
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 */
#include "../include/Obj05048.h"

typedef unsigned char u8;
typedef unsigned int u32;

typedef signed int     s32;
struct Rec;
struct Rec3;
extern u32 PRINTSYS_PrintStreamGetState(void *p);
extern void PRINTSYS_PrintStreamDelete(struct Rec3 *p);
extern void PRINTSYS_PrintStreamShortWait(struct Rec *p, s32 v);
extern unsigned int KEY_GetCont(void);
extern u32 KEY_GetTrg(void);
extern void PRINTSYS_PrintStreamReleasePause(void *);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);

u8 SCRCMD_PROC_FLD_PollMessageEnd(u8 *p)
{
    int r = PRINTSYS_PrintStreamGetState(((struct Obj05048 *)p)->f1B8);

    if (r == 2) {
        PRINTSYS_PrintStreamDelete(((struct Obj05048 *)p)->f1B8);
        return p[1];
    }
    if (r == 0) {
        if ((KEY_GetCont() & 1) || (KEY_GetCont() & 2)) {
            PRINTSYS_PrintStreamShortWait(((struct Obj05048 *)p)->f1B8, 0);
        }
    } else if (r == 1) {
        if ((KEY_GetTrg() & 1) || (KEY_GetTrg() & 2)) {
            PRINTSYS_PrintStreamReleasePause(((struct Obj05048 *)p)->f1B8);
            GFL_USE_PlaySeDefaultVolume(1351);
        }
    }
    return p[0];
}
