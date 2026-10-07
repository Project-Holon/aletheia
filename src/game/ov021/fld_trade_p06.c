/*
 * file:     fld_trade_p06.c
 * unit:     yes
 * function: func_021CCF7C, func_021CCFC0, func_021CCFD8, func_021CCFE4, func_021CCFF8, func_021CD004
 * address:  0x021CCF7C
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
 *   func_02020D0C  0x02020D0C  thumb
 *   func_02020298  0x02020298  thumb
 *   func_02190F64  0x02190F64  thumb  ov021
 *   func_02190E40  0x02190E40  thumb  ov021
 *   func_02190E74  0x02190E74  thumb  ov021
 *   func_02190EF0  0x02190EF0  thumb  ov021
 *   func_02190708  0x02190708  thumb  ov021
 */
#include "../../matched/include/Obj18359.h"
#include "../../matched/include/Obj18361.h"

struct Obj;
struct Fx;
struct Obj2;
typedef struct {
    int pad[4];
    int f10;
} Info;

typedef unsigned int   u32;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef struct {
    u8 pad0[0xa4];
    void *fA4;
    void *fA8;
    u8 padAC[4];
    void *fB0;
    void *fB4;
} Work;

typedef signed short   s16;

typedef signed char    s8;

extern u32 func_02020D0C(unsigned char *p);
extern void func_02020298(struct Obj *obj, u8 a, u8 b, u8 c);
extern struct Obj2 *func_02190F64(struct Fx *a, u32 b);
extern int func_02190E40(u32 a);
extern u32 func_02190E74(u32, u32, u32, u32);
extern u32 func_02190EF0(u32 *p);
extern void *func_02190708(struct Fx *p, u32 a, u16 b, u16 c, u16 d, u16 e);
void func_021CCF7C(void *p, int k);
void func_021CCFC0(Work *w);
void func_021CCFD8(u8 *p);
int func_021CCFE4(u32 a, u32 b);
int func_021CCFF8(u8 *p);
void func_021CD004(Work *w);


void func_021CCF7C(void *p, int k)
{
    Info *i = (Info *)func_02020D0C(p);

    if (k == 0 && i->f10 == 1) {
        func_02020298(p, 1, 0, 2);
        return;
    }
    if (k == 1) {
        func_02020298(p, 1, 0, 2);
        return;
    }
    func_02020298(p, 1, 0, 2);
}


/*
 * Builds the +0xB0 handle of the work block from its +0xA4 object and +0xA8 entry.
 *
 * Addresses are Black-image addresses.
 */
void func_021CCFC0(Work *w)
{
    w->fB0 = func_02190F64(w->fA4, (u32)w->fA8);
}


/*
 * Tail call on the word at +0xb0.
 *
 * Addresses are Black-image addresses.
 */
void func_021CCFD8(u8 *p)
{
    func_02190E40(((struct Obj18359 *)p)->fB0);
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021CCFE4(u32 a, u32 b)
{
return func_02190E74(*(u32 *)((u8 *)((a + 176))), 0, 0, b);
}


int func_021CCFF8(u8 *p)
{
    return func_02190EF0((u32 *)(((struct Obj18361 *)p)->fB0));
}


/*
 * Creates the +0xB4 handle of the work block once, from its +0xA4 object and +0xA8 entry.
 *
 * Addresses are Black-image addresses.
 */
void func_021CD004(Work *w)
{
    if (w->fB4 == 0)
        w->fB4 = func_02190708(w->fA4, (u32)w->fA8, 1, 2, 0x1e, 6);
}
