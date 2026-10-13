/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/000_02004000.s.
 *
 * unit:     yes
 * address:  0x020071CC
 * packet:   pkt_02006E40
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: SAVE_CONTROL_GetBlock
 *
 * symbols:
 *   BACKUP_SYSTEM_GetRecordWork  0x020319A4  arm
 *
 * One function, twelve bytes, and it is the block lookup every save accessor
 * in this region goes through: src/matched/unit_02007454.c, unit_02007664.c,
 * unit_02007774.c, unit_020079BC.c and unit_02007AC8.c all reach their data
 * through it.  It is a tail call, so it has no prologue and no label of its
 * own beyond the one disasm.py's cross-reference pass gave it; see
 * docs/idioms/tail-call-is-a-pool-word-and-bx.md.
 *
 * It is a file of its own for an evidence reason rather than a structural
 * one.  The twelve bytes on either side of it, 0x020071C0 and 0x020071D8,
 * are the same shape with the same object and tail-call the ARM addresses
 * 0x02031E68 and 0x02031994.  Neither of those two carries a `func_` label:
 * they open `ldr r0, [r0, #0x144]` and `ldr r2, [r0, #0x30]` with no
 * register-saving prologue, so disasm.py's sweep never fires on them, and
 * the only word in the whole image that names either is the pool word of the
 * caller under test.  `literal` therefore discards its own witness and
 * neither address can be attested, so both functions are left out and this
 * one is cut free between them.  0x020319A4, by contrast, is a labelled ARM
 * function reached by `bl` from 0x02032B10 and 0x02032C5C, which is the
 * `label` class with two witnesses outside any range here.
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Sub020071CCCtrl {
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

extern u32 BACKUP_SYSTEM_GetRecordWork(u8 *p, u32 id);

void *SAVE_CONTROL_GetBlock(struct Sub020071CCCtrl *ctrl, u32 id)
{
    return (void *)BACKUP_SYSTEM_GetRecordWork(ctrl->unk10, id);
}
