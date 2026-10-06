/*
 * file:     particle_p06.c
 * unit:     yes
 * function: func_02050944, func_02050984, func_020509E0, func_020509E8
 * address:  0x02050944
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02050A58  0x02050A58  arm
 *   func_02050A00  0x02050A00  arm
 */
#include "../../matched/include/Obj16163.h"
#include "../../matched/include/Obj02611.h"
#include "../../matched/include/Obj16164.h"

struct Cmd;
struct Ent;
typedef unsigned short u16;

struct S14 {
    u16 f : 14;
};

typedef void (*Fn)(void);

typedef unsigned int u32;

extern int func_02050A58(struct Ent *e, struct Cmd *c);
extern int func_02050A00(struct Ent *e, struct Cmd *c);
extern void func_020500A0(int p0);
Fn func_02050984(u32 id);
int func_020509E0(void);
int func_020509E8(void *p, void *q);


/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02050944.c \
 *       --func func_02050944 --addr 0x02050944 --cc 1.1p1 --arm
 */
int func_02050944(void *p, struct S14 *q)
{
    int (*fn)(void *, struct S14 *);

    fn = (int (*)(void *, struct S14 *))func_02050984(q->f);
    ((struct Obj16163 *)p)->f1C = q->f;
    return fn(p, q);
}


/*
 * PROMOTED from src/pending/func_02050984.c 2026-09-21 (wave 4, billboard_act).
 * The C is UNCHANGED: it was parked at MATCH* because three of its four ABS32
 * pool words -- 0x020509E0, 0x02050A00 and 0x02050A58 -- each had exactly one
 * mention image wide, the pool word inside this very function, so neither
 * `label` nor `literal` reached them.  All three handlers are now filed EXACT
 * (src/matched/func_020509E0.c, func_02050A00.c, func_02050A58.c, shard
 * arm9/pkt_02050984.json), so every site resolves by the `matched` class and
 * this file verifies EXACT* with no edit to the body.
 *
 * EXACT*, not EXACT: the listing's extent runs 100 bytes because the follower
 * at 0x020509E0 is reached only through this function's own pool word and has
 * no prologue that saves lr, so disasm.py does not label it.  Report
 * 0x020509E0 as a seed for layout/function_starts.txt; it is never a byte
 * difference.
 *
 * The switch normalises the id with two subtracts and no `mov` of the base,
 * which is the whole reason the case labels read 0x3FFC..0x3FFF: the image
 * subtracts 0x3FC and then 0x3C00, i.e. 0x3FFC, and spelling the cases
 * 0x43FC..0x43FF makes the second subtract `#0x4000` and the four case arms
 * come out in the wrong order.  Writing the cases in DESCENDING source order
 * is what reproduces the image's arm order (case 0x3FFF's arm nearest the
 * table); ascending order puts case 0x3FFC's arm there and differs in four
 * branch instructions.
 *
 * `return <function address>;` is the shape: each arm is `ldr r0, [pc, #n];
 * bx lr` and the fall-through is `mov r0, #0; bx lr`.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02050984.c \
 *       --func func_02050984 --addr 0x02050984 --cc 1.1p1 --arm
 */
Fn func_02050984(u32 id)
{
    switch (id) {
    case 0x3FFF: return (Fn)func_020509E0;
    case 0x3FFE: return (Fn)func_020509E8;
    case 0x3FFD: return (Fn)func_02050A00;
    case 0x3FFC: return (Fn)func_02050A58;
    }
    return 0;
}

/*
 * The second arm of the four-entry handler table func_02050984 dispatches
 * through (its pool word at 0x020509D0).  Eight bytes, a leaf that returns the
 * nonzero constant the dispatch caller tests, and one of the pool words that
 * keeps src/pending/func_02050984.c wildcarded until it has an EXACT entry.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020509E0.c \
 *       --func func_020509E0 --addr 0x020509E0 --cc 1.1p1 --arm
 */
int func_020509E0(void)
{
    return 1;
}


/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020509E8.c \
 *       --func func_020509E8 --addr 0x020509E8 --cc 1.1p1 --arm
 */
int func_020509E8(void *p, void *q)
{
    ((struct Obj02611 *)p)->fE = ((struct Obj16164 *)q)->f2;
    func_020500A0((int)p);
    return 0;
}
