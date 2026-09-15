/*
 * unit:     no
 * function: func_02041300
 * address:  0x02041300
 * packet:   pkt_02040F84
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * symbols:
 *   g_02146A44     0x02146A44  data
 *   func_02042D2C  0x02042D2C  arm
 *   func_02042E34  0x02042E34  arm
 *   func_02042ED8  0x02042ED8  arm
 *
 * Blocked at MATCH: all 176 concrete bytes are correct, but three of the
 * four relocation sites have no witness of any evidence class.  Each of
 * func_02042D2C, func_02042E34 and func_02042ED8 has exactly one branch
 * reference image wide, and it is the call inside this function, so no cut
 * frees them either:
 *
 *   suggest-split: best partition: 0 piece(s), 1 function(s) left out
 *                  OUT 02041300..020413B0 func_02041300
 *
 * The unblock is the `matched` class: decompile any one of the three
 * blitters (they live in pkt_02042B24, not this packet) to EXACT and the
 * corresponding site here becomes attested.  All three are needed for this
 * file to reach EXACT.
 *
 * Fan-out on the colour depth of one of the 0x2c-byte slots behind
 * 0x02146A44 (the same table as src/matched/func_020414EC.c and
 * src/matched/sub_02042FB0.c), dispatching a fill to one of three blitters
 * on the mode byte at +0x1c.  The neighbouring byte at +0x1d is the
 * screen-size code, so +0x1c is the bit-depth selector: arm 0 is the
 * seven-argument form, arm 1 drops the last argument and truncates the
 * second to u8, and the default arm is the seven-argument form again.
 *
 * Codegen note worth keeping.  The slot's sub-object pointer has to be
 * spelled as byte arithmetic with the constant added first,
 *
 *     (u8 *)g_02146A44 + 8 + index * sizeof(struct Entry)
 *
 * and written out at every call site.  The natural spelling
 * `&g_02146A44[index].unk_08` computes base + index * 0x2c first and lets
 * the front end contract the whole address into a single
 * `mla ip, r0, ip, r4`, which is twelve bytes shorter than the original and
 * changes the register allocation (one callee-saved register instead of
 * two).  The original keeps the table base and the scaled index in separate
 * registers across the dispatch and re-derives `base + 8 + off` in each
 * arm, which is what the constant-first spelling produces.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02041300.c \
 *       --func func_02041300 --addr 0x02041300 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Entry {
    u8 pad_00[8];
    u8 unk_08[0x14];
    u8 unk_1c;
    u8 pad_1d[0xf];
};

extern struct Entry *g_02146A44;

extern void func_02042D2C(void *surf, u32 a1, u32 a2, u32 a3, u8 a4, u8 a5,
                          u8 a6);
extern void func_02042E34(void *surf, u8 a1, u32 a2, u32 a3, u8 a4, u8 a5);
extern void func_02042ED8(void *surf, u32 a1, u32 a2, u32 a3, u8 a4, u8 a5,
                          u8 a6);

void func_02041300(u32 index, u32 a1, u32 a2, u32 a3, u8 a4, u8 a5, u8 a6)
{
    u8 kind = g_02146A44[index].unk_1c;

    if (kind == 0) {
        func_02042D2C((u8 *)g_02146A44 + 8 + index * sizeof(struct Entry),
                      a1, a2, a3, a4, a5, a6);
    } else if (kind == 1) {
        func_02042E34((u8 *)g_02146A44 + 8 + index * sizeof(struct Entry),
                      a1, a2, a3, a4, a5);
    } else {
        func_02042ED8((u8 *)g_02146A44 + 8 + index * sizeof(struct Entry),
                      a1, a2, a3, a4, a5, a6);
    }
}
