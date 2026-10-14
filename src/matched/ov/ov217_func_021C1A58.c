/*
 * function: CircleGraph_SetEnabledImpl
 * address:  0x021C1A58
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Stores one word at offset 4.  Reached only from the tail-call veneer
 * CircleGraph_SetEnabled.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

typedef struct {
    u32 w;
    u32 a;
} Rec;

void CircleGraph_SetEnabledImpl(Rec *p, u32 v)
{
    p->a = v;
}
