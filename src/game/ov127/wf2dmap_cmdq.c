/*
 * file:     wf2dmap_cmdq.c
 * unit:     yes
 * function: func_021C5EEC, func_021C5F30, func_021C5F44
 * address:  0x021C5EEC
 * region:   ov127
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02030734 0x02030734 arm
 *   d_021C6158 0x021C6158 data a1
 *   func_020307B0  0x020307B0  arm
 *   _u32_div_f 0x0209C2B0 arm
 *   func_021C5F80 0x021C5F80 thumb ov127
 */
#include "../../matched/include/Obj23061.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed short s16;

typedef struct { void *entries; u32 count; u16 used, capacity; } Container;

typedef signed int     s32;

typedef struct {u16 x,y;} Entry;

typedef struct {Entry *data;u32 count;u16 r,w;} S;

extern void *func_02030734(u16,u32,int,const char *,u16);
extern u32 func_020307B0(void *p);
extern u32 _u32_div_f(u32,u32);
extern int func_021C5F80(S *,Entry *);
Container *func_021C5EEC(int n, int heap);
void func_021C5F30(u8 *p);
void func_021C5F44(S *p,const Entry *q);
extern const char d_021C6158[];

Container *func_021C5EEC(int n, int heap)
{
    Container *p;
    p=func_02030734(heap,12,1,d_021C6158,211);
    p->count=n+1;
    p->entries=func_02030734(heap,p->count*4,1,d_021C6158,216);
    p->used=0;
    p->capacity=0;
    return p;
}


/*
 * Addresses are Black-image addresses.
 */
void func_021C5F30(u8 *p)
{
    func_020307B0(((struct Obj23061 *)p)->f0);
    func_020307B0(p);
}

void func_021C5F44(S *p,const Entry *q) {Entry tmp; if((p->w+1u)%p->count==p->r) func_021C5F80(p,&tmp);p->data[p->w]=*q;p->w=(p->w+1u)%p->count;}
