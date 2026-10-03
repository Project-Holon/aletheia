/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/000_02004000.s.
 *
 * unit:     yes
 * address:  0x02007324
 * packet:   pkt_02006E40
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: sub_02007324, sub_0200734C
 *
 * symbols:
 *   sub_02007324_Table  0x0209D950  data
 *   sub_0200734C_File   0x020A7064  data
 *   func_0203195C       0x0203195C  arm
 *   func_02031948       0x02031948  arm
 *   func_02034714       0x02034714  arm
 *
 * The open-for-write that does not register the stream afterwards, and a
 * second copy of the close.  sub_02007324 passes zero where sub_020072CC
 * passes one as the fifth argument of func_02031948, and stores the result
 * with a plain `str r0, [r1, #0x14]` rather than through the `+0x14` base
 * register the other accessors build, because the slot is written once and
 * never read back in this function.
 *
 * 0x0209D950 is the table of 0x18 byte stream descriptors, indexed by the
 * stream id and passed by address.  Three pool words in this original file
 * name it, at 0x020072A0, 0x02007320 and 0x02007348, and the first two are
 * outside this range, which is what carries it under the `literal` class.
 * func_02031948 is likewise reached from exactly two places in the image,
 * 0x020072EE and 0x0200733C, so the cut at 0x02007324 is what leaves the one
 * inside this range a witness.
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Sub02007324Desc {
    u8 data[0x18];
};

struct Sub02007324Ctrl {
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

extern struct Sub02007324Desc sub_02007324_Table[];
extern const char sub_0200734C_File[];

extern void *func_02031948(struct Sub02007324Desc *desc, u32 heap, u32 a,
                           u32 b, u32 c);
extern void func_0203195C(u8 *p);
extern void func_02034714(const char *expr, u32 line, const char *file);

void sub_02007324(struct Sub02007324Ctrl *ctrl, u32 id, u32 heap, u32 a,
                  u32 b)
{
    ctrl->unk14[id] = func_02031948(&sub_02007324_Table[id], heap, a, b, 0);
}

void sub_0200734C(struct Sub02007324Ctrl *ctrl, u32 id)
{
    if (ctrl->unk14[id] == 0) {
        func_02034714(sub_0200734C_File, 0, sub_0200734C_File);
    }
    func_0203195C(ctrl->unk14[id]);
    ctrl->unk14[id] = 0;
}
