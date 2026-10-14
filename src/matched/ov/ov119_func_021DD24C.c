/*
 * function: POKETRADE_NEGO_CheckCancelTouch
 * address: 0x021DD24C
 * packet: pkt_ov119_021DD24C
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKETRADE_SAVE_OpenTaskMenuWindow 0x021E2984 thumb ov119
 *   POKETRADE_SAVE_IsTouchOutsideArea 0x021E2A80 thumb ov119
 *   POKETRADE_PROC_ClearNetAutoExit 0x021D89CC thumb ov119
 *   POKETRADE_PROC_SetStep 0x021D8E84 thumb ov119
 *   POKETRADE_PROC_StepBeginWipeOut 0x021D9434 thumb ov119
 */
#include "../include/Obj00001.h"
extern void *POKETRADE_SAVE_OpenTaskMenuWindow(char *p, int a);
extern int POKETRADE_SAVE_IsTouchOutsideArea(void *);
extern void POKETRADE_PROC_ClearNetAutoExit(char *p);
extern void POKETRADE_PROC_SetStep(void *, int);
extern void POKETRADE_PROC_StepBeginWipeOut(void *);
int POKETRADE_NEGO_CheckCancelTouch(char *p)
{
    if (((struct Obj00001 *)p)->f118C == 3) {
        if (*(int *)&((struct Obj00001 *)p)->f648 == 0) POKETRADE_SAVE_OpenTaskMenuWindow(p, 0x9a);
        if (POKETRADE_SAVE_IsTouchOutsideArea(p)) {
            POKETRADE_PROC_ClearNetAutoExit(p);
            POKETRADE_PROC_SetStep(p, (int)POKETRADE_PROC_StepBeginWipeOut);
            return 1;
        }
    }
    return 0;
}
