/*
 * function: GAME_DATA_PartSaveMain
 * address:  0x02012E7C
 * packet:   pkt_02012E7C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * blocker:  +0016 THM_CALL SAVE_CONTROL_StepExtraSaveWrite       : 020073B0 (thumb, from name) has no witness outside 02012E7C..02012EBC
 *
 * symbols:
 *   SAVE_CONTROL_StepExtraSaveWrite  0x020073B0  thumb
 *   WIH_DWC_ResumeTimers  0x02010444  thumb
 *   GFL_USE_IsLoaderBusy  0x02005C64  thumb
 */
#include "../include/Obj00054.h"

typedef unsigned char u8;
typedef unsigned int u32;

extern int GFL_USE_IsLoaderBusy(void);
extern int SAVE_CONTROL_StepExtraSaveWrite(char *a0, u32 a1);
extern int func_020351A0(u32 v);
extern void WIH_DWC_ResumeTimers(void);
extern void func_02034FB8(u32 a);

int GAME_DATA_PartSaveMain(char *p, int a1)
{
    int r;

    if (GFL_USE_IsLoaderBusy() == 1)
        return 0;
    r = SAVE_CONTROL_StepExtraSaveWrite((char *)(*(u32 *)&((struct Obj00054 *)p)->f0), a1);
    if (r == 2 || r == 3) {
        func_020351A0(2);
        WIH_DWC_ResumeTimers();
        ((struct Obj00054 *)p)->f1CE = 0;
        func_02034FB8(0x80);
    }
    return r;
}
