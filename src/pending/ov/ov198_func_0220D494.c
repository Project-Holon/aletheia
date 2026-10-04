/*
 * function: func_0220D494
 * address:  0x0220D494
 * packet:   pkt_0220D494
 * region:   ov198
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * symbols:
 *   func_02045EC0 0x02045EC0 arm
 *   func_02045770 0x02045770 arm
 *   func_0201C724 0x0201C724 thumb
 *   func_02045808 0x02045808 arm
 *   func_020457B0 0x020457B0 arm
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_0201D304 0x0201D304 thumb
 *   func_02045738 0x02045738 arm
 *
 * Near miss: the body is byte-for-byte right in shape; the residue is pure
 * register allocation / frame packing. The original keeps `handle` in r7
 * (used only for the 45738 call, then r7 is recycled by the shifted coordinate)
 * with `base` in [sp+0x1c] and `off` in r6, and packs the frame as
 * push {r3,r4,r5,r6,r7,lr} / sub sp,#0x40.  Naming base/off or inlining the
 * array, splitting f/y per block, and hoisting handle all leave the allocator
 * choosing a different split (5-reg push + #0x44) and one extra instruction.
 * Needs a different spelling of the three draw blocks; not an evidence problem.
 *
 * Re-verified (DIFF fixer): still 391 concrete bytes; all 15 relocations
 * resolve, so it is a frame-packing/allocation residue, not evidence.
 */
/*
 * 2026-10-04 (wave D2 lane03): DIFF, unchanged. Reading of the original frame: 16 words (0x40), mine 17.
 * Original keeps base1 = p+0x1F70 at [sp,#0x1C] and base2 = p+0x1F74 at [sp,#0x28] (two separate hoists,
 * one for the handle load, one for the flag strb); w1 stays at [sp,#0x24] and is reloaded in block 3
 * (`adds r2,r7,r2`); in block 3 the f1eac load lands in r4 (the pool register is dead by then:
 * `subs r4,#0xc4; ldr r4,[r5,r4]` after the handle load, before the 02045770 call) so block 3 needs no
 * f spill slot. Blocks 1 and 2 spill f to 0x18 and 0x14. Mine spills w1 and uses a different slot set.
 * Next idea: model slot records as `struct {u32 h; u8 flag;} *s = (p+0x1F70)` with `s[a1].h` read and
 * `s[a1].flag` written, and read f1eac after the handle in block 3 only.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

extern void *func_02045EC0(void *a, u32 b);
extern u32   func_02045770(void *a);
extern void  func_0201C724(u32 a, u32 b, s16 c, u32 d, u32 e, u32 f, u16 g);
extern void  func_02045808(void *a);
extern u32   func_020457B0(u32 a, u32 b);
extern void  func_0201EFA4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f);
extern void  func_0201F250(void *a, u32 b, void *c);
extern u32   func_0201D304(u32 a, u32 b, u32 c);
extern u32   func_02045738(void *a);

void func_0220D494(char *p, int a1, int a2, int a3)
{
    char *base = p + 0x1f70;
    int off = a1 * 8;
    u32 handle = *(u32 *)(base + off);
    u32 w1;
    u32 r7;

    {
        void *t1;
        u32 f;
        u32 y;

        t1 = func_02045EC0(*(void **)(p + 0x1ea0), 0x38);
        w1 = func_0201D304((u32)t1, *(u32 *)(*(u32 *)p + 0xc), 0);
        r7 = ((func_02045738((void *)handle) << 3) - w1) >> 1;
        f = *(u32 *)(p + 0x1eac);
        y = func_02045770((void *)*(u32 *)(base + off));
        func_0201C724(f, y, (s16)r7, 0, (u32)t1,
                      *(u32 *)(*(u32 *)p + 0xc), 0x3dc0);
        *(u8 *)(base + off + 4) = 1;
        func_02045808(t1);
    }

    {
        void *t2;
        u32 h2;
        u32 w2;
        u32 f;
        u32 y;

        t2 = func_02045EC0(*(void **)(p + 0x1ea0), 0x36);
        h2 = func_020457B0(6, *(u16 *)(*(u32 *)p + 0x10));
        func_0201EFA4(*(void **)(p + 0x1ea4), 0, a2, 3, 0, 1);
        func_0201F250(*(void **)(p + 0x1ea4), h2, t2);
        w2 = func_0201D304(h2, *(u32 *)(*(u32 *)p + 0xc), 0);
        f = *(u32 *)(p + 0x1eac);
        y = func_02045770((void *)*(u32 *)(base + off));
        func_0201C724(f, y, (s16)(r7 - w2), 0, h2,
                      *(u32 *)(*(u32 *)p + 0xc), 0x3dc0);
        *(u8 *)(base + off + 4) = 1;
        func_02045808(t2);
        func_02045808((void *)h2);
    }

    {
        void *t3;
        u32 h3;
        u32 f;
        u32 y;

        t3 = func_02045EC0(*(void **)(p + 0x1ea0), 0x37);
        h3 = func_020457B0(6, *(u16 *)(*(u32 *)p + 0x10));
        func_0201EFA4(*(void **)(p + 0x1ea4), 0, a3, 3, 0, 1);
        func_0201F250(*(void **)(p + 0x1ea4), h3, t3);
        f = *(u32 *)(p + 0x1eac);
        y = func_02045770((void *)*(u32 *)(base + off));
        func_0201C724(f, y, (s16)(r7 + w1), 0, h3,
                      *(u32 *)(*(u32 *)p + 0xc), 0x3dc0);
        *(u8 *)(base + off + 4) = 1;
        func_02045808(t3);
        func_02045808((void *)h3);
    }
}
