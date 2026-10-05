/*
 * function: func_02206768
 * address:  0x02206768
 * packet:   pkt_02206768
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_022067B0 0x022067B0 thumb ov195
 *   func_022086BC 0x022086BC thumb ov195
 */
#include "../include/Obj00300.h"
#include "../include/Obj14534.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void func_022067B0(char *a, int b, int c, int d, int e);
extern void func_022086BC(char *a, int b, int c, int d, int e);

void func_02206768(char *a, u32 x, u32 y, u32 z)
{
    char *t = *(char * *)&((struct Obj00300 *)a)->f58;
    u8 i;

    for (i = 0; i < 2; i++) {
        if (*(void **)(t + i * 4 + 8) != 0)
            func_022067B0(*(void **)(t + i * 4 + 8), ((struct Obj00300 *)a)->f0, x, y, z);
    }
    if (((struct Obj14534 *)t)->f10 != 0)
        func_022086BC(((struct Obj14534 *)t)->f10, ((struct Obj00300 *)a)->f0, x, y, z);
}
