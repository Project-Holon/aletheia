/*
 * function: func_021BDDF8
 * address:  0x021BDDF8
 * packet:   pkt_021BDDF8
 * region:   ov204
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void func_020450C8(u8 *);
extern void func_0203F9B4(void);
extern void func_02082BCC(u8 *, u32, u32);

void func_021BDDF8(u8 *p)
{
    func_020450C8(p);
    func_0203F9B4();
    func_02082BCC(p, 0, 4);
}

