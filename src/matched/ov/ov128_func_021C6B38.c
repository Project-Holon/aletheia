/*
 * function: func_021C6B38
 * address:  0x021C6B38
 * packet:   pkt_021C6B38
 * region:   ov128
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020456F8  0x020456F8  arm
 *   func_02045730  0x02045730  arm
 *   func_02041B6C  0x02041B6C  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void func_020456F8(void *);
extern u8 func_02045730(void *);
extern void func_02041B6C(u32);

void func_021C6B38(u8 *p)
{
    void *q = *(void **)(p + 0xc);
    func_020456F8(q);
    func_02041B6C(func_02045730(q));
}
