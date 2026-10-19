/*
 * unit:     no
 * function: ISS_SWITCH_Init
 * address:  0x0202C5B4
 * packet:   pkt_0202C4CC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * A constructor: sets a flag word and clears three u16 fields, no
 * relocations. disasm.py's extent for this address runs to
 * ISS_SWITCH_CountUpFade, but the fourteen bytes in between are not this
 * function's body: two bytes of padding, then the unlabelled leaf
 * ISS_SWITCH_SetParam (src/matched/sub_0202C5C4.c), then two more bytes of
 * padding.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/unit_0202C5B4.c \
 *       --func ISS_SWITCH_Init --addr 0x0202C5B4 --cc 1.1p1 --thumb
 */

typedef unsigned short u16;
typedef unsigned int u32;

struct Counter0202C5B4 {
    u32 unk00;
    u16 unk04;
    u16 unk06;
    u16 unk08;
};

void ISS_SWITCH_Init(struct Counter0202C5B4 *p)
{
    p->unk00 = 1;
    p->unk04 = 0;
    p->unk06 = 0;
    p->unk08 = 0;
}
