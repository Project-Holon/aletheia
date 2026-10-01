/*
 * function: func_021642D4
 * address:  0x021642D4
 * packet:   pkt_ov010_021642D4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf, blocker of ov021 func_0219FFD4: three chained table lookups.
 * Overlay choice, ov009 and ov010 share this window; ov009 holds ARM code here,
 * ov010 holds this Thumb routine, and the ov021 callers already name ov010
 * (ov010 is the overlay resident with ov021).
 *
 * symbols:
 *   d_02171458     0x02171458  data  a2
 *   d_02171460     0x02171460  data
 *   d_021714C0     0x021714C0  data  a4
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u8 a;
    u8 b;
    u8 c;
    u8 d;
} Quad;

extern u16 d_02171458[];
extern u8 d_02171460[];
extern Quad d_021714C0[];

u8 func_021642D4(int i, int v)
{
    u32 s = (u16)(v + d_02171458[i]);

    return d_021714C0[d_02171460[s >> 12]].b;
}
