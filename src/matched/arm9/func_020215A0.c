/*
 * unit:     no
 * function: func_020215A0
 * address:  0x020215A0
 * packet:   pkt_02021444
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 *
 * Release the double buffer of one palette-animation slot, the inverse of
 * func_0202155C.  The two slot pointers are read back from the array rather
 * than passed in, which is what makes the 0x14 stride multiply live.
 *
 * EXACT*: the extent runs long because the next function at 0x020215BC has
 * no label.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020215A0.c \
 *       --func func_020215A0 --addr 0x020215A0 --cc 1.1p1 --thumb
 */

typedef unsigned int u32;

struct PalAnmSlot {
    void *unk_00;
    void *unk_04;
    u32   size;
    u32   unk_0c;
    u32   unk_10;
};

extern u32 func_020307B0(void *p);

void func_020215A0(struct PalAnmSlot *slots, u32 idx)
{
    func_020307B0(slots[idx].unk_00);
    func_020307B0(slots[idx].unk_04);
}
