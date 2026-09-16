/*
 * unit:     yes
 * function: func_02043570
 * address:  0x02043570
 * packet:   pkt_02043570
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   gVisiblePlane  0x02146A48  data
 *   func_02043558  0x02043558  arm
 *
 * Two of the engine-B visible-plane mask writers, 0x02043570-0x02043598.
 *
 *   0x02043570  keep only the four background bits of the software copy
 *               gVisiblePlane[0] (mask 0xF)
 *   0x02043588  the pair call: run the sibling at 0x02043558, which keeps
 *               only bit 4 (the OBJ plane), then the one above, so the two
 *               together clear the software copy outright
 *
 * 0x02043570 has exactly one branch reference image-wide, the `bl` at
 * 0x02043590 inside 0x02043588, so folding the two into one unit costs no
 * witness (docs/idioms/a-unit-attests-only-its-own-start-address.md): the
 * interior address is nobody else's sole witness.
 *
 * The mask constants are plain `and` immediates, not a bitfield: both fit an
 * ARM rotated immediate and neither carries a narrowing shift pair.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02043570.c \
 *       --addr 0x02043570 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

extern u32 gVisiblePlane[2];

extern void func_02043558(void);

void func_02043570(void)
{
    gVisiblePlane[0] &= 0xF;
}

void func_02043588(void)
{
    func_02043558();
    func_02043570();
}
