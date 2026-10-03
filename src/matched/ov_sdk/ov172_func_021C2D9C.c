/*
 * function: func_021C2D9C
 * address:  0x021C2D9C
 * packet:   pkt_021C2D9C
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * SDK provenance: SSP_SetJpegEncoderSoftware (TwlSDK/libssp.TWL.HYB.a,
 * exifenc.o), ov172.
 *
 * Region-qualified: ov172's ARM copy.  (ov217 has a Thumb func_021C2D9C at
 * the same window address; a different function.)
 *
 * Copies at most 0x1e bytes of the argument string into the g_021CAE28 buffer
 * and stores (returned count + 1) into g_021CADF0.fieldC (the length the Exif
 * writer later reads).
 *
 * symbols:
 *   g_021CAE28  0x021CAE28  data
 *   g_021CADF0  0x021CADF0  data
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern char g_021CAE28[];
extern u8   g_021CADF0[];

int func_0208CB10(char *destp, const char *srcp, int siz);

void func_021C2D9C(const char *s)
{
    *(u32 *)(g_021CADF0 + 0xc) = func_0208CB10(g_021CAE28, s, 0x1e) + 1;
}
