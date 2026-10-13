/*
 * function: BTL_SERVER_FLOW_ProcMoveReflectOrAbsorbById
 * address: 0x021C846C
 * packet: pkt_ov093_021C846C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: Two bytes of alignment padding follow the 38-byte function.
 * symbols:
 *   BTL_SIDE_GetPokeByIdThunk 0x021B9934 thumb ov093
 *   BTL_SERVER_FLOW_ProcMoveReflectOrAbsorb 0x021BFEAC thumb ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8;
extern u8 *BTL_SIDE_GetPokeByIdThunk(char *p, int i);
extern int BTL_SERVER_FLOW_ProcMoveReflectOrAbsorb(u8 *, u8 *, u8 *, int *);
int BTL_SERVER_FLOW_ProcMoveReflectOrAbsorbById(u8 *p, int a, int b, int *out)
{
    u8 *x = BTL_SIDE_GetPokeByIdThunk(*(char * *)&((struct Obj00003 *)p)->f8, a);
    u8 *y = BTL_SIDE_GetPokeByIdThunk(*(char * *)&((struct Obj00003 *)p)->f8, b);
    return BTL_SERVER_FLOW_ProcMoveReflectOrAbsorb(p, x, y, out);
}
