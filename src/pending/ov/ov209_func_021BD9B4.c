/*
 * function: func_021BD9B4
 * address: 0x021BD9B4
 * packet: pkt_ov209_021BD9B4
 * region: ov209
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: DIFF
 * note (2026-10-04, wave D3 lane 17): DIFF. Structure and all callees/constants decoded
 *   (3 init loops of -1 at p+0xB64 x0x24, p+0xBF4 x6, p+0xC0C x6; handle 0x9f group; handle 7
 *   group with two 16-iteration loops at p+0xB64 and p+0xBA4; handle func_020275E4 group).
 *   Body is 472 bytes versus 500: the original keeps 0x6b in r7 for the first two stack
 *   arguments (movs r7,#0x6b; str r7,[sp] twice) and r6=0 (movs r6,#0) from the first group,
 *   so 0xBF0 is spilled to [sp,#8] and the frame is sp #0x18 with push r3; mine rematerialises
 *   0x6b per call and keeps 0xBF0 in r4 (frame 0xC). The original loops also use a separate
 *   zero local r4 copied from the loop counter r6 (adds r4,r6,#0) for the four zero arguments
 *   of func_0201BABC. Tried: u32 heap local (constant propagated away), z = i = 0 chained,
 *   separate k counter for the -1 loops, int *arr base pointers for the loop stores (these
 *   fixed the store shape). Next: find what makes mwcc CSE 0x6b into a register for stack args.
 * 2026-10-05 (wave D4 lane 01): DIFF, residue unchanged. Listing reading: the original keeps 0xBF0 in a
 *   spilled slot [sp,#8] and derives every later offset from it at run time (0xC08 = +0x18, 0xC20 = +0x30,
 *   0xB64 = -0x8c, 0xBF4 = +4, 0xC0C = +0x1c), then loads 0xBA4 and derives 0xBF8 (+0x54) and 0xC10 (+0x6c);
 *   so the source holds an offset in a local (D3 lever). Tried: off = 0xBF0 local with `p + (off + K)` (the
 *   adds appear, but off takes r4 and the 0x6b CSE into r7 is lost); `z = i = 0` moved after the first
 *   func_020490F4 call (fixes the early movs r6,#0); a heap local 0x6b (propagated); explicit ob/oc locals
 *   per group (propagated and folded); chr/pl/ce pointer locals (worse). Next: find why off spills while
 *   0x6b stays CSE'd in r7 (five live values: h r4, p r5, i r6, 0x6b r7, off on the stack).
 * 2026-10-05 (wave D5 lane09): DIFF, residue unchanged (472 vs 500 bytes). New reading: the derived
 *   offsets (+0x18, +0x30, -0x8c, +4, +0x1c, 0xBA4+0x54/+0x6c, 0xBEC+0x18/+0x30) are mwcc's own Thumb
 *   constant derivation (this draft emits them too). The real gap is the 0x6b in r7 for the first two
 *   stack arguments of the 0x9f group: in the 0x7 and func_020275E4 groups the original rematerialises
 *   0x6b even when r7 is free, so the r7 copy is a source value, not a compiler CSE. Tried: one handle
 *   variable for all three groups (identical output); the 0x9f group as a static inline helper with a
 *   u32 heap parameter and `heap | 0x8000` (propagated, identical). Next: find a source value equal to
 *   0x6b that survives propagation for the two stack arguments only.
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_02049238 0x02049238 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204ABF0 0x0204ABF0 arm
 *   func_0204ACEC 0x0204ACEC arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_0201BABC 0x0201BABC thumb
 *   func_0201BC3C 0x0201BC3C thumb
 *   func_0201BC40 0x0201BC40 thumb
 *   func_0201BC78 0x0201BC78 thumb
 *   func_0201BCB4 0x0201BCB4 thumb
 *   func_0201BCEC 0x0201BCEC thumb
 *   func_020275E4 0x020275E4 thumb
 *   func_02027614 0x02027614 thumb
 *   func_02027618 0x02027618 thumb
 *   func_0202761C 0x0202761C thumb
 *   func_02027620 0x02027620 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_020490F4(int, int);
extern void func_02049238(int);
extern int func_0204A6C8(int, u32, u32, u32, u16);
extern int func_0204ABF0(int, u32, u32, u32, u16);
extern int func_0204ACEC(int, u32, u32, u32, u16);
extern int func_0204AF28(int, u32, u32, u32);
extern u32 func_0201BABC(u32, u32, u32, u32);
extern u32 func_0201BC3C(void);
extern u32 func_0201BC40(void);
extern u32 func_0201BC78(void);
extern u32 func_0201BCB4(void);
extern u32 func_0201BCEC(void);
extern int func_020275E4(void);
extern u32 func_02027614(void);
extern u32 func_02027618(void);
extern u32 func_0202761C(u32);
extern u32 func_02027620(u32);

void func_021BD9B4(u8 *p)
{
    int h, h2, h3;
    u32 i;
    u32 k;
    u32 z;
    u32 a;
    int *arr;

    for (k = 0; k < 0x24; k++) *(int *)(p + k * 4 + 0xB64) = -1;
    for (k = 0; k < 6; k++) *(int *)(p + k * 4 + 0xBF4) = -1;
    for (k = 0; k < 6; k++) *(int *)(p + k * 4 + 0xC0C) = -1;

    h = func_020490F4(0x9f, 0x806B);
    *(int *)(p + 0xBF0) = func_0204A6C8(h, 0x37, 0, 0, 0x6b);
    *(int *)(p + 0xC08) = func_0204ABF0(h, 0x33, 0, 0, 0x6b);
    *(int *)(p + 0xC20) = func_0204AF28(h, 0x3d, 0x47, 0x6b);
    func_02049238(h);

    z = i = 0;
    h2 = func_020490F4(7, 0x806B);
    arr = (int *)(p + 0xB64);
    for (; i < 0x10; i++)
        arr[i] = func_0204A6C8(h2, func_0201BABC(z, z, z, z), z, z, 0x6b);
    *(int *)(p + 0xBF4) = func_0204ACEC(h2, func_0201BC3C(), z, 0x80, 0x6b);
    a = func_0201BC40();
    *(int *)(p + 0xC0C) = func_0204AF28(h2, a, func_0201BCB4(), 0x6b);

    arr = (int *)(p + 0xBA4);
    for (i = 0; i < 0x10; i++)
        arr[i] = func_0204A6C8(h2, func_0201BABC(0, 0, 0, 0), 0, 1, 0x6b);
    *(int *)(p + 0xBF8) = func_0204ACEC(h2, func_0201BC3C(), 1, 0, 0x6b);
    a = func_0201BC78();
    *(int *)(p + 0xC10) = func_0204AF28(h2, a, func_0201BCEC(), 0x6b);
    func_02049238(h2);

    h3 = func_020490F4(func_020275E4(), 0x806B);
    *(int *)(p + 0xBEC) = func_0204A6C8(h3, func_02027618(), 0, 0, 0x6b);
    *(int *)(p + 0xC04) = func_0204ABF0(h3, func_02027614(), 0, 0xe0, 0x6b);
    a = func_0202761C(2);
    *(int *)(p + 0xC1C) = func_0204AF28(h3, a, func_02027620(2), 0x6b);
    func_02049238(h3);
}
