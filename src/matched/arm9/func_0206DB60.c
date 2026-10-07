/*
 * function: func_0206DB60
 * address:  0x0206DB60
 * packet:   pkt_0206DB40
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_0214BAB4       0x0214BAB4  data
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0206DB60.c \
 *       --func func_0206DB60 --addr 0x0206DB60 --cc 1.1p1 --arm
 */

#include "../include/G_GeState.h"

extern struct GeState g_0214BAB4;
extern void   func_0206DB80(void);

void *func_0206DB60(void)
{
    void *r;

    func_0206DB80();
    r = (*(char * *)&g_0214BAB4);
    (*(char * *)&g_0214BAB4) = 0;
    return r;
}
