/*
 * function: BG_SYS_ResetSlot
 * address:  0x02041EE4
 * packet:   pkt_02041B94
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_02146A44     0x02146A44  data
 *   BG_SYS_SetScrollField  0x02042360  arm
 *
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
 *   python tools/match.py one --src src/matched/BG_SYS_ResetSlot.c \
 *       --func BG_SYS_ResetSlot --addr 0x02041EE4 --cc 1.1p1 --arm
 */

typedef unsigned short u16;
typedef unsigned int   u32;

struct Slot02041EE4 {
    u32 words[11];
};

struct Mod02041EE4 {
    u32 unk00;
    u16 live;
    u16 unk06;
    struct Slot02041EE4 slots[1];
};

extern struct Mod02041EE4 *g_02146A44;

struct Obj;
extern void BG_SYS_SetScrollField(struct Obj *p, u32 op, u32 value);

void BG_SYS_ResetSlot(u32 index, u32 a, u32 b)
{
    BG_SYS_SetScrollField((struct Obj *)(&g_02146A44->slots[index]), a, b);
    g_02146A44->live |= (u16)(1 << index);
}
