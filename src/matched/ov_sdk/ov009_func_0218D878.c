/*
 * function: func_0218D878
 * address:  0x0218D878
 * packet:   pkt_ov009_0218D878
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gpiStatusInfoAddKey (libdwcgsgp.TWL.HYB.a(gpikeys.o))
 *
 * symbols:
 *   func_02193734  0x02193734  arm  ov009
 *   func_0217F1E0  0x0217F1E0  arm  ov009
 *   func_021842D0  0x021842D0  arm  ov009
 *   g_021A4D90  0x021A4D90  data
 *   g_021A4DA4  0x021A4DA4  data
 *   func_0218D864  0x0218D864  arm  ov009
 */

struct GPIKey {
    char *name;
    char *value;
};

extern void func_02193734(void **connection, char *errorString);
extern char *func_0217F1E0(char *src);
extern void func_021842D0(void *array, void *newElem, int (*comparator)(void *, void *));
extern int func_0218D864(void *elem1, void *elem2);
extern char g_021A4D90[];
extern char g_021A4DA4[];

int func_0218D878(void **connection, void *keys, char *theKeyName, char *theKeyValue)
{
    struct GPIKey aKey;

    if (theKeyName == 0) {
        func_02193734(connection, g_021A4D90);
        return 2;
    }
    if (theKeyValue == 0) {
        func_02193734(connection, g_021A4DA4);
        return 2;
    }
    aKey.name = func_0217F1E0(theKeyName);
    aKey.value = func_0217F1E0(theKeyValue);
    func_021842D0(keys, &aKey, func_0218D864);
    return 0;
}
