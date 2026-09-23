/*
 * function: func_0204E914
 * address:  0x0204E914
 * packet:   pkt_0204E914
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   g_02146A80     0x02146A80  data
 *   func_020862F0  0x020862F0  arm
 *   func_0207E708  0x0207E708  arm
 *
 * double3Ddisp.c, second function (the TU starts at func_0204E8C0).  Builds
 * the twelve sub-engine sprites that carry the doubled 3D image, a 4 x 3
 * grid of 64 x 64 cells over 256 x 192, then flushes the OAM copy
 * (func_020862F0, DC_FlushRange) and loads it at OAM offset 0x3A0
 * (func_0207E708, GXS_LoadOAM).
 *
 * The lever that closed it (wave 17, from 15 bytes out): the inner loop
 * takes a pointer to the ENTRY, `oam = &g_02146A80->oam[k]`, and stores both
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

extern struct Double3Ddisp *g_02146A80;
extern void func_020862F0(void *p, u32 n);
extern void func_0207E708(void *p, u32 off, u32 n);

#define REG32(a) (*(volatile u32 *)(a))

void func_0204E914(void)
{
    s32 i;
    s32 x;
    s32 y;
    s32 k;
    union OamEntry *oam;

    REG32(0x04001000) = (REG32(0x04001000) & ~0x60) | 0x20;

    k = 0;

    for (i = 0; i < 12; i++) {
        g_02146A80->oam[i].w[0] = 0;
        g_02146A80->oam[i].w[1] = 0;
    }

    for (y = 0; y < 0xc0; y += 0x40) {
        for (x = 0; x < 0x100; x += 0x40) {
            oam = &g_02146A80->oam[k];
            oam->f.attr01 = 0xc0000c00 | (y & 0xff) | ((x & 0x1ff) << 16);
            oam->f.attr2 = (x / 8 + (y / 8) * 32) | 0xf000;
            k++;
        }
    }

    func_020862F0(g_02146A80->oam, 0x60);
    func_0207E708(g_02146A80->oam, 0x3a0, 0x60);
}
