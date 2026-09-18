/*
 * PARKED AT MATCH.  Every concrete byte is right; the one open site is the
 * `bl` to 0x020379C8, which has no outside witness - the only branch to that
 * address in the whole image is the one inside this function, and it carries
 * no `func_` label, so `label` cannot reach it.  It closes the day 0x020379C8
 * is matched itself, which would make this entry the witness.
 *
 * Closing this file also closes 0x0203D0FC (src/matched/func_0203D0FC.c),
 * which has this function as its only unresolved site.
 *
 * function: func_0203C010
 * address:  0x0203C010
 * packet:   pkt_0203B6EC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 * blocker:  `bl` to 0x020379C8: no branch outside this range reaches it and it carries no func_ label
 *
 * symbols:
 *   func_020379C8  0x020379C8  arm
 *   func_0203AD80  0x0203AD80  arm
 *   func_0203C00C  0x0203C00C  arm
 *   unk_021469DC   0x021469DC  data
 *
 * Allocates 0x200 bytes, then starts the card task on the object at
 * 0x021469DC with the four-byte `bx lr` stub at 0x0203C00C as its callback and
 * 0x4DA (1242) as the fourth argument - the source file/line pair of an assert
 * style entry point.  The stub is a real 4-byte ARM function in the listing, so
 * its address is declared as the function it is and passed as a function
 * pointer; the pool word for it is attested by a dozen other pools elsewhere
 * in the image, and unk_021469DC likewise.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0203C010.c \
 *       --func func_0203C010 --addr 0x0203C010 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

extern void func_020379C8(u32 size);
extern void func_0203AD80(u32 obj, void (*cb)(void), u32 c, u32 d);
extern void func_0203C00C(void);
extern u32  unk_021469DC;

void func_0203C010(void)
{
    func_020379C8(0x200);
    func_0203AD80(unk_021469DC, func_0203C00C, 0, 0x4DA);
}
