/*
 * function: func_021DD250
 * address:  0x021DD250
 * packet:   pkt_021DD250
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0217EAE0  0x_0217EAE0  arm  ov009
 *
 * ARM tail jump into 0x0217EAE0 (ov009); every register is forwarded, so
 *  *  the body is the call alone and nothing is saved.
 */

extern void func_0217EAE0(void);

void func_021DD250(void *sake)
{
    func_0217EAE0();
}

