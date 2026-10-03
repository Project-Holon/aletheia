/*
 * unit:     yes
 * function: func_020289D4
 * address:  0x020289D4
 * packet:   pkt_0202878C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * field_sound_system.c.  "Can the system take another request": two independent rejections, each
 * with its own epilogue, which is what says they are two `if`s and not one
 * conjunction (docs/idioms/guard-chain-sharing-one-exit-block-is-a-single-conjunction.md).
 *
 * symbols:
 *   func_02028DCC  0x02028DCC  thumb
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/func_020289D4.c  *       --addr 0x020289D4 --thumb
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

extern u8 func_02028DCC(struct Sys *s, u32 target);

u32 func_020289D4(struct Sys *s)
{
    if (s->unk1C == 4 && s->unk04 == 6) {
        return 0;
    }
    if (func_02028DCC(s, 4) != 0) {
        return 0;
    }
    return 1;
}
