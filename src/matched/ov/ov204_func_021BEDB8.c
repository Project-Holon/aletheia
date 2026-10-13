/*
 * function: func_021BEDB8
 * address: 0x021BEDB8
 * packet: pkt_ov204_021BEDB8
 * region: ov204
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: hardware BLDALPHA write at 021BEE46.
 * symbols:
 *   func_0207D63C 0x0207D63C arm
 *   CLACT_SetActorObjMode 0x0204B688 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_GetActorObjMode 0x0204B6E4 arm
 */
#include "../include/Obj14616.h"
extern void func_0207D63C(volatile void *, int, int, int, int);
typedef unsigned int   u32;
struct Actor;
struct Obj;
extern void CLACT_SetActorObjMode(struct Actor *actor, u32 value);
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
static inline void change_alpha(int a, int b)
{
    *(volatile unsigned short *)0x04000052 = (unsigned short)(a | (b << 8));
}
extern u32 CLACT_GetActorObjMode(const struct Actor *actor);
int func_021BEDB8(char *p, unsigned *state, unsigned *q)
{
    unsigned i;
    switch (*state) {
    case 0:
        func_0207D63C((volatile void *)0x04000050, 0, 12, 0, 16);
        CLACT_SetActorObjMode(*(void **)(p + 0x10a8 + q[0] * 4), 1);
        CLACT_SetActorDrawEnable(*(void **)(p + 0x10a8 + q[0] * 4), 1);
        ++*state;
        break;
    case 16:
        for (i = 0; i < 3; i++) {
            char *row = p + i * 4;
            if (CLACT_GetActorObjMode(((struct Obj14616 *)row)->f10A8) == 1)
                CLACT_SetActorObjMode(((struct Obj14616 *)row)->f10A8, 0);
        }
        *state = 0;
        return 1;
    default:
        ++*state;
        change_alpha(*state, 16 - *state);
        break;
    }
    return 0;
}
