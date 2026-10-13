/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/000_02004000.s.
 *
 * unit:     yes
 * address:  0x020072A4
 * packet:   pkt_02006E40
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: SAVE_CONTROL_DeleteExtraSave
 *
 * symbols:
 *   sub_020072A4_File   0x020A7064  data
 *   BACKUP_SYSTEM_Delete       0x0203195C  arm
 *   func_02034714       0x02034714  arm
 *
 * The close of one of the nine save streams the save_control block tracks at
 * +0x14.  The slot is asserted non-null and then cleared, and the assertion
 * message is the empty string at 0x020A7064, the same one six other
 * functions of this original file pass.  SAVE_CONTROL_DeleteExtraSaveBuffered in
 * src/matched/unit_02007324.c is the same function again on the same slot
 * array with its own pool word, which is what says these are two entry
 * points and not one.
 *
 * Two near misses bracket this range and neither is an evidence problem.
 *
 * 0x0200725C, 72 bytes, and 0x020072CC, 88 bytes, are the matching opens.
 * Both reproduce every instruction, every register and the whole of their
 * control flow, and both are wrong only in where the incoming third argument
 * is spilled.  The original stores it to its stack home as the first thing
 * the body does and then loads it back at each use (`str r2, [sp]` then
 * `ldr r1, [sp]` in 0x0200725C, `str r2, [sp, #4]` then two `ldr r1,
 * [sp, #4]` in 0x020072CC); this compiler keeps the value in r2 for the
 * first use and sinks the store past the constant set-up, which is 10 bytes
 * in the first function and 7 in the second, all of them in the four
 * halfwords around the spill.  Thirty source shapes were tried against each,
 * crossing the parameter types, pointer temporaries for the slot and the
 * descriptor, statement splitting, the prototype arity of BACKUP_SYSTEM_Create and
 * BACKUP_SYSTEM_CreateWithWork, a struct-by-value parameter and an address-taken one; every
 * one of them lands on the same two counts except the shapes that change the
 * function outright.  A `volatile` local closes 0x0200725C and makes
 * 0x020072CC worse, so it is a coincidence and not the answer, and it is not
 * a claim the bytes support.  All nine front ends at -O4,p agree with each
 * other here, so it is not a version question either.
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Sub020072A4Ctrl {
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

extern const char sub_020072A4_File[];

extern void BACKUP_SYSTEM_Delete(u8 *p);
extern void func_02034714(const char *expr, u32 line, const char *file);

void SAVE_CONTROL_DeleteExtraSave(struct Sub020072A4Ctrl *ctrl, u32 id)
{
    if (ctrl->unk14[id] == 0) {
        func_02034714(sub_020072A4_File, 0, sub_020072A4_File);
    }
    BACKUP_SYSTEM_Delete(ctrl->unk14[id]);
    ctrl->unk14[id] = 0;
}
