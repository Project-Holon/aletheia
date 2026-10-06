/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/000_02004000.s.
 *
 * unit:     yes
 * address:  0x02007084
 * packet:   pkt_02006E40
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: sub_02007084, sub_020070A4
 *
 * symbols:
 *   sub_02007084_Ptr    0x02146168  data
 *   sub_020070A4_File   0x020A7064  data
 *   func_020307B0       0x020307B0  arm
 *   func_0203195C       0x0203195C  arm
 *   func_02034714       0x02034714  arm
 *
 * alias: this is "save_control.c".  The constructor of the object these two
 * reach, sub_02006F20 at the head of the same original file, passes
 * 0x020A7054 to the debug allocator, and the bytes at 0x020A7054 spell
 * "save_control.c".  That function is a near miss and is not in this tree;
 * see the header of src/matched/unit_020071E4.c for the census.
 *
 * The teardown and the checked getter for the one global the file keeps: a
 * pointer at 0x02146168 to the 0x38 byte control block.  sub_020070A4 loads
 * that pointer twice out of one pool word, once for the assertion and once
 * for the result, which is what a global read either side of a call looks
 * like.
 *
 * The range stops at 0x020070C8 for an evidence reason.  sub_020070C8, 134
 * bytes, is the per-frame step of the same object and it calls
 * sub_020087C0, whose only branch anywhere in the 3.9 MB image is the `bl`
 * at 0x02007140 inside it: `label` has one witness and it is in the bytes
 * under test, `literal` sees no pool word naming the address at all, and no
 * cut can move the caller out of the range that contains it.  It closes the
 * day anything else in the image calls 0x020087C0.
 *
 * 0x020A7064 is the empty string, not a file name.  "save_control.c" ends
 * with its NUL at 0x020A7062 and the next twelve bytes are NUL up to
 * "box_savedata.c" at 0x020A706C, so the assertion helper at 0x02034714 is
 * being passed an empty message here and at six further sites in the same
 * original file.  The address is carried by the `literal` class: the pool
 * word at 0x02007080, inside sub_02006F20 and so outside this range, holds
 * it too.
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Sub02007084Ctrl {
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

extern struct Sub02007084Ctrl *sub_02007084_Ptr;
extern const char sub_020070A4_File[];

extern u32 func_020307B0(void *p);
extern void func_0203195C(u8 *p);
extern void func_02034714(const char *expr, u32 line, const char *file);

void sub_02007084(void)
{
    if (sub_02007084_Ptr != 0) {
        func_0203195C(sub_02007084_Ptr->unk10);
        func_020307B0(sub_02007084_Ptr);
        sub_02007084_Ptr = 0;
    }
}

struct Sub02007084Ctrl *sub_020070A4(void)
{
    if (sub_02007084_Ptr == 0) {
        func_02034714(sub_020070A4_File, 0, sub_020070A4_File);
    }
    return sub_02007084_Ptr;
}
