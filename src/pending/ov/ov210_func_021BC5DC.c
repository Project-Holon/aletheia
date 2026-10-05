/*
 * function: func_021BC5DC
 * address: 0x021BC5DC
 * packet: pkt_ov210_021BC5DC
 * region: ov210
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: DIFF
 * 2026-10-05 (wD7 lane19): still DIFF 67. Probe: changing one 4 (call 9 r2) to 9 still CSEs 4 into r7, so 4 does not win r7 by use count over 0x807B. The ours-only copies (r2/r3 = r5/r7) start at call 8, the same point as in ov123 021D9D3C (late calls copy hoisted constants). Image: r4 0x7B, r5 0 (i), r6 h, r7 0x807B, no free callee-saved register for 4. Open: why 0x807B is not CSE'd from the pool.
 * 2026-10-05 (wave D6 lane18): DIFF 67. New reading: r7 is 0x807B only until the second open; after
 *   func_02049740 r7 is `base` (the loop uses (u16)r7). In region 1 the image CSEs only the stack-argument
 *   constants (0x7B r4, 0 r5) and 0x807B (pool); ours CSEs 4 (three register uses) into r7, and then all
 *   register zeros are copies of r5. The sibling ov209 021BC574 (all literals, one 4 in region 1) keeps
 *   immediates. Tried: func_020490F4 heap as u32 and int (67); `for (i = 0; ...)` with i uninitialised (86,
 *   r5 zero still copied into register arguments).
 * 2026-10-05 (wD5 lane14): still DIFF 67. Reading: r5 is the loop counter i (0) and the image
 *   stores it for stack zeros, but uses immediates for register zeros and 4s; r7 holds 0x807B. Tried:
 *   `u32 heap = 0x807B;` local, the whole body as a static inline helper with a heap parameter, i = 0
 *   after the first call (84), unsigned long i, func_020413B0 with the house u8 parameters, u8 c for
 *   func_02049B68/9658/98F4: all 67 except where noted.
 * 2026-10-04 (wave D2 lane 08): re-tested, still DIFF (67 bytes). Image CSEs 0x807B into r7 (loaded at entry, used by both func_020490F4 calls) and 0x7B into r4; ours loads 0x807B into r1 per use, sets r5=0 before the first call (image: after the first call) and CSEs 4 into r7. Not resolved.
 * note (2026-10-02): logic complete, 67 bytes differ, all register choice. The original keeps
 *   0x807B in r7 (ldr r7 at entry, adds r1,r7 for both opens) and loads reg-arg zeros and 4s
 *   as immediates. This draft reloads 0x807B from the pool, CSEs 4 into r7 and copies r5 (zero)
 *   into r2/r3. Tried: heap local (u16/u32/enum), heap reused as base, int protos, loop shapes.
 * 2026-10-05 (wave D4 lane 04): DIFF, 67 bytes. Callee prototypes switched to the house forms (u16
 * heap as last parameter, u16 heap for func_020490F4): same output. Tried: for (i = 0; ...) with i not
 * initialised at its declaration (86 bytes). Residue unchanged: the original CSEs 0x807B in r7 and
 * uses immediates for the 4/0 register arguments; ours CSEs 4 in r7 and copies zeros from r5.
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049740 0x02049740 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   func_02049238 0x02049238 arm
 *   func_020275E4 0x020275E4 thumb
 *   func_02027628 0x02027628 thumb
 *   func_02027624 0x02027624 thumb
 *   func_0202762C 0x0202762C thumb
 *   func_020413B0 0x020413B0 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_0204162C 0x0204162C arm
 *   func_02049B40 0x02049B40 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_020490F4(unsigned int id, u16 heap);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_02049740(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u16 flags);
extern void func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_02049238(void *h);
extern u32 func_020275E4(void);
extern u32 func_02027628(void);
extern u32 func_02027624(void);
extern u32 func_0202762C(void);
extern void func_020413B0(u32, u32, u32, u32, u32, u32);
extern void func_02041B6C(u32 layer);
extern u32 func_0204162C(int channel);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);

void func_021BC5DC(void)
{
    void *h;
    u32 base;
    u32 i = 0;
    u8 *scr;

    h = func_020490F4(0x9F, 0x807B);
    func_02049B68(h, 0x49, 0, 0, 0xC0, 0x7B);
    func_02049B68(h, 0x4A, 4, 0, 0xA0, 0x7B);
    func_02049740(h, 0x51, 0, 0, 0, 0x7B);
    func_02049658(h, 0x51, 1, 0, 0, 0, 0x7B);
    func_02049658(h, 0x51, 3, 0, 0, 0, 0x7B);
    func_02049658(h, 0x4F, 2, 0, 0, 0, 0x7B);
    func_02049658(h, 0x51, 5, 0, 0, 0, 0x7B);
    func_02049658(h, 0x50, 6, 0, 0, 0, 0x7B);
    func_02049658(h, 0x50, 4, 0, 0, 0, 0x7B);
    func_020498F4(h, 0x5F, 2, 0, 0, 0, 0x7B);
    func_020498F4(h, 0x5E, 4, 0, 0, 0, 0x7B);
    func_020498F4(h, 0x60, 6, 0, 0, 0, 0x7B);
    func_02049238(h);
    h = func_020490F4(func_020275E4(), 0x807B);
    base = func_02049740(h, func_02027628(), 0, 0, 0, 0x7B);
    func_02049B68(h, func_02027624(), 0, 0x1C0, 0x20, 0x7B);
    func_020498F4(h, func_0202762C(), 0, 0, 0, 0, 0x7B);
    func_020413B0(0, 0, 0x15, 0x20, 3, 0xE);
    func_02041B6C(0);
    func_02049238(h);
    scr = (u8 *)func_0204162C(0);
    for (; i < 0x60; i++) {
        ((u16 *)scr)[i + 0x2A0] += (u16)base;
    }
    func_02041B6C(0);
    func_02049B40(0x17, 5, 0, 0x1E0, 0x20, 0x7B);
    func_02049B40(0x17, 5, 4, 0x1E0, 0x20, 0x7B);
}
