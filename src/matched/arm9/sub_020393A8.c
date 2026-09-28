/*
 * function: sub_020393A8
 * address:  0x020393A8
 * packet:   pkt_020393A8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0203D788  0x0203D788  arm
 *
 * Read the link driver's current mask through the indirect getter at +0x7c
 * of the object hanging off +0x340, truncate it to sixteen bits and drop
 * bit 0.
 *
 * The `lsl #16` / `lsr #16` pair is the truncation of an `int` return into a
 * `u16` local: a getter already declared to return `u16` would fold to the
 * bare `and` and lose four bytes
 * (docs/idioms/unequal-shift-pair-is-a-narrowing-cast-folded-with-a-shift.md
 * read the other way, the equal-amount pair being the conversion case).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020393A8.c \n *       --func sub_020393A8 --addr 0x020393A8 --cc 1.1p1 --arm
 */

typedef unsigned short u16;
typedef unsigned int   u32;

struct LinkDriver {
    unsigned char pad00[0x7c];
    u32 (*get_mask)(void);
};

struct LinkRoot {
    unsigned char pad000[0x340];
    struct LinkDriver *driver;
};

extern struct LinkRoot *func_0203D788(void);

int sub_020393A8(void)
{
    u16 mask;

    mask = func_0203D788()->driver->get_mask();
    return mask & 0xFFFE;
}
