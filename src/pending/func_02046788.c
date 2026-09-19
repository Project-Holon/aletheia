/*
 * function: func_02046788
 * address:  0x02046788
 * packet:   pkt_02046440
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * symbols:
 *   g_02146A5C      0x02146A5C  data
 *   func_020307B0   0x020307B0  arm
 *   func_0206DB24   0x0206DB24  arm
 *   func_0206DB60   0x0206DB60  arm
 *   func_02030BC8   0x02030BC8  arm
 *
 * Shut the module down: free the two owned pointers at +0x10 and +0x14 if
 * they are set, run the paired stop only when func_0206DB24 answers exactly
 * one, and finally free the context itself and null its slot.
 *
 * The context pointer is re-read from its slot for every use, so the two
 * guards each carry their own `ldr`; only the last statement caches the
 * slot's address in r4, because it needs it again for the store of zero.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02046788.c \
 *       --func func_02046788 --addr 0x02046788 --cc 1.1p1 --arm
 *
 * Parked: byte correct, capped at MATCH by the evidence rather than by the C.
 *
 * Every concrete byte is right; the site(s) above stay wildcarded because 0206DB24
 * has exactly one witness image wide and it is the branch inside this very range.
 * Blocking evidence class: label/matched, no outside witness.  It unsticks when the
 * callee is itself EXACT (the `matched` class) or a second caller turns up.
 *
 * Parked: byte correct, capped at MATCH by the evidence rather than by the C.
 * Blocking evidence class: label/matched, no outside witness.  0x0206DB24 is
 * called from this site and nowhere else the harness can see, so its PC24
 * stays wildcarded; matching 0x0206DB24 elsewhere (or a second caller)
 * closes it.
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Ctx {
    u8    pad_00[0x10];
    void *unk_10;
    void *unk_14;
};

extern struct Ctx *g_02146A5C;

extern void  func_020307B0(void *p);
extern u32   func_0206DB24(void);
extern void  func_0206DB60(void);
extern void  func_02030BC8(void);

void func_02046788(void)
{
    if (g_02146A5C->unk_10 != 0)
        func_020307B0(g_02146A5C->unk_10);
    if (g_02146A5C->unk_14 != 0)
        func_020307B0(g_02146A5C->unk_14);

    if (func_0206DB24() == 1) {
        func_0206DB60();
        func_02030BC8();
    }

    func_020307B0(g_02146A5C);
    g_02146A5C = 0;
}
