/*
 * function: func_021BAB58
 * address:  0x021BAB58
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * Reconstructed from the listing.
 *
 * BLOCKED at MATCH: both ABS32 sites are code pointers to functions that
 * sit inside *other* functions' pools and carry no func_ label anywhere in
 * the image, so `label`/`sole-ref/code`/`matched` never fire and they land
 * in a `sole-ref/data` grey zone: 0x021BAB50 is a `.word` run between two
 * functions in ov217 (it is the 8-byte stub `ldr r0,[pc]; bx r3` at +0x8,
 * its target 0x0204A648 pooled at 0x021BAB54) and 0x02005654 is an ARM
 * instruction word inside pool_02005650 in arm9 main.s.  Neither is a
 * labelled datum start nor a traced function.
 *
 * symbols:
 *   func_021BAB50  0x021BAB50  thumb  ov217
 *   func_02005654  0x02005654  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern void func_02005654(void (*)(), int);
extern void func_021BAB50();
void func_021BAB58(void)
{
    func_02005654(func_021BAB50, 0);
}

