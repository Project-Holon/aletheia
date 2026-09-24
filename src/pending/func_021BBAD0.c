/*
 * function: func_021BBAD0
 * address:  0x021BBAD0
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * Tail-call veneer: forwards arg(s) a0, 0 to func_021BC574.
 *
 * MATCH: the pool word has no witness outside the compared range:
 *   021BC574 (thumb, ov217) is not a traced label and is not yet matched.
 *
 * symbols:
 *   func_021BC574  0x021BC574  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void func_021BC574(u32, u32);

void func_021BBAD0(u32 a0, u32 a1)
{
    func_021BC574(a0, 0);
}

