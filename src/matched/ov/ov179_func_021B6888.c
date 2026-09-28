/*
 * function: func_021B6888
 * address:  0x021B6888
 * packet:   pkt_021B6888
 * region:   ov179
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * 12-byte leaf: forwards the second word of the record to func_02005DAC and
 * returns 1.  The lane enumerator reports 664 bytes because this is the last
 * func_ label in ov179; the disassembly ends at the pop and the rest is data.
 */

extern void func_02005DAC(unsigned int);

int func_021B6888(void *ctx, unsigned int *rec)
{
    func_02005DAC(rec[1]);
    return 1;
}
