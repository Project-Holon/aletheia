/*
 * function: RefStringCompare
 * address:  0x0219DF40
 * packet:   pkt_ov009_0219DF40
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0209ABF8                0x0209ABF8  arm
*/

extern int func_0209ABF8(char *s1, char *s2);

int RefStringCompare(void *entry1, void *entry2)
{
    return func_0209ABF8(*(char **)entry1, *(char **)entry2);
}
