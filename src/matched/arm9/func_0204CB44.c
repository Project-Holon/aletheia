/*
 * function: CLACT_DrawActor
 * address:  0x0204CB44
 * packet:   pkt_0204CB44
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Blocked at MATCH on the `label`/`matched` classes: all 108 concrete bytes
 * are right, but every one of the six callees has exactly one branch
 * reference image-wide and it is the call in this function, so none of the
 * six can be witnessed and no cut frees any of them.  Four of the six are
 * now closed and the file is at 4 of 6 relocation sites resolved:
 *
 *   NNSi_G2dSetRndCoreImageProxyVeneer  0x02066748   12 bytes  -- veneer, resolves `veneer`
 *   NNS_G2dBeginRendering  0x02065BD0  168 bytes  -- OPEN, docs/notes/NNS_G2dBeginRendering.c.txt
 *   CLACT_SetupActorDraw  0x0204CBB0  188 bytes  -- closed, resolves `matched`
 *   CLACT_SetPaletteBaseOffsets  0x0204BA7C  112 bytes  -- closed, resolves `matched`
 *   CLACT_ApplyActorTransform  0x0204CC6C  584 bytes  -- OPEN, soft-float, multi-function
 *   NNS_G2dEndRendering  0x02065C78  108 bytes  -- closed, resolves `matched`
 *
 * NNSi_G2dSetRndCoreImageProxyVeneer is not decompilable and never will be.  It is a twelve-byte
 * ARM linker veneer, `ldr ip, [pc]; bx ip; .word 0x02067AA0`, and the
 * `veneer` attestation class used to refuse it because 0x02067AA0 was an
 * unlabelled three-instruction leaf (`str r1, [r0, #8]; str r2, [r0, #0xc];
 * bx lr`) that `disasm.py` never labels, so `names_known_code()` failed.  The
 * integrator seeded 0x02067AA0 into layout/function_starts.txt before wave
 * 25 and the site now resolves `veneer` with no change to any source file,
 * exactly as
 * docs/idioms/a-veneer-attests-nothing-while-its-target-is-an-unlabelled-leaf.md
 * predicted.
 *
 * What remains is NNS_G2dBeginRendering, a 24-byte codegen near miss over one
 * zero-register allocation (the note names every spelling tried), and
 * CLACT_ApplyActorTransform, 584 bytes of soft-float record publishing that nobody has
 * attempted yet.  This function is itself the sole blocker for
 * src/pending/CLACT_DrawUnit.c, which is the sole blocker named in
 * docs/notes/clact_c_fan_in_1_blockers.c.txt for src/pending/CLACT_DrawAllUnits.c,
 * which is one of the two blockers of src/pending/CLACT_DrawSystem.c (the other
 * is 0x02066998).
 *
 * Per-element teardown.  Guarded by bit 26 of the flag word at +0x60; the
 * two values handed to CLACT_SetPaletteBaseOffsets are bits 12-15 (narrowed to u8, which
 * is what the otherwise redundant `and r1, r1, #0xff` after the shift pair
 * records) and bit 31 of the same word, read through one load.
 *
 * symbols:
 *   NNSi_G2dSetRndCoreImageProxyVeneer  0x02066748  arm
 *   NNS_G2dBeginRendering  0x02065BD0  arm
 *   CLACT_SetupActorDraw  0x0204CBB0  arm
 *   CLACT_SetPaletteBaseOffsets  0x0204BA7C  arm
 *   CLACT_ApplyActorTransform  0x0204CC6C  arm
 *   NNS_G2dEndRendering  0x02065C78  arm
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/CLACT_DrawActor.c \
 *       --func CLACT_DrawActor --addr 0x0204CB44 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Elem {
    u8  pad00[0x1c]; /* 0x00 */
    u8  unk1c[0x24]; /* 0x1c */
    u8  unk40[0x20]; /* 0x40 */
    u32 pad60_0 : 12;
    u32 unk60_c : 4;  /* 0x60, bits 12-15 */
    u32 pad60_1 : 10;
    u32 enabled : 1;  /* 0x60, bit 26 */
    u32 pad60_2 : 4;
    u32 unk60_1f : 1; /* 0x60, bit 31 */
};

typedef unsigned short u16;
struct Rec;
extern void NNSi_G2dSetRndCoreImageProxyVeneer(int *a0, int a1, int a2);
extern void NNS_G2dBeginRendering(void *obj);
extern void CLACT_SetupActorDraw(struct Elem *e, struct Rec *r);
extern void CLACT_SetPaletteBaseOffsets(u32 set, u16 bias, u32 v);
extern u32  CLACT_ApplyActorTransform(struct Elem *e);
extern void NNS_G2dEndRendering(u32 a);

void CLACT_DrawActor(struct Elem *e, u32 arg)
{
    if (e->enabled == 0)
        return;

    NNSi_G2dSetRndCoreImageProxyVeneer((int *)arg, (int)e->unk1c, (int)e->unk40);
    NNS_G2dBeginRendering((void *)arg);
    CLACT_SetupActorDraw(e, (struct Rec *)arg);
    CLACT_SetPaletteBaseOffsets((u32)e->unk40, (u8)e->unk60_c, e->unk60_1f);
    NNS_G2dEndRendering(CLACT_ApplyActorTransform(e));
}
