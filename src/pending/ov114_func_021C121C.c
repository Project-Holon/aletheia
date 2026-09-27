/*
 * function: CaseInsensitiveCompare
 * address:  0x021C121C
 * packet:   pkt_ov114_021C121C
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   PENDING
 *
 * SDK: TwlDWC/libdwcgsgstats.TWL.HYB.a(gbucket.o).  The listed body
 * tail-calls the arm9 strcmp helper at 0x020948E0 on the two dereferenced
 * string pointers.
 */
extern int func_020948E0(const char *s1, const char *s2);

int CaseInsensitiveCompare(const char **a, const char **b)
{
    return func_020948E0(*a, *b);
}
