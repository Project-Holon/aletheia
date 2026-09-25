/*
 * function: func_021FA04C
 * address:  0x021FA04C
 * packet:   pkt_021FA04C
 * region:   ov132
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021FA278  0x021FA278  thumb
 *   func_021FA0D4  0x021FA0D4  thumb
 *   func_020307B0  0x020307B0  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void func_021FA278(void *);
extern void func_021FA0D4(void *);
extern void func_020307B0(void *);

void func_021FA04C(u8 *p)
{
    func_021FA278(p);
    func_021FA0D4(p);
    func_020307B0(p);
}
