/*
 * function: func_021D7AF4
 * address: 0x021D7AF4
 * packet: pkt_ov120_021D7AF4
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * follower: two zero padding bytes at 021D7B36.
 * symbols:
 *   KEY_GetTrg 0x020362DC arm
 *   PRINTSYS_PrintStreamGetState  0x0201CE30  thumb  arm9
 *   PRINTSYS_PrintStreamReleasePause  0x0201CE38  thumb  arm9
 *   PRINTSYS_PrintStreamDelete  0x0201CE48  thumb  arm9
 */
#include "../include/Obj06441.h"

typedef unsigned int u32;
struct Rec3;
extern u32 PRINTSYS_PrintStreamGetState(void *p);
extern void PRINTSYS_PrintStreamDelete(struct Rec3 *p);
extern void PRINTSYS_PrintStreamReleasePause(void *);
extern u32 KEY_GetTrg(void);
int func_021D7AF4(char *p)
{
    if (((struct Obj06441 *)p)->f9C) {
        switch (PRINTSYS_PrintStreamGetState(((struct Obj06441 *)p)->f9C)) {
        case 2: PRINTSYS_PrintStreamDelete(((struct Obj06441 *)p)->f9C); ((struct Obj06441 *)p)->f9C=0; break;
        case 1: if (KEY_GetTrg()==1) PRINTSYS_PrintStreamReleasePause(((struct Obj06441 *)p)->f9C); break;
        }
        return 0;
    }
    return 1;
}
