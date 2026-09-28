/*
 * function: KeyValCompareKey
 * address:  0x0219E8D4
 * packet:   pkt_ov009_0219E8D4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      KeyValCompareKey (sb_server.o)
 *
 * Both keys tested in one conjunction and dereferenced only inside it: that is
 * what keeps the second load conditional (`ldrne r1,[r1]; cmpne r1,#0`) instead
 * of hoisting both loads.  strcasecmp resolves to a real ARM9 func_ label.
 *
 * symbols:
 *   strcasecmp  0x0209ABF8  arm
 */

struct _SBKeyValuePair {
    char *key;
    char *value;
};

extern int strcasecmp(char *a, char *b);

static int KeyValCompareKey(void *entry1, void *entry2)
{
    if (((struct _SBKeyValuePair *)entry1)->key != 0 &&
        ((struct _SBKeyValuePair *)entry2)->key != 0)
        return strcasecmp(((struct _SBKeyValuePair *)entry1)->key,
                          ((struct _SBKeyValuePair *)entry2)->key);
    return 1;
}
