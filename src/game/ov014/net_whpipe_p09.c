/*
 * file:     net_whpipe_p09.c
 * unit:     yes
 * function: func_02177ACC, func_02177AEC
 * address:  0x02177ACC
 * region:   ov014
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_021797A4 0x021797A4 data ov014 a4
 *   func_02178E38 0x02178E38 thumb ov014
 */
#include "../../matched/include/G_W.h"

typedef unsigned short u16;

typedef unsigned char u8;

extern u16 func_02178E38(void);
unsigned int func_02177ACC(void);
int func_02177AEC(void);
extern struct W *g_021797A4;

unsigned int func_02177ACC(void) { if (g_021797A4 != 0) return func_02178E38() & 0xFFFE; return 0; }


int func_02177AEC(void)
{
    u8 *w = ((u8 *)g_021797A4);

    if (w != 0 && w[0xCEB] != 0)
        return 1;
    return 0;
}
