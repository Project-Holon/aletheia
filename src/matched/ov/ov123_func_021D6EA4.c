/*
 * function: GSYNC_STATE_IsCommIdleWithTarget
 * address:  0x021D6EA4
 * packet:   pkt_021D6EA4
 * region:   ov123
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */
#include "../include/Obj13982.h"
#include "../include/Obj22953.h"

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

int GSYNC_STATE_IsCommIdleWithTarget(char *p)
{
    char *q = *(char * *)&((struct Obj22953 *)p)->f20;

    return ((struct Obj13982 *)q)->f50 != 0 && ((struct Obj13982 *)q)->fC == 0;
}
