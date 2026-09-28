/*
 * function: func_021EBF74
 * address:  0x021EBF74
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *
 * Sweep 0x2d slots of the 0x9E74 array, restarting each live one.
 *   The element address must be a named `int *row = (int *)(p + i*4)`
 *   and the offset written as the WORD index row[0x279d]: that is what
 *   puts i in r4, the row in r5 and 0x9E74 in r7 (the flat spelling
 *   swaps r4/r5).
 */

extern int func_0204B944(int);
extern void func_0204B8D4(int, int);
extern void func_0204A600(void);
extern int func_0204B944(int);
extern void func_0204B8D4(int, int);
extern void func_0204A600(void);
void func_021EBF74(char *p)
{
    unsigned i;
    for (i = 0; i < 0x2d; i++) {
        int *row = (int *)(p + i * 4);
        if (row[0x279d] != 0 && func_0204B944(row[0x279d]) != 1)
            func_0204B8D4(row[0x279d], 0x1000);
    }
    func_0204A600();
}

