/*
 * unit:     no
 * function: NNSi_G2dRendererDrawCellZOffset
 * address:  0x02065CE4
 * packet:   pkt_02064B68
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Draws one cell actor.  Exact twin of src/matched/NNSi_G2dRendererDrawCellTransformedZOffset.c with
 * NNSi_G2dRendererDrawCellToSurfaces in place of NNSi_G2dRendererDrawCellTransformed: the bank at 0x02147B88 carries an
 * object pointer at +0x08 whose secondary render surface is at +0x80.  With
 * no secondary surface the body is the plain draw; with one, the draw is
 * bracketed save / switch / bind / draw / switch back / rebind / close.
 *
 * Pinned to ../2.0/sp2 on the same "kept constants" tell its twin carries:
 * the image loads the &g_02147B88 pool word TWICE (r1 at 0x02065CE8, r0 again
 * at 0x02065D10) and so spends only two callee-saved registers, padding the
 * frame with r3 (push {r3, r4, r5, lr}); dsi/1.1p1 -O4,p CSEs the two reads,
 * holds the base in a third callee-saved register and comes out 96 bytes
 * against the original 100 of code.  docs/notes/NNSi_G2dRendererDrawCellZOffset.c.txt records
 * that four-byte residue and asks what makes mwccarm emit two separate
 * materialisations of one extern address; the answer is the front end, not
 * the C.  The `volatile` cast on each read is what keeps 2.0 from folding
 * them back together.  See docs/FRONTEND-PINS.md.
 *
 * symbols:
 *   g_02147B88  0x02147B88  data  a4
 *   NNS_G2dGetOamSoftEmuAutoZOffsetStep  0x02066E20  arm
 *   func_02066DEC  0x02066DEC  arm
 *   NNS_G2dSetOamSoftEmuAutoZOffsetStep  0x02066E10  arm
 *   func_02066DFC  0x02066DFC  arm
 *   NNSi_G2dRendererDrawCellToSurfaces  0x02065438  arm
 */

typedef struct
{
    unsigned char pad[0x80];
    int f80;
} Inner;

typedef struct
{
    unsigned char pad[8];
    Inner *f8;
} Ctx;

extern Ctx g_02147B88;

extern int NNS_G2dGetOamSoftEmuAutoZOffsetStep(void);
extern void func_02066DEC(int);
extern void NNS_G2dSetOamSoftEmuAutoZOffsetStep(int);
extern void func_02066DFC(void);
extern void NNSi_G2dRendererDrawCellToSurfaces(void *);

void NNSi_G2dRendererDrawCellZOffset(void *a0)
{
    int saved;

    if (((volatile Ctx *)&g_02147B88)->f8->f80 != 0)
    {
        saved = NNS_G2dGetOamSoftEmuAutoZOffsetStep();
        func_02066DEC(1);
        NNS_G2dSetOamSoftEmuAutoZOffsetStep(((volatile Ctx *)&g_02147B88)->f8->f80);
        NNSi_G2dRendererDrawCellToSurfaces(a0);
        func_02066DEC(0);
        NNS_G2dSetOamSoftEmuAutoZOffsetStep(saved);
        func_02066DFC();
    }
    else
    {
        NNSi_G2dRendererDrawCellToSurfaces(a0);
    }
}
