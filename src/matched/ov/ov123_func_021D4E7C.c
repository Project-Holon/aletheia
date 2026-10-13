/*
 * function: func_021D4E7C
 * address: 0x021D4E7C
 * packet: pkt_ov123_021D4E7C
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   APP_KEYCURSOR_Update 0x020286C4 thumb
 *   PRINTSYS_PrintStreamGetState 0x0201CE30 thumb
 *   PRINTSYS_PrintStreamDelete 0x0201CE48 thumb
 *   PRINTSYS_PrintStreamReleasePause 0x0201CE38 thumb
 *   PRINTSYS_PrintStreamShortWait 0x0201CE5C thumb
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   TOUCHPANEL_GetCont 0x02035C38 arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 */
#include "../include/Obj00626.h"
typedef signed int     s32;
typedef unsigned int   u32;
struct Ctx;
struct Rec;
struct Rec3;
extern void APP_KEYCURSOR_Update(struct Ctx *ctx, void *p, void *cell);
extern u32 PRINTSYS_PrintStreamGetState(void *p);
extern void PRINTSYS_PrintStreamDelete(struct Rec3 *p);
extern void PRINTSYS_PrintStreamReleasePause(void *);
extern void PRINTSYS_PrintStreamShortWait(struct Rec *p, s32 v);
extern int TOUCHPANEL_GetTrg(void);
extern int TOUCHPANEL_GetCont(void);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
int func_021D4E7C(char *p)
{
    if (((struct Obj00626 *)p)->f228) {
        if (((struct Obj00626 *)p)->f224)
            APP_KEYCURSOR_Update(((struct Obj00626 *)p)->f22C, ((struct Obj00626 *)p)->f228, ((struct Obj00626 *)p)->f224);
        switch (PRINTSYS_PrintStreamGetState(((struct Obj00626 *)p)->f228)) {
        case 2:
            PRINTSYS_PrintStreamDelete(((struct Obj00626 *)p)->f228);
            ((struct Obj00626 *)p)->f228 = 0;
            break;
        case 1:
            if (TOUCHPANEL_GetTrg()) {
                GFL_USE_PlaySeDefaultVolume(0x547);
                PRINTSYS_PrintStreamReleasePause(((struct Obj00626 *)p)->f228);
            }
            break;
        case 0:
            if (TOUCHPANEL_GetCont()) PRINTSYS_PrintStreamShortWait(((struct Obj00626 *)p)->f228, 0);
            break;
        }
        return 0;
    }
    return 1;
}
