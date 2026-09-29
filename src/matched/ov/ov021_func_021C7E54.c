/*
 * function: func_021C7E54
 * address:  0x021C7E54
 * packet:   pkt_ov021_021C7E54
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf accessor (prints as .word in the listing): returns the u16 at +0x1C (func_021C7E50 sets +0x1E).
 * Sole blocker of ov010 func_0215ECBC's MATCH.
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Obj {
    u8 pad00[0x1C];
    u16 f1c;            /* 0x1C */
} Obj;

u16 func_021C7E54(Obj *p)
{
    return p->f1c;
}
