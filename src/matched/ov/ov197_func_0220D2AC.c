/*
 * function: B_BAG_MAIN_StateMessageInput
 * address: 0x0220D2AC
 * packet: pkt_ov197_0220D2AC
 * region: ov197
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PRINTSYS_PrintStreamGetState 0x0201CE30 thumb
 *   PRINTSYS_PrintStreamShortWait 0x0201CE5C thumb
 *   PRINTSYS_PrintStreamReleasePause 0x0201CE38 thumb
 *   PRINTSYS_PrintStreamDelete 0x0201CE48 thumb
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   KEY_GetCont 0x0203630C arm
 *   KEY_GetTrg 0x020362DC arm
 *   B_BAG_MAIN_PlaySe2 0x0220D8B0 thumb ov197
 */
#include "../include/Obj03346.h"

typedef unsigned int u32;
struct Rec;
struct Rec3;
extern unsigned PRINTSYS_PrintStreamGetState(void *);
extern void PRINTSYS_PrintStreamShortWait(struct Rec *, int);
extern void PRINTSYS_PrintStreamReleasePause(void *);
extern void PRINTSYS_PrintStreamDelete(struct Rec3 *);
extern int TOUCHPANEL_GetTrg(void);
extern unsigned int KEY_GetCont(void);
extern u32 KEY_GetTrg(void);
extern void B_BAG_MAIN_PlaySe2(char **, int);
int B_BAG_MAIN_StateMessageInput(char *p)
{
    switch (PRINTSYS_PrintStreamGetState(*(struct Rec * *)&((struct Obj03346 *)p)->f1C)) {
    case 0:
        if (TOUCHPANEL_GetTrg() == 1 || (KEY_GetCont() & 3)) PRINTSYS_PrintStreamShortWait(*(struct Rec * *)&((struct Obj03346 *)p)->f1C, 0);
        ((struct Obj03346 *)p)->f20 = 0;
        break;
    case 1:
        if (!((struct Obj03346 *)p)->f20 && (TOUCHPANEL_GetTrg() == 1 || (KEY_GetTrg() & 3))) {
            B_BAG_MAIN_PlaySe2((char **)p, 0x547);
            PRINTSYS_PrintStreamReleasePause(*(struct Rec * *)&((struct Obj03346 *)p)->f1C);
            ((struct Obj03346 *)p)->f20 = 1;
        }
        break;
    case 2:
        PRINTSYS_PrintStreamDelete(*(struct Rec3 * *)&((struct Obj03346 *)p)->f1C);
        *(int *)&((struct Obj03346 *)p)->f1C = 0;
        ((struct Obj03346 *)p)->f20 = 0;
        return 15;
    }
    return 14;
}
