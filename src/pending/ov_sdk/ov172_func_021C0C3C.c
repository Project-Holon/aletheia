/*
 * function: func_021C0C3C
 * address:  0x021C0C3C
 * packet:   pkt_ov172_021C0C3C
 * region:   ov172
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * sdk:      Yos_BitWrite (jpegenc.o)
 *
 * note: near miss. gBitLen/gBitCode/gWriteLimit are three adjacent file statics
 * (offsets 0/4/8 of the pool word at 0x021CADE4); the draft models them as
 * static scalars, which reproduces the loop promotion, but the ABS32 then
 * targets .data and cannot be attested, and 4 bytes are added.
 *
 * symbols:
 *   g_021C7150  0x021C7150  data
 */

static unsigned long g_021CADE4 = 1;
static unsigned long g_021CADE8 = 1;
static unsigned long g_021CADEC = 1;
extern unsigned long g_021C7150[];

int func_021C0C3C(unsigned char *dst, unsigned long *ptr, unsigned long num, unsigned long size)
{
    unsigned long i;

    for (i = size; i != 0; i--) {
        if (num & g_021C7150[i])
            g_021CADE8 |= g_021C7150[g_021CADE4];
        g_021CADE4--;
        if (g_021CADE4 == 0) {
            dst[*ptr] = g_021CADE8;
            if (g_021CADE8 == 0xff) {
                if (*ptr + 2 >= g_021CADEC)
                    return 0;
                dst[*ptr + 1] = 0;
                *ptr += 2;
            } else {
                *ptr += 1;
                if (*ptr >= g_021CADEC)
                    return 0;
            }
            g_021CADE4 = 8;
            g_021CADE8 = 0;
        }
    }
    return 1;
}
