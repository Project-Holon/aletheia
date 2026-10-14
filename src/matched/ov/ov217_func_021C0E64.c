/*
 * function: RingQueue_IsEmpty
 * address:  0x021C0E64
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call veneer: branch to RingQueue_IsEmptyImpl.
 *
 * symbols:
 *   RingQueue_IsEmptyImpl  0x021C0EE4  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void RingQueue_IsEmptyImpl(void);

void RingQueue_IsEmpty(void)
{
    RingQueue_IsEmptyImpl();
}
