/*
 * function: func_020508C4
 * address:  0x020508C4
 * packet:   pkt_020508C4
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Leaf witness for ov021 0x021BBF10 / 0x021BC138 (lane wA1-12).
 */

typedef struct { int f0; char pad[0x24]; } E28_020508C4;
typedef struct { char pad[0x18]; E28_020508C4 *f18; } Mgr_020508C4;

int func_020508C4(Mgr_020508C4 *p, int i)
{
    return p->f18[i].f0;
}
