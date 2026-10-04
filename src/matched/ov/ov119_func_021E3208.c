/*
 * function: func_021E3208
 * address:  0x021E3208
 * packet:   pkt_021E3208
 * region:   ov119
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021E324C  0x021E324C  thumb  ov119
 *   tbl_021E7AC4   0x021E7AC4  data   ov119  a4
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj03779.h"

typedef unsigned int u32;
typedef void (*Fn)(void *);

extern void func_021E324C(char *p, int n);
extern Fn tbl_021E7AC4[];

void func_021E3208(void *p, int a)
{
    func_021E324C(p, a);
    if (((struct Obj03779 *)p)->f109C != 0xFFFFFFFF) {
        tbl_021E7AC4[*(u32 *)((char *)p + 0x109C) * 2](p);
    }
}
