/*
 * function: BILLBOARD_ACT_GetControlHandler
 * address:  0x02050984
 * packet:   pkt_02050984
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * PROMOTED from src/pending/BILLBOARD_ACT_GetControlHandler.c 2026-09-21 (wave 4, billboard_act).
 * The C is UNCHANGED: it was parked at MATCH* because three of its four ABS32
 * pool words -- 0x020509E0, 0x02050A00 and 0x02050A58 -- each had exactly one
 * mention image wide, the pool word inside this very function, so neither
 * `label` nor `literal` reached them.  All three handlers are now filed EXACT
 * (src/matched/BILLBOARD_ACT_CmdEnd.c, BILLBOARD_ACT_CmdLoop.c, BILLBOARD_ACT_CmdJump.c, shard
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
 * symbols:
 *   BILLBOARD_ACT_CmdJump  0x02050A58  arm
 *   BILLBOARD_ACT_CmdLoop  0x02050A00  arm
 *   BILLBOARD_ACT_CmdSetList  0x020509E8  arm
 *   BILLBOARD_ACT_CmdEnd  0x020509E0  arm
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BILLBOARD_ACT_GetControlHandler.c \
 *       --func BILLBOARD_ACT_GetControlHandler --addr 0x02050984 --cc 1.1p1 --arm
 */

typedef void (*Fn)(void);
typedef unsigned int u32;

struct Cmd;
struct Ent;
extern int BILLBOARD_ACT_CmdJump(struct Ent *e, struct Cmd *c);
extern int BILLBOARD_ACT_CmdLoop(struct Ent *e, struct Cmd *c);
extern int BILLBOARD_ACT_CmdSetList(void *p, void *q);
extern int BILLBOARD_ACT_CmdEnd(void);

Fn BILLBOARD_ACT_GetControlHandler(u32 id)
{
    switch (id) {
    case 0x3FFF: return (Fn)BILLBOARD_ACT_CmdEnd;
    case 0x3FFE: return (Fn)BILLBOARD_ACT_CmdSetList;
    case 0x3FFD: return (Fn)BILLBOARD_ACT_CmdLoop;
    case 0x3FFC: return (Fn)BILLBOARD_ACT_CmdJump;
    }
    return 0;
}
