/*
 * function: func_021BE4B8
 * address: 0x021BE4B8
 * packet: pkt_ov204_021BE4B8
 * region: ov204
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   INTRO_MCSS_AddSlot 0x021BF624 thumb ov204
 *   INTRO_G3D_AddPokemonSlot 0x021BF67C thumb ov204
 *   INTRO_G3D_SetSlotMepachi 0x021BF7CC thumb ov204
 *   d_021BFFE4 0x021BFFE4 data a1
 */
#include "../include/Obj10874.h"
extern void INTRO_MCSS_AddSlot(char *p, unsigned int a, unsigned int b, unsigned int c, void *d, unsigned char i);
extern void INTRO_G3D_AddPokemonSlot(char *p, unsigned int a, unsigned int b, unsigned int c, unsigned int species, unsigned char i);
typedef unsigned char  u8;
extern void INTRO_G3D_SetSlotMepachi(u8 *p, u8 index, int flag);
extern const char d_021BFFE4[];
int func_021BE4B8(char *p, int unused, unsigned *q)
{
    if (q[1] == 0) {
        INTRO_MCSS_AddSlot(((struct Obj10874 *)p)->f8, q[2], q[3], 0, (void *)d_021BFFE4, q[0]);
        INTRO_G3D_SetSlotMepachi(((struct Obj10874 *)p)->f8, q[0], 1);
    } else {
        INTRO_G3D_AddPokemonSlot(((struct Obj10874 *)p)->f8, q[2], q[3], 0x1000, q[1], q[0]);
    }
    return 1;
}
