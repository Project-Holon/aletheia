/*
 * function: func_021C29F0
 * address:  0x021C29F0
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call veneer: passes its argument through to func_021C2A30.
 *
 * symbols:
 *   func_021C2A30  0x021C2A30  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

typedef struct {
    u32 w[8];
} Rec;

extern void func_021C2A30(Rec *);

void func_021C29F0(Rec *p)
{
    func_021C2A30(p);
}
