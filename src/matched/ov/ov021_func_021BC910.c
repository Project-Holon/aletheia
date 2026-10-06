/*
 * function: func_021BC910
 * address:  0x021BC910
 * packet:   pkt_ov021_021BC910
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021BD138  0x021BD138  thumb  ov021
 */

typedef unsigned char u8;

typedef struct {
    char pad[0x148];
    u8 b148;
} Obj;

extern u8 func_021BD138(u8 *p);

int func_021BC910(Obj *p)
{
    if (func_021BD138((u8 *)p) <= p->b148) {
        return 1;
    }
    return 0;
}
