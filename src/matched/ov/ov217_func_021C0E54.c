/*
 * function: RingQueue_Pop
 * address:  0x021C0E54
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call veneer: branch to RingQueue_PopImpl.
 *
 * symbols:
 *   RingQueue_PopImpl  0x021C0EC0  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct Ring;

extern u32 RingQueue_PopImpl(struct Ring *r);

u32 RingQueue_Pop(struct Ring *r)
{
    return RingQueue_PopImpl(r);
}
