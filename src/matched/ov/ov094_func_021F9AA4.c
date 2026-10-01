/*
 * function: func_021F9AA4
 * address:  0x021F9AA4
 * packet:   pkt_ov094_021F9AA4
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Clears the two words at 0x2a4 and 0x2a8 of the owner's work.
 *
 * symbols:
 *   func_02011324 0x02011324 thumb
 */
extern char *func_02011324(void *);

void func_021F9AA4(void *a)
{
    char *s = func_02011324(a);
    *(int *)(s + 0x2a4) = 0;
    *(int *)(s + 0x2a8) = 0;
}
