/*
 * function: FLDMMDL_BLACT_ClearActorReserve
 * address:  0x0219D1F8
 * packet:   pkt_0219D1F8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Clears the byte at +0xd, then tail calls with 0 and 0x28.
 *
 * symbols:
 *   func_02082BCC  0x02082BCC  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_02082BCC(u8 *p, u32 a, u32 b);

void FLDMMDL_BLACT_ClearActorReserve(u8 *p)
{
    *((u8 *)p + 0xd) = 0;
    func_02082BCC(p, 0, 0x28);
}
