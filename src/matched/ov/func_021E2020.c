/*
 * function: BOX2_SEQ_StateWaitWipe
 * address:  0x021E2020
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WIPE_SYS_EndCheck  0x020221A4  thumb  arm9
 *
 * Query the current mode; when it is 1 return the 0xA188 word of
 *   the p+0x2c object, else 2.
 */
#include "../include/Obj18463.h"


typedef unsigned int   u32;
extern u32 WIPE_SYS_EndCheck(void);
int BOX2_SEQ_StateWaitWipe(char *p)
{
    if (WIPE_SYS_EndCheck() == 1)
        return *(int *)(((struct Obj18463 *)p)->f2C + 0xA188);
    return 2;
}
