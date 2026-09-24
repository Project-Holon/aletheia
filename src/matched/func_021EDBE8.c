/*
 * function: func_021EDBE8
 * address:  0x021EDBE8
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   g_021EFCEC  0x021EFCEC  data  ov170
 *
 * Copies one byte of a fixed table into every element of a[] that equals d,
 * for the first n entries.  The table byte is loop-invariant: mwccarm only
 * hoists it into the rotated preheader when the table is a CONST-qualified
 * extern array symbol -- the address then materialises in the entry block
 * (r0) and the load sits after the entry test, as the image has it.
 */



extern const unsigned char g_021EFCEC[];
void func_021EDBE8(int x0, unsigned char *a, unsigned c, unsigned char d, unsigned n)
{
    unsigned i;
    for (i = 0; i < n; i++)
        if (a[i] == d)
            a[i] = g_021EFCEC[c];
}
