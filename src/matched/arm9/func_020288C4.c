/*
 * unit:     yes
 * function: func_020288C4
 * address:  0x020288C4
 * packet:   pkt_0202878C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * field_sound_system.c.  The queue depth the callers poll: the recorded base count plus the pending
 * requests of kind 3, less those of kind 4, with two mode specific
 * corrections.  The mode word is read once and kept, which is what makes it a
 * named local rather than two reads
 * (docs/idioms/keeping-a-cursor-in-a-named-local-costs-a-callee-saved-register.md).
 *
 * symbols:
 *   func_02028DCC  0x02028DCC  thumb
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/func_020288C4.c  *       --addr 0x020288C4 --thumb
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

s32 func_020288C4(struct Sys *s)
{
    s32 n = s->unk20;
    u32 mode;

    n = n + func_02028DCC(s, 3);
    n = n - func_02028DCC(s, 4);
    mode = s->unk1C;
    if (mode == 3) {
        if (s->unk04 == 5 || s->unk04 - 0xB <= 1) {
            n++;
        }
    }
    if (mode == 4) {
        if (s->unk04 == 6) {
            n--;
        }
    }
    return n;
}
