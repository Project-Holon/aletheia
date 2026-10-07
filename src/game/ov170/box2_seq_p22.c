/*
 * file:     box2_seq_p22.c
 * unit:     yes
 * function: func_021E954C, func_021E95CC
 * address:  0x021E954C
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
 *   func_020260F0 0x020260F0 thumb
 *   func_020355D8 0x020355D8 arm
 *   func_021E8F90 0x021E8F90 thumb
 */
#include "../../matched/include/Obj00000.h"

#define WORK(p) (*(char **)((p) + 0x2C))
struct Sound;
typedef struct {
    unsigned char pad[0x1A6];
    unsigned char flag : 1;
    unsigned char id : 7;
    unsigned char lo : 4;
    unsigned char hi : 4;
    unsigned char state;
    unsigned char count;
    unsigned char x;
    unsigned char y;
    unsigned char w;
    unsigned char h;
} Work;

typedef struct {
    unsigned char pad[0x28];
    int arg;
    Work *work;
} Sys;

typedef unsigned int   u32;

typedef unsigned char  u8;

extern u32 func_020260F0(struct Sound *obj);
extern void func_020355D8(u8 v);
extern int func_021E8F90(void *p, int a);
int func_021E954C(Sys *p, int id, int lo, int arg);
int func_021E95CC(unsigned char *p, unsigned char v);


int func_021E954C(Sys *p, int id, int lo, int arg)
{
    p->work->flag = 0;
    p->work->id = (unsigned char)id;
    p->work->lo = (unsigned char)lo;
    p->work->hi = 0;
    p->work->state = 0;
    p->work->count = 0;
    p->work->x = 0;
    p->work->y = 0;
    p->work->w = 0;
    p->work->h = 0;
    p->arg = arg;
    return 8;
}


/*
 * Enters state 9 with reason v.
 */
int func_021E95CC(unsigned char *p, unsigned char v)
{
    if (func_020260F0(*(void **)(WORK(p) + 0x70)) == 1)
        func_020355D8(0);
    else
        func_020355D8(1);
    ((struct Obj00000 *)p)->f28 = 9;
    p[0x12] = v;
    return func_021E8F90(p, 1);
}
