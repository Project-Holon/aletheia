/*
 * function: func_0200725C
 * address:  0x0200725C
 * packet:   pkt_02007248
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0200725C_Table  0x0209D950  data
 *   func_02008784        0x02008784  thumb
 *   func_020087D4        0x020087D4  thumb
 *   func_0203192C        0x0203192C  arm
 *   func_02031DC0        0x02031DC0  arm
 *
 * One of nine save-stream slots the save_control block tracks at +0x14.
 * The slot is opened through the backup-system stream constructor, the open
 * is checked by func_02008784, and on success the record is committed by
 * func_02031DC0.
 *
 * Two findings closed this function and its sibling (the other of the pair
 * is noted in each file):
 *
 * 1. func_02031DC0's second and third arguments are (heap, buf), NOT
 *    (buf, heap).  The image names the order directly: heap is loaded into
 *    r1 from its stack home and the func_020087D4 result is dereferenced
 *    into r2.  Every statement reordering, temporary and pointer/type
 *    variation leaves a flat 5-byte residue at exactly those two loads --
 *    tools/permuter.py could not move it at all in 74 (0x0200725C) and 90
 *    (0x020072CC) mutations -- because the residue is in the DECLARATION,
 *    not the body.  Compare src/matched/func_02031DC0.c, whose own
 *    parameters are (Obj *, u32 a1, u32 a2) with a1 passed straight to
 *    func_02031FE0/func_02032688; this file fixes which of the two is heap.
 *
 * 2. The heap parameter is u8, not u32.  With u32 the constant set-up sinks
 *    past the incoming spill (`str r2, [sp]` moves four halfwords later),
 *    which is the residue docs/notes recorded for both functions and which
 *    src/matched/unit_020072A4.c's header describes as unexplained.  It is
 *    a heap id, a small byte value, and narrowing the PARAMETER is what
 *    closes it: a u32 parameter with a u8 local copy, or a u8 in the callee
 *    prototype alone, both stay DIFF.  The matched callers
 *    (src/matched/unit_0200B4E0.c, unit_0200B5CC.c) spell the argument u32;
 *    that is a caller-side widening and does not contradict this, but the
 *    conflict is recorded here rather than silently resolved.
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Desc {
    u8 data[0x18];
};

struct Ctrl {
    u8    unk00;
    u8    unk01;
    u8    unk02;
    u8    unk03;
    u8    unk04;
    u8    unk05;
    u8    pad06[6];
    u32   unk0C;
    void *unk10;
    void *unk14[9];
};

extern struct Desc func_0200725C_Table[];

extern u32 func_0203192C(void *a, void *b);
struct Obj02031DC0;
extern int func_02008784(void *sys, u32 index);
extern u32 *func_020087D4(void *sys, u32 index);
extern int func_02031DC0(struct Obj02031DC0 *a0, u32 a1, u32 a2);

u32 func_0200725C(struct Ctrl *ctrl, u32 id, u8 heap)
{
    ctrl->unk14[id] = (void *)func_0203192C(&func_0200725C_Table[id], (void *)heap);
    if (func_02008784(ctrl, id) == 0) {
        return 0;
    }
    func_02031DC0(ctrl->unk14[id], heap, *func_020087D4(ctrl, id));
}
