/*
 * function: func_021DDEFC
 * address:  0x021DDEFC
 * packet:   pkt_ov170_021DDEFC
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EC0B0 0x021EC0B0 thumb
 *   func_021EC548 0x021EC548 thumb
 *   func_021EDA70 0x021EDA70 thumb
 */
#include "../include/Obj00000.h"

typedef struct {
    unsigned short idx;
    unsigned short slot;
    unsigned short f4;
    unsigned short f6;
    int vx;
    int vy;
    short dx;
    short dy;
    short x;
    short y;
} Obj;

extern void func_021EC0B0(char *p, int i, short *a, short *b, unsigned short space);
extern void func_021EC548(unsigned i, short *x, short *y, int mode);
extern void func_021EDA70(int a0, int a1, short *a2, short *a3);

void func_021DDEFC(unsigned char *p, Obj *o)
{
    short t[2];
    func_021EC0B0(*(char * *)&((struct Obj00000 *)p)->f2C, *(unsigned char *)(*(char * *)&((struct Obj00000 *)p)->f2C + o->idx + 0x3DD2), &o->x, &o->y, 0);
    if (o->f6 != 2) {
        if (o->slot < 0x24)
            func_021EC548(o->slot, &t[1], &t[0], p[0x1A]);
        else
            func_021EDA70((int)(*(char * *)&((struct Obj00000 *)p)->f2C), o->slot - 0x24, &t[1], &t[0]);
    } else if (p[0x14] > p[0x17]) {
        func_021EC0B0(*(char * *)&((struct Obj00000 *)p)->f2C, 0, &t[1], &t[0], 0);
    } else {
        func_021EC0B0(*(char * *)&((struct Obj00000 *)p)->f2C, 1, &t[1], &t[0], 0);
    }
    if (o->x <= t[1]) {
        o->dx = 1;
        o->vx = ((t[1] - o->x) << 16) / 8;
    } else {
        o->dx = -1;
        o->vx = ((o->x - t[1]) << 16) / 8;
    }
    if (o->y <= t[0]) {
        o->dy = 1;
        o->vy = ((t[0] - o->y) << 16) / 8;
    } else {
        o->dy = -1;
        o->vy = ((o->y - t[0]) << 16) / 8;
    }
}
