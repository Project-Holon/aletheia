/*
 * function: func_021B91C8
 * address:  0x021B91C8
 * packet:   pkt_ov021_021B91C8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021D9A0C     0x021D9A0C  data  a4
 *   func_021B8820  0x021B8820  thumb  ov021
 */

#include "../include/G_Elem.h"

typedef unsigned short u16;

typedef struct {
    char pad[0x10];
    void *f10;
    char pad2[0x28];
    void *f3C;
} Info;

typedef struct {
    u16 h0;
    Info *f4;
    char pad[0x1C];
    void *f24;
} Obj;

extern struct Elem d_021D9A0C;

extern void *func_021B8820(void *a, void *b);

void *func_021B91C8(Obj *p)
{
    switch (p->h0) {
    case 0:
        return func_021B8820(p->f24, p->f4->f3C);
    case 1:
        return func_021B8820(p->f24, p->f4->f10);
    }
    return &(*(int *)&d_021D9A0C);
}
