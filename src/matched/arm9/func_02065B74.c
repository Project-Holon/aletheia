/*
 * function: NNS_G2dInitRenderSurface
 * address:  0x02065B74
 * packet:   pkt_02064B68
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Wipe and initialise a 0x48-byte object: MIi_CpuClear16(0, p, 0x48) first,
 * then the state word at +0x10, the mode word at +0x14 and four function
 * pointers at +0x18..+0x24 -- a vtable laid out in the object itself, in pool
 * order, not an array of addresses.
 *
 * Pinned to ../2.0/sp2 on the "kept constants" tell: the image interleaves
 * load/store and rematerialises 1 and 3 into r0 between the stores, where
 * dsi/1.1p1 -O4,p hoists all four address loads to the top of the body and
 * holds the two constants live in lr/ip, 92 bytes and 31 concrete out at the
 * same size.  Under the pin the same C is 0 mismatches.  See
 * docs/FRONTEND-PINS.md.
 *
 * The four ABS32 pool words resolve by sole-ref/code (each is exactly a
 * traced func_ label); the earlier MATCH cap recorded in
 * docs/notes/pkt_02065B74.c.txt predates that class being widened.
 *
 * symbols:
 *   MIi_CpuClear16   0x02082A48  arm
 *   NNSi_G2dRendererBeforeDrawCell    0x02065020  arm
 *   NNSi_G2dRendererAfterDrawCell    0x02065134  arm
 *   NNSi_G2dRendererPreDrawOam    0x020651B8  arm
 *   NNSi_G2dRendererCallSurfaceOamFunc    0x020653A4  arm
 */

typedef unsigned char u8;
typedef unsigned int u32;

struct Obj {
    u8   pad_00[0x10];
    u32  state;     /* 0x10 */
    u32  mode;      /* 0x14 */
    u32  fn18;      /* 0x18 */
    u32  fn1c;      /* 0x1c */
    u32  fn20;      /* 0x20 */
    u32  fn24;      /* 0x24 */
};

extern void MIi_CpuClear16(u32 val, void *dst, u32 size);

struct Cell;
struct Host;
extern void NNSi_G2dRendererBeforeDrawCell(struct Host *h, void *a1);
extern void NNSi_G2dRendererAfterDrawCell(void *a0, void *a1);
extern void NNSi_G2dRendererPreDrawOam(struct Cell *c, void *a1, void *a2);
extern void NNSi_G2dRendererCallSurfaceOamFunc(void *a0, void *a1, void *a2);

void NNS_G2dInitRenderSurface(struct Obj *p)
{
    MIi_CpuClear16(0, p, 0x48);

    p->state = 1;
    p->mode  = 3;

    p->fn18 = (u32)NNSi_G2dRendererBeforeDrawCell;
    p->fn1c = (u32)NNSi_G2dRendererAfterDrawCell;
    p->fn20 = (u32)NNSi_G2dRendererPreDrawOam;
    p->fn24 = (u32)NNSi_G2dRendererCallSurfaceOamFunc;
}
