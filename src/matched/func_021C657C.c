/*
 * function: func_021C657C
 * address:  0x021C657C
 * packet:   pkt_021C657C
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C6688  0x021C6688  thumb
 *   func_021C65E4  0x021C65E4  thumb
 *   func_021C674C  0x021C674C  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void func_021C6688(void *);
extern void func_021C65E4(void *);
extern void func_021C674C(void *);

void func_021C657C(u8 *p)
{
    func_021C6688(*(void **)(p + 8));
    func_021C65E4(*(void **)(p + 8));
    func_021C674C(*(void **)(p + 8));
}
