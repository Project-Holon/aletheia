/*
 * file:     iss_zone_sys_p02.c
 * unit:     yes
 * function: func_0202BE54, func_0202BE68, func_0202BEA4, func_0202BEBC, func_0202BECC, func_0202BEDC
 * address:  0x0202BE54
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   _u32_div_f   0x0209C2B0  arm
 */
#include "../../matched/include/Obj03439.h"
#include "../../matched/include/Obj11316.h"
#include "../../matched/include/Obj02602.h"
#include "../../matched/include/Obj03440.h"

struct Obj;
typedef unsigned char u8;

typedef unsigned int  u32;

typedef unsigned short u16;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void  func_0202BEEC(u8 *p, u32 heapId);
extern u32 func_020307B0(void *p);
extern void func_0202BFF0(struct Obj *o);
extern void func_0202BF90(struct Obj *o, u32 key);
extern void func_0202BF54(void);
u32 func_0202BE54(u8 *p, u32 a);
u8 *func_0202BE68(u32 heapId);
void func_0202BEA4(u8 *p);
void func_0202BEBC(u8 *p);
void func_0202BECC(u8 *p, u32 key);
void func_0202BEDC(int a, int b);


/*
 * Returns (p[9] * a) / 0x7f truncated to a byte.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202BE54.c \
 *       --func func_0202BE54 --addr 0x0202BE54 --thumb --cc 1.1p1
 */
u32 func_0202BE54(u8 *p, u32 a)
{
    return (u8)((p[9] * a) / 0x7f);
}


/*
 * Allocates a 0x18-byte iss_zone_sys node through the debug allocator, zeroes
 * its fields with the two exceptions (+0xc takes 0xff, the "no record" index),
 * and runs the init that takes the heap id.
 *
 * The allocator's __FILE__ word is the anchor at 0x0202BEA0, the same
 * 0x020A7748 the sibling func_0202BEEC pools.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202BE68.c \
 *       --func func_0202BE68 --addr 0x0202BE68 --thumb --cc 1.1p1
 */
u8 *func_0202BE68(u32 heapId)
{
    u8 *p = (u8 *)func_02030734(heapId, 0x18, 0, (const void *)0x020A7748,
                                0x55);

    ((struct Obj03439 *)p)->f0 = 0;
    p[4] = 0;
    ((struct Obj03439 *)p)->f8 = 0;
    p[0xc] = 0xff;
    ((struct Obj03439 *)p)->fE = 0;
    ((struct Obj03439 *)p)->f10 = 0;
    ((struct Obj03439 *)p)->f12 = 0;
    ((struct Obj03439 *)p)->f14 = 0;
    func_0202BEEC(p, heapId);
    return p;
}


/*
 * Releases the +8 pointer when set, then the object itself.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202BEA4.c \
 *       --func func_0202BEA4 --addr 0x0202BEA4 --thumb --cc 1.1p1
 */
void func_0202BEA4(u8 *p)
{
    if (*(u32 *)&((struct Obj11316 *)p)->f8 != 0) {
        func_020307B0(((struct Obj11316 *)p)->f8);
    }
    func_020307B0(p);
}


/*
 * Calls func_0202BFF0 when the object's +0 word is set.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202BEBC.c \
 *       --func func_0202BEBC --addr 0x0202BEBC --thumb --cc 1.1p1
 */
void func_0202BEBC(u8 *p)
{
    if (((struct Obj02602 *)p)->f0 != 0) {
        func_0202BFF0((struct Obj *)p);
    }
}


/*
 * Guarded one-argument forward: only when the node's first word is set does
 * func_0202BF90 get called with the node itself.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0202BECC.c \
 *       --func func_0202BECC --addr 0x0202BECC --thumb --cc 1.1p1
 *
 * Closed by the `matched` class: 0x0202BF90 was filed as an EXACT entry this wave (pkt_0202BEBC), matched with the object spelled as a struct.
 */
void func_0202BECC(u8 *p, u32 key)
{
    if (((struct Obj03440 *)p)->f0 != 0) {
        func_0202BF90((struct Obj *)p, key);
    }
}


/*
 * A four-byte tail-call thunk to func_0202BF54: one PROGBITS section per
 * function means this compiler cannot encode a displacement to another
 * function, so the target's address materialises through a literal pool word
 * and a `bx` (docs/idioms/tail-call-is-a-pool-word-and-bx.md).  The pool
 * word's low bit carries the Thumb bit, so the extern is declared Thumb.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202BEDC.c \
 *       --func func_0202BEDC --addr 0x0202BEDC --thumb --cc 1.1p1
 */
void func_0202BEDC(int a, int b)
{
    func_0202BF54();
}
