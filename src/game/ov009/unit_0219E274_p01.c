/*
 * file:     unit_0219E274_p01.c
 * unit:     yes
 * function: func_0219E274, func_0219E2D4
 * address:  0x0219E274
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   strcmp                         0x020948E0  arm
 *   g_021A8120                     0x021A8120  data
 *   _ZZ5mytokPccE6thestr            0x021AEAF8  data
 */
typedef struct {
    char *k[2];
} InvalidKeyList;

extern int strcmp(char *a, char *b);
int func_0219E274(char *key);
char *mytok(char *instr, char delim);
extern char *g_021A8120[2];


/*
 * sdk:      CheckValidKey (sb_server.o)
 *
 * Closed (w5_nm): InvalidKeys is filled by one 8-byte struct assignment from the
 * initializer template, which loads both words before either store.  The vendor
 * initializer is @13711 (two relocated string pointers, 0x021A8128 and
 * 0x021A8118), which the template class cannot compare, so it is declared as
 * the data label g_021A8120.
 */
int func_0219E274(char *key)
{
    char *InvalidKeys[2];
    unsigned int i;

    *(InvalidKeyList *)InvalidKeys = *(InvalidKeyList *)g_021A8120;
    for (i = 0; i < 2; i++) {
        if (strcmp(key, InvalidKeys[i]) == 0)
            return 0;
    }
    return 1;
}

char *mytok(char *instr, char delim)
{
    char *result;
    static char *thestr;

    if (instr)
        thestr = instr;
    result = thestr;
    while (*thestr && *thestr != delim)
        thestr++;
    if (thestr == result)
        result = 0;
    if (*thestr)
        *thestr++ = '\0';
    return result;
}
