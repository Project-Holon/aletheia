/*
 * file:     unit_0206AAD4_p03.c
 * unit:     yes
 * function: func_0206ADBC, func_0206ADF4, func_0206AE2C, func_0206AE94
 * address:  0x0206ADBC
 * region:   arm9
 * compiler: dsi/../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_02148B4C   0x02148B4C  data
 *   g_02148C7C   0x02148C7C  data
 *   func_0206AD64  0x0206AD64  arm
 *   g_02148CAC   0x02148CAC  data
 *   g_02148D4C   0x02148D4C  data
 *   func_0206AAD4  0x0206AAD4  arm
 *   func_0206AD20  0x0206AD20  arm
 *   func_0207B5C0  0x0207B5C0  arm
 *   func_0207BE14  0x0207BE14  arm
 */
typedef unsigned int u32;

extern void func_0206AD64(void);
extern u32 *func_0206AAD4(void);
extern u32 *func_0206AD20(void);
extern void  func_0207B5C0(void *a, void *buf);
extern void  func_0207BE14(void *a, void *buf, void *c);
u32 *func_0206ADBC(void);
u32 *func_0206ADF4(void);
void *func_0206AE2C(void);
void func_0206AE94(u32 *a0, u32 *a1, u32 *a2, u32 *a3);
extern u32 g_02148B4C[];
extern u32 g_02148C7C[];
extern u32 g_02148CAC[];
extern char g_02148D4C[];


/*
 * Pin evidence (2.0), measured 2026-09-19 by wave r8 lane small-3:
 *   The image re-materialises the flags object 0x02148B4C from its pool word
 *   at +002C (a fresh `ldr r0, [pc, #0x10]` after the call at +0018) and keeps
 *   a bare 56-byte body with a `push {r3, lr}` frame.  dsi/1.1p1 keeps the
 *   address live in a callee-saved register across the call and grows the
 *   frame to `push {r4, lr}` with 21 differing bytes; dsi/../2.0/sp2 with this
 *   C compiles to the original's 56 bytes with zero concrete mismatches.  Same
 *   tell ("kept constants", docs/FRONTEND-PINS.md) and same family as
 *   src/pending/func_0206AD64.c and src/pending/func_0206AE2C.c, both already
 *   pinned to ../2.0/sp2 by wave r6.
 *
 * Rig-slot setup for bit 7: if the flags object's +0xfc word does not already
 * carry 0x80, run the slot teardown and set it.  The address of the slot at
 * 0x02148C7C is returned either way, which is why the pool word for it sits
 * last and is loaded once, after the branch target.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0206ADBC.c \
 *       --func func_0206ADBC --addr 0x0206ADBC --cc ../2.0/sp2 --arm
 */
u32 *func_0206ADBC(void)
{
    if ((g_02148B4C[0x3f] & 0x80) == 0) {
        func_0206AD64();
        g_02148B4C[0x3f] |= 0x80;
    }
    return g_02148C7C;
}


/*
 * Pin evidence (2.0), measured 2026-09-19 by wave r8 lane small-3: identical
 * shape and identical tell to its twin src/matched/func_0206ADBC.c - the flags
 * object 0x02148B4C is re-materialised from its pool word at +002C after the
 * call, 56 bytes, `push {r3, lr}`, zero concrete mismatches under
 * dsi/../2.0/sp2 where dsi/1.1p1 keeps the address live in r4 and grows the
 * frame.  The only difference from the twin is the slot address returned
 * (0x02148CAC instead of 0x02148C7C), which each function carries in its own
 * pool.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0206ADF4.c \
 *       --func func_0206ADF4 --addr 0x0206ADF4 --cc ../2.0/sp2 --arm
 */
u32 *func_0206ADF4(void)
{
    if ((g_02148B4C[0x3f] & 0x80) == 0) {
        func_0206AD64();
        g_02148B4C[0x3f] |= 0x80;
    }
    return g_02148CAC;
}


/*
 * Pin evidence (2.0): the image re-materialises the address of the flags
 * object 0x02148B4C from its pool word at +0044, *after* the two calls at
 * +0020 and +0040; 1.1p1 keeps that address live across both calls in a
 * callee-saved register and grows the frame (push {r3,r4,r5,lr}), which is
 * the documented 2.0 tell in docs/FRONTEND-PINS.md ("kept constants": the
 * image rematerialises a constant from the pool where the build keeps it
 * live in a callee-saved register).  Same family as src/pending/
 * func_0206B6A4.c, pinned for the identical tell.
 *
 * PARKED AT MATCH.  Under the pin every concrete byte of the 88-byte body
 * reproduces; the single open site is the call to func_0206AAD4 at +0010,
 * which is the only branch to that address anywhere in the image.  It
 * unsticks when 0x0206AAD4 is itself an EXACT manifest entry (`matched`) or
 * a second caller turns up in an overlay.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0206AE2C.c \
 *       --func func_0206AE2C --addr 0x0206AE2C --cc ../2.0/sp2 --arm
 */
void *func_0206AE2C(void)
{
    char buf[0x40];
    void *a;
    void *b;

    if ((g_02148B4C[0x3f] & 0x40) == 0) {
        a = func_0206AAD4();
        b = func_0206AD20();
        func_0207B5C0(a, buf);
        func_0207BE14(b, buf, g_02148D4C);
        g_02148B4C[0x3f] |= 0x40;
    }
    return g_02148D4C;
}


/*
 * Pin evidence (2.0), measured 2026-09-19 by wave r8 lane small-3: with
 * dsi/1.1p1 every one of the four guarded arms is if-converted into predicated
 * instructions (`cmp r0, #0` / `ldrne ip, [pc, #0x54]` / `ldrne ip, [ip, #0xa0]`
 * / `andne ip, ip, #0xff` / `strne ip, [r0]`), which shortens the body to 100
 * bytes and leaves 81 differing bytes; dsi/../2.0/sp2 emits the image's
 * branchy form (`cmp` / `beq` over an unconditional body, with only the last
 * arm predicated as `bxeq lr`) at exactly 116 bytes with zero concrete
 * mismatches.  Same front end as the rest of this packet's filed rows
 * (docs/FRONTEND-PINS.md: pkt_0206AA78 keeps constants live / re-materialises
 * them from the pool per front end).  Neither `-proc arm7tdmi` nor volatile
 * destination pointers changed the 1.1p1 if-conversion.
 *
 * Four-byte nibble extractor: the word at g_02148B4C + 0xa0 is spread over up
 * to four word-sized destinations, one byte per word, low byte first.  Each
 * arm re-spells the global rather than sharing a named local, which is what
 * makes the image re-load the pool word in every arm (and what puts the first
 * arm's value in ip while the rest use r0).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0206AE94.c \
 *       --func func_0206AE94 --addr 0x0206AE94 --cc ../2.0/sp2 --arm
 */
void func_0206AE94(u32 *a0, u32 *a1, u32 *a2, u32 *a3)
{
    if (a0 != 0)
        *a0 = g_02148B4C[0x28] & 0xff;
    if (a1 != 0)
        *a1 = (g_02148B4C[0x28] >> 8) & 0xff;
    if (a2 != 0)
        *a2 = (g_02148B4C[0x28] >> 16) & 0xff;
    if (a3 != 0)
        *a3 = (g_02148B4C[0x28] >> 24) & 0xff;
}
