/*
 * function: func_02194670
 * address:  0x02194670
 * packet:   pkt_ov021_02194670
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_0203101C  0x0203101C  arm
 *   func_02194A58  0x02194A58  thumb  ov021
 *   func_021954CC  0x021954CC  thumb  ov021
 *   d_021DDAC4     0x021DDAC4  data  a4
 *   d_020A8140     0x020A8140  data  a4
 *   d_020A8148     0x020A8148  data  a4
 */
#include "../include/Obj07451.h"

typedef unsigned short u16;
typedef struct { unsigned w[6]; } T24;

extern int d_021DDAC4;
extern void *(*d_020A8140)(int, int, int);
extern void *(*d_020A8148)(int, int, int);

extern void *func_02030734(unsigned int heap, unsigned int size, int clear, const char *site, u16 tag);
typedef unsigned int   u32;
struct Tcbl;
extern struct Tcbl *func_0203101C(u32 heap, u16 tag, u32 count, u32 workSize);
extern void func_02194A58(void *p);
extern unsigned func_021954CC(void *a, void *b);

void *func_02194670(u16 *a)
{
    unsigned char *r6;
    int i;

    r6 = (unsigned char *)func_02030734(*a, 0xcd0, 1, (const char *)&d_021DDAC4, 0xec);
    *(T24 *)r6 = *(T24 *)a;
    ((struct Obj07451 *)r6)->fC98 = func_0203101C(*a, *a, 0x20, 0x20);
    for (i = 0; i < 0x20; i++)
        func_02194A58(r6 + 0x18 + i * 0x64);
    ((struct Obj07451 *)r6)->fCC8 = d_020A8140(0x20, 0, 0);
    ((struct Obj07451 *)r6)->fCCC = d_020A8148(0x20, 0, 0);
    ((struct Obj07451 *)r6)->fC9C = func_021954CC(r6, r6) >> 5;
    return r6;
}
