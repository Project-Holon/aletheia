/*
 * function: func_02006544
 * address:  0x02006544
 * packet:   pkt_02006544
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * blocker:  020067D0 - the `bl` inside the loop is the only branch to it, so
 *           the `label` class has no witness outside the compared range.  All
 *           124 concrete bytes and every data site are right.
 *
 * symbols:
 *   g_02140484     0x02140484  data
 *   g_02140524     0x02140524  data
 *   g_02140504     0x02140504  data
 *   g_02140534     0x02140534  data
 *   g_02140488     0x02140488  data
 *   g_0209D8C0     0x0209D8C0  data
 *   func_020067D0  0x020067D0  thumb
 *
 * Initialise the three mixer voices of the sound driver: publish the voice
 * count as a halfword, clear the driver's status byte, and for each of the
 * three 0x34-byte voices clear the enable word, copy the two 4-bit
 * pan/format fields out of the halfword table at 0x0209D8C0 (they are
 * adjacent `u8`-based bitfields, which is why the incoming halfword is
 * narrowed to 8 bits and the second one is shifted up by four into position
 * - see docs/idioms/a-bitfields-base-type-shows-up-as-a-redundant-truncation-
 * of-the-argument.md), then reset the voice.  Voice 0 also gets the same
 * pointer in both of its buffer slots.
 *
 * The three globals really are three separate symbols and not one struct:
 * the pool words are 0x02140524 and 0x02140504 outright, with 0x0C and
 * 0x20/0x22/0x24/0x28 as *instruction* offsets, so declaring one base and
 * adding the deltas would change the relocation.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02006544.c \
 *       --func func_02006544 --addr 0x02006544 --cc 1.1p1 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Sub02006544Voice {
    u32 unk00;
    u32 unk04;
    u32 unk08;
    u32 unk0C;
    u32 unk10;
    u32 unk14;
    u32 unk18;
    u8  unk1C;
    u8  unk1D;
    u8  lo : 4;
    u8  hi : 4;
    u8  unk1F;
    u32 unk20;
    u32 unk24;
    u32 unk28;
    u32 unk2C;
    u32 unk30;
};

struct Sub02006544Pair {
    u16 lo;
    u16 hi;
};

extern u16 g_02140484;
extern u8  g_02140524[];
extern u8  g_02140504[];
extern u8  g_02140534[];
extern struct Sub02006544Voice g_02140488[];
extern struct Sub02006544Pair  g_0209D8C0[];

extern void func_020067D0(struct Sub02006544Voice *v);

void func_02006544(u16 a0, u32 a1, u32 a2)
{
    struct Sub02006544Voice *p;
    int i;

    g_02140484 = a0;
    g_02140524[0xC] = 0x7F;
    for (i = 0; i < 3; i++) {
        p = &g_02140488[i];
        p->unk00 = 0;
        p->lo = (u8)g_0209D8C0[i].lo;
        p->hi = (u8)g_0209D8C0[i].hi;
        func_020067D0(p);
        if (i == 0) {
            p->unk04 = (u32)g_02140534;
            p->unk10 = (u32)g_02140534;
        }
    }
    *(u16 *)(g_02140504 + 0x22) = 1;
    *(u16 *)(g_02140504 + 0x20) = 0;
    *(u32 *)(g_02140504 + 0x24) = a1;
    *(u32 *)(g_02140504 + 0x28) = a2;
}
