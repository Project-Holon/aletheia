/*
 * function: func_021C71A8
 * address:  0x021C71A8
 * packet:   pkt_021C71A8
 * region:   ov136
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */
#include "../include/Obj00127.h"
#include "../include/Obj23639.h"

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

int func_021C71A8(char *p, int v, int w)
{
    ((struct Obj23639 *)(*(char * *)&((struct Obj00127 *)p)->f8))->f1DD = v;
    *(int *)&((struct Obj00127 *)p)->f28 = w;
    return 3;
}
