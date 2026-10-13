/*
 * function: func_021E0920
 * address:  0x021E0920
 * packet:   pkt_ov093_021E0920
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * The call passes r3 (d) through to func_021E0944, whose own C takes three
 * parameters; the prototype here carries the fourth.
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   func_021E0944  0x021E0944  thumb  ov093
 */

extern int BTL_EVENT_GetVar(int key);
extern void func_021E0944(int a, void *q, int id, int d);

void func_021E0920(int a, void *b, int c, int d)
{
    if (c == BTL_EVENT_GetVar(2))
        func_021E0944(a, b, c, d);
}
