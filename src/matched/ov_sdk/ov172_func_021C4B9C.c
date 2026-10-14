/*
 * function: SSP_ExifEncode
 * address:  0x021C4B9C
 * packet:   pkt_021C4B9C
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT*
 *
 * Region-qualified: ov111 has a different SSP_ExifEncode in its window.
 *
 * SDK provenance: SSP_ExifEncode, TwlSDK/libssp.TWL.HYB.a (exifenc.o), ov172.
 * Its callee tree (all libssp exifenc.o, now matched): SSP_SetJpegEncoderSoftware
 * (SSP_SetJpegEncoderSoftware), SSP_SetJpegEncoderDateTime (SSP_SetJpegEncoderDateTime),
 * SSP_SetJpegEncoderDateTimeNow (SSP_SetJpegEncoderDateTimeNow) and jpeg_encode_main
 * (jpeg_encode_main, still a documented DIFF near miss).
 *
 * JPEG encode driver.  Sets up the g_021CAE90 encoder config (0x1000/7 and a
 * 28-byte payload clamped to 30), zeroes the g_021CAEC6 string scratch, builds
 * a 4-byte id at `local` (0 unless OS_IsRunOnTwl() reports the firmware id, in
 * which case the hardware word at 0x02FFE230 is taken), copies it into the
 * local buf and NUL-terminates so SSP_SetJpegEncoderSoftware can publish it as the string
 * length.  Then, if the global-outstanding flag g_021CADF0.f0 is clear, it
 * spins on SSP_SetJpegEncoderDateTimeNow (RTC string rebuild) with 5-tick sleeps until the
 * RTC is readable, and finally runs the Exif/JPEG encoder jpeg_encode_main with
 * encode_option = (a4 != 0) and thumb data a3/thumb_size a4; a non-1 result is
 * a fatal error (OS_Terminate).  The tail clears the g_021CADF0 state and
 * returns its +4 slot, which the encoder filled with the result.
 *
 * The opening block keeps g_021CAE90 in ip and g_021CADF0 in lr; storing
 * g_021CADF0.f14 before the config block is what reproduces that allocator
 * choice (see docs/idioms/two-live-pool-global-bases-swap-ip-and-lr.md).
 *
 * symbols:
 *   g_021CAE90  0x021CAE90  data
 *   g_021CADF0  0x021CADF0  data  ov172
 *   g_021CAEC6  0x021CAEC6  data  ov172
 *   jpeg_encode_main  0x021C3DF4  arm  ov172
 *   SSP_SetJpegEncoderDateTimeNow  0x021C2D24  arm  ov172
 *   SSP_SetJpegEncoderSoftware  0x021C2D9C  arm  ov172
 *   OS_IsRunOnTwl  0x02085D3C  arm  arm9
 *   MI_CpuFill8  0x02082BCC  arm  arm9
 *   MI_CpuCopy8  0x02082D44  arm  arm9
 *   OS_SpinWaitSysCycles  0x02087A04  arm  arm9
 *   OS_Terminate  0x02088234  arm  arm9
 *
 * Addresses are Black-image addresses.
 */

#include "../include/G_Ae90.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

struct Adf0 {
    u32 f0;
    u32 f4;
    u32 f8;
    u32 fc;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1c;
    u32 f20;
    u8  pad24[0x13];
    u8  f37;
};

extern struct Ae90 g_021CAE90;
extern struct Adf0 g_021CADF0;
extern u8  g_021CAEC6[];

void MI_CpuFill8(void *dst, int val, u32 n);
int  OS_IsRunOnTwl(void);
void MI_CpuCopy8(void *src, void *dst, u32 n);
void OS_SpinWaitSysCycles(u32 x);
void OS_Terminate(void);
s16  jpeg_encode_main(s16 width, s16 height, u16 encode_option,
                   u8 *thumb_src, u32 thumb_size);
void SSP_SetJpegEncoderSoftware(const char *s);
int  SSP_SetJpegEncoderDateTimeNow(void);

u32 SSP_ExifEncode(int a0, int a1, int a2, u8 *a3, u32 a4)
{
    char buf[0x20];
    u32 local;

    g_021CADF0.f14 = a0;
    g_021CAE90.tag = 0x1000;
    g_021CAE90.type = 7;
    g_021CAE90.count = 0x1C;
    if (g_021CAE90.count > 0x1E)
        g_021CAE90.count = 0x1E;
    g_021CAE90.f8 = 0;
    g_021CAE90.fa = 0;
    g_021CAE90.fc = 0;
    g_021CAE90.f10 = 0;
    g_021CAE90.f14 = 0;
    MI_CpuFill8(g_021CAEC6, 0, g_021CAE90.count);

    local = 0;
    if (OS_IsRunOnTwl() == 1)
        local = *(u32 *)0x02FFE230;
    MI_CpuCopy8(&local, buf, 4);
    buf[4] = 0;
    SSP_SetJpegEncoderSoftware(buf);

    if (g_021CADF0.f0 == 0) {
        while (SSP_SetJpegEncoderDateTimeNow() == 0)
            OS_SpinWaitSysCycles(5);
    }

    g_021CADF0.f4 = 0;
    if (a4 == 0) {
        if (jpeg_encode_main((s16)a1, (s16)a2, 0, a3, a4) != 1)
            OS_Terminate();
    } else {
        if (jpeg_encode_main((s16)a1, (s16)a2, 1, a3, a4) != 1)
            OS_Terminate();
    }

    g_021CADF0.f1c = 0;
    g_021CADF0.f18 = 0;
    g_021CADF0.f20 = 0;
    g_021CADF0.f10 = 0;
    g_021CADF0.f0 = 0;
    return g_021CADF0.f4;
}
