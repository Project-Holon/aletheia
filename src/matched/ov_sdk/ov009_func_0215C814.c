/*
 * function: func_0215C814
 * address:  0x0215C814
 * packet:   pkt_ov009_0215C814
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      rawip (libcps.TWL.HYB.a(network.o))
 *
 * symbols:
 *   func_0215C7E0  0x0215C7E0  arm  ov009
 */

extern unsigned long func_0215C7E0(unsigned char *s, unsigned char **end);

unsigned long func_0215C814(unsigned char *name, unsigned long *pip)
{
    unsigned long ip = 0;
    int i = 0;
    unsigned long field;
    unsigned char *next;

    do {
        field = func_0215C7E0(name, &next);
        if (name == next)
            return 0;
        name = next;
        if (field > 0xff)
            goto fail;
        if (i != 3) {
            unsigned char c = *name++;

            if (c != '.')
                goto fail;
        }
        if (i == 3) {
            if (*name != 0) {
fail:
                return 0;
            }
        }
        ip = field | (ip << 8);
        i++;
    } while (i < 4);
    *pip = ip;
    return 1;
}
