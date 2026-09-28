/*
 * function: func_0204241C
 * address:  0x0204241C
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
 *   func_0207E888   0x0207E888  arm
 *   func_0207EA00   0x0207EA00  arm
 *   func_0207EB78   0x0207EB78  arm
 *   func_0207ECF0   0x0207ECF0  arm
 *   func_0207E944   0x0207E944  arm
 *   func_0207EABC   0x0207EABC  arm
 *   func_0207EC34   0x0207EC34  arm
 *   func_0207EDAC   0x0207EDAC  arm
 *
 * One screen-base upload for the layer in r0: flush the source range and
 * then dispatch on the layer index 0..7.  The eight callees are consecutive
 * entries of the same SDK object (gx_load2d.o, 188 bytes each, 0x0207E888
 * first), four for the main engine then four for the sub engine, and
 * layout/symbols_sdk.txt gives all eight the same recovered name, so they
 * are named by address here rather than by a guess at the BG number.
 *
 * The three transform arguments are passed straight through in r1/r2/r3
 * (nothing in any arm writes r1 or r3) and every arm repeats the same
 * `mov r0, r1, r2` trio before its call; the flush gets the source and the
 * size, the arms get source, offset and size.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204241C.c \
 *       --func func_0204241C --addr 0x0204241C --cc 1.1p1 --arm
 */

typedef unsigned int u32;

extern void DC_FlushRange(void *p, u32 size);
extern void func_0207E888(const void *src, u32 offset, u32 size);
extern void func_0207EA00(const void *src, u32 offset, u32 size);
extern void func_0207EB78(const void *src, u32 offset, u32 size);
extern void func_0207ECF0(const void *src, u32 offset, u32 size);
extern void func_0207E944(const void *src, u32 offset, u32 size);
extern void func_0207EABC(const void *src, u32 offset, u32 size);
extern void func_0207EC34(const void *src, u32 offset, u32 size);
extern void func_0207EDAC(const void *src, u32 offset, u32 size);

void func_0204241C(u32 layer, const void *src, u32 offset, u32 size)
{
    DC_FlushRange((void *)src, size);

    switch (layer) {
    case 0:
        func_0207E888(src, offset, size);
        break;
    case 1:
        func_0207EA00(src, offset, size);
        break;
    case 2:
        func_0207EB78(src, offset, size);
        break;
    case 3:
        func_0207ECF0(src, offset, size);
        break;
    case 4:
        func_0207E944(src, offset, size);
        break;
    case 5:
        func_0207EABC(src, offset, size);
        break;
    case 6:
        func_0207EC34(src, offset, size);
        break;
    case 7:
        func_0207EDAC(src, offset, size);
        break;
    }
}
