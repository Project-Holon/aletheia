/*
 * function: func_020425B4
 * address:  0x020425B4
 * packet:   pkt_02041F28
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DC_FlushRange   0x020862F0  arm
 *   GX_LoadBG0Char   0x0207EE68  arm
 *   func_0207EF90   0x0207EF90  arm
 *   func_0207F024   0x0207F024  arm
 *   GX_LoadBG2Char   0x0207F0B8  arm
 *   func_0207EEFC   0x0207EEFC  arm
 *   func_0207F14C   0x0207F14C  arm
 *   func_0207F1E0   0x0207F1E0  arm
 *   func_0207F274   0x0207F274  arm
 *
 * The character-base twin of func_0204241C, byte for byte the same shape
 * over the next eight entries of the same SDK object (0x0207EE68 first,
 * 0x94 bytes each): flush, then dispatch on the layer index 0..7 with the
 * source, offset and size passed through in r1/r2/r3.  The sub-engine
 * callees are the second group of four, which is why the case order is not
 * the address order; see the symbol note in func_0204241C.c.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020425B4.c \
 *       --func func_020425B4 --addr 0x020425B4 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

extern void DC_FlushRange(void *p, u32 size);
extern void GX_LoadBG0Char(const void *src, u32 offset, u32 size);
extern void func_0207EF90(const void *src, u32 offset, u32 size);
extern void func_0207F024(const void *src, u32 offset, u32 size);
extern void GX_LoadBG2Char(const void *src, u32 offset, u32 size);
extern void func_0207EEFC(const void *src, u32 offset, u32 size);
extern void func_0207F14C(const void *src, u32 offset, u32 size);
extern void func_0207F1E0(const void *src, u32 offset, u32 size);
extern void func_0207F274(const void *src, u32 offset, u32 size);

void func_020425B4(u32 layer, const void *src, u32 offset, u32 size)
{
    DC_FlushRange((void *)src, size);

    switch (layer) {
    case 0:
        GX_LoadBG0Char(src, offset, size);
        break;
    case 1:
        func_0207EF90(src, offset, size);
        break;
    case 2:
        GX_LoadBG2Char(src, offset, size);
        break;
    case 3:
        func_0207F1E0(src, offset, size);
        break;
    case 4:
        func_0207EEFC(src, offset, size);
        break;
    case 5:
        func_0207F024(src, offset, size);
        break;
    case 6:
        func_0207F14C(src, offset, size);
        break;
    case 7:
        func_0207F274(src, offset, size);
        break;
    }
}
