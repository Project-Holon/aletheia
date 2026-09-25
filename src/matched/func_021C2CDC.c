/*
 * function: func_021C2CDC
 * address:  0x021C2CDC
 * packet:   pkt_021C2CDC
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * SDK provenance: SSP_SetJpegEncoderDateTime (TwlSDK/libssp.TWL.HYB.a,
 * exifenc.o), ov172.
 *
 * Small leaf: copies 0x13 bytes (reversed-copy helper func_02082EA4) from the
 * bss/string object g_021CAE14 into the caller's buffer, then raises the
 * g_021CADF0 flag at +0 and clears the byte at +0x37.
 *
 * symbols:
 *   g_021CAE14  0x021CAE14  data  ov172
 *   g_021CADF0  0x021CADF0  data  ov172
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u8 g_021CAE14[];
extern u8 g_021CADF0[];

void func_02082EA4(void *dst, const void *src, u32 n);

void func_021C2CDC(u8 *buf)
{
    func_02082EA4(buf, g_021CAE14, 0x13);
    g_021CADF0[0x37] = 0;
    *(u32 *)g_021CADF0 = 1;
}
