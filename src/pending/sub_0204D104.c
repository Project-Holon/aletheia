/*
 * function: sub_0204D104
 * address:  0x0204D104
 * packet:   pkt_0204CA74
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * symbols:
 *   gUnk_020A13D0  0x020A13D0  data
 *   MI_CpuFill8    0x02082BCC  arm
 *
 * Destructor for the 0x7c-byte sub-object embedded at +0x68 of the
 * 0x0204Bxxx owner: dispatch on the kind tag in word 0 through the handler
 * table at 0x020A13D0, then wipe the whole record.  `blx` rather than `bl`
 * because the table entries may be Thumb.
 *
 * Blocked at MATCH: every concrete byte is right, but the ABS32 pool word
 * for the handler table 0x020A13D0 has no witness.  That address appears in
 * no other literal pool in the image, so the `literal` class is unavailable
 * and no other class applies to plain data.  This file was written to serve
 * as a `matched` witness for sub_0204B3B4's only call site, which it cannot
 * do while it is MATCH; src/pending/sub_0204B3B4.c records the other half.
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Dispatchable {
    u32 kind;
};

extern void (*const gUnk_020A13D0[])(struct Dispatchable *);
extern void MI_CpuFill8(void *dest, u8 data, u32 size);

void sub_0204D104(struct Dispatchable *p)
{
    gUnk_020A13D0[p->kind](p);
    MI_CpuFill8(p, 0, 0x7c);
}
