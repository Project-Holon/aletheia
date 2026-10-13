/*
 * function: func_021B9C00
 * address: 0x021B9C00
 * packet: pkt_ov218_021B9C00
 * region: ov218
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PRINTSYS_PrintStreamGetState 0x0201CE30 thumb
 *   PRINTSYS_PrintStreamDelete 0x0201CE48 thumb
 *   PRINTSYS_PrintStreamReleasePause 0x0201CE38 thumb
 *   PRINTSYS_PrintStreamShortWait 0x0201CE5C thumb
 *   KEY_GetTrg 0x020362DC arm
 *   KEY_GetCont 0x0203630C arm
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   TOUCHPANEL_GetCont 0x02035C38 arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 * Original consumes r0 from the legacy void 35C38/35C60 wrappers;
 * their final forwarding targets 357A0/357C0 return a halfword load.
 */
#include "../include/Obj05563.h"

typedef unsigned int u32;
struct Rec3;
struct Rec;
extern unsigned int PRINTSYS_PrintStreamGetState(void *);
extern void PRINTSYS_PrintStreamDelete(struct Rec3 *);
extern void PRINTSYS_PrintStreamReleasePause(void *);
extern void PRINTSYS_PrintStreamShortWait(struct Rec *, int);
extern u32 KEY_GetTrg(void);
extern unsigned int KEY_GetCont(void);
extern int TOUCHPANEL_GetTrg(void);
extern int TOUCHPANEL_GetCont(void);
extern void GFL_USE_PlaySeDefaultVolume(unsigned int);
int func_021B9C00(char *p)
{
    if (((struct Obj05563 *)p)->f20 != 0) {
        switch (PRINTSYS_PrintStreamGetState(((struct Obj05563 *)p)->f20)) {
        case 2:
            PRINTSYS_PrintStreamDelete(*(struct Rec3 * *)&((struct Obj05563 *)p)->f20);
            ((struct Obj05563 *)p)->f20 = 0;
            return 1;
        case 1:
            if (KEY_GetTrg() == 1 || KEY_GetTrg() == 2 || TOUCHPANEL_GetTrg() != 0) {
                PRINTSYS_PrintStreamReleasePause(((struct Obj05563 *)p)->f20);
                GFL_USE_PlaySeDefaultVolume(1356);
            }
            break;
        case 0:
            if (((unsigned int)KEY_GetCont() & 3) != 0 || TOUCHPANEL_GetCont() != 0)
                PRINTSYS_PrintStreamShortWait(*(struct Rec * *)&((struct Obj05563 *)p)->f20, 0);
            break;
        }
        return 0;
    }
    return 0;
}
