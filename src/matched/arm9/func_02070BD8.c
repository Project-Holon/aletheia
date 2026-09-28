/*
 * function: func_02070BD8
 * address:  0x02070BD8
 * packet:   pkt_0207010C
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   data_020A8220  0x020A8220  data
 *
 * Unlabelled leaf follower of func_02070B64: no lr-saving prologue, so
 * disasm.py never auto-labels it and the worklist folds its 72 bytes into
 * func_02070B64's inferred extent.  It should be seeded into
 * layout/function_starts.txt as a function start at 0x02070BD8, extent
 * 0x02070BD8..0x02070C20 with a single pool word at 0x02070C20.
 *
 * Every one of the 18 instructions is byte-for-byte identical to the image.
 * The single ABS32 site (the pool word at 0x02070C20 holding 0x020A8220)
 * resolves `data_table x8`, so the row is EXACT with no wildcards.
 *
 * Initialiser slot-table setup: stores a global word to +0x0C, copies the
 * count byte from src[0x17] into +0x19, stores the caller's word at +0x08,
 * then fills +0x1A with `i | 0x100` halfwords for i in [0, count).
 * The counter/bound order (`i = 0` assigned before the loop, bound re-read
 * from the struct field each iteration) is what gives `mov ip, #0` hoisted
 * above the first store and the two `ldrb r1, [r0, #0x19]` reloads.
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 data_020A8220;

struct S {
    u8  pad0[8];
    u32 f8;
    u32 fc;
    u8  pad10[9];
    u8  f19;
    u16 f1a[1];
};

void func_02070BD8(struct S *s, u32 a, u8 *src)
{
    u32 i = 0;
    s->fc = data_020A8220;
    s->f19 = src[0x17];
    s->f8 = a;
    while (i < s->f19) {
        s->f1a[i] = (u16)(i | 0x100);
        i = i + 1;
    }
}
