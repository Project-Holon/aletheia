/*
 * file:     unit_0206AAD4_p02.c
 * unit:     yes
 * function: func_0206AD20, func_0206AD64
 * address:  0x0206AD20
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
 *   g_02148B54   0x02148B54  data
 *   g_02148D0C   0x02148D0C  data
 *   func_0206AB18  0x0206AB18  arm
 *   g_02148B98   0x02148B98  data
 *   g_02148C08   0x02148C08  data
 *   g_02148C7C   0x02148C7C  data
 *   g_02148CAC   0x02148CAC  data
 *   func_0207B9F0  0x0207B9F0  arm
 *   func_0207B60C  0x0207B60C  arm
 *   func_0207B67C  0x0207B67C  arm
 */
typedef unsigned int u32;

extern void func_0206AB18(u32 *a, u32 *b);
extern void func_0207B9F0(void *a, void *b, void *c);
extern void func_0207B60C(void *a, void *b, u32 c, u32 d, u32 e);
extern void func_0207B67C(void *a, void *b);
u32 *func_0206AD20(void);
void func_0206AD64(void);
extern u32 g_02148B4C[];
extern u32 g_02148B54[];
extern u32 g_02148D0C[];
extern char g_02148B98[];
extern char g_02148C08[];
extern char g_02148C7C[];
extern char g_02148CAC[];


/*
 *           +001C inside this function, so `label` has no witness outside the
 *           compared range 0206AD20..0206AD64 and the site stays wildcarded;
 *           own-pool: g_02148D0C (0x02148D0C) occurs exactly once in the whole
 *           arm9 image, in this function's own pool at 0x0206AD60 (+0040).
 *
 * Pin evidence (2.0), measured 2026-09-19 by wave r8 lane small-3: identical
 * shape and identical tell to src/pending/func_0206AAD4.c - the flags object
 * 0x02148B4C is re-materialised from its pool word at +0034 after the call,
 * 68 bytes (56 code + three pool words), `push {r3, lr}`, zero concrete
 * differences under dsi/../2.0/sp2 where dsi/1.1p1 grows the frame to r4 and
 * leaves 21 differing bytes.
 *
 * Rig-slot setup for bit 4: if the flags object's +0xfc word does not already
 * carry 0x10, hand the slot pair (0x02148B54, 0x02148D0C) to the matrix helper
 * and set it, then answer with the slot address either way.  Two of the four
 * sites resolve on `literal` (0x02148B4C x115, 0x02148B54 x22); the call and
 * the returned slot address stay wildcarded.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0206AD20.c \
 *       --func func_0206AD20 --addr 0x0206AD20 --cc ../2.0/sp2 --arm
 */
u32 *func_0206AD20(void)
{
    if ((g_02148B4C[0x3f] & 0x10) == 0) {
        func_0206AB18(g_02148B54, g_02148D0C);
        g_02148B4C[0x3f] |= 0x10;
    }
    return g_02148D0C;
}


/*
 * Pin evidence (2.0), measured 2026-09-19:
 *   The image re-materialises the address of the flags object 0x02148B4C from
 *   its pool word at +0014, *before* the three calls, and loads the two other
 *   slot addresses (0x02148C08, 0x02148B98) straight into r0/r1/r2; the frame
 *   is a bare `push {r3, lr}` and the body is 88 bytes.
 *   dsi/1.1p1 keeps those addresses live in callee-saved registers instead
 *   (frame `push {r3, r4, r5, lr}` at 96 bytes, or 100 bytes with the same C
 *   spelled for it), which is the documented "kept constants" tell in
 *   docs/FRONTEND-PINS.md.  dsi/../2.0/sp2 with this C compiles to the
 *   original's 88 bytes with zero concrete mismatches; dsi/1.1p1 gives 78
 *   differing bytes and dsi/../1.2/sp2 gives 76 across 100 bytes.  Same tell
 *   and same family as src/pending/func_0206B6A4.c, already pinned.
 *
 * Rig-slot teardown for the flags object at 0x02148B4C: release the two
 * scratch buffers, hand the three power-of-two state words to the matrix
 * helper, then hand the pair back to the slot fetch.
 *
 * PARKED AT MATCH.  Every concrete byte of the 88-byte body reproduces under
 * the pin; the single open site is func_0207B60C's only branch reference
 * anywhere in the image, the `bl` at 0x0206AD94 inside this function, so the
 * PC24 site is its own witness and no C can resolve it.  It unsticks the day
 * 0x0207B60C is itself an EXACT manifest entry (`matched`) or a second caller
 * turns up in an overlay.  The other two calls resolve on `label` and every
 * ABS32 resolves on `literal`.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0206AD64.c \
 *       --func func_0206AD64 --addr 0x0206AD64 --arm --cc ../2.0/sp2
 */
void func_0206AD64(void)
{
    func_0207B9F0(g_02148C08, g_02148B98, g_02148C7C);
    func_0207B60C(g_02148C7C, g_02148C7C, g_02148B4C[0x3b], g_02148B4C[0x3c],
                  g_02148B4C[0x3d]);
    func_0207B67C(g_02148C7C, g_02148CAC);
}
