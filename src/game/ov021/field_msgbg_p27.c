/*
 * file:     field_msgbg_p27.c
 * unit:     yes
 * function: func_0218C7F0, func_0218C860
 * address:  0x0218C7F0
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
 *   func_02030734  0x02030734  arm
 *   func_0218BBD0  0x0218BBD0  thumb  ov021
 *   func_0218BFB4  0x0218BFB4  thumb  ov021
 *   func_0218BA70  0x0218BA70  thumb  ov021
 *   d_021DD9CC     0x021DD9CC  data   ov021  a4
 *   func_0218BA48  0x0218BA48  thumb  ov021
 *   func_0218C0D8  0x0218C0D8  thumb  ov021
 *   func_0218C54C  0x0218C54C  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 */
#include "../../matched/include/Obj04199.h"
#include "../../matched/include/Obj09456.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct Blk {
    u32 w[15];
} Blk;

typedef struct {
    void *owner;
    int f4;
    void *f8;
    unsigned char fC[1];
} S;

extern void *func_02030734(unsigned int heapId, unsigned int size, int clear, const char *site, unsigned short tag);
extern int func_0218BBD0(u8 *owner, u32 x);
extern void func_0218BFB4(u8 *a, u32 *out, u32 *st);
extern void func_0218BA70(u8 *owner, u8 *node);
void func_0218BA48(void *s, void *v);
void func_0218C0D8(void **s);
void func_0218C54C(void *p, int save);
u32 func_020307B0(void *p);
u8 *func_0218C7F0(u8 *owner, u32 x, Blk *src);
void func_0218C860(S *p);
extern u8 d_021DD9CC[];


/*
 * Allocates a 0x60-byte node, copies a 60-byte block into it, registers it.
 *
 * Addresses are Black-image addresses.
 */
u8 *func_0218C7F0(u8 *owner, u32 x, Blk *src)
{
    u8 *p = func_02030734(((struct Obj04199 *)owner)->f0, 0x60, 0, (const char *)d_021DD9CC, 0x825);

    *(u8 * *)&((struct Obj09456 *)p)->f0 = owner;
    ((struct Obj09456 *)p)->f8 = 0;
    ((struct Obj09456 *)p)->f4 = 0xFFFF;
    *(Blk *)(p + 0x24) = *src;
    func_0218BFB4(owner, (u32 *)(p + 0xC),
                  (u32 *)(*(u8 * *)&((struct Obj04199 *)owner)->f1CC + func_0218BBD0(owner, x) * 0x18));
    func_0218BA70(owner, p);
    return p;
}


void func_0218C860(S *p)
{
    if (p != 0) {
        func_0218BA48(p->owner, p);
        func_0218C0D8((void **)p->fC);
        if (p->f8 != 0)
            func_0218C54C(p->f8, 1);
        func_020307B0(p);
    }
}
