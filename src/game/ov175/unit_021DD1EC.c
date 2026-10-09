/*
 * file:     unit_021DD1EC.c
 * function: func_021DD1EC
 * address:  0x021DD1EC
 * packet:   pkt_ov175_021DD1EC
 * region:   ov175
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      sakeStartup (sakemain.o)
 *
 * symbols:
 *   func_0217CE1C  0x0217CE1C  arm  ov009
 *   func_0217EAB0  0x0217EAB0  arm  ov009
 *   func_020923B0  0x020923B0  arm
 *   g_021ACEF8  0x021ACEF8  data
 */

typedef struct SAKEInternal {
    unsigned char data[0x4C];
} SAKEInternal;

extern int g_021ACEF8;
extern int func_0217CE1C(void);
extern void *func_0217EAB0(unsigned long size);
extern void *func_020923B0(void *dst, int val, unsigned long n);

int func_021DD1EC(SAKEInternal **sakePtr)
{
    SAKEInternal *sake;

    if (g_021ACEF8 != 1)
        return 1;
    if (func_0217CE1C())
        return 2;
    sake = (SAKEInternal *)func_0217EAB0(sizeof(SAKEInternal));
    if (!sake)
        return 3;
    func_020923B0(sake, 0, sizeof(SAKEInternal));
    *sakePtr = sake;
    return 0;
}
