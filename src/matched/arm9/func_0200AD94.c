/*
 * function: WORLDTRADE_SetIsDeposited
 * address:  0x0200AD94
 * packet:   pkt_0200AD94
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * note:     wave 18 lane ties_b: unlabelled follower; setter of the u16 at +0xEC (extent includes two bytes of padding).
 */

typedef unsigned short u16;

typedef struct Rec0200AD94 {
    unsigned char pad[0xEC];
    u16 fEC;
} Rec0200AD94;

void WORLDTRADE_SetIsDeposited(Rec0200AD94 *p, u16 v)
{
    p->fEC = v;
}
