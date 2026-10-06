/*
 * function: func_021C2D24
 * address:  0x021C2D24
 * packet:   pkt_021C2D24
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * SDK provenance: SSP_SetJpegEncoderDateTimeNow (TwlSDK/libssp.TWL.HYB.a,
 * exifenc.o), ov172.
 *
 * Builds the RTC date/time string.  func_021C2D0C(&d.year, &d) forwards its two
 * pointers to func_020889C0, which fills the DateTime struct d (memory order
 * hour,min,sec,year,month,day); the "year" field is stored as year-2000, so the
 * formatting call adds 2000 (0x7d0).  The rendered string in the local buffer is
 * then handed to func_021C2CDC, which copies it out to g_021CAE14.
 *
 * symbols:
 *   g_021C8874  0x021C8874  data
 *   func_021C2D0C  0x021C2D0C  arm  ov172
 *   func_021C2CDC  0x021C2CDC  arm  ov172
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct DateTime {
    u32 hour;
    u32 min;
    u32 sec;
    u32 year;
    u32 month;
    u32 day;
    u32 field18;
};

extern const char g_021C8874[];

int func_021C2D0C(void *a, void *b);
void func_0208D7E0(char *dst, const char *fmt, ...);
void func_021C2CDC(u8 *buf);

int func_021C2D24(void)
{
    struct DateTime d;
    char buf[0x14];

    if (func_021C2D0C(&d.year, &d) != 1)
        return 0;

    func_0208D7E0(buf, g_021C8874,
                  d.year + 0x7d0, d.month, d.day,
                  d.hour, d.min, d.sec);
    func_021C2CDC((u8 *)buf);
    return 1;
}
