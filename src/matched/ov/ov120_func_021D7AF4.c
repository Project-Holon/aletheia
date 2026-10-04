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
 *   func_020362DC 0x020362DC arm
 */
#include "../include/Obj06441.h"

typedef unsigned int u32;
struct Rec3;
extern u32 func_0201CE30(void *p);
extern void func_0201CE48(struct Rec3 *p);
extern void func_0201CE38(void *);
extern u32 func_020362DC(void);
int func_021D7AF4(char *p)
{
    if (((struct Obj06441 *)p)->f9C) {
        switch (func_0201CE30(((struct Obj06441 *)p)->f9C)) {
        case 2: func_0201CE48(((struct Obj06441 *)p)->f9C); ((struct Obj06441 *)p)->f9C=0; break;
        case 1: if (func_020362DC()==1) func_0201CE38(((struct Obj06441 *)p)->f9C); break;
        }
        return 0;
    }
    return 1;
}
