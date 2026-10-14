/*
 * function: SSP_ExifDecode
 * address:  0x021C0BB4
 * packet:   pkt_ov172_021C0BB4
 * region:   ov172
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SSP_ExifDecode (exifdec.o)
 *
 * symbols:
 *   GetAPP1  0x021C0440  arm  ov172
 *   g_021CAD9C     0x021CAD9C  data
 */

struct ExifState {
    unsigned short h0;
    unsigned short h2;
    unsigned short h4;
    char pad[0xc - 6];
    unsigned long f0c;
    unsigned long f10;
};

extern short GetAPP1(unsigned char *src, unsigned long src_size, unsigned long cur, long *soi_addr, int option);
extern struct ExifState g_021CAD9C;

long SSP_ExifDecode(unsigned char *src, unsigned long src_size, int *cur, int option)
{
    short result;
    unsigned long c = *cur;

    g_021CAD9C.f10 = 0;
    g_021CAD9C.h0 = 0;
    g_021CAD9C.f0c = 0;
    g_021CAD9C.h2 = 0;
    g_021CAD9C.h4 = 0;

    result = GetAPP1(src, src_size, c, (long *)cur, option);

    if (g_021CAD9C.f10 != 0)
        g_021CAD9C.f10 = g_021CAD9C.f10 + (unsigned long)(src + 12);
    if (g_021CAD9C.f0c != 0)
        g_021CAD9C.f0c = g_021CAD9C.f0c + (unsigned long)(src + 12);
    return result;
}
