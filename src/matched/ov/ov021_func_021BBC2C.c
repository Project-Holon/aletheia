/*
 * function: func_021BBC2C
 * address:  0x021BBC2C
 * packet:   pkt_ov021_021BBC2C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   _u32_div_f     0x0209C2B0  arm
 *   d_021D9AE0     0x021D9AE0  data  a4
 */

typedef struct {
    char pad[0x1A];
    char s1A[10];
} Entry;

extern char d_021D9AE0[];

extern int func_0203EFC8(const char *a, const char *b, int n);

Entry *func_021BBC2C(Entry *tab, unsigned int i)
{
    Entry *e = &tab[i % 30];

    if (func_0203EFC8(e->s1A, d_021D9AE0, 6) == 0) {
        e = 0;
    }
    return e;
}
