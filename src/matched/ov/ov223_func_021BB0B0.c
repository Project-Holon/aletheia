/*
 * function: func_021BB0B0
 * address:  0x021BB0B0
 * packet:   pkt_021BB0B0
 * region:   ov223
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
 *   PRINTSYS_PrintStreamGetState  0x0201CE30  thumb  arm9
 *   PRINTSYS_PrintStreamReleasePause  0x0201CE38  thumb  arm9
 *   PRINTSYS_PrintStreamShortWait  0x0201CE5C  thumb  arm9
 */
#include "../include/Obj00084.h"

typedef unsigned int u32;

typedef signed int     s32;
struct Rec;
extern u32 PRINTSYS_PrintStreamGetState(void *p);
extern void PRINTSYS_PrintStreamShortWait(struct Rec *p, s32 v);
extern void PRINTSYS_PrintStreamReleasePause(void *p);
extern unsigned int KEY_GetCont(void);
extern int TOUCHPANEL_GetCont(void);
extern u32 KEY_GetTrg(void);
extern int TOUCHPANEL_GetTrg(void);

int func_021BB0B0(char *a)
{
    int r = 0;

    switch (PRINTSYS_PrintStreamGetState((void *)(*(u32 *)&((struct Obj00084 *)a)->f250))) {
    case 0:
        if ((KEY_GetCont() & 3) != 0 || TOUCHPANEL_GetCont() != 0) {
            PRINTSYS_PrintStreamShortWait((struct Rec *)(*(u32 *)&((struct Obj00084 *)a)->f250), 0);
            if ((KEY_GetCont() & 3) != 0)
                ((struct Obj00084 *)a)->f8 = 0;
            else
                ((struct Obj00084 *)a)->f8 = 1;
        }
        break;
    case 1:
        if ((KEY_GetTrg() & 3) != 0 || TOUCHPANEL_GetTrg() != 0) {
            PRINTSYS_PrintStreamReleasePause((void *)(*(u32 *)&((struct Obj00084 *)a)->f250));
            if ((KEY_GetTrg() & 3) != 0)
                ((struct Obj00084 *)a)->f8 = 0;
            else
                ((struct Obj00084 *)a)->f8 = 1;
        }
        break;
    case 2:
        r = 1;
        break;
    }
    return r;
}
