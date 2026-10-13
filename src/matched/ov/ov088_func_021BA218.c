/*
 * function: STARTMENU_StateWaitFade
 * address:  0x021BA218
 * packet:   pkt_ov088_021BA218
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WIPE_SYS_EndCheck  0x020221A4  thumb
 */
#include "../include/Obj20813.h"

typedef unsigned int   u32;
extern u32 WIPE_SYS_EndCheck(void);

int STARTMENU_StateWaitFade(char *p)
{
    if (WIPE_SYS_EndCheck() == 1) {
        return ((struct Obj20813 *)p)->f144;
    }
    return 2;
}
