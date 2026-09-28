/*
 * function: func_0201057C
 * address:  0x0201057C
 * packet:   pkt_02010068
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Sixteen bytes: a boolean test of bit 0x10 of a halfword field at +0x2C of
 * its argument.  The functions on both sides of it are not matched yet, so
 * it is a file of its own, the same situation documented for
 * src/matched/unit_02011F24.c.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0201057C.c \
 *       --func func_0201057C --addr 0x0201057C --cc 1.1p1
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Ctx {
    u8  unk00[0x2C];
    u16 unk2C;
};

u32 func_0201057C(const struct Ctx *p)
{
    if (p->unk2C & 0x10) {
        return 1;
    }
    return 0;
}
