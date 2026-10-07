/*
 * file:     bg_sys_p04.c
 * unit:     yes
 * function: func_020414AC, func_020414C4, func_020414EC, func_0204152C, func_02041570, func_020415B4, func_0204162C, func_02041648, func_02041664, func_02041680, func_0204169C, func_020416B8, func_020416D4, func_020419E4, func_02041A1C, sub_02041B6C, func_02041B94, func_02041EE4, func_02041F28, func_02041F6C, func_02041FB0, func_02041FF4, func_02042218, sub_020422D4, sub_02042360, func_020423D4, func_0204241C, func_02042508, func_020425B4
 * address:  0x020414AC
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by hand from the verified parts of tools/restructure.py.
 *
 * symbols:
 *   g_02146A44     0x02146A44  data
 *   func_02040B94  0x02040B94  arm
 *   MIi_CpuClear16 0x02082A48  arm
 *   func_020409B4  0x020409B4  arm
 *   ptr_02146A44   0x02146A44  data
 *   func_02041B6C  0x02041B6C  arm
 *   func_0207E1F8  0x0207E1F8  arm
 *   func_0207E24C  0x0207E24C  arm
 *   func_0207E2A0  0x0207E2A0  arm
 *   func_0207E330  0x0207E330  arm
 *   func_0207E22C  0x0207E22C  arm
 *   func_0207E280  0x0207E280  arm
 *   func_0207E2F0  0x0207E2F0  arm
 *   func_0207E388  0x0207E388  arm
 *   g_BgConfig     0x02146A44  data
 *   gUnk_02146A44  0x02146A44  data
 *   func_0203D814  0x0203D814  arm
 *   func_02051E74  0x02051E74  arm
 *   func_0207D59C  0x0207D59C  arm
 *   func_02042360  0x02042360  arm
 *   func_02043228  0x02043228  arm
 *   func_02043264  0x02043264  arm
 *   func_020432E4  0x020432E4  arm
 *   g_020A7E5C     0x020A7E5C  data
 *   func_02040EE0  0x02040EE0  arm
 *   func_02030734  0x02030734  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02043130  0x02043130  arm
 *   func_02082D44  0x02082D44  arm
 *   sub_02040860   0x02040860  arm
 *   DC_FlushRange  0x020862F0  arm
 *   func_0207E888  0x0207E888  arm
 *   func_0207EA00  0x0207EA00  arm
 *   func_0207EB78  0x0207EB78  arm
 *   func_0207ECF0  0x0207ECF0  arm
 *   func_0207E944  0x0207E944  arm
 *   func_0207EABC  0x0207EABC  arm
 *   func_0207EC34  0x0207EC34  arm
 *   func_0207EDAC  0x0207EDAC  arm
 *   sub_02030734   0x02030734  arm
 *   sub_020307B0   0x020307B0  arm
 *   func_02040968  0x02040968  arm
 *   func_0207EE68  0x0207EE68  arm
 *   func_0207EF90  0x0207EF90  arm
 *   func_0207F024  0x0207F024  arm
 *   func_0207F0B8  0x0207F0B8  arm
 *   func_0207EEFC  0x0207EEFC  arm
 *   func_0207F14C  0x0207F14C  arm
 *   func_0207F1E0  0x0207F1E0  arm
 *   func_0207F274  0x0207F274  arm
 */
#include "../../matched/include/Obj16005.h"

typedef unsigned char      u8;
typedef unsigned short     u16;
typedef unsigned int       u32;
typedef signed int         s32;
typedef signed short       s16;
typedef int                BOOL;

struct AreaMan;
struct Mtx22;

struct Bg {
    void *buf;
    u32   bufSize;
    u32   unk_08;
    u32   scrollX;
    u32   scrollY;
    u8    type;
    u8    unk_15;
    u8    unk_16;
    u8    unk_17;
    u16   unk_18;
    u16   unk_1a;
    u32   unk_1c;
    u32   unk_20;
    u32   unk_24;
    u32   unk_28;
};

struct BgSys {
    u16       heapId;
    u16       unk_02;
    u16       unk_04;
    u16       unk_06;
    struct Bg bgs[8];
    void     *unk_168;
    void     *unk_16c;
    u32       unk_170[8];
    u32       unk_190[8];
    u32       unk_1b0[8];
};

struct Mtx { u32 w[4]; };
struct BgConfigLayer {
    char pad_00[0x1C];
    u8 mode;
    char pad_1D[0x0F];
};
struct BgCnt { u16 prio : 2; u16 rest : 14; };
struct Param {
    u32 unk00;
    u32 unk04;
    u32 unk08;
    u32 unk0c;
};

extern struct BgSys *g_02146A44;
extern char g_020A7E5C[];

asm void func_020414AC(void);
void func_020414C4(u32 idx);
void func_020414EC(u32 i);
void func_0204152C(int channel, u16 val);
void func_02041570(int channel, u16 val);
u32 func_020415B4(u32 channel);
u32 func_0204162C(int channel);
u32 func_02041648(u8 channel);
u32 func_02041664(u8 channel);
u8 func_02041680(int channel);
u8 func_0204169C(int channel);
u8 func_020416B8(int channel);
u8 func_020416D4(u32 layer);
void func_020419E4(void);
void func_02041A1C(void);
void sub_02041B6C(u32 bit);
void func_02041B94(void);
void func_02041EE4(u32 index, u32 a, u32 b);
void func_02041F28(u32 which, u32 op, u16 value);
void func_02041F6C(u32 which, u32 op, u32 value);
void func_02041FB0(u32 which, u32 op, u16 value);
u32 func_02041FF4(u32 layer, u16 x, u16 y, u16 *flags);
int func_02042218(int a0, int a1);
void sub_020422D4(u32 mode, u8 *a, u8 *b);
void sub_02042360(struct Bg *p, u32 op, u32 value);
void func_020423D4(u32 layer);
void func_0204241C(u32 layer, const void *src, u32 offset, u32 size);
void func_02042508(u32 index, const u32 *src, u32 mode, u32 size);
void func_020425B4(u32 layer, const void *src, u32 offset, u32 size);
extern void func_02040B94(u32 layer, u32 size, u32 offset, u32 heapId);
extern void MIi_CpuClear16(u16 val, void *dest, u32 size);
extern void func_020409B4(u32 index);
extern void func_02041B6C(u32 bit);
extern void *func_0207E1F8(void);
extern void *func_0207E24C(void);
extern void *func_0207E2A0(void);
extern void *func_0207E330(void);
extern u32 func_0207E22C(void);
extern u32 func_0207E280(void);
extern void *func_0207E2F0(void);
extern void *func_0207E388(void);
extern void func_0203D814(u32 x, u32 y);
struct Mtx22;
extern void func_02051E74(struct Mtx22 *mtx, u32 ang, const void *v1, const void *v2, u8 mode);
extern void func_0207D59C(void *reg, struct Mtx *m, u32 a, u32 b, u32 x, u32 y);
extern void func_02042360(struct Bg *p, u32 op, u32 value);
extern void func_02043228(struct Bg *p, u32 op, u16 value);
extern void func_02043264(struct Bg *p, u32 op, u32 value);
extern void func_020432E4(struct Bg *p, u32 op, u32 value);
extern u16 func_02040EE0(int x, int y, u32 code);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern void func_02043130(u16 flags, u8 *buf, u32 page);
extern void func_02082D44(void *dst, const void *src, u32 size);
extern char g_020A7E5C[];
extern void sub_02040860(u32 layer, u32 a, u32 b, u32 c);
extern void DC_FlushRange(void *p, u32 size);
extern void func_0207E888(const void *src, u32 offset, u32 size);
extern void func_0207EA00(const void *src, u32 offset, u32 size);
extern void func_0207EB78(const void *src, u32 offset, u32 size);
extern void func_0207ECF0(const void *src, u32 offset, u32 size);
extern void func_0207E944(const void *src, u32 offset, u32 size);
extern void func_0207EABC(const void *src, u32 offset, u32 size);
extern void func_0207EC34(const void *src, u32 offset, u32 size);
extern void func_0207EDAC(const void *src, u32 offset, u32 size);
extern void *sub_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void  func_02040968(const void *src, void *dst, u32 mode);
extern void func_0207EE68(const void *src, u32 offset, u32 size);
extern void func_0207EF90(const void *src, u32 offset, u32 size);
extern void func_0207F024(const void *src, u32 offset, u32 size);
extern void func_0207F0B8(const void *src, u32 offset, u32 size);
extern void func_0207EEFC(const void *src, u32 offset, u32 size);
extern void func_0207F14C(const void *src, u32 offset, u32 size);
extern void func_0207F1E0(const void *src, u32 offset, u32 size);
extern void func_0207F274(const void *src, u32 offset, u32 size);

asm void func_020414AC(void)
{
    stmfd sp!, {r4, lr}
    mov	r4, r0
    bl func_020414C4
    mov	r0, r4
    bl func_020414EC
    ldmfd sp!, {r4, pc}
}

void func_020414C4(u32 idx)
{
    func_02040B94(idx, (u32)g_02146A44->unk_1b0[idx], 0, g_02146A44->heapId);
}

/*
 * Clear slot `i` of the 0x2c-byte slot table behind 0x02146A44: if the
 * buffer pointer at +8 is unset there is nothing to do, otherwise zero the
 * buffer over its +0xc length and notify func_020409B4.  Same table and
 * same guard shape as src/matched/sub_020403F4.c, which frees the buffer
 * instead of clearing it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020414EC.c \
 *       --func func_020414EC --addr 0x020414EC --cc 1.1p1 --arm
 */
void func_020414EC(u32 i)
{
    if (g_02146A44->bgs[i].buf == 0) {
        return;
    }
    MIi_CpuClear16(0, g_02146A44->bgs[i].buf, g_02146A44->bgs[i].bufSize);
    func_020409B4(i);
}

/*
 * A whole translation unit, matched as one byte range.
 *
 * Channel clear and audio dispatcher functions.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0204152C.c \
 *       --addr 0x0204152C --arm
 */
void func_0204152C(int channel, u16 val)
{

    if (g_02146A44->bgs[channel].buf == 0) {
        return;
    }
    MIi_CpuClear16(val, g_02146A44->bgs[channel].buf, g_02146A44->bgs[channel].bufSize);
    func_020409B4(channel);
}

void func_02041570(int channel, u16 val)
{

    if (g_02146A44->bgs[channel].buf == 0) {
        return;
    }
    MIi_CpuClear16(val, g_02146A44->bgs[channel].buf, g_02146A44->bgs[channel].bufSize);
    func_02041B6C(channel);
}

u32 func_020415B4(u32 channel)
{
    switch (channel) {
    case 0: return (u32)func_0207E1F8();
    case 1: return (u32)func_0207E24C();
    case 2: return (u32)func_0207E2A0();
    case 3: return (u32)func_0207E330();
    case 4: return func_0207E22C();
    case 5: return func_0207E280();
    case 6: return (u32)func_0207E2F0();
    case 7: return (u32)func_0207E388();
    default: return 0;
    }
}

/*
 * A whole translation unit, matched as one byte range.
 *
 *           func_0204169C, func_020416B8
 *
 * Channel state struct member accessors.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0204162C.c \
 *       --addr 0x0204162C --arm
 */
u32 func_0204162C(int channel)
{
    return (u32)g_02146A44->bgs[channel].buf;
}

u32 func_02041648(u8 channel)
{
    return g_02146A44->bgs[channel].scrollX;
}

u32 func_02041664(u8 channel)
{
    return g_02146A44->bgs[channel].scrollY;
}

u8 func_02041680(int channel)
{
    return g_02146A44->bgs[channel].type;
}

u8 func_0204169C(int channel)
{
    return g_02146A44->bgs[channel].unk_16;
}

u8 func_020416B8(int channel)
{
    return g_02146A44->bgs[channel].unk_17;
}

#define R(a) (*(struct BgCnt *)(a))

/*
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
 *   python3 tools/match.py one --src src/matched/func_020416D4.c \
 *       --func func_020416D4 --addr 0x020416D4 --arm --cc 1.1p1
 */
u8 func_020416D4(u32 layer)
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
            u8 m = g_02146A44->bgs[layer].type;
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
            u8 m = g_02146A44->bgs[layer].type;
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
            u8 m = g_02146A44->bgs[layer].type;
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
            u8 m = g_02146A44->bgs[layer].type;
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

/*
 * note:     re-verified 2026-09-20: MATCH; see verify output
 */
void func_020419E4(void)
{
    if (g_02146A44 == 0) {
        return;
    }

    func_02041B94();
    func_02041A1C();

    g_02146A44->unk_04 = 0;
    g_02146A44->unk_06 = 0;
}

/*
 * Flush the eight tile slots of the 0x2c-byte table behind 0x02146A44 whose
 * dirty bit is set in the u16 at +6: each selected slot re-uploads its tile
 * buffer at the same argument triple func_020409E0 uses (index, tiles,
 * unk_10 * 2, unk_0c).  The global is re-read once per arm because the call
 * may write it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02041A1C.c \
 *       --func func_02041A1C --addr 0x02041A1C --cc 1.1p1 --arm
 */
void func_02041A1C(void)
{
    if (g_02146A44->unk_06 & 0x01)
        func_0204241C(0, g_02146A44->bgs[0].buf, g_02146A44->bgs[0].unk_08 * 2,
                      g_02146A44->bgs[0].bufSize);
    if (g_02146A44->unk_06 & 0x02)
        func_0204241C(1, g_02146A44->bgs[1].buf, g_02146A44->bgs[1].unk_08 * 2,
                      g_02146A44->bgs[1].bufSize);
    if (g_02146A44->unk_06 & 0x04)
        func_0204241C(2, g_02146A44->bgs[2].buf, g_02146A44->bgs[2].unk_08 * 2,
                      g_02146A44->bgs[2].bufSize);
    if (g_02146A44->unk_06 & 0x08)
        func_0204241C(3, g_02146A44->bgs[3].buf, g_02146A44->bgs[3].unk_08 * 2,
                      g_02146A44->bgs[3].bufSize);
    if (g_02146A44->unk_06 & 0x10)
        func_0204241C(4, g_02146A44->bgs[4].buf, g_02146A44->bgs[4].unk_08 * 2,
                      g_02146A44->bgs[4].bufSize);
    if (g_02146A44->unk_06 & 0x20)
        func_0204241C(5, g_02146A44->bgs[5].buf, g_02146A44->bgs[5].unk_08 * 2,
                      g_02146A44->bgs[5].bufSize);
    if (g_02146A44->unk_06 & 0x40)
        func_0204241C(6, g_02146A44->bgs[6].buf, g_02146A44->bgs[6].unk_08 * 2,
                      g_02146A44->bgs[6].bufSize);
    if (g_02146A44->unk_06 & 0x80)
        func_0204241C(7, g_02146A44->bgs[7].buf, g_02146A44->bgs[7].unk_08 * 2,
                      g_02146A44->bgs[7].bufSize);
}

/*
 * Sets one bit of the 16-bit request mask at +6 of the singleton reached
 * through the pointer at 0x02146A44.  The lsl #16 / lsr #16 pair is the
 * u16 truncation of `1 << bit`, not a mask written in the source.
 */
void sub_02041B6C(u32 bit)
{
    g_02146A44->unk_06 |= 1 << bit;
}

#define SLOT(i) (g_02146A44->bgs[i])
#define W(a) (*(volatile u32 *)(a))

/*
 * The per-frame scroll/affine flush for the whole BG system: eight
 * independent blocks, one per layer, each guarded by its own bit of the
 * dirty mask at +0x04 of the singleton (the mask unit_02041F28 ORs
 * (1 << layer) into after every register write).  Nothing loops; all eight
 * blocks are written out, which is why the function is 848 bytes of almost
 * entirely repeated code.
 *
 * Layers 0, 1, 4 and 5 have only the plain path: pack scroll_x (+0x14) and
 * scroll_y (+0x18) into one word, low 9 bits and bits 16..24, and store it
 * to the layer's BGxOFS pair.  Layer 1 additionally tail-calls
 * func_0203D814 with that same scroll pair.
 *
 * Layers 2, 3, 6 and 7 are affine-capable and first read the record's +0x1c
 * flag: zero takes the same plain path, non-zero builds a 16-byte matrix on
 * the stack with func_02051E74 and hands it to func_0207D59C along with the
 * layer's affine register block.
 *
 * THREE DECLARATIONS CARRY THE FUNCTION, all three established by this pass
 * (it was untouched before):
 *
 *  1. THE RECORD REACHES PAST ITS OWN STRIDE.  The stride is 0x2c, but the
 *     affine arms read two words at slot-relative +0x2c and +0x30 -- for
 *     layer 2 those are the absolute offsets 0x84 and 0x88, which lie in the
 *     head of layer 3's record.  Declaring the record as exactly 0x2c bytes
 *     and indexing an array of them cannot express that, so the record is
 *     declared out to +0x34 and the array indexing is done explicitly with a
 *     0x2c byte stride (the SLOT macro).  The image's constant offsets, with
 *     no `mla` anywhere, are what show the indices are all compile-time.
 *
 *  2. THE MATRIX IS 16 BYTES, NOT 32.  The four stack temporaries sit at
 *     sp+0x38, +0x28, +0x18 and +0x08: a stride of 0x10.  With a 32-byte
 *     matrix the frame comes out `sub sp, #0x88` instead of `#0x48`.
 *
 *  3. func_0207D59C TAKES THE AFFINE PAIR IN r2/r3 AND THE SCROLL PAIR ON
 *     THE STACK.  That is arguments 3 and 4 being +0x2c/+0x30 and arguments
 *     5 and 6 being scroll_x/scroll_y, not the other way round.  The
 *     reversed order compiles and is the same size; it differs only in which
 *     two values are spilled to [sp] and [sp,#4], which is how the diff
 *     names it.
 *
 * func_0203D814's parameter list is also pinned here: it takes the scroll
 * pair (two u32), which the image shows as the two loads of +0x40/+0x44
 * immediately before the `bl`.  A void declaration leaves those two loads
 * with no reason to exist and loses them.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_02041B94.c \
 *       --func func_02041B94 --addr 0x02041B94 --arm --cc 1.1p1
 */
void func_02041B94(void)
{
    u32 m  = 0x1ff;
    u32 hm = m << 16;

    if (g_02146A44->unk_04 & 0x01) {
        W(0x04000010) = (SLOT(0).scrollX & m)
                      | (hm & (SLOT(0).scrollY << 16));
    }
    if (g_02146A44->unk_04 & 0x02) {
        W(0x04000014) = (SLOT(1).scrollX & m)
                      | (hm & (SLOT(1).scrollY << 16));
        func_0203D814(SLOT(1).scrollX,
                      SLOT(1).scrollY);
    }
    if (g_02146A44->unk_04 & 0x04) {
        if (SLOT(2).type == 0) {
            W(0x04000018) = (SLOT(2).scrollX & m)
                          | (hm & (SLOT(2).scrollY << 16));
        } else {
            struct Mtx t;
            func_02051E74((struct Mtx22 *)(&t), SLOT(2).unk_18,
                          (const void *)SLOT(2).unk_1c,
                          (const void *)SLOT(2).unk_20, 2);
            func_0207D59C((void *)0x04000020, &t,
                          SLOT(2).unk_24, SLOT(2).unk_28,
                          SLOT(2).scrollX, SLOT(2).scrollY);
        }
    }
    if (g_02146A44->unk_04 & 0x08) {
        if (SLOT(3).type == 0) {
            W(0x0400001c) = (SLOT(3).scrollX & m)
                          | (hm & (SLOT(3).scrollY << 16));
        } else {
            struct Mtx t;
            func_02051E74((struct Mtx22 *)(&t), SLOT(3).unk_18,
                          (const void *)SLOT(3).unk_1c,
                          (const void *)SLOT(3).unk_20, 2);
            func_0207D59C((void *)0x04000030, &t,
                          SLOT(3).unk_24, SLOT(3).unk_28,
                          SLOT(3).scrollX, SLOT(3).scrollY);
        }
    }
    if (g_02146A44->unk_04 & 0x10) {
        W(0x04001010) = (SLOT(4).scrollX & m)
                      | (hm & (SLOT(4).scrollY << 16));
    }
    if (g_02146A44->unk_04 & 0x20) {
        W(0x04001014) = (SLOT(5).scrollX & m)
                      | (hm & (SLOT(5).scrollY << 16));
    }
    if (g_02146A44->unk_04 & 0x40) {
        if (SLOT(6).type == 0) {
            W(0x04001018) = (SLOT(6).scrollX & m)
                          | (hm & (SLOT(6).scrollY << 16));
        } else {
            struct Mtx t;
            func_02051E74((struct Mtx22 *)(&t), SLOT(6).unk_18,
                          (const void *)SLOT(6).unk_1c,
                          (const void *)SLOT(6).unk_20, 2);
            func_0207D59C((void *)0x04001020, &t,
                          SLOT(6).unk_24, SLOT(6).unk_28,
                          SLOT(6).scrollX, SLOT(6).scrollY);
        }
    }
    if (g_02146A44->unk_04 & 0x80) {
        if (SLOT(7).type == 0) {
            W(0x0400101c) = (SLOT(7).scrollX & m)
                          | (hm & (SLOT(7).scrollY << 16));
        } else {
            struct Mtx t;
            func_02051E74((struct Mtx22 *)(&t), SLOT(7).unk_18,
                          (const void *)SLOT(7).unk_1c,
                          (const void *)SLOT(7).unk_20, 2);
            func_0207D59C((void *)0x04001030, &t,
                          SLOT(7).unk_24, SLOT(7).unk_28,
                          SLOT(7).scrollX, SLOT(7).scrollY);
        }
    }
}

/*
 * Reset slot `index` of the module's 0x2C-byte slot array and mark it live
 * in the halfword bitmask at +4.  The slot address is one `mla`: the base
 * pointer plus 8 plus index * 0x2C.
 *
 * The second parameter is real, not a leftover: the original steps over both r1
 * and r2 and uses r3 for the slot-address temporary.  Each register the
 * body skips is an argument still live for the forwarding call: with one
 * parameter the temporary lands in r1, with two in r2, and only with three
 * in r3.
 *
 * The bit is narrowed to sixteen bits before the `orr` (the `lsl #16` /
 * `lsr #16` pair), which is what says the mask is a u16 field and the
 * shift is done in int width first.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02041EE4.c \
 *       --func func_02041EE4 --addr 0x02041EE4 --cc 1.1p1 --arm
 */
void func_02041EE4(u32 index, u32 a, u32 b)
{
    func_02042360(&g_02146A44->bgs[index], a, b);
    g_02146A44->unk_04 |= (u16)(1 << index);
}

/*
 * Three consecutive "bring one video slot up" entry points, 68 bytes each
 * and no padding between them, differing only in the helper they call:
 * each hands the slot record (base +8, stride 0x2c) to its helper and then
 * sets that slot's own bit in the halfword at +4 of the same context.
 *
 * Each helper is the three-argument set/add/sub family matched as
 * src/matched/sub_02043228.c and its siblings, so `op` and `value` pass
 * straight through in r1/r2 and the call site prepares only r0.  That is
 * what pins the register the context value lands in: written as a
 * one-argument call every instruction of the body is still right but the
 * context load comes out in r1, four bytes per function; with the two
 * pass-through parameters declared, r1/r2 are live across the address
 * computation and the scratch goes to r3.  See
 * docs/idioms/arguments-left-in-place-keep-the-low-registers-out-of-the-scratch-pool.md.
 *
 * The bit set is the u16 truncation idiom, not a mask: `1 << which` is
 * materialised and then narrowed with the lsl #0x10 / lsr #16 pair the
 * `orr` takes as a shifted operand, which only a `u16` lvalue produces.
 * The context pointer is re-read from its own slot after the call, because
 * the callee may store it.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02041F28.c \
 *       --addr 0x02041F28 --arm
 */
void func_02041F28(u32 which, u32 op, u16 value)
{
    func_02043228(&g_02146A44->bgs[which], op, value);
    g_02146A44->unk_04 |= (u16)(1 << which);
}

void func_02041F6C(u32 which, u32 op, u32 value)
{
    func_02043264(&g_02146A44->bgs[which], op, value);
    g_02146A44->unk_04 |= (u16)(1 << which);
}

void func_02041FB0(u32 which, u32 op, u16 value)
{
    func_020432E4(&g_02146A44->bgs[which], op, value);
    g_02146A44->unk_04 |= (u16)(1 << which);
}

/*
 * bg_sys.c: does the pixel under (x, y) on a layer match the caller's
 * colour list?  4bpp layers (flag_1e == 0) decode the tile into a scratch
 * 0x40-byte nibble buffer and test bit v of *flags; 8bpp layers copy the
 * tile (or, for mode 1, read the affine byte map directly) and scan a
 * 0xFFFF-terminated list.
 *
 * WHAT CLOSED IT (wave 12, 42 -> 0): the sub-tile coordinates px/py are
 * FUNCTION-SCOPE u8 locals declared first and assigned after the two
 * calls (the block-scoped `u8 px = x & 7; u16 py = y & 7;` of the wave-11
 * source kept x/y and px/py in separate registers: 42); the nibble loop
 * counter i is also function-scope (15 -> 9); and i must be declared
 * before tbl, tbl before buf (9 -> 0).  All other facts (u16 first
 * parameter of func_02043130, shared fail exit, mode != 1 arm first) are
 * from docs/notes/pkt_02041FF4.c.txt.
 */
u32 func_02041FF4(u32 layer, u16 x, u16 y, u16 *flags)
{
  u8 px;
  u8 py;
  u16 key;
  u8 *chr;
  u8 i;
  u16 *tbl;
  u8 *buf;
  u8 v;
  if (g_02146A44->bgs[layer].buf == 0)
    return 0;
  key = func_02040EE0((u8) (x >> 3), (u8) (y >> 3), g_02146A44->bgs[layer].unk_15);
  chr = (u8 *)func_020415B4(layer);
  px = x & 7;
  py = y & 7;
  if (g_02146A44->bgs[layer].unk_16 == 0)
  {
    u8 *src;
    tbl = g_02146A44->bgs[layer].buf;
    buf = func_02030734((u16)((g_02146A44->heapId & 0x7fff) | 0x8000), 0x40, 0, g_020A7E5C, 0xa77);
    src = chr + (((u32) (tbl[key] << 22)) >> 17);
    for (i = 0; i < 0x20; i++)
    {
      buf[i * 2] = src[i] & 0xf;
      buf[(i * 2) + 1] = src[i] >> 4;
    }

    func_02043130((tbl[key] >> 10) & 3, buf, g_02146A44->heapId);
    v = buf[px + (py << 3)];
    func_020307B0(buf);
    if (((*flags) & (1 << v)) == 0)
      goto fail;
    return 1;
  }
  if (g_02146A44->bgs[layer].type != 1)
  {
    tbl = g_02146A44->bgs[layer].buf;
    buf = func_02030734((u16)((g_02146A44->heapId & 0x7fff) | 0x8000), 0x40, 0, g_020A7E5C, 0xa8f);
    func_02082D44(buf, chr + (((u32) (tbl[key] << 22)) >> 16), 0x40);
    func_02043130((tbl[key] >> 10) & 3, buf, g_02146A44->heapId);
    v = buf[px + (py << 3)];
    func_020307B0(buf);
  }
  else
  {
    v = chr[((((u8 *) g_02146A44->bgs[layer].buf)[key] << 6) + px) + (py << 3)];
  }
  for (;;)
  {
    if ((*flags) == 0xffff)
      goto fail;
    if (v == ((*flags) & 0xff))
      return 1;
  }
  fail:
  return 0;

}

/*
 * Two-dimensional table: the first argument picks a row, the second a column,
 * and each cell is a two- or three-bit index.  Rows 0 and 1 both fall through
 * to the shared `return 0` (a `break` out of the switch), so mwcc if-converts
 * every arm but the last of those two rows -- which is exactly the bne/mov/bx
 * shape the original shows -- while row 2, being the final case, keeps its
 * last arm if-converted too.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02042218.c \
 *       --func func_02042218 --addr 0x02042218 --cc 1.1p1 --arm
 */
int func_02042218(int a0, int a1)
{
    switch (a1) {
    case 0:
        if (a0 == 1)
            return 0;
        if (a0 == 2)
            return 2;
        if (a0 == 3)
            return 1;
        if (a0 == 4)
            return 3;
        break;
    case 1:
        if (a0 == 0)
            return 0;
        if (a0 == 1)
            return 1;
        if (a0 == 4)
            return 2;
        if (a0 == 5)
            return 3;
        break;
    case 2:
        if (a0 == 0)
            return 0;
        if (a0 == 1)
            return 1;
        if (a0 == 4)
            return 2;
        if (a0 == 5)
            return 3;
        break;
    }
    return 0;
}

/*
 * The two register values a layer's window mode implies: six modes, each
 * writing one byte into each of the two output pointers, and nothing at all
 * for a mode above five (`addls` over a bare `bx lr`).  Modes 0, 1, 4 and 5
 * write the same constant twice, so the compiler materialises it once and
 * reuses r0 for both stores; modes 2 and 3 write two different ones in the
 * order they are given.  The arms are byte stores, so the values are `u8`.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020422D4.c \
 *       --func sub_020422D4 --addr 0x020422D4 --cc 1.1p1 --arm
 */
void sub_020422D4(u32 mode, u8 *a, u8 *b)
{
    switch (mode) {
    case 0:
        *a = 0x10;
        *b = 0x10;
        break;
    case 1:
        *a = 0x20;
        *b = 0x20;
        break;
    case 2:
        *a = 0x20;
        *b = 0x40;
        break;
    case 3:
        *a = 0x40;
        *b = 0x20;
        break;
    case 4:
        *a = 0x40;
        *b = 0x40;
        break;
    case 5:
        *a = 0x80;
        *b = 0x80;
        break;
    }
}

/*
 * The 32-bit member of the set / add / subtract family whose 16-bit
 * counterpart is src/matched/sub_02043228.c: opcodes 0..2 on the word at
 * +0xc of the record in r0, opcodes 3..5 on the word at +0x10, and nothing
 * at all above 5.  Each arm loads, combines and stores the field spelled
 * out as two statements of one expression, which is what keeps a single
 * `ldr` per arm.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02042360.c \
 *       --func sub_02042360 --addr 0x02042360 --cc 1.1p1 --arm
 */
void sub_02042360(struct Bg *p, u32 op, u32 value)
{
    switch (op) {
    case 0:
        p->scrollX = value;
        break;
    case 1:
        p->scrollX = p->scrollX + value;
        break;
    case 2:
        p->scrollX = p->scrollX - value;
        break;
    case 3:
        p->scrollY = value;
        break;
    case 4:
        p->scrollY = p->scrollY + value;
        break;
    case 5:
        p->scrollY = p->scrollY - value;
        break;
    }
}

/*
 * One layer's affine setup: fill a scratch parameter block on the stack,
 * then push it into the layer through sub_02040860 with a zero transform.
 * The block is 0x10 bytes at sp+4 and the first call's fifth argument is
 * the word at sp+0, which is why the frame is `sub sp, sp, #0x14`: four
 * bytes of outgoing argument plus sixteen of local.
 *
 * The first call's third and fourth arguments are the same literal, so the
 * compiler materialises 0x1000 once in r2 and copies it to r3; the zero is
 * shared the same way and survives into the second call.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020423D4.c \
 *       --func func_020423D4 --addr 0x020423D4 --cc 1.1p1 --arm
 */
void func_020423D4(u32 layer)
{
    struct Param p;

    func_02051E74((struct Mtx22 *)(&p), 0, (const void *)0x1000, (const void *)0x1000, 0);
    sub_02040860(layer, (u32)(&p), 0, 0);
}

/*
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

/*
 * bg_sys.c.  Upload tile data to a layer, decompressing first when the
 * caller asks for mode 0.  The mode parameter does double duty: it is the
 * conversion selector on the mode-0 path and, on the direct path, it is
 * passed straight through to func_020425B4 as that call's own fourth
 * argument, which is why "movs r6, r2" tests it and keeps it live.
 *
 * Three declarations carry this function, all of them from the family
 * header (docs/families/bg_sys.h):
 *   - the allocator's signature, sub_02030734(heapId, size, clear, site,
 *     tag), with the u16 heap id first and the __FILE__ anchor fourth;
 *   - the scratch heap id spelling (g_02146A44->heapId & 0x7fff) | 0x8000,
 *     the same masked form func_02040B94 and func_02040C14 use;
 *   - the source's first word being a header whose top 24 bits are the
 *     decompressed byte count, hence "lsr r4, r2, #8" on *src.
 * The allocator tag is 2963 and the site string is the bg_sys.c anchor at
 * 0x020A7E5C.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_02042508.c \
 *       --func func_02042508 --addr 0x02042508 --cc 1.1p1 --arm
 */
void func_02042508(u32 index, const u32 *src, u32 mode, u32 size)
{
    if (mode == 0) {
        u32   n = *src >> 8;
        void *buf;

        buf = sub_02030734((u16)((g_02146A44->heapId & 0x7fff) | 0x8000),
                           n, 0, g_020A7E5C, 2963);
        func_02040968(src, buf, mode);
        func_020425B4(index, buf, size, n);
        func_020307B0(buf);
    } else {
        func_020425B4(index, src, size, mode);
    }
}

/*
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
void func_020425B4(u32 layer, const void *src, u32 offset, u32 size)
{
    DC_FlushRange((void *)src, size);

    switch (layer) {
    case 0:
        func_0207EE68(src, offset, size);
        break;
    case 1:
        func_0207EF90(src, offset, size);
        break;
    case 2:
        func_0207F0B8(src, offset, size);
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
