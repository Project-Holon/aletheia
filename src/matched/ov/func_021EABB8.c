/*
 * function: func_021EABB8
 * address:  0x021EABB8
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020456F8  0x020456F8  arm  arm9
 *   func_02045730  0x02045730  arm  arm9
 *   func_02041B6C  0x02041B6C  arm  arm9
 *
 * Release both children of the object and then a global one.
 */

typedef unsigned char  u8;
struct Descriptor;
extern void func_020456F8(struct Descriptor *d);
extern u8 func_02045730(struct Descriptor *p);
extern void func_02041B6C(unsigned int);

void func_021EABB8(void **p)
{
    func_020456F8(*p);
    func_02041B6C(func_02045730(*p));
}

