/*
 * function: func_02012BC8
 * address:  0x02012BC8
 * packet:   pkt_02012BC8
 * region:   arm9
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02008450  0x02008450  thumb
 *
 * Forward a boolean-normalised flag to func_02008450 on the object held at
 * +0x198 of the game-data object (func_0200873C(handle) in func_020124F4).
 *
 * The tail call's pool word names 0x02008450, an unlabelled Thumb leaf
 * (the bit-10 setter beside the labelled getter func_02008448); this
 * pool word is its only reference in the image.  It is attested by the
 * compiled witness src/matched/func_02008450.c (class `matched`).
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern void func_02008450(u32 flags, int on);

void func_02012BC8(u8 *p, int on)
{
    func_02008450(*(u32 *)(p + 0x198), on ? 1 : 0);
}
