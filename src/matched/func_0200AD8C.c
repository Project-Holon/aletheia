/*
 * function: func_0200AD8C
 * address:  0x0200AD8C
 * packet:   pkt_0200AD8C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * note:     wave 18 lane ties_b: unlabelled follower; getter of the u16 at +0xEC (extent includes two bytes of padding).
 */

typedef unsigned short u16;

typedef struct Rec0200AD8C {
    unsigned char pad[0xEC];
    u16 fEC;
} Rec0200AD8C;

u16 func_0200AD8C(const Rec0200AD8C *p)
{
    return p->fEC;
}
