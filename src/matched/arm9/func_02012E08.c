/*
 * function: GAME_DATA_SaveCancel
 * address:  0x02012E08
 * packet:   pkt_02012E08
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * blocker:  +0024 THM_CALL func_02034FE8       : 02034FE8 (arm, from name) has no witness outside 02012E08..02012E40
 *
 * symbols:
 *   SAVE_CONTROL_CancelSave  0x020071A8  thumb
 *   WIH_DWC_ResumeTimers  0x02010444  thumb
 */
#include "../include/Obj08745.h"

typedef unsigned char u8;
typedef unsigned int u32;

extern int func_020351A0(u32 v);
extern void WIH_DWC_ResumeTimers(void);
extern int SAVE_CONTROL_CancelSave(int a0);
extern int  func_02034FE8(u32 a);
extern void func_02034FB8(u32 a);

void GAME_DATA_SaveCancel(char *p)
{
    u32 x;

    if (((struct Obj08745 *)p)->f1CE != 1)
        return;
    func_020351A0(2);
    WIH_DWC_ResumeTimers();
    ((struct Obj08745 *)p)->f1CE = 0;
    SAVE_CONTROL_CancelSave(((struct Obj08745 *)p)->f0);
    x = 0x80;
    if (func_02034FE8(x) == 1)
        func_02034FB8(x);
}
