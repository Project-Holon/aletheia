/*
 * function: func_0219E274
 * address:  0x0219E274
 * packet:   pkt_ov009_0219E274
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CheckValidKey (sb_server.o)
 *
 * Closed (w5_nm): InvalidKeys is filled by one 8-byte struct assignment from the
 * initializer template, which loads both words before either store.  The vendor
 * initializer is @13711 (two relocated string pointers, 0x021A8128 and
 * 0x021A8118), which the template class cannot compare, so it is declared as
 * the data label g_021A8120.
 *
 * symbols:
 *   strcmp                         0x020948E0  arm
 *   g_021A8120                     0x021A8120  data
 */

extern int strcmp(char *a, char *b);

typedef struct {
    char *k[2];
} InvalidKeyList;

extern char *g_021A8120[2];

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
