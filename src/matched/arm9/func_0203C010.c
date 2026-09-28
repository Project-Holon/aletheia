/*
 * PROMOTED FROM src/pending/ AT THE END OF WAVE 4 LANE 0x02038000..0x02040000.
 * It was parked at MATCH with every concrete byte right, held there only by
 * the `bl` to 0x020379C8, which nothing outside this range witnessed.  That
 * address has since been matched, so the site now resolves on the `matched`
 * class and the whole 52 bytes are EXACT with no change to the C at all.
 *
 * The callback stub this file passes, 0x0203C00C, is matched as well now, as
 * the last function of src/matched/unit_0203BF9C.c.
 *
 * function: func_0203C010
 * address:  0x0203C010
 * packet:   pkt_0203BEC8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
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
