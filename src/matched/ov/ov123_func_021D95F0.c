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
 *   func_020362DC 0x020362DC arm
 */
#include "../include/Obj06470.h"

typedef unsigned int u32;
struct Rec3;
extern u32 func_0201CE30(void *p);
extern void func_0201CE48(struct Rec3 *p);
extern void func_0201CE38(void *);
extern u32 func_020362DC(void);
int func_021D95F0(char *p)
{
    if (((struct Obj06470 *)p)->f80) {
        switch (func_0201CE30(((struct Obj06470 *)p)->f80)) {
        case 2:
            func_0201CE48(((struct Obj06470 *)p)->f80);
            ((struct Obj06470 *)p)->f80=0;
            break;
        case 1:
            if (func_020362DC()==1) func_0201CE38(((struct Obj06470 *)p)->f80);
            break;
        }
        return 0;
    }
    return 1;
}
