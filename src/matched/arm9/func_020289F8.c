/*
 * Byte-correct, MATCH-capped.  NOT in the manifest; see src/pending/README.md.
 *
 * function: func_020289F8
 * address:  0x020289F8
 * packet:   pkt_0202878C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * field_sound_system.c.  The command enqueue every caller in the region goes through: it builds the
 * sixteen byte command record on its own stack and hands its address to the
 * queue.  The fifth argument arrives at [sp, #0x10], which is the pushed `lr`
 * plus the twelve bytes of the record.
 *
 * Why it is capped: the single relocation is the call to func_02028E0C, and a
 * scan of the image finds exactly one branch to 0x02028E0C, the one inside
 * this function.  The `label` class therefore has no witness outside the
 * compared range and no cut helps: the range cannot be made smaller than the
 * one function that holds the call.  It closes the day 0x02028E0C itself is
 * matched (it is in the packet that starts at 0x02028D7C, not in
 * pkt_0202878C), or the day a second caller appears.
 *
 * Wave 26: 0x02028E0C is now decompiled and byte-correct in
 * src/pending/func_02028E0C.c, but it is capped in turn, and permanently, by
 * the permission table at 0x0209FD90 that its own callee func_02028E48 reads
 * (src/pending/func_02028E48.c).  That word appears in exactly one literal
 * pool image-wide, inside func_02028E48 itself, so this chain cannot be closed
 * from inside field_sound_system.c.  A second caller is the only route left.
 *
 * symbols:
 *   func_02028E0C  0x02028E0C  thumb
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_020289F8.c  *       --func func_020289F8 --addr 0x020289F8 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef int            s32;

struct Sys {
    u32 unk00;
    u32 unk04;
    u8  unk08[0x14];
    u32 unk1C;
    u32 unk20;
};

struct SndCmd {
    u32 unk00;
    u32 unk04;
    u16 unk08;
    u16 unk0A;
};

struct Cmd;
extern void func_02028E0C(struct Sys *s, struct Cmd *cmd);

void func_020289F8(struct Sys *s, u32 a, u32 b, u16 c, u16 d)
{
    struct SndCmd cmd;

    cmd.unk00 = a;
    cmd.unk04 = b;
    cmd.unk08 = c;
    cmd.unk0A = d;
    func_02028E0C(s, (struct Cmd *)(&cmd));
}
