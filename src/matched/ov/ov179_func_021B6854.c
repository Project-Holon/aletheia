/*
 * function: func_021B6854
 * address:  0x021B6854
 * packet:   pkt_ov179_021B6854
 * region:   ov179
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf (no lr-saving prologue): the listing prints it as .word
 * data.  Entry of the ov179 command table (pool word 0x021B6855 at 0x021B6A6C).
 * volatile: 0x04000050 is a hardware register (REG_BLDCNT).
 */
#include "../include/Obj08296.h"
int func_021B6854(char *p)
{
    *(volatile unsigned short *)0x04000050 = 0;
    ((struct Obj08296 *)p)->f6024 = 0;
    ((struct Obj08296 *)p)->f6028 = 0;
    ((struct Obj08296 *)p)->f602C = 0;
    ((struct Obj08296 *)p)->f6030 = 0;
    return 1;
}
