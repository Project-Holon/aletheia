/*
 * function: func_021BB458
 * address:  0x021BB458
 * packet:   pkt_021BB458
 * region:   ov214
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * 14-byte leaf: bracket two SDK calls around a call on the pointed-to word.
 * The lane enumerator reports 552 bytes because the next func_ label is far;
 * the disassembly ends at the pop and the rest is data.
 */

extern void func_02047964(void);
extern void func_02048AD0(unsigned int);
extern void func_020479D8(void);

void func_021BB458(unsigned int *p)
{
    func_02047964();
    func_02048AD0(*p);
    func_020479D8();
}
