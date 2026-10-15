/*
 * function: BR_CODEIN_RecordCreateTextWin
 * address: 0x021DD0AC
 * packet: pkt_ov183_021DD0AC
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BR_UTIL_CreateTextWin 0x021FD12C thumb ov186
 *   BR_UTIL_StartEffect 0x021FD860 thumb ov186
 */
#include "../include/Obj00050.h"
#include "../include/Obj24573.h"
typedef unsigned short u16;
extern void *BR_UTIL_CreateTextWin(int a, void *owner, u16 heap);
extern void BR_UTIL_StartEffect(int, int, int *);
void BR_CODEIN_RecordCreateTextWin(char *p)
{
    if (!((struct Obj00050 *)p)->fE0) {
        int args[2];
        ((struct Obj00050 *)p)->fE0 = 1;
        if (!((struct Obj00050 *)p)->f18)
            ((struct Obj00050 *)p)->f18 = BR_UTIL_CreateTextWin(((struct Obj24573 *)(*(char * *)&((struct Obj00050 *)p)->fD0))->f10, (void *)(*(int *)&((struct Obj00050 *)p)->f4), ((struct Obj00050 *)p)->fB4);
        args[0] = 0x80;
        args[1] = 0x60;
        BR_UTIL_StartEffect(*(int *)&((struct Obj00050 *)p)->fC, 4, args);
    }
}
