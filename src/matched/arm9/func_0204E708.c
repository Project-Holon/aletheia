/*
 * function: func_0204E708
 * address:  0x0204E708
 * packet:   pkt_0204E6F4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Arms +0x1c of the singleton reached through the pointer at 0x02146A7C:
 * the same field func_0204E6F4 sets from an argument, here forced to 1.
 * Same object as src/matched/unit_0204E720.c.
 *
 * symbols:
 *   g_02146A7C  0x02146A7C  data
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204E708.c \
 *       --func func_0204E708 --addr 0x0204E708 --cc 1.1p1 --arm
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

void func_0204E708(void)
{
    g_02146A7C->unk1c = 1;
}
