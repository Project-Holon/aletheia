/*
 * function: ITEMMENU_IsMessageFinished
 * address:  0x021BADF0
 * packet:   pkt_ov070_021BADF0
 * region:   ov070
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   PRINTSYS_PrintStreamGetState  0x0201CE30  thumb
 *   APP_KEYCURSOR_Update  0x020286C4  thumb
 *   PRINTSYS_PrintStreamDelete  0x0201CE48  thumb
 *   KEY_GetTrg  0x020362DC  arm
 *   TOUCHPANEL_GetTrg  0x02035C60  arm
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   PRINTSYS_PrintStreamReleasePause  0x0201CE38  thumb
 *   KEY_GetCont  0x0203630C  arm
 *   TOUCHPANEL_GetCont  0x02035C38  arm
 *   PRINTSYS_PrintStreamShortWait  0x0201CE5C  thumb
 */
#include "../include/Obj00002.h"

typedef unsigned int u32;

typedef signed int     s32;
struct Ctx;
struct Rec;
struct Rec3;
extern u32 PRINTSYS_PrintStreamGetState(void *p);
extern void APP_KEYCURSOR_Update(struct Ctx *ctx, void *p, void *cell);
extern void PRINTSYS_PrintStreamDelete(struct Rec3 *p);
extern u32 KEY_GetTrg(void);
extern int TOUCHPANEL_GetTrg(void);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern void PRINTSYS_PrintStreamReleasePause(void *p);
extern unsigned int KEY_GetCont(void);
extern int TOUCHPANEL_GetCont(void);
extern void PRINTSYS_PrintStreamShortWait(struct Rec *p, s32 v);

int ITEMMENU_IsMessageFinished(int p)
{
    int r;

    if (((struct Obj00002 *)p)->f510 != 0) {
        r = PRINTSYS_PrintStreamGetState((void *)(((struct Obj00002 *)p)->f510));
        APP_KEYCURSOR_Update((struct Ctx *)(((struct Obj00002 *)p)->f518), (void *)(((struct Obj00002 *)p)->f510), (void *)(((struct Obj00002 *)p)->f4FC));
        switch (r) {
        case 2:
            PRINTSYS_PrintStreamDelete((struct Rec3 *)(((struct Obj00002 *)p)->f510));
            ((struct Obj00002 *)p)->f510 = 0;
            ((struct Obj00002 *)p)->f514 = 0;
            break;
        case 1:
            if (((struct Obj00002 *)p)->f514 == 0) {
                if ((KEY_GetTrg() & 3) != 0 || TOUCHPANEL_GetTrg() != 0) {
                    GFL_USE_PlaySeDefaultVolume(0x547);
                    PRINTSYS_PrintStreamReleasePause((void *)(((struct Obj00002 *)p)->f510));
                    ((struct Obj00002 *)p)->f514 = 1;
                }
            }
            break;
        case 0:
            if ((KEY_GetCont() & 3) != 0 || TOUCHPANEL_GetCont() != 0) {
                PRINTSYS_PrintStreamShortWait((struct Rec *)(((struct Obj00002 *)p)->f510), 0);
            }
            ((struct Obj00002 *)p)->f514 = 0;
            break;
        }
        return 0;
    }
    return 1;
}
