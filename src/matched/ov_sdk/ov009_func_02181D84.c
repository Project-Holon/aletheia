/*
 * function: gsXmlFreeWriter
 * address:  0x02181D84
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Calls the module helper on the pointed-to block and then on the pointer.
 *
 * symbols:

 */

extern void func_0217EAE0(void *p);

void gsXmlFreeWriter(void **p)
{
    func_0217EAE0(*p);
    func_0217EAE0(p);
}

