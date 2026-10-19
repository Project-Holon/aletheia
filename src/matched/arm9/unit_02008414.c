/*
 * unit:     yes
 * function: CONFIG_ApplyTextLanguage
 * address:  0x02008414
 * packet:   pkt_02008414
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_020461D4    0x020461D4  arm
 *
 * The packet 0x02008414..0x02008448 is three functions, two of which carry no
 * label in the generated listing (neither saves lr): the 14-byte wrapper at the
 * packet start and the two accessors at 0x02008428 and 0x02008430 that the
 * extent to the next label swallows.  All three reach the same halfword of the
 * object through a bitfield, which is why the read is an unequal lsls/lsrs
 * pair and the write of the middle one narrows its argument to the field's
 * u16 base type before shifting it into place.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Flags02008414 {
    u16 lo  : 8;
    u16 b8  : 1;
    u16 b9  : 1;
    u16 b10 : 1;
    u16 hi  : 5;
};

extern u8 func_020461D4(u32 v);

u8 CONFIG_ApplyTextLanguage(const struct Flags02008414 *p)
{
    return func_020461D4((u8)p->b8);
}

u32 CONFIG_GetButtonMode(const struct Flags02008414 *p)
{
    return p->b9;
}

void CONFIG_SetButtonMode(struct Flags02008414 *p, int b)
{
    p->b9 = b;
}
