/*
 * function: BMP_MENU_Add
 * address:  0x0201F9D0
 * packet:   pkt_0201F5BC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * A pass-through onto BMP_MENU_Create: the four register arguments are never
 * touched and only the two stacked ones are copied down into the new frame.
 * The fifth is a halfword and needs `add r4, sp, #0x10` + `ldrh` because
 * Thumb has no halfword load with an sp base; the sixth is a word and loads
 * directly.
 *
 * Blocked on the `label` class: 0x0201F93C has no branch reference anywhere
 * in the image except the one in this function, and the range cannot be cut
 * smaller than the single function, so no witness exists.  0x0201F93C is a
 * 148-byte constructor (debug allocator at 0x02030734, 0x38 bytes, line 97,
 * a nine-word ldm/stm copy of the caller's descriptor, then BMP_MENU_GetMaxItemWidth)
 * and was not attempted in wave 20B for budget reasons, not for difficulty.
 *
 * symbols:
 *   BMP_MENU_Create  0x0201F93C  thumb
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BMP_MENU_Add.c \
 *       --func BMP_MENU_Add --addr 0x0201F9D0 --cc 1.1p1 --thumb
 */
typedef unsigned short u16;
typedef unsigned int   u32;

extern void BMP_MENU_Create(u32 a, u32 b, u32 c, u32 d, u16 e, u32 f);

void BMP_MENU_Add(u32 a, u32 b, u32 c, u32 d, u16 e, u32 f)
{
    BMP_MENU_Create(a, b, c, d, e, f);
}
