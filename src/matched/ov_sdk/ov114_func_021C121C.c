/*
 * function: ghiCompareCertUrl
 * address:  0x021C121C
 * packet:   pkt_ov114_021C121C
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * SDK: TwlDWC/libdwcgsgstats.TWL.HYB.a(gbucket.o).  The listed body
 * tail-calls the arm9 strcmp helper at 0x020948E0 on the two dereferenced
 * string pointers.
 *
 * symbols:
 *   strcmp  0x020948E0  arm  arm9
 */
extern int strcmp(const char *s1, const char *s2);

static int ghiCompareCertUrl(const char **a, const char **b)
{
    return strcmp(*a, *b);
}
