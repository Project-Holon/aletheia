/*
 * function: DOUBLE3DDISP_InitOam
 * address:  0x0204E914
 * packet:   pkt_0204E914
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   gDouble3Ddisp     0x02146A80  data
 *   DC_FlushRange  0x020862F0  arm
 *   GXS_LoadOAM  0x0207E708  arm
 *
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
typedef unsigned short u16;
typedef unsigned int   u32;
typedef int            s32;

union OamEntry {
    u32 w[2];
    struct { u32 attr01; u16 attr2; u16 attr3; } f;
};

struct Double3Ddisp {
    u16 heap;
    u16 pad02;
    s32 unk04;
    s32 unk08;
    union OamEntry oam[12];
};

extern struct Double3Ddisp *gDouble3Ddisp;
extern void DC_FlushRange(void *p, u32 n);
extern void GXS_LoadOAM(void *p, u32 off, u32 n);

#define REG32(a) (*(volatile u32 *)(a))

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
