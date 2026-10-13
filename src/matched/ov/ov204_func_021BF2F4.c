/*
 * function: func_021BF2F4
 * address:  0x021BF2F4
 * packet:   pkt_021BF2F4
 * region:   ov204
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   KEY_GetCont  0x0203630C  arm
 *   TOUCHPANEL_GetCont  0x02035C38  arm
 *   KEY_GetTrg  0x020362DC  arm
 *   TOUCHPANEL_GetTrg  0x02035C60  arm
 *   APP_KEYCURSOR_Update  0x020286C4  thumb  arm9
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb  arm9
 *   PRINTSYS_PrintStreamGetState  0x0201CE30  thumb  arm9
 *   PRINTSYS_PrintStreamReleasePause  0x0201CE38  thumb  arm9
 *   PRINTSYS_PrintStreamDelete  0x0201CE48  thumb  arm9
 *   PRINTSYS_PrintStreamShortWait  0x0201CE5C  thumb  arm9
 */
#include "../include/Obj03358.h"

typedef unsigned int u32;

typedef signed int     s32;
struct Ctx;
struct Rec;
struct Rec3;
extern u32 PRINTSYS_PrintStreamGetState(void *p);
extern void PRINTSYS_PrintStreamDelete(struct Rec3 *p);
extern void PRINTSYS_PrintStreamShortWait(struct Rec *p, s32 v);
extern void PRINTSYS_PrintStreamReleasePause(void *p);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern void APP_KEYCURSOR_Update(struct Ctx *ctx, void *p, void *cell);
extern unsigned int KEY_GetCont(void);
extern int TOUCHPANEL_GetCont(void);
extern u32 KEY_GetTrg(void);
extern int TOUCHPANEL_GetTrg(void);

int func_021BF2F4(char *a)
{
    if (((struct Obj03358 *)a)->f14 != 0) {
        APP_KEYCURSOR_Update((struct Ctx *)(((struct Obj03358 *)a)->f20), (void *)(((struct Obj03358 *)a)->f14),
                      (void *)(((struct Obj03358 *)a)->f1C));

        switch (PRINTSYS_PrintStreamGetState((void *)(((struct Obj03358 *)a)->f14))) {
        case 2:
            PRINTSYS_PrintStreamDelete((struct Rec3 *)(((struct Obj03358 *)a)->f14));
            ((struct Obj03358 *)a)->f14 = 0;
            return 1;
        case 1:
            if (KEY_GetTrg() == 1 || KEY_GetTrg() == 2
                || TOUCHPANEL_GetTrg() != 0) {
                PRINTSYS_PrintStreamReleasePause((void *)(((struct Obj03358 *)a)->f14));
                GFL_USE_PlaySeDefaultVolume(0x547);
            }
            break;
        case 0:
            if ((KEY_GetCont() & 3) != 0 || TOUCHPANEL_GetCont() != 0)
                PRINTSYS_PrintStreamShortWait((struct Rec *)(((struct Obj03358 *)a)->f14), 0);
            break;
        }
        return 0;
    }
    return 0;
}
