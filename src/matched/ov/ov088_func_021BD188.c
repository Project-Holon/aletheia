/*
 * function: STARTMENU_SaveEraseUpdateMessage
 * address:  0x021BD188
 * packet:   pkt_ov088_021BD188
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   TCBL_Main  0x020310C4  arm
 *   APP_KEYCURSOR_Update  0x020286C4  thumb
 *   PRINTSYS_PrintStreamGetState  0x0201CE30  thumb
 *   KEY_GetTrg  0x020362DC  arm
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   PRINTSYS_PrintStreamReleasePause  0x0201CE38  thumb
 *   PRINTSYS_PrintStreamDelete  0x0201CE48  thumb
 */
#include "../include/Obj00578.h"

typedef unsigned int u32;

struct Ctx;
struct Rec3;
struct Tcbl;
extern void TCBL_Main(struct Tcbl *p);
extern void APP_KEYCURSOR_Update(struct Ctx *ctx, void *p, void *cell);
extern u32 PRINTSYS_PrintStreamGetState(void *p);
extern u32 KEY_GetTrg(void);
extern void GFL_USE_PlaySeDefaultVolume(u32);
extern void PRINTSYS_PrintStreamReleasePause(void *);
extern void PRINTSYS_PrintStreamDelete(struct Rec3 *p);

int STARTMENU_SaveEraseUpdateMessage(char *p)
{
    TCBL_Main(((struct Obj00578 *)p)->f18);
    APP_KEYCURSOR_Update(((struct Obj00578 *)p)->f24, ((struct Obj00578 *)p)->f14, ((struct Obj00578 *)p)->f1C);
    switch (PRINTSYS_PrintStreamGetState(((struct Obj00578 *)p)->f14)) {
    case 0:
        ((struct Obj00578 *)p)->f28 = 0;
        break;
    case 1:
        if (((struct Obj00578 *)p)->f28 == 0) {
            if (KEY_GetTrg() & 3) {
                GFL_USE_PlaySeDefaultVolume(0x547);
                PRINTSYS_PrintStreamReleasePause(((struct Obj00578 *)p)->f14);
                ((struct Obj00578 *)p)->f28 = 1;
            }
        }
        break;
    case 2:
        PRINTSYS_PrintStreamDelete(((struct Obj00578 *)p)->f14);
        ((struct Obj00578 *)p)->f28 = 0;
        return 0;
    }
    return 1;
}
