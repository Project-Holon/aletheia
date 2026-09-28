/*
 * function: func_021B8954
 * address:  0x021B8954
 * packet:   pkt_021B6868
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Sets the +0x194 flag, refills the +0x1a4 block and returns it.
 *
 * symbols:
 *   func_02082A7C  0x02082A7C  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void func_02082A7C(int a, int b, int c);

int func_021B8954(void *p, char *q)
{
    *(u32 *)(q + 0x194) = 1;
    func_02082A7C(0, *(u32 *)(q + 0x1a4), 0x208);
    return *(u32 *)(q + 0x1a4);
}
