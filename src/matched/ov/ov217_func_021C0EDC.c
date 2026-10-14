/*
 * function: RingQueue_ResetImpl
 * address:  0x021C0EDC
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Clears two words of a record.  Reached only from the tail-call veneer
 * RingQueue_Reset.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

typedef struct {
    u32 w[2];
    u32 a;
    u32 b;
} Rec;

void RingQueue_ResetImpl(Rec *p)
{
    p->a = 0;
    p->b = 0;
}
