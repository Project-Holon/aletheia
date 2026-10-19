/*
 * function: DEMO3D_DATA_ScaleTime
 * address:  0x021BF7AC
 * packet:   pkt_021BF7AC
 * region:   ov203
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */
#include "../include/Obj03917.h"
#include "../include/Obj25328.h"

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

struct Q { char pad[6]; unsigned short flag : 1; };

int DEMO3D_DATA_ScaleTime(char *p, int v)
{
    struct Q *q = *(struct Q * *)&((struct Obj25328 *)(*(char * *)&((struct Obj03917 *)p)->f1C))->f74;
    int flag = q->flag;

    if (flag == 1)
        v *= 2;
    return v;
}
