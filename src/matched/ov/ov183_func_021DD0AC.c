/*
 * function: func_021DD0AC
 * address: 0x021DD0AC
 * packet: pkt_ov183_021DD0AC
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021FD12C 0x021FD12C thumb ov186
 *   func_021FD860 0x021FD860 thumb ov186
 */
#include "../include/Obj00050.h"
#include "../include/Obj24573.h"
typedef unsigned short u16;
extern void *func_021FD12C(int a, void *owner, u16 heap);
extern void func_021FD860(int, int, int *);
void func_021DD0AC(char *p)
{
    if (!((struct Obj00050 *)p)->fE0) {
        int args[2];
        ((struct Obj00050 *)p)->fE0 = 1;
        if (!((struct Obj00050 *)p)->f18)
            ((struct Obj00050 *)p)->f18 = func_021FD12C(((struct Obj24573 *)(*(char * *)&((struct Obj00050 *)p)->fD0))->f10, (void *)(*(int *)&((struct Obj00050 *)p)->f4), ((struct Obj00050 *)p)->fB4);
        args[0] = 0x80;
        args[1] = 0x60;
        func_021FD860(*(int *)&((struct Obj00050 *)p)->fC, 4, args);
    }
}
