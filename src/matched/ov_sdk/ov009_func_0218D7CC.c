/*
 * function: func_0218D7CC
 * address:  0x0218D7CC
 * packet:   pkt_ov009_0218D7CC
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gpiStatusInfoKeyFree (libdwcgsgp.TWL.HYB.a(gpikeys.o))
 *
 * symbols:
 *   func_0217EAE0  0x0217EAE0  arm  ov009
 */

struct GPIKey {
    char *name;
    char *value;
};

extern void func_0217EAE0(void *ptr);

void func_0218D7CC(void *element)
{
    struct GPIKey *aKey = (struct GPIKey *)element;

    func_0217EAE0(aKey->name);
    aKey->name = 0;
    func_0217EAE0(aKey->value);
    aKey->value = 0;
}
