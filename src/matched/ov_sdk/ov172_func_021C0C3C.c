/*
 * function: func_021C0C3C
 * address:  0x021C0C3C
 * packet:   pkt_ov172_021C0C3C
 * region:   ov172
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      Yos_BitWrite (jpegenc.o)
 *
 * note: gBitLen/gBitCode/gWriteLimit are three adjacent file statics in
 * ov172's bss (zero-initialised; offsets 0/4/8 from 0x021CADE4).  The
 * relocation against `.bss` is placed by the three symbols: lines, which keep
 * the compiled layout (gBitCode is declared first so the compiler lays len
 * out at +0).
 *
 * symbols:
 *   gBitLen      0x021CADE4  data
 *   gBitCode     0x021CADE8  data
 *   gWriteLimit  0x021CADEC  data
 *   g_021C7150   0x021C7150  data
 */

static unsigned long gBitCode = 0;
static unsigned long gBitLen = 0;
static unsigned long gWriteLimit = 0;
extern unsigned long g_021C7150[];

int func_021C0C3C(unsigned char *dst, unsigned long *ptr, unsigned long num, unsigned long size)
{
    unsigned long i;

    for (i = size; i != 0; i--) {
        if (num & g_021C7150[i])
            gBitCode |= g_021C7150[gBitLen];
        gBitLen--;
        if (gBitLen == 0) {
            dst[*ptr] = gBitCode;
            if (gBitCode == 0xff) {
                if (*ptr + 2 >= gWriteLimit)
                    return 0;
                dst[*ptr + 1] = 0;
                *ptr += 2;
            } else {
                *ptr += 1;
                if (*ptr >= gWriteLimit)
                    return 0;
            }
            gBitCode = 0;
            gBitLen = 8;
        }
    }
    return 1;
}
