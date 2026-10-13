/*
 * function: STARTMENU_UpdateMessage
 * address:  0x021BBFA8
 * packet:   pkt_ov088_021BBFA8
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   APP_KEYCURSOR_Update  0x020286C4  thumb
 *   PRINTSYS_PrintStreamGetState  0x0201CE30  thumb
 *   KEY_GetCont  0x0203630C  arm
 *   PRINTSYS_PrintStreamShortWait  0x0201CE5C  thumb
 *   KEY_GetTrg  0x020362DC  arm
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   PRINTSYS_PrintStreamReleasePause  0x0201CE38  thumb
 *   PRINTSYS_PrintStreamDelete  0x0201CE48  thumb
 */
#include "../include/Obj01887.h"

typedef unsigned int u32;

typedef signed int     s32;
struct Ctx;
struct Rec;
struct Rec3;
extern void APP_KEYCURSOR_Update(struct Ctx *ctx, void *p, void *cell);
extern u32 PRINTSYS_PrintStreamGetState(void *p);
extern unsigned int KEY_GetCont(void);
extern void PRINTSYS_PrintStreamShortWait(struct Rec *p, s32 v);
extern u32 KEY_GetTrg(void);
extern void GFL_USE_PlaySeDefaultVolume(u32);
extern void PRINTSYS_PrintStreamReleasePause(void *);
extern void PRINTSYS_PrintStreamDelete(struct Rec3 *p);

int STARTMENU_UpdateMessage(char *p)
{
    if (((struct Obj01887 *)p)->f6C == 0)
        return 0;
    APP_KEYCURSOR_Update(((struct Obj01887 *)p)->f74, ((struct Obj01887 *)p)->f6C, ((struct Obj01887 *)p)->fE8);
    switch (PRINTSYS_PrintStreamGetState(((struct Obj01887 *)p)->f6C)) {
    case 0:
        if (KEY_GetCont() & 3)
            PRINTSYS_PrintStreamShortWait(((struct Obj01887 *)p)->f6C, 0);
        ((struct Obj01887 *)p)->f78 = 0;
        break;
    case 1:
        if (((struct Obj01887 *)p)->f78 == 0) {
            if (KEY_GetTrg() & 3) {
                GFL_USE_PlaySeDefaultVolume(0x547);
                PRINTSYS_PrintStreamReleasePause(((struct Obj01887 *)p)->f6C);
                ((struct Obj01887 *)p)->f78 = 1;
            }
        }
        break;
    case 2:
        PRINTSYS_PrintStreamDelete(((struct Obj01887 *)p)->f6C);
        *(int *)&((struct Obj01887 *)p)->f6C = 0;
        ((struct Obj01887 *)p)->f78 = 0;
        return 0;
    }
    return 1;
}
