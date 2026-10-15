/*
 * function: NNS_G2dRndCoreDrawCellVramTransfer
 * address:  0x02067DC8
 * packet:   pkt_02067DC8
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * The rig-step entry of the NNS G2D cell composer, the sibling of
 * NNS_G2dRndCoreDrawCell (src/pending/NNS_G2dRndCoreDrawCell.c) that also takes a part
 * index.  Reads the singleton rig at sRndCoreInstance, raises its +0x30 gate,
 * runs the caller's +0x18 pre hook, and while the gate survives the hook
 * dispatches on the inner object's +0x14 mode through a four-entry table:
 * mode 0 -> NNSi_G2dDrawCellToSurface3D, modes 1 and 2 -> NNSi_G2dDrawCellToSurface2D, mode 3 empty
 * (the empty arm is what makes the `addls pc, pc, r0, lsl #2` table exist
 * at all).  When a1 is not the -1 sentinel it first sets the part's own
 * bit in NNSi_G2dGetCellTransferState(a1)->f20.  The +0x1c post hook closes it.
 *
 * BYTE-CORRECT: 232 bytes, 0 concrete mismatches, under the pin below.
 *
 * blocked:  label, no outside witness.  Two of the four relocation sites
 *   stay wildcarded: the +0x00B0 PC24 to NNSi_G2dDrawCellToSurface3D and the +0x00C0
 *   PC24 to NNSi_G2dDrawCellToSurface2D.  Each of those two callees is branched to from
 *   exactly two places image-wide, this function and NNS_G2dRndCoreDrawCell
 *   (0x02067D14), and that file is itself parked at MATCH, so neither
 *   caller attests the other and `label` refuses both.  Being one
 *   function, no `--suggest-split` cut exists.  It promotes with NO edit
 *   the moment 0x02067998 or 0x02067340 has a `matched` entry; both live
 *   in pkt_02066E30 (see docs/notes/pkt_02066E30.c.txt).
 *
 * compiler pin, ../2.0/sp2, the "kept constants" tell of
 * src/matched/NNSi_G2dIsVramHandleSetEx.c measured again on this row: the image
 * materialises the -1 sentinel in a register, `mvn r0, #0` (`00 00 e0 e3`)
 * at 0x02067E20 followed by `cmp r4, r0` (`00 00 54 e1`) at 0x02067E24,
 * where dsi/1.1p1 -O4,p folds the constant into the compare as
 * `cmn r5, #1` and drops the separate materialisation: 228 bytes against
 * the original's 232, 117 concrete bytes out with everything after
 * 0x02067E20 shifted by four.  Twelve sentinel spellings are recorded as
 * measured in docs/notes/pkt_02067D14.c.txt and every one folds under
 * 1.1p1.  Under the pin the same C is 232 bytes, 0 mismatches.
 *
 * The one C lever needed under the pin is declaration order
 * (docs/idioms/declaration-order-decides-which-register-a-local-gets.md):
 * `u32 idx;` must be declared BEFORE `struct Inner *o;`, which is what
 * puts the inner object in r5 and the bit index in r4.  With `idx`
 * declared inside the `a1 != -1` arm the two callee-saved registers come
 * out swapped and 13 instructions differ at the same 232 bytes.
 *
 * symbols:
 *   sRndCoreInstance    0x02148B48  data
 *   NNSi_G2dGetCellTransferState 0x02066878  arm
 *   NNSi_G2dDrawCellToSurface3D 0x02067998  arm
 *   NNSi_G2dDrawCellToSurface2D 0x02067340  arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;
typedef signed int    s32;

typedef void (*CB)(void *, u32);

struct Inner {
    u8  pad_00[0x10];
    u32 field_10;
    u32 mode;
    CB  cb_18;
    CB  cb_1c;
};

struct Rig {
    struct Inner *inner;
    u8  pad_04[0x2c];
    u32 flag_30;
};

struct Part { u8 pad_00[0x20]; u32 f20; };

extern struct Rig *sRndCoreInstance;
extern u8 *NNSi_G2dGetCellTransferState(u32 i);
struct Hooks;
struct List;
extern void NNSi_G2dDrawCellToSurface3D(struct Hooks *h, struct List *lst);
extern void NNSi_G2dDrawCellToSurface2D(struct Inner *a, u32 b);

void NNS_G2dRndCoreDrawCellVramTransfer(u32 a0, s32 a1)
{
    u32 idx;
    struct Inner *o;
    struct Rig *g = sRndCoreInstance;

    o = g->inner;
    if (o->field_10 == 0) return;

    g->flag_30 = 1;
    if (o->cb_18 != 0) o->cb_18(sRndCoreInstance, a0);

    if (sRndCoreInstance->flag_30 != 0) {
        if (a1 != -1) {
            struct Part *p;
            idx = o->mode;
            p = (struct Part *)NNSi_G2dGetCellTransferState(a1);
            p->f20 = (p->f20 & ~(1 << idx)) | (1 << idx);
        }
        switch (o->mode) {
        case 0: NNSi_G2dDrawCellToSurface3D((struct Hooks *)o, (struct List *)a0); break;
        case 1:
        case 2: NNSi_G2dDrawCellToSurface2D(o, a0); break;
        case 3: break;
        }
    }
    if (o->cb_1c != 0) o->cb_1c(sRndCoreInstance, a0);
}
