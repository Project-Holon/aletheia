/*
 * file:     field_g3dobj_p05.c
 * unit:     yes
 * function: func_021C6580, func_021C6590, func_021C6628
 * address:  0x021C6580
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021C6940  0x021C6940  thumb  ov021
 *   func_021C69B4  0x021C69B4  thumb  ov021
 *   func_0207ADC4  0x0207ADC4  arm
 *   func_021C6A90  0x021C6A90  thumb  ov021
 */
#include "../../matched/include/Obj18310.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct {
    int x;
    int y;
    int z;
} Vec;

typedef struct {
    u32 kind : 2;
    u32 b2 : 1;
    u32 rest : 29;
    u16 f4;
    u16 f6;
    Vec f8;
    int f14;
    int f18;
    int f1C;
    u8 f20[0x24];
    void *f44;
    u8 pad48[0x20];
} Elem_021C6590;

typedef struct {
    u16 f0;
    u16 f2;
    u16 f4;
    u16 f6;
    u8 *f8;
    Elem_021C6590 *fC;
} Mgr_021C6590;

typedef struct { u8 pad[0x2c]; } Item;

typedef struct { u32 k:2; u32 rest:30; u16 f4; u8 pad[0x62]; } Elem_021C6628;

typedef struct { u16 f0; u16 f2; u16 f4; u16 f6; Item *f8; Elem_021C6628 *fC; } Mgr_021C6628;

extern void func_021C6940(u8 *p);
extern void func_021C69B4(Elem_021C6590 *e, u8 *s, int a, int b, int c, void *d, int f);
extern void func_0207ADC4(void *p);
extern void func_021C6A90(u32 *p, u8 *q);
void func_021C6580(u8 *p, int i);
u16 func_021C6590(Mgr_021C6590 *m, u16 idx, u16 a, Vec *src);
void func_021C6628(Mgr_021C6628 *m, int idx);


/*
 * Tail call on a strided element of the array at +8.
 *
 * Addresses are Black-image addresses.
 */
void func_021C6580(u8 *p, int i)
{
    func_021C6940((u8 *)(((struct Obj18310 *)p)->f8 + i * 0x2c));
}


u16 func_021C6590(Mgr_021C6590 *m, u16 idx, u16 a, Vec *src)
{
    u16 i;
    Elem_021C6590 *e;
    u8 *s;

    e = m->fC;
    for (i = 0; i < m->f6; i++) {
        if (e->kind == 0 && e->f44 == 0) {
            s = m->f8 + idx * 0x2c;
            if (s[0x29] == 2) {
                e->f4 = idx;
                e->f6 = a;
                e->kind = 2;
                e->b2 = 1;
                e->f14 = 0x1000;
                e->f18 = 0x1000;
                e->f1C = 0x1000;
                if (src != 0)
                    e->f8 = *src;
                func_0207ADC4(e->f20);
            } else {
                func_021C69B4(e, s, idx, a, m->f0, src, 1);
            }
            return i;
        }
        e++;
    }
    return 0;
}

void func_021C6628(Mgr_021C6628 *m, int idx)
{
    Elem_021C6628 *e;
    e = &m->fC[idx];
    m->f2 = 0;
    if (e->k == 1)
        func_021C6A90((u32 *)e, (u8 *)(&m->f8[e->f4]));
    m->f2 = 1;
}
