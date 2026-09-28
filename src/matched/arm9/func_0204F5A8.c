/*
 * function: func_0204F5A8
 * address:  0x0204F5A8
 * packet:   pkt_0204F344
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT*
 *
 * If the low 14 bits of the u16 at the record field are not already all ones,
 * set them and leave the top two bits alone.  The 14-bit width only survives to
 * a plain lsl/lsr pair as a bitfield: a mask in C would need the value in a
 * register first (docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md).
 *
 * symbols:
 *   none (no external calls; 0x3fff is a plain literal)
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Rec {
    u16 lo : 14;
    u16 hi : 2;
};

void func_0204F5A8(void *p, u32 idx)
{
    struct Rec *r = (struct Rec *)(*(u8 **)((u8 *)p + 8) + idx * 0x1c);

    if (r->lo != 0x3fff) {
        r->lo = 0x3fff;
    }
}
