/*
 * function: IRCBATTLEMENU_IsMessageEnd
 * address:  0x021975D0
 * packet:   pkt_ov021_021975D0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Per-frame poll of the object at +0x2B4; returns 1 when it is absent.
 *
 * symbols:
 *   APP_KEYCURSOR_Update  0x020286C4  thumb
 *   PRINTSYS_PrintStreamGetState  0x0201CE30  thumb
 *   PRINTSYS_PrintStreamDelete  0x0201CE48  thumb
 *   PRINTSYS_PrintStreamReleasePause  0x0201CE38  thumb
 *   PRINTSYS_PrintStreamShortWait  0x0201CE5C  thumb
 *   TOUCHPANEL_GetTrg  0x02035C60  arm
 *   TOUCHPANEL_GetCont  0x02035C38  arm
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00094.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct Ctx;
struct Rec;
struct Rec3;
extern void APP_KEYCURSOR_Update(struct Ctx *ctx, void *p, void *cell);
extern u32 PRINTSYS_PrintStreamGetState(void *p);
extern void PRINTSYS_PrintStreamDelete(struct Rec3 *p);
extern void PRINTSYS_PrintStreamReleasePause(void *h);
extern void PRINTSYS_PrintStreamShortWait(struct Rec *p, s32 v);
extern int TOUCHPANEL_GetTrg(void);
extern int TOUCHPANEL_GetCont(void);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);

int IRCBATTLEMENU_IsMessageEnd(u8 *p)
{
    if (((struct Obj00094 *)p)->f2B4 != 0) {
        if (((struct Obj00094 *)p)->f2B0 != 0)
            APP_KEYCURSOR_Update(((struct Obj00094 *)p)->f2A8, ((struct Obj00094 *)p)->f2B4, ((struct Obj00094 *)p)->f2B0);
        switch (PRINTSYS_PrintStreamGetState(((struct Obj00094 *)p)->f2B4)) {
        case 2:
            PRINTSYS_PrintStreamDelete(((struct Obj00094 *)p)->f2B4);
            ((struct Obj00094 *)p)->f2B4 = 0;
            break;
        case 1:
            if (TOUCHPANEL_GetTrg() != 0) {
                GFL_USE_PlaySeDefaultVolume(0x547);
                PRINTSYS_PrintStreamReleasePause(((struct Obj00094 *)p)->f2B4);
            }
            break;
        case 0:
            if (TOUCHPANEL_GetCont() != 0)
                PRINTSYS_PrintStreamShortWait(((struct Obj00094 *)p)->f2B4, 0);
            break;
        }
        return 0;
    }
    return 1;
}
