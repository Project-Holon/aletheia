/*
 * function: BG_SYS_Get
 * address:  0x020416D4
 * packet:   pkt_020416D4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_02146A44  0x02146A44  data
 *
 * The BG priority getter: returns the 2-bit priority field of the layer's
 * BGxCNT register.  Layers 0/1/4/5 read their register directly; layers
 * 2/3/6/7 first consult the slot's +0x1c mode byte, which selects one of
 * three otherwise identical reads of the SAME register (only the stack
 * slot the raw halfword spills to differs).
 *
 * Three declarations carry the whole function and none is optional:
 *
 *  1. The return is a 2-BIT BITFIELD of a struct COPIED from the register,
 *     not a masked read.  `struct BgCnt { u16 prio : 2; u16 rest : 14; }`
 *     assigned into a local is what emits the `lsl #0x1e / lsr #0x1e` pair
 *     AND the `strh r1, [sp, #N]` spill of the raw halfword together.  A
 *     plain `(x & 3)` loses both; a plain u16 local loses the spill.
 *  2. Each read needs its OWN local (c0..c15).  The sixteen distinct
 *     locals are what place the spills at the descending slots 0x1e, 0x1c,
 *     0x1a, ...; one reused local collapses them all onto [sp].
 *  3. The return type is u8, which is the trailing `and r0, r0, #0xff`.
 *
 * WHAT CLOSED THE LAST 303 BYTES (wave 2 of this family).  The four
 * sub-dispatch arms must emit the FULL unfused comparison chain
 *     cmp r0,#0 ; beq A ; cmp r0,#1 ; beq B ; cmp r0,#2 ; beq C ; <fall>
 * where the mode==0 branch target IS the fall-through address, so the
 * mode==0 body is reached both by its own beq and by falling off the end
 * of the chain.  No if/else-if chain reproduces that: the compiler fuses
 * the first test into `cmp r0,#0 / bne`.  An inner `switch` builds a jump
 * table and comes out 16 bytes short.  Only an explicit goto chain
 *     if (m == 0) goto L_0;  if (m == 1) goto L_1;  if (m == 2) goto L_2;
 *     L_0: ...  L_1: ...  L_2: ...
 * with the labels following in source order emits the three separate
 * cmp/beq pairs and lets L_0 double as the fall-through, which is the
 * shape docs/idioms/guards-separated-by-statements-share-an-exit-only-through-goto.md
 * describes.  Caching the mode in a `u8 m` local is part of it: reading
 * `g_02146A44[layer].mode` three times re-emits the mla address
 * computation before each test.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/BG_SYS_Get.c \
 *       --func BG_SYS_Get --addr 0x020416D4 --arm --cc 1.1p1
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct BgCnt { u16 prio : 2; u16 rest : 14; };
struct BgSlot { u8 pad_00[0x1c]; u8 mode; u8 pad_1d[0xf]; };
extern struct BgSlot *g_02146A44;

#define R(a) (*(struct BgCnt *)(a))

u8 BG_SYS_Get(u32 layer)
{
    struct BgCnt c0, c1, c2, c3, c4, c5, c6, c7, c8, c9, c10, c11, c12, c13, c14, c15;

    switch (layer) {
    case 0:
        c0 = R(0x04000008);
        return c0.prio;
    case 1:
        c1 = R(0x0400000a);
        return c1.prio;
    case 2:
        {
            u8 m = g_02146A44[layer].mode;
            if (m == 0) goto L0_0;
            if (m == 1) goto L0_1;
            if (m == 2) goto L0_2;
        L0_0:
            c2 = R(0x0400000c);
            return c2.prio;
        L0_1:
            c3 = R(0x0400000c);
            return c3.prio;
        L0_2:
            c4 = R(0x0400000c);
            return c4.prio;
        }
    case 3:
        {
            u8 m = g_02146A44[layer].mode;
            if (m == 0) goto L1_0;
            if (m == 1) goto L1_1;
            if (m == 2) goto L1_2;
        L1_0:
            c5 = R(0x0400000e);
            return c5.prio;
        L1_1:
            c6 = R(0x0400000e);
            return c6.prio;
        L1_2:
            c7 = R(0x0400000e);
            return c7.prio;
        }
    case 4:
        c8 = R(0x04001008);
        return c8.prio;
    case 5:
        c9 = R(0x0400100a);
        return c9.prio;
    case 6:
        {
            u8 m = g_02146A44[layer].mode;
            if (m == 0) goto L2_0;
            if (m == 1) goto L2_1;
            if (m == 2) goto L2_2;
        L2_0:
            c10 = R(0x0400100c);
            return c10.prio;
        L2_1:
            c11 = R(0x0400100c);
            return c11.prio;
        L2_2:
            c12 = R(0x0400100c);
            return c12.prio;
        }
    case 7:
        {
            u8 m = g_02146A44[layer].mode;
            if (m == 0) goto L3_0;
            if (m == 1) goto L3_1;
            if (m == 2) goto L3_2;
        L3_0:
            c13 = R(0x0400100e);
            return c13.prio;
        L3_1:
            c14 = R(0x0400100e);
            return c14.prio;
        L3_2:
            c15 = R(0x0400100e);
            return c15.prio;
        }
    }

    return 0;
}
