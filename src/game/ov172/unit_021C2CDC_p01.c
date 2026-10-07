/*
 * file:     unit_021C2CDC_p01.c
 * unit:     yes
 * function: func_021C2CDC, func_021C2D0C, func_021C2D24, func_021C2D9C, func_021C2DC8
 * address:  0x021C2CDC
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_021CAE14  0x021CAE14  data  ov172
 *   g_021CADF0  0x021CADF0  data  ov172
 *   func_020889C0  0x020889C0  arm
 *   g_021C8874  0x021C8874  data
 *   g_021CAE28  0x021CAE28  data
 *   @12445  0x021C719C  data
 */
struct RTCDate;
struct RTCTime;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed int     s32;

struct DateTime {
    u32 hour;
    u32 min;
    u32 sec;
    u32 year;
    u32 month;
    u32 day;
    u32 field18;
};

struct exif_tag_entry {
    unsigned short tag;
    unsigned short type;
    unsigned long count;
};

void func_02082EA4(void *dst, const void *src, u32 n);
extern int func_020889C0(struct RTCDate *date, struct RTCTime *time);
void func_0208D7E0(char *dst, const char *fmt, ...);
int func_0208CB10(char *destp, const char *srcp, int siz);
void func_021C2CDC(u8 *buf);
int func_021C2D0C(void *a, void *b);
int func_021C2D24(void);
void func_021C2D9C(const char *s);
unsigned long func_021C2DC8(struct exif_tag_entry *entry);
extern u8 g_021CAE14[];
extern u8 g_021CADF0[];
extern const char g_021C8874[];
extern char g_021CAE28[];


/*
 * SDK provenance: SSP_SetJpegEncoderDateTime (TwlSDK/libssp.TWL.HYB.a,
 * exifenc.o), ov172.
 *
 * Small leaf: copies 0x13 bytes (reversed-copy helper func_02082EA4) from the
 * bss/string object g_021CAE14 into the caller's buffer, then raises the
 * g_021CADF0 flag at +0 and clears the byte at +0x37.
 *
 * Addresses are Black-image addresses.
 */
void func_021C2CDC(u8 *buf)
{
    func_02082EA4(buf, g_021CAE14, 0x13);
    g_021CADF0[0x37] = 0;
    *(u32 *)g_021CADF0 = 1;
}


/*
 * 1 when the ARM9 predicate is zero.
 *
 * Addresses are Black-image addresses.
 */
int func_021C2D0C(void *a, void *b)
{
    if (func_020889C0(a, b) == 0) {
        return 1;
    }
    return 0;
}


/*
 * SDK provenance: SSP_SetJpegEncoderDateTimeNow (TwlSDK/libssp.TWL.HYB.a,
 * exifenc.o), ov172.
 *
 * Builds the RTC date/time string.  func_021C2D0C(&d.year, &d) forwards its two
 * pointers to func_020889C0, which fills the DateTime struct d (memory order
 * hour,min,sec,year,month,day); the "year" field is stored as year-2000, so the
 * formatting call adds 2000 (0x7d0).  The rendered string in the local buffer is
 * then handed to func_021C2CDC, which copies it out to g_021CAE14.
 *
 * Addresses are Black-image addresses.
 */
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


void func_021C2D9C(const char *s)
{
    *(u32 *)(g_021CADF0 + 0xc) = func_0208CB10(g_021CAE28, s, 0x1e) + 1;
}


/*
 * sdk:      jpeg_exif_get_tag_size (exifenc.o)
 *
 * The type_size initializer copies from the vendor template @12445 at
 * 0x021C719C (template class, ov172 scope).
 */
unsigned long func_021C2DC8(struct exif_tag_entry *entry)
{
    signed char type_size[11] = {0, 1, 1, 2, 4, 8, 0, 1, 0, 4, 8};

    return type_size[entry->type] * entry->count;
}
