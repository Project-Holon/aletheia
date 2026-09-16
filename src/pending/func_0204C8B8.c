/*
 * unit:     no
 * function: func_0204C8B8
 * address:  0x0204C8B8
 * packet:   pkt_0204BD64
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * symbols:
 *   g_020A138C     0x020A138C  data
 *   DC_FlushRange  0x020862F0  arm
 *
 * Blocked at MATCH: all 44 concrete bytes are correct, but the ABS32 at
 * +0x0028 (the handler table at 0x020A138C) has no witness.  The table is
 * plain data, so only the `literal` class could attest it, and the pool word
 * inside this function is the address's only occurrence image wide; there is
 * no second site.  The same wall docs/notes/clact_c_fan_in_1_blockers.c.txt
 * describes for 0x0204C83C, but without its escape: there the address was a
 * function that could be decompiled to EXACT and become a `matched` witness,
 * here it is a table and nothing compiles it.
 *
 * Run one 16-byte transfer record: flush the source range out of the data
 * cache, then dispatch on the record's fourth word through the handler table
 * at 0x020A138C, passing the other three words.
 *
 * The four words are read back with a single `ldm r4, {r0, r1, r2, ip}`,
 * which is the compiler combining four consecutive field loads, not a struct
 * copy: the first and third are loaded a second time here because
 * DC_FlushRange may have written them.
 *
 * This function is the sole blocker for src/pending/func_0204C7A4.c, whose
 * only call to it is the one branch reference it has image wide.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0204C8B8.c \
 *       --func func_0204C8B8 --addr 0x0204C8B8 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

struct Xfer {
    void *src;
    u32   unk_04;
    u32   size;
    u32   kind;
};

extern void (*g_020A138C[])(void *src, u32 arg, u32 size);

extern void DC_FlushRange(void *addr, u32 size);

void func_0204C8B8(struct Xfer *x)
{
    DC_FlushRange(x->src, x->size);
    g_020A138C[x->kind](x->src, x->unk_04, x->size);
}
