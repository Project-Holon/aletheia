/*
 * function: func_021FB964
 * address: 0x021FB964
 * packet: pkt_ov135_021FB964
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B3DC 0x0204B3DC arm
 *   CLACT_GetActorAnimSeq 0x0204B898 arm
 *   func_0204B878 0x0204B878 arm
 *   func_021F9CDC 0x021F9CDC thumb ov135
 */
#include "../include/Obj00194.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct Obj;
extern void func_0204B3DC(struct Obj *p, unsigned int on);
extern u16 CLACT_GetActorAnimSeq(struct Obj *p);
extern void func_0204B878(struct Obj *p, u16 value);
extern int func_021F9CDC(void *p, u8 *flags);
int func_021FB964(u8 *p)
{
    int r;
    r = func_021F9CDC(p, p + 0x60);
    switch ((u32)r) {
    case 0: case 1: case 2: case 3: case 4:
        func_0204B3DC((struct Obj *)((struct Obj00194 *)p)->f8, 1);
        func_0204B878((struct Obj *)(((struct Obj00194 *)p)->f8), CLACT_GetActorAnimSeq((struct Obj *)(((struct Obj00194 *)p)->f8)) + 9);
        ((struct Obj00194 *)p)->f48 = 24;
        ((struct Obj00194 *)p)->f3A = r;
        break;
    case -2:
        func_0204B3DC((struct Obj *)((struct Obj00194 *)p)->f8, 1);
        func_0204B878((struct Obj *)(((struct Obj00194 *)p)->f8), CLACT_GetActorAnimSeq((struct Obj *)(((struct Obj00194 *)p)->f8)) + 9);
        ((struct Obj00194 *)p)->f48 = 24;
        ((struct Obj00194 *)p)->f3A = -1;
        break;
    }
    return -1;
}
