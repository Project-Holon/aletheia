/*
 * function: func_021C4B9C
 * address:  0x021C4B9C
 * packet:   pkt_021C4B9C
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT*
 *
 * Region-qualified: ov111 has a different func_021C4B9C in its window.
 *
 * SDK provenance: SSP_ExifEncode, TwlSDK/libssp.TWL.HYB.a (exifenc.o), ov172.
 * Its callee tree (all libssp exifenc.o, now matched): SSP_SetJpegEncoderSoftware
 * (func_021C2D9C), SSP_SetJpegEncoderDateTime (func_021C2CDC),
 * SSP_SetJpegEncoderDateTimeNow (func_021C2D24) and jpeg_encode_main
 * (func_021C3DF4, still a documented DIFF near miss).
 *
 * JPEG encode driver.  Sets up the g_021CAE90 encoder config (0x1000/7 and a
 * 28-byte payload clamped to 30), zeroes the g_021CAEC6 string scratch, builds
 * a 4-byte id at `local` (0 unless OS_IsRunOnTwl() reports the firmware id, in
 * which case the hardware word at 0x02FFE230 is taken), copies it into the
 * local buf and NUL-terminates so func_021C2D9C can publish it as the string
 * length.  Then, if the global-outstanding flag g_021CADF0.f0 is clear, it
 * spins on func_021C2D24 (RTC string rebuild) with 5-tick sleeps until the
 * RTC is readable, and finally runs the Exif/JPEG encoder func_021C3DF4 with
 * encode_option = (a4 != 0) and thumb data a3/thumb_size a4; a non-1 result is
 * a fatal error (func_02088234).  The tail clears the g_021CADF0 state and
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
 *   func_021C3DF4  0x021C3DF4  arm  ov172
 *   func_021C2D24  0x021C2D24  arm  ov172
 *   func_021C2D9C  0x021C2D9C  arm  ov172
 *   OS_IsRunOnTwl  0x02085D3C  arm  arm9
 *   MI_CpuFill8  0x02082BCC  arm  arm9
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
void func_02082D44(void *src, void *dst, u32 n);
void func_02087A04(u32 x);
void func_02088234(void);
s16  func_021C3DF4(s16 width, s16 height, u16 encode_option,
                   u8 *thumb_src, u32 thumb_size);
void func_021C2D9C(const char *s);
int  func_021C2D24(void);

u32 func_021C4B9C(int a0, int a1, int a2, u8 *a3, u32 a4)
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
    func_02082D44(&local, buf, 4);
    buf[4] = 0;
    func_021C2D9C(buf);

    if (g_021CADF0.f0 == 0) {
        while (func_021C2D24() == 0)
            func_02087A04(5);
    }

    g_021CADF0.f4 = 0;
    if (a4 == 0) {
        if (func_021C3DF4((s16)a1, (s16)a2, 0, a3, a4) != 1)
            func_02088234();
    } else {
        if (func_021C3DF4((s16)a1, (s16)a2, 1, a3, a4) != 1)
            func_02088234();
    }

    g_021CADF0.f1c = 0;
    g_021CADF0.f18 = 0;
    g_021CADF0.f20 = 0;
    g_021CADF0.f10 = 0;
    g_021CADF0.f0 = 0;
    return g_021CADF0.f4;
}
