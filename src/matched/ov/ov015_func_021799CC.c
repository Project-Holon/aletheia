/*
 * function: IRCNET_Start
 * address:  0x021799CC
 * packet:   pkt_021799CC
 * region:   ov015
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_0217AB80  0x0217AB80  data  ov015
 *   gIrcNetAssertText  0x0217AAAC  data  ov015
 *   func_02034714  0x02034714  arm
 */

#include "../include/G_State.h"

extern struct State d_0217AB80;
extern unsigned char gIrcNetAssertText[];
typedef unsigned int   u32;
extern void func_02034714(const char *expr, u32 line, const char *file);

void IRCNET_Start(void)
{
    if (((unsigned char *)&d_0217AB80)[0xc] != 0)
        func_02034714((const char *)gIrcNetAssertText, 0, (const char *)gIrcNetAssertText);
    ((unsigned char *)&d_0217AB80)[0xc] = 1;
}
