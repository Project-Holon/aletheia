/*
 * function: func_021626A8
 * address:  0x021626A8
 * packet:   pkt_ov010_021626A8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Unlabelled leaf, blocker of ov021 func_0218AD80: compiler tail call (ldr r3,=; bx r3) of
 * func_02162B68; not a linker veneer.
 * Overlay choice, ov009 and ov010 share this window; ov009 holds ARM code here,
 * ov010 holds this Thumb routine, and the ov021 callers already name ov010
 * (ov010 is the overlay resident with ov021).
 *
 * symbols:
 *   func_02162B68  0x02162B68  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Box;
u16 func_02162B68(struct Box *b, int *pos);

u16 func_021626A8(void *b, void *pos)
{
    return func_02162B68(b, pos);
}
