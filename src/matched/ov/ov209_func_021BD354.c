/*
 * function: func_021BD354
 * address: 0x021BD354
 * packet: pkt_ov209_021BD354
 * region: ov209
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: 021BD396 two-byte alignment padding before 021BD398.
 * symbols:
 *   func_02012BF8 0x02012BF8 thumb
 *   func_02012BE0 0x02012BE0 thumb
 *   func_021BD890 0x021BD890 thumb ov209
 */
extern int func_02012BF8(int, int);
extern void func_02012BE0(void *, unsigned, unsigned);
extern void func_021BD890(char *, int, int);
void func_021BD354(char *p)
{
    if (func_02012BF8(**(int **)p, 15) == 1) {
        func_02012BE0(**(void ***)p, 15, 0);
        func_021BD890(p, 5, 6);
    } else {
        func_02012BE0(**(void ***)p, 15, 1);
        func_021BD890(p, 5, 7);
    }
}
