/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/000_02004000.s.
 *
 * unit:     yes
 * address:  0x020073D8
 * packet:   pkt_02006E40
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: sub_020073D8
 *
 * symbols:
 *   sub_020073D8_File  0x020A7064  data
 *   func_020319A4      0x020319A4  arm
 *   func_02034714      0x02034714  arm
 *
 * One checked forwarder on the stream slot array: the slot is asserted
 * non-null with the empty string at 0x020A7064 and then handed to the ARM
 * func_020319A4 with the caller's value.
 *
 * The function immediately after it, sub_02007400 at 0x02007400, is the same
 * twenty instructions against func_020319F0 and is left out.  Its callee is
 * named twice in the whole image: by the `blx` at 0x0200741E inside it, and
 * by the pool word at 0x02007238 in sub_02007230.  A pool word only counts
 * under the `literal` class, which requires the word to sit at an address
 * disasm.py classified as a literal pool, and 0x02007238 is inside an
 * unlabelled tail-call function rather than a pool, so it is not admitted.
 * The `label` class therefore has the one `blx`, which is inside whatever
 * range holds sub_02007400, and no cut can move it out.  The direction that
 * does work is the other one: src/matched/unit_020071E4.c holds the pool
 * word and takes that same `blx` as its outside witness, which is why the
 * accessor run stops at 0x02007248 and this range starts at 0x020073D8.
 *
 * The two functions immediately below this range, 0x02007374 and 0x020073B0,
 * are left out for the plainer version of the same reason.  Each is the only
 * thing in the image that names its callee: 0x02031C10 is reached only from
 * the `blx` at 0x020073A6 inside sub_02007374, and 0x02031C30 only from
 * 0x020073CE inside sub_020073B0.  The witness is in both cases the call
 * itself, so shrinking the range to the one function keeps it inside, and
 * the target is ARM library code that cannot be made `local`.  The same
 * argument leaves out 0x02007248, whose callee 0x020334E8 is named once, by
 * the `blx` at 0x02007252 inside it, and 0x02007150, 0x02007168 and
 * 0x020071A8, whose callees 0x02031B8C, 0x02031BB4 and 0x02031C04 are each
 * named once in the same way.  All six close the day something else in the
 * image calls those addresses.
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Sub020073D8Ctrl {
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

extern const char sub_020073D8_File[];

extern void *func_020319A4(void *stream, u32 v);
extern void func_02034714(const char *file, int line, const char *msg);

void *sub_020073D8(struct Sub020073D8Ctrl *ctrl, u32 id, u32 v)
{
    if (ctrl->unk14[id] == 0) {
        func_02034714(sub_020073D8_File, 0, sub_020073D8_File);
    }
    return func_020319A4(ctrl->unk14[id], v);
}
