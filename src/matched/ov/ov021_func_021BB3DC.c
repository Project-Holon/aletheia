/*
 * function: func_021BB3DC
 * address:  0x021BB3DC
 * packet:   pkt_ov021_021BB3DC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: the object's word at +0x0, r1/r2 passed through
 * (ov046 func_021F4078 calls it with three arguments).
 *
 * symbols:
 *   func_021B7C04  0x021B7C04  thumb  ov021
 */

typedef unsigned int u32;

typedef unsigned char  u8;
extern void func_021B7C04(u8 *o, int k, int flag);

void func_021BB3DC(u32 *p, int b, int c)
{
    func_021B7C04((u8 *)(*p), b, c);
}
