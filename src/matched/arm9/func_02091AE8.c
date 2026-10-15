/*
 * function: fclose
 * address:  0x02091AE8
 * packet:   pkt_0209159C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   MSL_C_LIB_FlushStream  0x02091B5C  arm
 */
#include "../include/Obj00481.h"

typedef unsigned char u8;
typedef unsigned int u32;

struct P02091B5C;
extern int MSL_C_LIB_FlushStream(struct P02091B5C *p);

int fclose(u8 *p)
{
    u32 mode;
    int r;
    int x;

    if (p == 0)
        return -1;
    mode = (((struct Obj00481 *)p)->f4 << 22) >> 29;
    if (mode == 0)
        return 0;
    r = (int)MSL_C_LIB_FlushStream((struct P02091B5C *)p);
    x = ((int (*)(u32))*(u32 *)(p + 0x44))(((struct Obj00481 *)p)->f0);
    ((struct Obj00481 *)p)->f4 &= ~0x380u;
    ((struct Obj00481 *)p)->f0 = 0;
    if ((((struct Obj00481 *)p)->f8 << 28) >> 31)
        return -1;
    return (r != 0 || x != 0) ? -1 : 0;
}
