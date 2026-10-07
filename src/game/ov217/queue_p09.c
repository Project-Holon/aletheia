/*
 * file:     queue_p09.c
 * unit:     yes
 * function: func_021C0E78, func_021C0E98, func_021C0EA4, func_021C0EC0, func_021C0EDC, func_021C0EE4
 * address:  0x021C0E78
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 *   _s32_div_f  0x0209C0A4  arm
 *   _u32_div_f  0x0209C0A4  arm
 */
#include "../../matched/include/Obj06714.h"
#include "../../matched/include/Obj26003.h"
#include "../../matched/include/Obj06715.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed char    s8;

typedef signed short   s16;

typedef signed int     s32;

struct Ring {
    u32 *buf;
    u32 count;
    u32 pos;
};

typedef struct {
    u32 w[2];
    u32 a;
    u32 b;
} Rec;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern int _s32_div_f(int, int);
void func_021C0E78(u32 a0, u32 a1, u32 a2);
void func_021C0E98(u8 *a0);
void func_021C0EA4(char *p, int v);
u32 func_021C0EC0(struct Ring *r);
void func_021C0EDC(Rec *p);
int func_021C0EE4(Rec *p);

/*
 * Reconstructed from the listing (.inst decoded).
 *
 * Addresses are Black-image addresses.
 */
void func_021C0E78(u32 a0, u32 a1, u32 a2)
{
    ((struct Obj06714 *)((u8*)a0))->f0 = (u32)func_02030734(a2, ((u32)a1 << 2), 0, (const char *)0x21C4050, 211);
    ((struct Obj06714 *)(((u8*)a0)))->f4 = a1;
}


void func_021C0E98(u8 *a0)
{
    func_020307B0((void *)((u32)(((struct Obj26003 *)a0)->f0)));
}


/*
 * Addresses are Black-image addresses.
 */
void func_021C0EA4(char *p, int v)
{
    *(int *)(((struct Obj06715 *)p)->f0 + ((struct Obj06715 *)p)->fC * 4) = v;
    ((struct Obj06715 *)p)->fC = (((struct Obj06715 *)p)->fC + 1) % ((struct Obj06715 *)p)->f4;
}


u32 func_021C0EC0(struct Ring *r)
{
    u32 v;
    v = r->buf[r->pos];
    r->pos = (r->pos + 1) % r->count;
    return v;
}


/*
 * Clears two words of a record.  Reached only from the tail-call veneer
 * func_021C0E5C.
 *
 * Addresses are Black-image addresses.
 */
void func_021C0EDC(Rec *p)
{
    p->a = 0;
    p->b = 0;
}


/*
 * Whether two words of a record are equal.  Reached only from the tail-call
 * veneer func_021C0E64.
 *
 * Addresses are Black-image addresses.
 */
int func_021C0EE4(Rec *p)
{
    return p->a == p->b;
}
