/*
 * function: func_021D95F0
 * address: 0x021D95F0
 * packet: pkt_ov123_021D95F0
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two zero alignment bytes follow the return.
 * symbols:
 *   KEY_GetTrg 0x020362DC arm
 *   PRINTSYS_PrintStreamGetState  0x0201CE30  thumb  arm9
 *   PRINTSYS_PrintStreamReleasePause  0x0201CE38  thumb  arm9
 *   PRINTSYS_PrintStreamDelete  0x0201CE48  thumb  arm9
 */
#include "../include/Obj06470.h"

typedef unsigned int u32;
struct Rec3;
extern u32 PRINTSYS_PrintStreamGetState(void *p);
extern void PRINTSYS_PrintStreamDelete(struct Rec3 *p);
extern void PRINTSYS_PrintStreamReleasePause(void *);
extern u32 KEY_GetTrg(void);
int func_021D95F0(char *p)
{
    if (((struct Obj06470 *)p)->f80) {
        switch (PRINTSYS_PrintStreamGetState(((struct Obj06470 *)p)->f80)) {
        case 2:
            PRINTSYS_PrintStreamDelete(((struct Obj06470 *)p)->f80);
            ((struct Obj06470 *)p)->f80=0;
            break;
        case 1:
            if (KEY_GetTrg()==1) PRINTSYS_PrintStreamReleasePause(((struct Obj06470 *)p)->f80);
            break;
        }
        return 0;
    }
    return 1;
}
