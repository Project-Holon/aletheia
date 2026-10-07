/*
 * file:     box2_main_p05.c
 * unit:     yes
 * function: func_021DDE20, func_021DDE80, func_021DDEFC
 * address:  0x021DDE20
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021DD25C 0x021DD25C thumb ov170
 *   func_021DD694 0x021DD694 thumb ov170
 *   func_0201AB28 0x0201AB28 thumb
 *   func_02017E1C 0x02017E1C thumb
 *   func_0202136C 0x0202136C thumb
 *   func_021EC0B0 0x021EC0B0 thumb
 *   func_021EC548 0x021EC548 thumb
 *   func_021EDA70 0x021EDA70 thumb
 */
#include "../../matched/include/Obj00000.h"

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

extern unsigned func_021DD25C(void ***,unsigned short,int,unsigned,unsigned);
extern int func_021DD694(void ***,unsigned);
extern void *func_0201AB28(void *,unsigned);
extern unsigned func_02017E1C(void *,unsigned,unsigned);
extern unsigned func_0202136C(unsigned short);
extern void func_021EC0B0(char *p, int i, short *a, short *b, unsigned short space);
extern void func_021EC548(unsigned i, short *x, short *y, int mode);
extern void func_021EDA70(int a0, int a1, short *a2, short *a3);
int func_021DDE20(unsigned char *p,unsigned a,unsigned b);
int func_021DDE80(unsigned char *p, unsigned a, unsigned b);
void func_021DDEFC(unsigned char *p, Obj *o);

/*
 * trailing: two bytes alignment padding at 0x021DDE7E.
 */
int func_021DDE20(unsigned char *p,unsigned a,unsigned b)
{
    int result = 0;
    if (func_021DD25C((void ***)p,(unsigned short)b,p[0x14],0xa9,0))
        return result;
    if (!func_021DD694((void ***)p,a-30))
        return result;
    if (func_0202136C((unsigned short)func_02017E1C(func_0201AB28((*(void ***)p)[2],a-30),6,0)) != 1)
        result = 1;
    return result;
}


int func_021DDE80(unsigned char *p, unsigned a, unsigned b)
{
    if (func_021DD25C((void ***)p, b, p[0x14], 0xA9, 0) == 0)
        return 0;
    if (func_021DD25C((void ***)p, b, p[0x14], 0x4C, 0) != 0)
        return 0;
    if (func_0202136C(func_021DD25C((void ***)p, a, p[0x14], 6, 0)) == 1)
        return 0;
    if (func_0202136C(func_021DD25C((void ***)p, b, p[0x14], 6, 0)) == 1)
        return 0;
    return 1;
}


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
