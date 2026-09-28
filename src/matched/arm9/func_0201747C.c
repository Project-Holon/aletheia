/*
 * function: func_0201747C
 * address:  0x0201747C
 * packet:   pkt_020173F0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02017DBC  0x02017DBC  thumb
 *   func_02017E88  0x02017E88  thumb
 *   func_02017DE4  0x02017DE4  thumb
 *   func_020173F0  0x020173F0  thumb
 *   func_02017E40  0x02017E40  thumb
 *   func_02008F08  0x02008F08  thumb
 *   func_020307B0  0x020307B0  arm
 *   func_020185C4  0x020185C4  thumb
 *
 * "Clone this Pokemon into a fresh allocation on heap `heap`."
 *
 * It takes the block lock (func_02017DBC), reads species (id 0x05), level
 * (id 0x9E) and OT id (id 0x07) -- all three through the block-lock getter
 * func_02017E88, and species and level truncated to u16 at the assignment,
 * which is what the two `lsls #0x10 / lsrs #0x10` pairs at +0x18 and +0x26
 * are -- builds a fresh record with func_020173F0(species, level, otId, 0,
 * heap), releases the lock, copies the WHOLE 0x88-word record over the fresh
 * one, then zeroes the three party-area ids the clone must not inherit
 * (0x9D, 0xA0 current HP, 0xA1 max HP), attaches a fresh mail block and
 * recomputes the stats.
 *
 * THE ONE LEVER, and the whole residue of the first draft:
 *
 *   THE RECORD COPY IS A STRUCT ASSIGNMENT, NOT A HAND-WRITTEN WORD LOOP.
 *
 * The original's copy is
 *
 *     020174C8  adds r3, r4, #0
 *     020174CA  movs r2, #0x11
 *     020174CC  ldm r5!, {r0, r1}
 *     020174CE  stm r3!, {r0, r1}
 *     020174D0  subs r2, r2, #1
 *     020174D2  bne #0x20174cc
 *
 * i.e. 0x11 iterations of an eight-byte ldm/stm pair, which is exactly
 * docs/idioms/big-struct-assignment-is-an-ldm-stm-loop.md: above the unroll
 * threshold mwcc turns a whole-struct assignment into a counted ldm/stm loop
 * whose step is the struct's alignment.  Writing the same copy as an explicit
 * `d[0] = s[0]; d[1] = s[1]; s += 2; d += 2;` loop compiles to four separate
 * `ldr`/`str` plus two pointer bumps -- eight bytes longer and the whole tail
 * shifted (the first draft was 180 bytes against 172, with everything up to
 * +0x4C already byte-identical).  Only the aggregate assignment reaches it.
 *
 * The copy is 0x22 words = 0x88 bytes, NOT the record's full 0xDC: it copies
 * the plaintext header and the 0x80-byte masked block area and stops at the
 * party area, which is what the three explicit zeroes that follow then
 * rebuild.  That is why `struct Mon` here is declared as 0x22 words and not
 * as docs/families/poke_tool.h's full record -- the declared size IS the
 * evidence, since it is what sets the loop's trip count to 0x11.
 *
 * The heap tag handed to func_02008F08 is `(heap & 0x7fff) | 0x8000`: the pool
 * word at 0x02017524 is 0x00007FFF and the original derives the OR mask from
 * it with `adds r0, r0, #1` rather than pooling 0x8000 separately
 * (docs/idioms/a-small-constant-is-rematerialised-off-a-zero-register-unless-an-argument-shares-it.md).
 *
 * Nothing here is version specific: 0x05, 0x07, 0x9D, 0x9E, 0xA0, 0xA1 and
 * 0xA7 are all field selectors.
 *
 * Verified with
 *   python tools/match.py one --src src/matched/func_0201747C.c \
 *       --func func_0201747C --addr 0x0201747C --cc 1.1p1 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

/* the header plus the masked block area: 0x22 words, whose eight-byte
 * ldm/stm step and 0x11 trip count are what the copy loop below proves */
struct Mon { u32 w[0x22]; };

extern u32   func_02017DBC(void *p);
extern u32   func_02017DE4(void *p, u32 f);
extern u32   func_02017E88(void *p, u32 id, u32 v);
extern void  func_02017E40(void *p, u32 id, u32 v);
extern void *func_020173F0(u16 species, u16 level, u32 otId, u32 a3, u32 heap);
extern void *func_02008F08(u16 tag);
extern void  func_020307B0(void *m);
extern void  func_020185C4(void *p);

void *func_0201747C(struct Mon *p, u32 heap)
{
    u32 t = func_02017DBC(p);
    u16 species = (u16)func_02017E88(p, 5, 0);
    u16 level = (u16)func_02017E88(p, 0x9e, 0);
    u32 otId = func_02017E88(p, 7, 0);
    void *q = func_020173F0(species, level, otId, 0, heap);
    void *m;

    func_02017DE4(p, t);

    *(struct Mon *)q = *p;

    func_02017E40(q, 0x9d, 0);
    func_02017E40(q, 0xa0, 0);
    func_02017E40(q, 0xa1, 0);
    m = func_02008F08((u16)((heap & 0x7fff) | 0x8000));
    func_02017E40(q, 0xa7, (u32)m);
    func_020307B0(m);
    func_020185C4(q);
    return q;
}
