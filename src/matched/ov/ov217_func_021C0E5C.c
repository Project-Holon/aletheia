/*
 * function: RingQueue_Reset
 * address:  0x021C0E5C
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call veneer: branch to RingQueue_ResetImpl.
 *
 * symbols:
 *   RingQueue_ResetImpl  0x021C0EDC  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void RingQueue_ResetImpl(void);

void RingQueue_Reset(void)
{
    RingQueue_ResetImpl();
}
