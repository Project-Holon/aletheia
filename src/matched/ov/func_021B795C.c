/*
 * function: func_021B795C
 * address:  0x021B795C
 * packet:   pkt_021B795C
 * region:   ov104
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B7D0C  0x021B7D0C  thumb  ov104
 *
 * blocker: Target 0x021B7D0C is unlabelled in ov104; the only pool word naming it is the one inside this function, so no evidence class can attest it outside the range. Byte-correct.
 
 *
 * DUPLICATE: the region-qualified copy src/matched/ov104_func_021B795C.c is the
 * promoted EXACT entry for this address; this legacy-named file is
 * left parked so the same address is not sharded twice.
*/

void func_021B7D0C(int);

void func_021B795C(int x)
{
    func_021B7D0C(x + 4);
}
