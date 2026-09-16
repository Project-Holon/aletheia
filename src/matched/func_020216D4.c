/*
 * unit:     no
 * function: func_020216D4
 * address:  0x020216D4
 * packet:   pkt_02021444
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020215BC  0x020215BC  thumb
 *
 * Snapshot one palette bank into the animation slot that shadows it.  The
 * bank selector indexes both the hardware palette base and the slot array,
 * so 0..3 are the four DS palette RAM windows in the order
 * main BG / sub BG / main OBJ / sub OBJ:
 *
 *   0  0x05000000  main BG
 *   1  0x05000400  sub BG
 *   2  0x05000200  main OBJ
 *   3  0x05000600  sub OBJ
 *
 * Only 0x05000000 is built with `movs #5 / lsls #24`; the other three need a
 * pool word each, which is why the dense halfword table has one arm that is
 * two instructions and three that are one.
 *
 * The offset is added as `u16 *` arithmetic to the bank base and passed
 * again, unscaled, as the callee's own halfword offset.
 *
 * EXACT*: the extent runs to 106 bytes because the switch pools and the next function at 0x0202173E are pulled in.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020216D4.c \
 *       --func func_020216D4 --addr 0x020216D4 --cc 1.1p1 --thumb
 */

typedef unsigned short u16;
typedef unsigned int   u32;

struct PalAnmSlot {
    u16 *unk_00;
    u16 *unk_04;
    u32  size;
    u32  unk_0c;
    u32  unk_10;
};

extern void func_020215BC(struct PalAnmSlot *slots, const void *src, u32 idx,
                          u32 off, u16 size);

void func_020216D4(struct PalAnmSlot *slots, u32 bank, u32 off, u32 size)
{
    u16 *base;

    switch (bank) {
    case 0:
        base = (u16 *)0x05000000;
        break;
    case 1:
        base = (u16 *)0x05000400;
        break;
    case 2:
        base = (u16 *)0x05000200;
        break;
    case 3:
        base = (u16 *)0x05000600;
        break;
    default:
        return;
    }

    func_020215BC(slots, base + off, bank, off, (u16)size);
}
