/*
 * file:     unit_0218D7CC_p01.c
 * unit:     yes
 * function: func_0218D7CC, func_0218D7F4, func_0218D840, func_0218D864
 * address:  0x0218D7CC
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
 *   func_0217EAE0  0x0217EAE0  arm  ov009
 *   func_02184144  0x02184144  arm  ov009
 *   func_02193734  0x02193734  arm  ov009
 *   g_021A4D80  0x021A4D80  data
 *   func_021841B0  0x021841B0  arm  ov009
 *   func_020948E0                0x020948E0  arm
 */
struct GPIKey {
    char *name;
    char *value;
};

struct GPIConnection {
    char pad[0x3b4];
    void *statusInfoKeys;
};

extern void func_0217EAE0(void *ptr);
extern void *func_02184144(int elemSize, int numElems, void (*freeFn)(void *));
extern void func_02193734(int *p, int b);
extern void func_021841B0(void *array);
extern int func_020948E0(const char *s1, const char *s2);
void func_0218D7CC(void *element);
int func_0218D7F4(void **connection);
void func_0218D840(void **connection);
asm void CaseInsensitiveCompare(void);
extern char g_021A4D80[];


/*
 * sdk:      gpiStatusInfoKeyFree (libdwcgsgp.TWL.HYB.a(gpikeys.o))
 */
void func_0218D7CC(void *element)
{
    struct GPIKey *aKey = (struct GPIKey *)element;

    func_0217EAE0(aKey->name);
    aKey->name = 0;
    func_0217EAE0(aKey->value);
    aKey->value = 0;
}


/*
 * sdk:      gpiStatusInfoKeysInit (libdwcgsgp.TWL.HYB.a(gpikeys.o))
 */
int func_0218D7F4(void **connection)
{
    struct GPIConnection *iconnection = (struct GPIConnection *)*connection;
    int result = 1;

    iconnection->statusInfoKeys = func_02184144(8, result, func_0218D7CC);
    if (iconnection->statusInfoKeys != 0)
        return 0;
    func_02193734((int *)connection, (int)g_021A4D80);
    return result;
}


/*
 * sdk:      gpiStatusInfoKeysDestroy (libdwcgsgp.TWL.HYB.a(gpikeys.o))
 */
void func_0218D840(void **connection)
{
    struct GPIConnection *iconnection = (struct GPIConnection *)*connection;

    if (iconnection->statusInfoKeys == 0)
        return;
    func_021841B0(iconnection->statusInfoKeys);
    iconnection->statusInfoKeys = 0;
}


asm void CaseInsensitiveCompare(void)
{
	ldr r0, [r0]
	ldr r1, [r1]
	ldr ip, =func_020948E0
	bx ip
}
