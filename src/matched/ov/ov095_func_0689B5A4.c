/*
 * function: BTLV_SCD_OpenChoiceScreen
 * address: 0x0689B5A4
 * packet: pkt_ov095_0689B5A4
 * region: ov095
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0689B5BC 0x0689B5BC thumb ov095
 */
#include "../include/Obj13637.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_0689B5BC(u32, int, int);
void BTLV_SCD_OpenChoiceScreen(u8 *s, int value)
{
    func_0689B5BC(((struct Obj13637 *)s)->fB0, 4, value);
    s[0x93] = 0;
}
