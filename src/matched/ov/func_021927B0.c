/*
 * function: func_021927B0
 * address:  0x021927B0
 * packet:   pkt_021927B0
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
 *   func_021927E8  0x021927E8  thumb  ov021
 *   ENV_SetResourceSet  0x020307B0  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;
extern void func_021927E8(u32 *p);
extern void ENV_SetResourceSet(void *p);

void func_021927B0(u8 *p)
{
    func_021927E8((u32 *)p);
    ENV_SetResourceSet(p);
}
