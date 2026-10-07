/*
 * file:     unit_021B7560_p05.c
 * unit:     yes
 * function: func_021B85F4, func_021B8624, func_021B86F8, func_021B86FC
 * address:  0x021B85F4
 * region:   ov102
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020452E8 0x020452E8 arm
 *   func_02051C6C 0x02051C6C arm
 *   func_02082BCC 0x02082BCC arm
 */
#include "../../matched/include/Obj13728.h"
#include "../../matched/include/Obj22165.h"

struct Descriptor;
struct Ctx;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct { u16 tag,x,y,w,h,pad; } Row;

typedef struct {
    struct Ctx *ctx;
    u8 pad04[0x28-4];
    u8 *rows;
    u16 count, pad2e, index, done, phase, timer;
    u32 enabled;
} State;

typedef short s16;

typedef signed char s8;

typedef int s32;

extern u32 func_020452E8(struct Descriptor *d);
extern void func_02051C6C(void *);
extern void func_02082BCC(void *, int, u32);
extern int func_02051C88(struct Ctx *);
extern void func_020061E4(u32);
extern u8 func_02045730(struct Descriptor *);
extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void func_020409B4(u32 index);
void func_021B85F4(u8 *p);
void func_021B8624(State *p);
void func_021B86F8(u8 *p, u32 v);
int func_021B86FC(u8 *p);

void func_021B85F4(u8 *p) { int i; for(i=0;i<((struct Obj13728 *)p)->f2C;i++)func_020452E8(*(void **)(p+4+i*4)); func_02051C6C(((struct Obj13728 *)p)->f0); func_02082BCC(p,0,60); }

#pragma opt_propagation off

void func_021B8624(State *p)
{
    switch(p->phase) {
    case 0:
        p->done=0;
        if(func_02051C88(p->ctx) && p->enabled) {
            func_020061E4(1352);
            p->timer=0;
            p->phase=1;
        }
        break;
    case 1: {
        u8 palette0;
        u8 win;
        u8 a,b,c,d;
        u8 blink;
        const Row *row;
        u16 i;
        int off;
        u8 *rows;
        u8 palette1;
        blink=(u8)((p->timer/4)%2);
        win=func_02045730(*(struct Descriptor **)((u8 *)p+4+p->index*4));
        i=p->index;
        off=i*12;
        rows=p->rows;
        row=(const Row *)(rows+off);
        a=row->x; b=row->y; c=row->w; d=row->h;
        switch(i) {
        case 0: palette1=12; palette0=11; break;
        case 1: palette1=9; palette0=4; break;
        }
        if (blink == 0) {
            func_020413B0(win,a,b,c,d,palette0);
            func_020409B4(win);
        } else {
            func_020413B0(win,a,b,c,d,palette1);
            func_020409B4(win);
        }
        (p->timer)++;
        if(p->timer>=16) {
            p->done=1;
            p->phase=0;
        }
        break;
    }
    }
}

#pragma opt_propagation reset


void func_021B86F8(u8 *p, u32 v) { ((struct Obj22165 *)p)->f38 = v; }

/*
 * note: 2026-10-05 wave P27: u16 field at +0x34 tested for non-zero. 14 B compiled, 2 B trailing pad. Twin shape in ov068 021BA6B8 area (ldrh #0x34 callers).
 */
int func_021B86FC(u8 *p)
{
    return *(u16 *)(p + 0x34) != 0;
}
