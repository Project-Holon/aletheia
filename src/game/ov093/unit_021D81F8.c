/*
 * file:     unit_021D81F8.c
 * unit:     yes
 * function: func_021D81F8, func_021D8230, func_021D8244, func_021D826C, func_021D8270, func_021D82D0, func_021D82FC
 * address:  0x021D81F8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021F6368 0x021F6368 data a4
 *   func_021D80BC 0x021D80BC thumb ov093
 *   func_021B902C  0x021B902C  thumb
 */
#include "../../matched/include/G_B.h"
#include "../../matched/include/Obj13452.h"

typedef unsigned int u32;

typedef unsigned short u16;

typedef unsigned char u8;

struct IdSet4 { u32 count; u8 val[4]; };

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

typedef struct { u32 n; u8 v[4]; } List4;

struct Unk021D82D0 { u32 kind : 4; u32 sub : 3; u32 id : 16; u32 rest : 9; };

struct Unk021D82FC { u32 kind : 4; u32 sub : 3; u32 id : 16; u32 pad : 3; u32 flag : 1; u32 rest : 5; };

extern int func_021D80BC(void *, int, int, u16);
extern int func_021B902C(int a, int b);
int func_021D81F8(void *p, int a, int m, u16 move, struct B *b);
void func_021D8230(u8 *p);
void func_021D8244(struct IdSet4 *p, int n);
u32 func_021D826C(u32 *p);
int func_021D8270(List4 *l, u8 y, u32 k);
void func_021D82D0(struct Unk021D82D0 *out, u32 id, u32 sub);
void func_021D82FC(struct Unk021D82FC *p, int sub);
void func_021D8318(struct Unk021D82FC *p);
u32 func_021D832C(struct Unk021D82FC *p);
extern struct B d_021F6368;


int func_021D81F8(void *p, int a, int m, u16 move, struct B *b)
{
    int v;

    *b = d_021F6368;
    v = func_021D80BC(p, a, m, move);
    d_021F6368 = *b;
    return v;
}



void func_021D8230(u8 *p) { u32 i; for(i=0;i<4;i++) p[4+i]=4; ((struct Obj13452 *)p)->f0=0; }



void func_021D8244(struct IdSet4 *p, int n) { u32 i; for(i=0;i<4;i++) { if(p->val[i]==n) return; if(p->val[i]==4) { p->val[i]=n; ++p->count; return; } } }




/* 021D826C  ldr r0,[r0] */
/*
 * Reads the u32 field at offset 0 of the argument and returns it.
 */
u32 func_021D826C(u32 *p) { return *p; }



int func_021D8270(List4 *l, u8 y, u32 k)
{
    int miss = 0;
    int hit = 0;
    u32 i;
    for (i = 0; i < l->n; i++) {
        if (func_021B902C(l->v[i], y))
            hit = 1;
        else
            miss = 1;
    }
    if (hit && miss) {
        if (k <= 1)
            return 3;
        return 2;
    }
    return hit ? 3 : 4;
}




void func_021D82D0(struct Unk021D82D0 *out, u32 id, u32 sub)
{
    struct Unk021D82D0 t = {0};
    t.kind = 1;
    t.sub = sub;
    t.id = id;
    *out = t;
}




/*
 * Three accessors on the kind-1 record of func_021D82D0 (kind:4, sub:3,
 * id:16): set the 3-bit sub (unless 6), set the flag at bit 26, read it.
 */
void func_021D82FC(struct Unk021D82FC *p, int sub)
{
    if (p->kind == 1) {
        if (sub != 6)
            p->sub = sub;
    }
}




void func_021D8318(struct Unk021D82FC *p)
{
    if (p->kind == 1)
        p->flag = 1;
}




u32 func_021D832C(struct Unk021D82FC *p)
{
    if (p->kind == 1)
        return p->flag;
    return 0;
}
