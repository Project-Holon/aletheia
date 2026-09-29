/*
 * function: func_02159BFC
 * address:  0x02159BFC
 * packet:   pkt_ov010_02159BFC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf accessor (prints as .word): returns the field at +0x10.
 * Sole blocker of ov021 func_02189B30's MATCH.
 */

typedef struct Obj {
    char pad[0x10];
    int f;
} Obj;

int func_02159BFC(Obj *p)
{
    return p->f;
}
