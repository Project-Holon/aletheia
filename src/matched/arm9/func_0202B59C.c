/*
 * function: func_0202B59C
 * address:  0x0202B59C
 * packet:   pkt_0202B59C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Parked: five of the six initialisers resolve as `matched` (0x0202B5FC,
 * 0x0202B610, 0x0202B624, 0x0202B63C, 0x0202B65C).  The one that does not is
 * 0x0202B64C at +002A, which is itself capped on 0x0202C070, which is capped
 * on 0x0202C148 (DIFF).  Every concrete byte reproduces; the C is final.
 *
 * Constructor hub: fills the four word/halfword members of a node and runs
 * its six initialisers in order.
 *
 * symbols:
 *   func_0202B5FC  0x0202B5FC  thumb
 *   func_0202B610  0x0202B610  thumb
 *   func_0202B624  0x0202B624  thumb
 *   func_0202B63C  0x0202B63C  thumb
 *   func_0202B64C  0x0202B64C  thumb
 *   func_0202B65C  0x0202B65C  thumb
 */
#include "../include/Obj00563.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Obj;
extern void func_0202B5FC(struct Obj *o);
extern void func_0202B610(struct Obj *o);
extern void func_0202B624(struct Obj *o);
extern void func_0202B63C(struct Obj *o);
extern void func_0202B64C(struct Obj *o);
extern void func_0202B65C(struct Obj *o);

struct SaveBlock;

void func_0202B59C(u8 *p, struct SaveBlock *a, u32 b)
{
    ((struct Obj00563 *)p)->f4  = (u32)a;
    ((struct Obj00563 *)p)->f8  = 0xffffffff;
    ((struct Obj00563 *)p)->f0  = (u16)b;
    ((struct Obj00563 *)p)->fC = 0;

    func_0202B5FC((struct Obj *)p);
    func_0202B610((struct Obj *)p);
    func_0202B624((struct Obj *)p);
    func_0202B63C((struct Obj *)p);
    func_0202B64C((struct Obj *)p);
    func_0202B65C((struct Obj *)p);
}
