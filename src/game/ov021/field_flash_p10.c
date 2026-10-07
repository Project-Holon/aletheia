/*
 * file:     field_flash_p10.c
 * unit:     yes
 * function: func_021C7D78, func_021C7DAC, func_021C7DE0, func_021C7DFC, func_021C7E30, func_021C7E50, func_021C7E54, func_021C7E58, func_021C7E64, func_021C7E70
 * address:  0x021C7D78
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
 *   func_021ADD7C  0x021ADD7C  thumb  ov021
 *   d_021DE4FC  0x021DE4FC  data  ov021  a4
 *   func_02030734  0x02030734  arm
 *   func_020307B0  0x020307B0  arm
 *   func_021C8018  0x021C8018  thumb  ov021
 *   func_021C8054  0x021C8054  thumb  ov021
 *   d_021DAAD0  0x021DAAD0  data  ov021  a4
 *   func_021C7E90  0x021C7E90  thumb  ov021
 *   func_021C7EEC  0x021C7EEC  thumb  ov021
 *   func_021C7EF4  0x021C7EF4  thumb  ov021
 *   func_021C8078  0x021C8078  thumb  ov021
 *   func_02082BCC  0x02082BCC  arm
 */
#include "../../matched/include/Obj18324.h"
#include "../../matched/include/Obj03529.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct { u32 f0; u32 f4; u32 f8; u8 fC; u8 fD; u16 fE; u16 f10; u16 f12; } W;

typedef struct { u32 f0; u8 sub[0x18]; u16 f1C; u16 f1E; } M;

typedef struct Obj {
    u8 pad00[0x1C];
    u16 f1c;            /* 0x1C */
} Obj;

typedef signed short   s16;

typedef signed char    s8;

extern void func_021ADD7C(int a, int b);
extern u32 func_020307B0(void *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_021C8018(u32 heap);
extern int func_021C8054(void *a);
extern int func_021C7E90(void *p);
extern u32 func_021C7EEC(u8 *p);
extern u8 func_021C7EF4(u8 *p);
extern void func_021C8078(u32 h, u32 a, u32 b);
extern void func_02082BCC();
int func_021C7D78(W *w);
M *func_021C7DAC(u32 heap);
void func_021C7DE0(M *m);
void func_021C7DFC(M *m);
void func_021C7E30(M *m);
void func_021C7E50(u8 *p, u16 v);
u16 func_021C7E54(Obj *p);
void func_021C7E58(u32 a);
void func_021C7E64(u32 a);
int func_021C7E70(u32 a, u32 b, u32 c, u32 d, u32 e0, u32 e1);
extern char d_021DE4FC[];

int func_021C7D78(W *w)
{
    if (w->fC == 0) {
        if (w->fE % w->f12 == 0)
            func_021ADD7C(w->f8, w->f4);
        if (w->f10 <= w->fE++)
            return 1;
    }
    return 0;
}

M *func_021C7DAC(u32 heap)
{
    M *m = func_02030734(heap, 0x20, 1, d_021DE4FC, 0x7a);
    m->f0 = func_021C8018(heap);
    m->f1C = 0;
    m->f1E = 4;
    func_021C7E58((u32)m->sub);
    return m;
}

void func_021C7DE0(M *m)
{
    if (m != 0) {
        func_021C7E64((u32)m->sub);
        func_021C8054((void *)m->f0);
        func_020307B0(m);
    }
}

extern void (*d_021DAAD0[])(M *m);

void func_021C7DFC(M *m)
{
    if (m != 0) {
        if (m->f1E != 4) {
            d_021DAAD0[m->f1E](m);
            m->f1E = 4;
        }
        if (m->f1C == 2 && func_021C7E90(m->sub))
            m->f1C = 3;
    }
}

void func_021C7E30(M *m)
{
    u32 a;
    if (m != 0) {
        a = func_021C7EEC(m->sub);
        func_021C8078(m->f0, a, func_021C7EF4(m->sub));
    }
}


/*
 * Field setter at +0x1e.
 *
 * Addresses are Black-image addresses.
 */
void func_021C7E50(u8 *p, u16 v)
{
    ((struct Obj18324 *)p)->f1E = v;
}


/*
 * Unlabelled leaf accessor (prints as .word in the listing): returns the u16 at +0x1C (func_021C7E50 sets +0x1E).
 * Sole blocker of ov010 func_0215ECBC's MATCH.
 */
u16 func_021C7E54(Obj *p)
{
    return p->f1c;
}


/*
 * Tail-call thunk: pins arguments 2 and 3 to 0 and 24.
 *
 * Addresses are Black-image addresses.
 */
void func_021C7E58(u32 a)
{
    func_02082BCC(a, 0, 24);
}


void func_021C7E64(u32 a)
{
    func_02082BCC(a, 0, 24);
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021C7E70(u32 a, u32 b, u32 c, u32 d, u32 e0, u32 e1)
{
((struct Obj03529 *)((u8 *)(a)))->f0 = b;
((struct Obj03529 *)((u8 *)(a)))->fC = b;
((struct Obj03529 *)((u8 *)(a)))->f10 = (c - b);
((struct Obj03529 *)((u8 *)(a)))->f4 = d;
((struct Obj03529 *)((u8 *)(a)))->f14 = d;
((struct Obj03529 *)((u8 *)(a)))->f16 = (*(u8 *)((u8 *)((u8 *)&e0)) - d);
((struct Obj03529 *)((u8 *)(a)))->f6 = 0;
((struct Obj03529 *)((u8 *)(a)))->f8 = e1;
return a;
}
