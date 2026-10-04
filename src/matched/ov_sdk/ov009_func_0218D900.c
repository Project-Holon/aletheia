/*
 * function: func_0218D900
 * address:  0x0218D900
 * packet:   pkt_ov009_0218D900
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gpiStatusInfoSetKey (libdwcgsgp.TWL.HYB.a(gpikeys.o))
 *
 * symbols:
 *   func_02193734  0x02193734  arm  ov009
 *   func_0217F1E0  0x0217F1E0  arm  ov009
 *   func_021843E8  0x021843E8  arm  ov009
 *   func_02184208  0x02184208  arm  ov009
 *   func_0217EAE0  0x0217EAE0  arm  ov009
 *   g_021A4D90  0x021A4D90  data
 *   func_0218D864  0x0218D864  arm  ov009
 */

struct GPIKey {
    char *name;
    char *value;
};

extern void func_02193734(int *p, int b);
extern char *func_0217F1E0(char *src);
extern int func_021843E8(void *array, void *key, int (*comparator)(void *, void *), int fromIndex, int isSorted);
extern void *func_02184208(void *array, int n);
extern void func_0217EAE0(void *ptr);
extern int func_0218D864(void *elem1, void *elem2);
extern char g_021A4D90[];

int func_0218D900(void **connection, void *keys, char *keyName, char *newKeyValue)
{
    struct GPIKey aKey;
    struct GPIKey *aKeyFound;
    int anIndex;

    if (keyName == 0) {
        func_02193734((int *)connection, (int)g_021A4D90);
        return 2;
    }
    aKey.name = func_0217F1E0(keyName);
    anIndex = func_021843E8(keys, &aKey, func_0218D864, 0, 1);
    if (anIndex != -1) {
        aKeyFound = (struct GPIKey *)func_02184208(keys, anIndex);
        func_0217EAE0(aKeyFound->value);
        aKeyFound->value = func_0217F1E0(newKeyValue);
    }
    func_0217EAE0(aKey.name);
    aKey.name = 0;
    return 0;
}
