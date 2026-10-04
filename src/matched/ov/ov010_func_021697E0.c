/*
 * function: func_021697E0
 * address:  0x021697E0
 * packet:   pkt_ov010_021697E0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf (no push, so disasm.py printed it as a .word run);
 * called from ov021 func_0218DBD4.
 */
#include "../include/Obj09322.h"

int func_021697E0(char *p)
{
    if (((struct Obj09322 *)p)->fD0 == 0
        || *(int *)(*(char * *)&((struct Obj09322 *)p)->f28 + ((struct Obj09322 *)p)->f18 * 16 + 8) == 0)
        return 0;
    return 1;
}
