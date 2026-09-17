/*
 * unit:     no
 * function: func_0201D83C
 * address:  0x0201D83C
 * packet:   pkt_0201D7EC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Destructor / teardown pass for font objects in gf_font.c.
 *
 * symbols:
 *   sub_0201DADC   0x0201DADC  thumb
 *   sub_0201D9C8   0x0201D9C8  thumb
 *   sub_020307B0   0x020307B0  arm
 */

typedef unsigned char u8;

extern void sub_0201DADC(void *font);
extern void sub_0201D9C8(void *font);
extern void sub_020307B0(void *font);

void func_0201D83C(void *font)
{
    sub_0201DADC(font);
    sub_0201D9C8(font);
    sub_020307B0(font);
}
