/*
 * function: gpiStatusInfoAddKey
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
 *   gpiSetErrorString  0x02193734  arm  ov009
 *   goastrdup  0x0217F1E0  arm  ov009
 *   func_021842D0  0x021842D0  arm  ov009
 *   gGpiKeysErrorInvalidName  0x021A4D90  data
 *   gGpiKeysErrorInvalidValue  0x021A4DA4  data
 *   func_0218D864  0x0218D864  arm  ov009
 */

struct GPIKey {
    char *name;
    char *value;
};

extern void gpiSetErrorString(int *p, int b);
extern char *goastrdup(char *src);
extern void func_021842D0(void *array, void *newElem, int (*comparator)(void *, void *));
extern int func_0218D864(void *elem1, void *elem2);
extern char gGpiKeysErrorInvalidName[];
extern char gGpiKeysErrorInvalidValue[];

int gpiStatusInfoAddKey(void **connection, void *keys, char *theKeyName, char *theKeyValue)
{
    struct GPIKey aKey;

    if (theKeyName == 0) {
        gpiSetErrorString((int *)connection, (int)gGpiKeysErrorInvalidName);
        return 2;
    }
    if (theKeyValue == 0) {
        gpiSetErrorString((int *)connection, (int)gGpiKeysErrorInvalidValue);
        return 2;
    }
    aKey.name = goastrdup(theKeyName);
    aKey.value = goastrdup(theKeyValue);
    func_021842D0(keys, &aKey, func_0218D864);
    return 0;
}
