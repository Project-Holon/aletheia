/*
 * unit:     yes
 * function: func_0202B7F8, func_0202B804, func_0202B810
 * address:  0x0202B7F8
 * packet:   pkt_0202B7BC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The three iss_3ds_sys.c tail-call units that resolve without any further
 * work: func_0202B7F8 forwards the +4 field to func_020127A4,
 * func_0202B804 chains it into func_02012AC8, and func_0202B810 is a bare
 * thunk to func_02005C44.  All three are named in the `function:` field
 * above so that the `matched` class attests all three addresses: the 32
 * bytes laid out by `tu` cover all three entry points, and
 * src/pending/func_0202B744.c needs 0x0202B804 as a witness.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0202B7F8.c \
 *       --addr 0x0202B7F8 --thumb --cc 1.1p1
 */
#include "../include/Obj17267.h"

typedef unsigned char u8;
typedef unsigned int  u32;

struct Obj;
struct SaveBlock;
struct Rec44;

extern void *func_020127A4(struct SaveBlock *p);
typedef unsigned short u16;
extern u16 func_02012AC8(const struct Rec44 *p);
extern u16 func_02005C44(void);

void *func_0202B7F8(struct Obj *o)
{
    return func_020127A4((struct SaveBlock *)((struct Obj17267 *)o)->f4);
}

u16 func_0202B804(struct Obj *o)
{
    return func_02012AC8(func_0202B7F8(o));
}

u16 func_0202B810(void)
{
    return func_02005C44();
}
