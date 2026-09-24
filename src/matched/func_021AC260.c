/*
 * function: func_021AC260
 * address:  0x021AC260
 * packet:   pkt_021AC260
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Pattern-generated from the ov021 family.
 *
 * symbols:
 *   func_021AC2AC  0x021AC2AC  thumb  ov021
 *   ENV_SetResourceSet  0x020307B0  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;
extern void func_021AC2AC(void *p);
extern void ENV_SetResourceSet(void *p);

void func_021AC260(u32 a, u8 *p)
{
    func_021AC2AC(p);
    ENV_SetResourceSet(p);
}
