/*
 * function: gpiStatusInfoCheckKey
 * address:  0x0218D9A8
 * packet:   pkt_ov009_0218D9A8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gpiStatusInfoCheckKey (libdwcgsgp.TWL.HYB.a(gpikeys.o))
 *
 * symbols:
 *   gpiSetErrorString  0x02193734  arm  ov009
 *   goastrdup  0x0217F1E0  arm  ov009
 *   func_021843E8  0x021843E8  arm  ov009
 *   func_02184208  0x02184208  arm  ov009
 *   gsifree  0x0217EAE0  arm  ov009
 *   gGpiKeysErrorInvalidName  0x021A4D90  data
 *   func_0218D864  0x0218D864  arm  ov009
 */

struct GPIKey {
    char *name;
    char *value;
};

extern void gpiSetErrorString(int *p, int b);
extern char *goastrdup(char *src);
extern int func_021843E8(void *array, void *key, int (*comparator)(void *, void *), int fromIndex, int isSorted);
extern void *func_02184208(void *array, int n);
extern void gsifree(void *ptr);
extern int func_0218D864(void *elem1, void *elem2);
extern char gGpiKeysErrorInvalidName[];

int gpiStatusInfoCheckKey(void **connection, void *keys, char *keyName, char **keyValue)
{
    struct GPIKey aKey;
    struct GPIKey *aKeyFound;
    int anIndex;

    if (keyName == 0) {
        gpiSetErrorString((int *)connection, (int)gGpiKeysErrorInvalidName);
        return 2;
    }
    aKey.name = goastrdup(keyName);
    anIndex = func_021843E8(keys, &aKey, func_0218D864, 0, 1);
    if (anIndex != -1) {
        aKeyFound = (struct GPIKey *)func_02184208(keys, anIndex);
        *keyValue = aKeyFound->value;
    }
    gsifree(aKey.name);
    aKey.name = 0;
    return 0;
}
