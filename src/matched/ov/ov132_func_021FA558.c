/*
 * function: func_021FA558
 * address:  0x021FA558
 * packet:   pkt_021FA558
 * region:   ov132
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */
#include "../include/Obj23226.h"
#include "../include/Obj23227.h"

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

void func_021FA558(char *p, int i, int v)
{
    char *q = p + i * 4;

    ((struct Obj23227 *)q)->f1EC = v;
    ((struct Obj23226 *)p)->f200 = 1;
}
