/*
 * file:     double3Ddisp.c
 * unit:     yes
 * function: DOUBLE3DDISP_Init, DOUBLE3DDISP_InitOam, DOUBLE3DDISP_Exit, DOUBLE3DDISP_GetMode, DOUBLE3DDISP_SetDrawDone, DOUBLE3DDISP_Delete, DOUBLE3DDISP_SetupGraphics, DOUBLE3DDISP_SetupGraphicsSubObj
 * address:  0x0204E8C0
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Cut from double3Ddisp.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   double3Ddisp_File 0x020A7F94  data
 *   gDouble3Ddisp     0x02146A80  data
 *   DC_FlushRange  0x020862F0  arm
 *   GXS_LoadOAM  0x0207E708  arm
 *   GX_DisableBankForLCDC  0x02080B98  arm
 *   GX_DisableBankForSubBG  0x02080BAC  arm
 *   GX_DisableBankForSubOBJ  0x02080BC0  arm
 *   GX_ResetBankForSubOBJ   0x020809B4  arm
 *   GX_SetBankForSubBG   0x020806B0  arm
 *   GX_SetBankForLCDC   0x0208068C  arm
 *   GX_SetGraphicsMode   0x0207D4B0  arm
 *   GXS_SetGraphicsMode   0x0207D518  arm
 *   GX_ResetBankForSubBG   0x020809A0  arm
 *   GX_SetBankForSubOBJ   0x0208074C  arm
 *   GFL_HEAP_Free  0x020307B0  arm
 */
#include "../types.h"

union OamEntry {
    u32 w[2];
    struct { u32 attr01; u16 attr2; u16 attr3; } f;
};

struct Double3Ddisp {
    u16 heap;           /* 0x00 */
    u16 pad02;          /* 0x02 */
    s32 displayMode;    /* 0x04  which sub-engine setup is active, 0 or 1 */
    s32 drawDone;       /* 0x08  set once the frame's particles are drawn  */
    union OamEntry oam[12];
};

typedef int GXVRam;
typedef int GXVRamBG;
typedef int GXVRamOBJ;
typedef int GXVRamTex;
#include "gx_vramcnt.h"



#include "gx.h"




#include "gfl_heap_wrap.h"


extern const char double3Ddisp_File[];

#include "os_cache.h"

#include "gx_load2d.h"




void DOUBLE3DDISP_Init(u32 heap);

void DOUBLE3DDISP_InitOam(void);

int DOUBLE3DDISP_Exit(void);

u32 DOUBLE3DDISP_GetMode(void);

void DOUBLE3DDISP_SetDrawDone(void);

void DOUBLE3DDISP_Delete(void);

void DOUBLE3DDISP_SetupGraphics(void);

void DOUBLE3DDISP_SetupGraphicsSubObj(void);

extern struct Double3Ddisp *gDouble3Ddisp;

#define REG32(a) (*(volatile u32 *)(a))

/*
 * TU: double3Ddisp.c.  The __FILE__ pointer at 0x020A7F94 reads
 * "double3Ddisp.c" (line 63 here), and it is the first reference to that
 * string in the image, so this function is the start of the translation
 * unit.  The block just before it belongs to fade.c (0x020A7F8C, referenced
 * from 0x0204E630), which is the file src/matched/unit_0204E720.c and its
 * neighbours are in.
 *
 * Blocked at MATCH on the `label`/`matched` classes: all 68 concrete bytes
 * are right, but DOUBLE3DDISP_InitOam (0x0204E914) has exactly one branch
 * reference image-wide, the call at the end of this function, so the site
 * has no witness and no cut frees it.  0x0204E914 is closed to a register
 * allocation residue, see docs/notes/DOUBLE3DDISP_InitOam.c.txt, which also
 * carries the C for it.
 *
 * Constructor: allocate the 0x6c-byte singleton on the caller's heap and
 * publish it at 0x02146A80.  The `mov r4, #1` is shared between the
 * allocator's third argument and the store to +0x04.  Only the first store
 * uses the pointer the allocator returned; the two after it re-read the
 * global, because a store through it could have overwritten the global
 * itself.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/DOUBLE3DDISP_Init.c \
 *       --func DOUBLE3DDISP_Init --addr 0x0204E8C0 --cc 1.1p1 --arm
 */
void DOUBLE3DDISP_Init(u32 heap)
{
    gDouble3Ddisp = GFL_HEAP_Alloc(heap, 0x6c, 1, double3Ddisp_File, 63);

    gDouble3Ddisp->heap = heap;
    gDouble3Ddisp->displayMode = 1;
    gDouble3Ddisp->drawDone = 0;

    DOUBLE3DDISP_InitOam();
}

/*
 * double3Ddisp.c, second function (the TU starts at DOUBLE3DDISP_Init).  Builds
 * the twelve sub-engine sprites that carry the doubled 3D image, a 4 x 3
 * grid of 64 x 64 cells over 256 x 192, then flushes the OAM copy
 * (DC_FlushRange, DC_FlushRange) and loads it at OAM offset 0x3A0
 * (GXS_LoadOAM, GXS_LoadOAM).
 *
 * The lever that closed it (wave 17, from 15 bytes out): the inner loop
 * takes a pointer to the ENTRY, `oam = &gDouble3Ddisp->oam[k]`, and stores both
 * attributes through it.  Indexing the array base (`oam = g->oam;
 * oam[k].f.attr01 = ...`) builds the same instructions but gives the base,
 * attr01 and attr2 three fresh registers (push r3 and sb as well).  The
 * declaration order i, x, y, k, oam (wave 16) is still load-bearing: it
 * makes the clearing counter share x's register and y take the stored zero.
 */
void DOUBLE3DDISP_InitOam(void)
{
    s32 i;
    s32 x;
    s32 y;
    s32 k;
    union OamEntry *oam;

    REG32(0x04001000) = (REG32(0x04001000) & ~0x60) | 0x20;

    k = 0;

    for (i = 0; i < 12; i++) {
        gDouble3Ddisp->oam[i].w[0] = 0;
        gDouble3Ddisp->oam[i].w[1] = 0;
    }

    for (y = 0; y < 0xc0; y += 0x40) {
        for (x = 0; x < 0x100; x += 0x40) {
            oam = &gDouble3Ddisp->oam[k];
            oam->f.attr01 = 0xc0000c00 | (y & 0xff) | ((x & 0x1ff) << 16);
            oam->f.attr2 = (x / 8 + (y / 8) * 32) | 0xf000;
            k++;
        }
    }

    DC_FlushRange(gDouble3Ddisp->oam, 0x60);
    GXS_LoadOAM(gDouble3Ddisp->oam, 0x3a0, 0x60);
}

int DOUBLE3DDISP_Exit(void)
{
    GX_DisableBankForLCDC();
    GX_DisableBankForSubBG();
    GX_DisableBankForSubOBJ();
    GFL_HEAP_Free(gDouble3Ddisp);
    gDouble3Ddisp = 0;
    return 0;
}

/*
 * The +4 word of the singleton, through its pool word.  The same global
 * DOUBLE3DDISP_Delete and DOUBLE3DDISP_SetupGraphics write.
 */
u32 DOUBLE3DDISP_GetMode(void)
{
    return gDouble3Ddisp->displayMode;
}

/*
 * Sets the +8 word of the cell-actor singleton to 1.
 * Witness leaf for ov180 HALL_OF_FAME_DrawParticles.
 */
void DOUBLE3DDISP_SetDrawDone(void)
{
    gDouble3Ddisp->drawDone = 1;
}

/*
 * The cell-actor system's shutdown step: it bails out while the power-control
 * halfword at 0x04000304 is non-zero, then tears the system down one way or
 * the other depending on the +4 word of the singleton, clears +8 and toggles
 * +4 to 1 if it was 0.
 *
 * 0x04000606 is a hardware address cast in the source, not a relocation: it
 * is a pool word with no symbols block entry, and the halfword there is read
 * (which is what a `u16` hardware register at that address looks like).
 *
 * The +4 word is both tested and then re-read, and both re-reads of the
 * singleton (`ldr r0, [pc, #0x24]; ldr r1, [r0]`) are the global's own address
 * being reloaded after the call, so the source spells `gDouble3Ddisp` out again
 * instead of holding it in a local.
 *
 * `x = (x == 0) ? 1 : 0` comes out as `mov r2, #0` before the earlier store
 * and a single predicated `moveq r2, #1` here: the zero is materialised once
 * and shared with the store of 0 to +8.
 */
void DOUBLE3DDISP_Delete(void)
{
    if (*(volatile u16 *)0x04000606 != 0) {
        return;
    }
    if (gDouble3Ddisp->drawDone == 0) {
        return;
    }
    if (gDouble3Ddisp->displayMode != 0) {
        DOUBLE3DDISP_SetupGraphicsSubObj();
    } else {
        DOUBLE3DDISP_SetupGraphics();
    }
    gDouble3Ddisp->drawDone = 0;
    gDouble3Ddisp->displayMode = (gDouble3Ddisp->displayMode == 0) ? 1 : 0;
}

/*
 * The mirror of DOUBLE3DDISP_SetupGraphicsSubObj, and DOUBLE3DDISP_Delete's other shutdown arm: it
 * *sets* bit 15 of the power-control halfword at 0x04000304 instead of
 * clearing it, runs the complementary SDK calls, and leaves 0x04001000 and
 * 0x0400100c in the "on" state.
 *
 * Three things here are spelling rather than codegen.  The u32 clear is
 * `& ~0x1f00`, which is encodable and becomes `bic`; the u16 mask at the very
 * end is written `& 0xffbf` rather than `& ~0x40` because 0xffbf is not an ARM
 * immediate and therefore costs a pool word, which is what the image has -
 * `~0x40` would have been a `bic #0x40` and four bytes shorter.  And the two
 * last statements each read 0x0400100c afresh, because the first one's store
 * makes the second's read a genuinely new volatile load.
 */
void DOUBLE3DDISP_SetupGraphics(void)
{
    u16 v = *(volatile u16 *)0x04000304;

    *(volatile u16 *)0x04000304 = v | 0x8000;
    GX_ResetBankForSubOBJ();
    GX_SetBankForSubBG(4);
    GX_SetBankForLCDC(8);
    *(volatile u32 *)0x04000064 = 0x80330010;
    GX_SetGraphicsMode(1, 0, 1);
    GXS_SetGraphicsMode(5);
    *(volatile u32 *)0x04001000 = (*(volatile u32 *)0x04001000 & ~0x1f00) | 0x400;
    *(volatile u16 *)0x0400100c = (*(volatile u16 *)0x0400100c & 0x43) | 0x84 | 0x4000;
    *(volatile u16 *)0x0400100c = *(volatile u16 *)0x0400100c & 0xffbf;
}

/*
 * The other arm of DOUBLE3DDISP_Delete's shutdown: it clears bit 15 of the
 * power-control halfword at 0x04000304, runs three SDK calls, writes
 * 0x80320010 to 0x04000064, runs the two channel teardowns and finally sets
 * bit 12 of 0x04001000 in place.
 *
 * Every one of those addresses is a cast constant, not a symbol: the pool
 * words carry no relocations.  The first and the fifth share a single pool
 * word, because 0x04000064 is 0x2A0 below 0x04000304 and the load's reach
 * covers it - that is the "pool base for a far field" sharing
 * (docs/idioms/pool-base-for-a-far-field-is-the-symbol-offset-masked-by-the-load-reach.md),
 * and writing the second address as its own literal costs an extra pool word
 * and four bytes.
 *
 * Both read-modify-writes are one expression each, which is why there is
 * exactly one load and one store per register despite both being volatile.
 */
void DOUBLE3DDISP_SetupGraphicsSubObj(void)
{
    u16 v = *(volatile u16 *)0x04000304;

    *(volatile u16 *)0x04000304 = (u16)(v & ~0x8000);
    GX_ResetBankForSubBG();
    GX_SetBankForSubOBJ(8);
    GX_SetBankForLCDC(4);
    *(volatile u32 *)0x04000064 = 0x80320010;
    GX_SetGraphicsMode(1, 0, 1);
    GXS_SetGraphicsMode(5);
    *(volatile u32 *)0x04001000 = (*(volatile u32 *)0x04001000 & ~0x1f00) | 0x1000;
}
