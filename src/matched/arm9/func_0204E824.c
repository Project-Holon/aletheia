/*
 * function: func_0204E824
 * address:  0x0204E824
 * packet:   pkt_0204E6F4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Push the current fade level at +0x08 of the singleton out to whichever of
 * the four master-brightness slots the low nibble of +0x00 selects: bit 0
 * and bit 1 darken the main and sub engine (the level is negated), bits 2
 * and 3 brighten them (it is not).  The two register addresses 0x0400006c
 * and 0x0400106c are MASTER_BRIGHT for the two engines and are the
 * function's only two pool words besides the singleton pointer.
 *
 * The pointer and the flag word are re-read from scratch in front of every
 * one of the four tests, because func_0207D534 is opaque and may write
 * either of them.
 *
 * symbols:
 *   func_0207D534  0x0207D534  arm
 *   g_02146A7C     0x02146A7C  data
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204E824.c \
 *       --func func_0204E824 --addr 0x0204E824 --cc 1.1p1 --arm
 */

typedef signed int   s32;
typedef unsigned int u32;

struct Run0204E720 {
    u32 unk00; /* 0x00 */
    s32 unk04; /* 0x04 */
    s32 unk08; /* 0x08 */
    s32 unk0c; /* 0x0c */
    s32 unk10; /* 0x10 */
    s32 unk14; /* 0x14 */
    s32 unk18; /* 0x18 */
    s32 unk1c; /* 0x1c */
};

extern struct Run0204E720 *g_02146A7C;

typedef unsigned short u16;
extern void func_0207D534(volatile u16 *reg, int brightness);

void func_0204E824(void)
{
    if (g_02146A7C->unk00 & 1)
        func_0207D534((void *)0x0400006c, -g_02146A7C->unk08);

    if (g_02146A7C->unk00 & 2)
        func_0207D534((void *)0x0400106c, -g_02146A7C->unk08);

    if (g_02146A7C->unk00 & 4)
        func_0207D534((void *)0x0400006c, g_02146A7C->unk08);

    if (g_02146A7C->unk00 & 8)
        func_0207D534((void *)0x0400106c, g_02146A7C->unk08);
}
