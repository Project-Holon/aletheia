/*
 * function: func_021B6EBC
 * address:  0x021B6EBC
 * packet:   pkt_021B6100
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail call to func_0207E008 (ARM9).
 *
 * symbols:
 *   func_0207E008  0x0207E008  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void *func_0207E008(void);

void *func_021B6EBC(void)
{
    return func_0207E008();
}
