/*
 * function: sakeStartup
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
 *   gsCoreIsShutdown  0x0217CE1C  arm  ov009
 *   gsimalloc  0x0217EAB0  arm  ov009
 *   MSL_C_LIB_MemsetPtr  0x020923B0  arm
 *   g_021ACEF8  0x021ACEF8  data
 */

typedef struct SAKEInternal {
    unsigned char data[0x4C];
} SAKEInternal;

extern int g_021ACEF8;
extern int gsCoreIsShutdown(void);
extern void *gsimalloc(unsigned long size);
extern void *MSL_C_LIB_MemsetPtr(void *dst, int val, unsigned long n);

int sakeStartup(SAKEInternal **sakePtr)
{
    SAKEInternal *sake;

    if (g_021ACEF8 != 1)
        return 1;
    if (gsCoreIsShutdown())
        return 2;
    sake = (SAKEInternal *)gsimalloc(sizeof(SAKEInternal));
    if (!sake)
        return 3;
    MSL_C_LIB_MemsetPtr(sake, 0, sizeof(SAKEInternal));
    *sakePtr = sake;
    return 0;
}
