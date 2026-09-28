/*
 * function: func_0204DCA8
 * address:  0x0204DCA8
 * packet:   pkt_0204D768
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Closes the other of the two clact.c fan-in-1 blockers of func_0204D7E0
 * documented in docs/notes/clact_c_fan_in_1_blockers.c.txt (the other is
 * func_0204DA5C, this packet's previous function).
 *
 * Allocate `count` 0x18-byte records and set bit 31 of the word at +0x14
 * of each (a one-bit bitfield; the unconditional `bic`/`orr` pair of the
 * same immediate is the bitfield-store tell, same shape as
 * func_0204DA5C's +0x3c field).
 *
 * The record size 0x18 is a real `mul` against a register, not a shift
 * pair, because 0x18 is not a power of two; the per-record address inside
 * the loop is then one `mla`.
 *
 * symbols:
 *   s_clact_c  0x020A7F74  data
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204DCA8.c \
 *       --func func_0204DCA8 --addr 0x0204DCA8 --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Rec {
    u8  pad_00[0x14];
    u32 unk_14_0  : 31;     /* 0x14 */
    u32 unk_14_31 : 1;
};

extern void *sub_02030734(u32 heapId, u32 size, int clear, const char *file, u16 line);

extern char s_clact_c[];

void *func_0204DCA8(u32 heapId, u32 count)
{
    u32 i;
    struct Rec *arr;

    arr = sub_02030734(heapId, count * sizeof(struct Rec), 0, s_clact_c, 0x1c58);

    for (i = 0; i < count; i++) {
        arr[i].unk_14_31 = 1;
    }

    return arr;
}
