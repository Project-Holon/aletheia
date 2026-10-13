/*
 * function: BTL_CLIENT_CmdHpMinus
 * address: 0x021D36CC
 * packet: pkt_ov093_021D36CC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: compiled 30 bytes followed by two zero alignment bytes.
 * symbols:
 *   BTL_SIDE_GetPokeByIdThunk 0x021B9934 thumb ov093
 *   BTL_POKEPARAM_SubHp 0x021D5F90 thumb ov093
 */
#include "../include/Obj21166.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern u8 *BTL_SIDE_GetPokeByIdThunk(char *p, int i);
extern void BTL_POKEPARAM_SubHp(u8 *, u16);
int BTL_CLIENT_CmdHpMinus(char *p, int *state, unsigned int *q)
{
    BTL_POKEPARAM_SubHp(BTL_SIDE_GetPokeByIdThunk(*(char * *)&((struct Obj21166 *)p)->f4, (u8)q[0]), q[1]);
    return 1;
}
