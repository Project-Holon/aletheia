/*
 * function: func_021BE578
 * address: 0x021BE578
 * packet: pkt_ov204_021BE578
 * region: ov204
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   INTRO_G3D_SetSlotAlpha 0x021BF794 thumb ov204
 *   INTRO_G3D_SetVanishFlag 0x021BF720 thumb ov204
 */
#include "../include/Obj04609.h"
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void INTRO_G3D_SetSlotAlpha(u8 *p, u8 index, u32 alpha);
extern void INTRO_G3D_SetVanishFlag(u8 *p, int flag, u8 index);
int func_021BE578(char *p, int *state, unsigned *q)
{
    switch (*state) {
    case 0:
        if (q[1] != 0)
            INTRO_G3D_SetSlotAlpha(((struct Obj04609 *)p)->f8, q[0], (unsigned char)1);
        else
            INTRO_G3D_SetSlotAlpha(((struct Obj04609 *)p)->f8, q[0], (unsigned char)31);
        INTRO_G3D_SetVanishFlag(((struct Obj04609 *)p)->f8, 1, q[0]);
        state[1] = 31;
        ++*state;
        break;
    case 1:
        state[1] -= 2;
        if (state[1] <= 0) {
            INTRO_G3D_SetSlotAlpha(((struct Obj04609 *)p)->f8, q[0], (unsigned char)31);
            INTRO_G3D_SetVanishFlag(((struct Obj04609 *)p)->f8, q[1], q[0]);
            return 1;
        }
        if (q[1] == 1)
            INTRO_G3D_SetSlotAlpha(((struct Obj04609 *)p)->f8, q[0], (unsigned char)(31 - state[1]));
        else if (q[1] == 0)
            INTRO_G3D_SetSlotAlpha(((struct Obj04609 *)p)->f8, q[0], (unsigned char)state[1]);
        break;
    }
    return 0;
}
