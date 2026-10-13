/*
 * function: P_STATUS_CanUseButtons
 * address:  0x021D62E4
 * packet:   pkt_021D62E4
 * region:   ov131
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */
#include "../include/Obj23130.h"
#include "../include/Obj23131.h"

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

int P_STATUS_CanUseButtons(char *p)
{
    char *q = *(char * *)&((struct Obj23130 *)p)->f8;

    return ((struct Obj23131 *)q)->f20 == 1;
}
