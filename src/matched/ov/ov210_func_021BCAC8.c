/*
 * function: func_021BCAC8
 * address:  0x021BCAC8
 * packet:   pkt_ov210_021BCAC8
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020490F4  0x020490F4  arm
 *   func_020498F4  0x020498F4  arm
 *   func_02049238  0x02049238  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
typedef signed int     s32;
extern void *func_020490F4(unsigned int id, u16 heap);
extern void func_020498F4(void *, u32, u32, u32, u32, u32, u16);
extern void func_02049238(void *);

void func_021BCAC8(void)
{
    void *h = func_020490F4(159, 0x807b);
    func_020498F4(h, 89, 3, 0, 0, 0, 123);
    func_02049238(h);
}
