/*
 * function: OEKAKI_IsMessageDone
 * address:  0x021862B0
 * packet:   pkt_ov023_021862B0
 * region:   ov023
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   PRINTSYS_PrintStreamGetState  0x0201CE30  thumb
 *   KEY_GetTrg  0x020362DC  arm
 *   PRINTSYS_PrintStreamReleasePause  0x0201CE38  thumb
 *   PRINTSYS_PrintStreamDelete  0x0201CE48  thumb
 */
#include "../include/Obj00525.h"

typedef unsigned int u32;

struct Rec3;
extern u32 PRINTSYS_PrintStreamGetState(void *p);
extern u32 KEY_GetTrg(void);
extern void PRINTSYS_PrintStreamReleasePause(void *h);
extern void PRINTSYS_PrintStreamDelete(struct Rec3 *p);

int OEKAKI_IsMessageDone(char *p)
{
    int r = PRINTSYS_PrintStreamGetState(((struct Obj00525 *)p)->f16C);

    if (r == 1) {
        if (KEY_GetTrg() & 1) {
            PRINTSYS_PrintStreamReleasePause(((struct Obj00525 *)p)->f16C);
        }
        return 0;
    }
    if (r == 2) {
        PRINTSYS_PrintStreamDelete(((struct Obj00525 *)p)->f16C);
        ((struct Obj00525 *)p)->f16C = 0;
        return 1;
    }
    return ((struct Obj00525 *)p)->f16C == 0;
}
