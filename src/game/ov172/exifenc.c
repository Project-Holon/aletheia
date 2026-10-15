/*
 * file:     exifenc.c
 * unit:     yes
 * function: SSP_SetJpegEncoderDateTime, SSP_GetDateTime, SSP_SetJpegEncoderDateTimeNow, SSP_SetJpegEncoderSoftware, jpeg_exif_get_tag_size, jpeg_exif_set_tag_value, jpeg_encode_ifd_direct, jpeg_encode_ifd, jpeg_encode_exif, jpeg_encode_main, SSP_ExifEncode
 * address:  0x021C2CDC
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT*
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * Region-qualified: ov111 has a different SSP_ExifEncode in its window.
 * SDK provenance: SSP_ExifEncode, TwlSDK/libssp.TWL.HYB.a (exifenc.o), ov172.
 * Its callee tree (all libssp exifenc.o, now matched): SSP_SetJpegEncoderSoftware
 * (SSP_SetJpegEncoderSoftware), SSP_SetJpegEncoderDateTime (SSP_SetJpegEncoderDateTime),
 * SSP_SetJpegEncoderDateTimeNow (SSP_SetJpegEncoderDateTimeNow) and jpeg_encode_main
 * (jpeg_encode_main, still a documented DIFF near miss).
 * JPEG encode driver.  Sets up the gExifMakerNoteConfig encoder config (0x1000/7 and a
 * 28-byte payload clamped to 30), zeroes the gExifMakerNoteConfigData string scratch, builds
 * a 4-byte id at `local` (0 unless OS_IsRunOnTwl() reports the firmware id, in
 * which case the hardware word at 0x02FFE230 is taken), copies it into the
 * local buf and NUL-terminates so SSP_SetJpegEncoderSoftware can publish it as the string
 * length.  Then, if the global-outstanding flag g_021CADF0.f0 is clear, it
 * spins on SSP_SetJpegEncoderDateTimeNow (RTC string rebuild) with 5-tick sleeps until the
 * RTC is readable, and finally runs the Exif/JPEG encoder jpeg_encode_main with
 * encode_option = (a4 != 0) and thumb data a3/thumb_size a4; a non-1 result is
 * a fatal error (OS_Terminate).  The tail clears the g_021CADF0 state and
 * returns its +4 slot, which the encoder filled with the result.
 * The opening block keeps gExifMakerNoteConfig in ip and g_021CADF0 in lr; storing
 * g_021CADF0.f14 before the config block is what reproduces that allocator
 * choice (see docs/idioms/two-live-pool-global-bases-swap-ip-and-lr.md).
 * Addresses are Black-image addresses.
 *
 * symbols:
 *   dateTimeData  0x021CAE14  data  ov172
 *   dateTimeDataFlag  0x021CADF0  data  ov172
 *   RTC_GetDateTime  0x020889C0  arm
 *   gExifDateTimeFormat  0x021C8874  data
 *   SSPiSoftware  0x021CAE28  data
 *   STD_GetStringLength  0x0208CC78  arm
 *   MI_CpuCopy           0x02082EA4  arm
 *   gExifIfdSlotManager 0x021CAE48 data ov172
 *   gExifIfd0Slots 0x021CB728 data
 *   gExifExifIfdSlots 0x021CC070 data ov172
 *   gExifMakerNoteSlots 0x021CAEE8 data ov172
 *   gExifInteropIfdSlots 0x021CB308 data ov172
 *   gExifIfd1Slots 0x021CBBA0 data ov172
 *   gExifMake 0x021C8894 data ov172
 *   gExifModel 0x021C88A0 data ov172
 *   encode_file_size 0x021CADF4 data ov172
 *   SSPiEncodeSignCheckMode 0x021CADF8 data ov172
 *   SSPiSoftwareSize 0x021CADFC data ov172
 *   SSPiMakerNoteUserBufferSize 0x021CAE00 data ov172
 *   dst 0x021CAE04 data ov172
 *   SSPiMakerNoteBufferSize 0x021CAE08 data ov172
 *   SSPiMakerNoteBuffer 0x021CAE0C data ov172
 *   SSPiMakerNoteUserBuffer 0x021CAE10 data ov172
 *   gExifVersion 0x021C88AC data ov172
 *   gExifFlashpixVersion 0x021C88B4 data ov172
 *   gExifMakerNoteConfig 0x021CAE90 data
 *   gExifMakerNoteConfigData 0x021CAEC6 data ov172
 *   gExifInteropIndex 0x021C88BC data ov172
 *   gExifRelatedImageFormat 0x021C88C0 data ov172
 *   write_exif_ifd_tables 0x021C3A28 arm ov172
 *   STD_CopyLString  0x0208CB10  arm  arm9
 *   @12445  0x021C719C  data
 *   @12604         0x021C7194  data
 *   g_021CADF0  0x021CADF0  data  ov172
 *   OS_IsRunOnTwl  0x02085D3C  arm  arm9
 *   MI_CpuFill8  0x02082BCC  arm  arm9
 *   MI_CpuCopy8  0x02082D44  arm  arm9
 *   OS_SpinWaitSysCycles  0x02087A04  arm  arm9
 *   OS_Terminate  0x02088234  arm  arm9
 */
#include "../../matched/include/G_Ae90.h"

#define PUT(v)  (dst[encode_file_size++] = (unsigned char)(v))
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

typedef struct exif_tag_entry {
    unsigned short tag;
    unsigned short type;
    unsigned long count;
    signed char byte_data;
    unsigned char padding[1];
    short short_data;
    long long_data;
    long rational_data[2];
    signed char undefined_data[30];
    signed char ascii_data[30];
    unsigned long offset;
} exif_tag_entry;

typedef struct exif_ifd_data {
    exif_tag_entry *entries;
    short count;
    unsigned char padding[2];
    long next_ifd_pointer;
} exif_ifd_data;

typedef struct jpeg_exif_data_structure {
    exif_ifd_data ifd[5];
    unsigned long app1_length;
    unsigned long thumb_compressed_data;
    long thumb_compressed_length;
} jpeg_exif_data_structure;

typedef signed char s8;

typedef signed short s16;

struct Slot
{
  u16 tag;
  u16 type;
  u32 count;
  s8 field8;
  u8 pad9;
  s16 fieldA;
  u32 fieldC;
  u32 field10;
  u32 field14;
  u8 field18[30];
  char str[30];
  u32 field54;
};

struct SlotManager
{
  struct Slot *ptr0;
  s16 count0;
  u16 pad6;
  u32 field8;
  struct Slot *ptrC;
  s16 count1;
  u16 pad12;
  u32 field14;
  struct Slot *ptr18;
  s16 count2;
  u16 pad1E;
  u32 field20;
  struct Slot *ptr24;
  s16 count3;
  u16 pad2A;
  u32 field2C;
  struct Slot *ptr30;
  s16 count4;
  u16 pad36;
  u32 field38;
  u32 pad3C[2];
  u32 field44;
};

struct UnkObj
{
  u32 field0;
  u32 len;
  u32 field8;
  u32 fieldC;
  u32 field10;
  u8 *buffer;
  u32 field18;
};

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

void func_02082EA4(const void *src, void *dst, u32 n);
extern int RTC_GetDateTime(struct RTCDate *date, struct RTCTime *time);
void func_0208D7E0(char *dst, const char *fmt, ...);
int STD_CopyLString(char *destp, const char *srcp, int siz);
extern int STD_GetStringLength(char *str);
extern void MI_CpuCopy(void *srcp, void *destp, unsigned long size);
extern void MI_CpuCopy8(const void *src, void *dst, u32 n);
extern u32 write_exif_ifd_tables(struct SlotManager *mgr, u32 mode, u8 *thumb_src, u32 thumb_size);
void MI_CpuFill8(void *dst, int val, u32 n);
int  OS_IsRunOnTwl(void);
void OS_SpinWaitSysCycles(u32 x);
void OS_Terminate(void);
void SSP_SetJpegEncoderDateTime(u8 *buf);
int SSP_GetDateTime(void *a, void *b);
int SSP_SetJpegEncoderDateTimeNow(void);
void SSP_SetJpegEncoderSoftware(const char *s);
unsigned long jpeg_exif_get_tag_size(struct exif_tag_entry *entry);
void jpeg_exif_set_tag_value(exif_tag_entry *entry);
void jpeg_encode_ifd_direct(void *unused, exif_ifd_data *ifd, short is_last);
void jpeg_encode_ifd(jpeg_exif_data_structure *jexif, exif_ifd_data *ifd, short is_last);
short jpeg_encode_exif(jpeg_exif_data_structure *jexif, short option, unsigned char *thumb_src, unsigned long thumb_size);
s16 jpeg_encode_main(s16 width, s16 height, u16 encode_option, u8 *thumb_src, u32 thumb_size);
u32 SSP_ExifEncode(int a0, int a1, int a2, u8 *a3, u32 a4);
extern const char gExifDateTimeFormat[];
extern struct SlotManager gExifIfdSlotManager;
extern struct Slot gExifIfd0Slots[];
extern struct Slot gExifExifIfdSlots[];
extern struct Slot gExifMakerNoteSlots[];
extern struct Slot gExifInteropIfdSlots[];
extern struct Slot gExifIfd1Slots[];
extern const char gExifMake[];
extern const char gExifModel[];
extern const char gExifVersion[];
extern const char gExifFlashpixVersion[];
extern struct Ae90 gExifMakerNoteConfig;
extern char gExifMakerNoteConfigData[];
extern const char gExifInteropIndex[];
extern const char gExifRelatedImageFormat[];
extern struct Adf0 g_021CADF0;

static int dateTimeDataFlag = 0;

static u8 *SSPiMakerNoteUserBuffer = 0;

static u8 *SSPiMakerNoteBuffer = 0;

static u32 SSPiMakerNoteBufferSize = 0;

static u8 *dst = 0;

static u32 SSPiMakerNoteUserBufferSize = 0;

static u32 SSPiSoftwareSize = 0;

int SSPiEncodeSignCheckMode = 0;

static u32 encode_file_size = 0;

static char dateTimeData[20] = {0};

static char SSPiSoftware[30] = {0};






/*
 * SDK provenance: SSP_SetJpegEncoderDateTime (TwlSDK/libssp.TWL.HYB.a,
 * exifenc.o), ov172.
 *
 * Small leaf: copies 0x13 bytes (reversed-copy helper func_02082EA4) from the
 * bss/string object dateTimeData into the caller's buffer, then raises the
 * dateTimeDataFlag at +0 and clears the byte at +0x37.
 *
 * Addresses are Black-image addresses.
 */
void SSP_SetJpegEncoderDateTime(u8 *buf)
{
    func_02082EA4(buf, dateTimeData, 0x13);
    dateTimeData[19] = 0;
    dateTimeDataFlag = 1;
}






/*
 * 1 when the ARM9 predicate is zero.
 *
 * Addresses are Black-image addresses.
 */
int SSP_GetDateTime(void *a, void *b)
{
    if (RTC_GetDateTime(a, b) == 0) {
        return 1;
    }
    return 0;
}






/*
 * SDK provenance: SSP_SetJpegEncoderDateTimeNow (TwlSDK/libssp.TWL.HYB.a,
 * exifenc.o), ov172.
 *
 * Builds the RTC date/time string.  SSP_GetDateTime(&d.year, &d) forwards its two
 * pointers to RTC_GetDateTime, which fills the DateTime struct d (memory order
 * hour,min,sec,year,month,day); the "year" field is stored as year-2000, so the
 * formatting call adds 2000 (0x7d0).  The rendered string in the local buffer is
 * then handed to SSP_SetJpegEncoderDateTime, which copies it out to dateTimeData.
 *
 * Addresses are Black-image addresses.
 */
int SSP_SetJpegEncoderDateTimeNow(void)
{
    struct DateTime d;
    char buf[0x14];

    if (SSP_GetDateTime(&d.year, &d) != 1)
        return 0;

    func_0208D7E0(buf, gExifDateTimeFormat,
                  d.year + 0x7d0, d.month, d.day,
                  d.hour, d.min, d.sec);
    SSP_SetJpegEncoderDateTime((u8 *)buf);
    return 1;
}






void SSP_SetJpegEncoderSoftware(const char *s)
{
    SSPiSoftwareSize = STD_CopyLString(SSPiSoftware, s, 0x1e) + 1;
}






/*
 * sdk:      jpeg_exif_get_tag_size (exifenc.o)
 *
 * The type_size initializer copies from the vendor template @12445 at
 * 0x021C719C (template class, ov172 scope).
 */
unsigned long jpeg_exif_get_tag_size(struct exif_tag_entry *entry)
{
    signed char type_size[11] = {0, 1, 1, 2, 4, 8, 0, 1, 0, 4, 8};

    return type_size[entry->type] * entry->count;
}







void jpeg_exif_set_tag_value(exif_tag_entry *entry)
{
    switch (entry->type) {
    case 0:
        break;
    case 1:
        PUT(entry->byte_data);
        PUT(0);
        PUT(0);
        PUT(0);
        break;
    case 3:
        PUT((entry->short_data & 0xff00) >> 8);
        PUT(entry->short_data);
        PUT(0);
        PUT(0);
        break;
    case 4:
    case 9:
        PUT((entry->long_data & 0xff000000) >> 24);
        PUT((entry->long_data & 0xff0000) >> 16);
        PUT((entry->long_data & 0xff00) >> 8);
        PUT(entry->long_data);
        break;
    case 5:
    case 10:
        PUT((entry->rational_data[0] & 0xff000000) >> 24);
        PUT((entry->rational_data[0] & 0xff0000) >> 16);
        PUT((entry->rational_data[0] & 0xff00) >> 8);
        PUT(entry->rational_data[0]);
        PUT((entry->rational_data[1] & 0xff000000) >> 24);
        PUT((entry->rational_data[1] & 0xff0000) >> 16);
        PUT((entry->rational_data[1] & 0xff00) >> 8);
        PUT(entry->rational_data[1]);
        break;
    case 7: {
        u32 size = jpeg_exif_get_tag_size(entry);
        u32 i;

        for (i = 0; i < size; i++)
            PUT(entry->undefined_data[i]);
        for (; i < 4; i++)
            PUT(0);
        break;
    }
    case 2: {
        u32 size = jpeg_exif_get_tag_size(entry);
        u32 i;

        for (i = 0; i < size; i++)
            PUT(entry->ascii_data[i]);
        for (; i < 4; i++)
            PUT(0);
        break;
    }
    case 6:
        break;
    case 8:
        break;
    }
}







void jpeg_encode_ifd_direct(void *unused, exif_ifd_data *ifd, short is_last)
{
    exif_tag_entry *entry;
    unsigned long size;
    signed char i;
    unsigned long j;
    long next_ifd_pointer;

    PUT((ifd->count & 0xff00) >> 8);
    PUT(ifd->count);

    next_ifd_pointer = ifd->next_ifd_pointer;
    entry = ifd->entries;
    for (i = 0; i < ifd->count; entry++, i++) {
        PUT((entry->tag & 0xff00) >> 8);
        PUT(entry->tag);
        PUT((entry->type & 0xff00) >> 8);
        PUT(entry->type);
        PUT((entry->count & 0xff000000) >> 24);
        PUT((entry->count & 0xff0000) >> 16);
        PUT((entry->count & 0xff00) >> 8);
        PUT(entry->count);

        size = jpeg_exif_get_tag_size(entry);
        if (size <= 4) {
            if (size == 2) {
                PUT(0);
                PUT(0);
            }
            if (entry->tag == 0x1001) {
                for (i = 0; i < SSPiMakerNoteBufferSize; i++)
                    PUT(SSPiMakerNoteBuffer[i]);
            } else if (entry->tag == 0x1002) {
                for (i = 0; i < SSPiMakerNoteUserBufferSize; i++)
                    PUT(SSPiMakerNoteUserBuffer[i]);
            }
        } else {
            PUT((entry->offset & 0xff000000) >> 24);
            PUT((entry->offset & 0xff0000) >> 16);
            PUT((entry->offset & 0xff00) >> 8);
            PUT(entry->offset);
        }
    }

    if (!is_last) {
        PUT((long)(next_ifd_pointer & 0xff000000) >> 24);
        PUT((short)(next_ifd_pointer & 0xff0000) >> 16);
        PUT((short)(next_ifd_pointer & 0xff00) >> 8);
        PUT(next_ifd_pointer);
    } else {
        PUT(0);
        PUT(0);
        PUT(0);
        PUT(0);
    }

    entry = ifd->entries;
    for (i = 0; i < ifd->count; entry++, i++) {
        size = jpeg_exif_get_tag_size(entry);
        if (size > 4) {
            if (entry->tag == 0x1000) {
                jpeg_exif_set_tag_value(entry);
                if (size & 1)
                    PUT(0);
            } else if (entry->tag == 0x1001) {
                for (j = 0; j < SSPiMakerNoteBufferSize; j++)
                    PUT(SSPiMakerNoteBuffer[j]);
            } else if (entry->tag == 0x1002) {
                for (j = 0; j < SSPiMakerNoteUserBufferSize; j++)
                    PUT(SSPiMakerNoteUserBuffer[j]);
            }
        }
    }
}






/*
 * sdk:      jpeg_encode_ifd (libssp.TWL.HYB.a exifenc.o)
 *
 * exifenc.o's file statics sit in one block based at dateTimeDataFlag
 * (0x021CADF0); every use goes through that one pool word, so the block
 * is written as a struct overlay named by offset (+0x04 write position,
 * +0x14 output buffer).
 *
 * The app1 length adjust needs an unsigned last operand (6u, as a sizeof
 * would give): with plain `- 2 - 6` the compiler folds the two subtracts.
 */
void jpeg_encode_ifd(jpeg_exif_data_structure *jexif, exif_ifd_data *ifd, short is_last)
{
    exif_tag_entry *entry;
    unsigned long size;
    signed char i;
    long next_ifd_pointer;

    PUT((ifd->count & 0xff00) >> 8);
    PUT(ifd->count);

    next_ifd_pointer = ifd->next_ifd_pointer;
    entry = ifd->entries;
    for (i = 0; i < ifd->count; entry++, i++) {
        switch (entry->tag) {
        case 0x201:
            entry->long_data = jexif->app1_length;
            entry->long_data = entry->long_data - jexif->thumb_compressed_length - 2 - 6u;
            break;
        case 0x202:
            entry->long_data = jexif->thumb_compressed_length;
            break;
        case 0x8769:
            entry->long_data = jexif->ifd[0].next_ifd_pointer;
            next_ifd_pointer = jexif->ifd[3].next_ifd_pointer;
            break;
        case 0x927c:
            entry->offset = jexif->ifd[1].next_ifd_pointer;
            next_ifd_pointer = jexif->ifd[3].next_ifd_pointer;
            break;
        case 0xa005:
            entry->long_data = jexif->ifd[2].next_ifd_pointer;
            next_ifd_pointer = jexif->ifd[3].next_ifd_pointer;
            break;
        }

        PUT((entry->tag & 0xff00) >> 8);
        PUT(entry->tag);
        PUT((entry->type & 0xff00) >> 8);
        PUT(entry->type);
        PUT((entry->count & 0xff000000) >> 24);
        PUT((entry->count & 0xff0000) >> 16);
        PUT((entry->count & 0xff00) >> 8);
        PUT(entry->count);

        if (jpeg_exif_get_tag_size(entry) <= 4) {
            jpeg_exif_set_tag_value(entry);
        } else {
            PUT((entry->offset & 0xff000000) >> 24);
            PUT((entry->offset & 0xff0000) >> 16);
            PUT((entry->offset & 0xff00) >> 8);
            PUT(entry->offset);
        }
    }

    if (!is_last) {
        PUT((next_ifd_pointer & 0xff000000) >> 24);
        PUT((next_ifd_pointer & 0xff0000) >> 16);
        PUT((next_ifd_pointer & 0xff00) >> 8);
        PUT(next_ifd_pointer);
    } else {
        PUT(0);
        PUT(0);
        PUT(0);
        PUT(0);
    }

    entry = ifd->entries;
    for (i = 0; i < ifd->count; entry++, i++) {
        size = jpeg_exif_get_tag_size(entry);
        if (size > 4 && entry->tag != 0x927c) {
            jpeg_exif_set_tag_value(entry);
            if (size & 1)
                PUT(0);
        }
    }
}




/*
 * sdk:      jpeg_encode_exif (libssp.TWL.HYB.a exifenc.o)
 *
 * The APP1 16-bit length high byte is written as
 * `(short)(app1_length & 0xff00) >> 8`: the (short) cast after the mask is
 * what makes mwcc emit the unwidened `and #0xff00; lsl #16; asr #24` triple
 * rather than a single `lsr #8`.
 */
short jpeg_encode_exif(jpeg_exif_data_structure *jexif, short option,
                    unsigned char *thumb_src, unsigned long thumb_size)
{
    char exif_header[5] = "Exif";
    unsigned long compressed_size;
    unsigned long size;
    exif_ifd_data *ifd;
    exif_tag_entry *entry;
    int i;
    int j;

    PUT(0xff);
    PUT(0xe1);
    jexif->app1_length = 2;
    jexif->app1_length += 6;
    jexif->app1_length += 8;

    for (i = 0; i < 5; i++) {
        ifd = &jexif->ifd[i];
        if (ifd->count <= 0 || ifd->entries == 0)
            continue;

        if (option == 0 || i != 4) {
            jexif->app1_length += 2;
            jexif->app1_length += 4;
            jexif->app1_length += ifd->count * 12;
        }

        for (j = 0, entry = ifd->entries; j < ifd->count; j++, entry++) {
            entry->offset = 0;
            size = jpeg_exif_get_tag_size(entry);
            if (size > 4 && entry->tag != 0x927c) {
                entry->offset = jexif->app1_length - 8;
                if (size & 1)
                    size++;
                if (option == 0 || i != 4)
                    jexif->app1_length += size;
            }
        }
        ifd->next_ifd_pointer = jexif->app1_length - 8;
    }

    if (option == 0) {
        if (jexif->thumb_compressed_length & 1)
            jexif->thumb_compressed_length++;
        jexif->app1_length += jexif->thumb_compressed_length;
        if (jexif->app1_length >= 0x10000)
            return 0;
    }

    PUT((short)(jexif->app1_length & 0xff00) >> 8);
    PUT(jexif->app1_length);
    for (j = 0; j < STD_GetStringLength(exif_header); j++)
        PUT(exif_header[j]);
    PUT(0);
    PUT(0);
    PUT(0x4d);
    PUT(0x4d);
    PUT(0);
    PUT(0x2a);
    PUT(0);
    PUT(0);
    PUT(0);
    PUT(8);

    jpeg_encode_ifd(jexif, &jexif->ifd[0], option);
    if (jexif->ifd[1].count > 0)
        jpeg_encode_ifd(jexif, &jexif->ifd[1], 1);
    if (jexif->ifd[2].count > 0)
        jpeg_encode_ifd_direct(jexif, &jexif->ifd[2], 1);
    if (jexif->ifd[3].count > 0)
        jpeg_encode_ifd(jexif, &jexif->ifd[3], 1);

    if (option == 0) {
        jpeg_encode_ifd(jexif, &jexif->ifd[4], 1);
        MI_CpuCopy(thumb_src, dst + encode_file_size, thumb_size);
        encode_file_size += thumb_size;
    }
    return 1;
}



/*
 * sdk:      jpeg_encode_main (libssp.TWL.HYB.a(exifenc.o))
 *
 * notes: EXACT 2026-10-01 (lane29), was 22 B. The old `g_021CADF0` struct is
 *   the object's separate .bss statics anchored at dateTimeDataFlag
 *   (encode_file_size +4, SSPiEncodeSignCheckMode +8 (global),
 *   SSPiSoftwareSize +0xc, SSPiMakerNoteUserBufferSize +0x10, dst +0x14,
 *   SSPiMakerNoteBufferSize +0x18, SSPiMakerNoteBuffer +0x1c,
 *   SSPiMakerNoteUserBuffer +0x20, dateTimeData +0x24, SSPiSoftware +0x38).
 *   Defining them as file statics fixed the count0++ / SSPiSoftwareSize test
 *   order at +0x204. 1.1p1 .bss layout for the 4-byte group: the first
 *   declared stays at offset 0, the rest are laid out in reverse declaration
 *   order; arrays follow in declaration order. Locals are still the old
 *   stand-ins (DWARF: jexif, cfg_encode_exif, 28 block-scoped `entry`).
 */
s16 jpeg_encode_main(s16 width, s16 height, u16 encode_option, u8 *thumb_src, u32 thumb_size)
{
  s16 cfg_encode_exif;
  s16 cfg_encode_gray_scale;
  s16 cfg_input_width;
  s16 cfg_input_height;
  struct SlotManager *sb = &gExifIfdSlotManager;
  struct Slot *s;
  s16 cfg_encode_exif_;
  sb->ptr0 = gExifIfd0Slots;
  sb->count0 = 0;
  sb->field8 = 0;
  sb->ptrC = gExifExifIfdSlots;
  sb->count1 = 0;
  sb->field14 = 0;
  sb->ptr18 = gExifMakerNoteSlots;
  sb->count2 = 0;
  sb->field20 = 0;
  sb->ptr24 = gExifInteropIfdSlots;
  sb->count3 = 0;
  sb->field2C = 0;
  sb->ptr30 = gExifIfd1Slots;
  sb->count4 = 0;
  sb->field38 = 0;
  if (encode_option & 1)
  {
    cfg_encode_exif = 1;
  }
  else
  {
    cfg_encode_exif = 0;
  }
  cfg_encode_gray_scale = 0;
  cfg_input_width = width;
  cfg_input_height = height;
  sb->count0 = 0;
  s = &sb->ptr0[sb->count0];
  s->tag = 0x010F;
  s->type = 2;
  s->count = 9;
  s->field8 = 0;
  s->fieldA = 0;
  s->fieldC = 0;
  s->field10 = 0;
  s->field14 = 0;
  STD_CopyLString(s->str, gExifMake, 9);
  s->field54 = 0;
  sb->count0++;
  s = &sb->ptr0[sb->count0];
  s->tag = 0x0110;
  s->type = 2;
  s->count = 11;
  s->field8 = 0;
  s->fieldA = 0;
  s->fieldC = 0;
  s->field10 = 0;
  s->field14 = 0;
  STD_CopyLString(s->str, gExifModel, 11);
  s->field54 = 0;
  sb->count0++;
  s = &sb->ptr0[sb->count0];
  s->tag = 0x011A;
  s->type = 5;
  s->count = 1;
  s->field8 = 0;
  s->fieldA = 0;
  s->fieldC = 0;
  s->field10 = 72;
  s->field14 = 1;
  s->field54 = 0;
  sb->count0++;
  s = &sb->ptr0[sb->count0];
  s->tag = 0x011B;
  s->type = 5;
  s->count = 1;
  s->field8 = 0;
  s->fieldA = 0;
  s->fieldC = 0;
  s->field10 = 72;
  s->field14 = 1;
  s->field54 = 0;
  sb->count0++;
  s = &sb->ptr0[sb->count0];
  s->tag = 0x0128;
  s->type = 3;
  s->count = 1;
  s->field8 = 0;
  s->fieldA = 2;
  s->fieldC = 0;
  s->field10 = 0;
  s->field14 = 0;
  s->field54 = 0;
  sb->count0++;
  if (SSPiSoftwareSize != 0)
  {
    s = &sb->ptr0[sb->count0];
    s->tag = 0x0131;
    s->type = 2;
    s->count = SSPiSoftwareSize;
    s->field8 = 0;
    s->fieldA = 0;
    s->fieldC = 0;
    s->field10 = 0;
    s->field14 = 0;
    STD_CopyLString(s->str, SSPiSoftware, s->count);
    s->field54 = 0;
    sb->count0++;
  }
  s = &sb->ptr0[sb->count0];
  s->tag = 0x0132;
  s->type = 2;
  s->count = 20;
  s->field8 = 0;
  s->fieldA = 0;
  s->fieldC = 0;
  s->field10 = 0;
  s->field14 = 0;
  STD_CopyLString(s->str, dateTimeData, 20);
  s->field54 = 0;
  sb->count0++;
  s = &sb->ptr0[sb->count0];
  s->tag = 0x0213;
  s->type = 3;
  s->count = 1;
  s->field8 = 0;
  s->fieldA = 2;
  s->fieldC = 0;
  s->field10 = 0;
  s->field14 = 0;
  s->field54 = 0;
  sb->count0++;
  sb->count1 = 0;
  s = &sb->ptrC[sb->count1];
  s->tag = 0x9000;
  s->type = 7;
  s->count = 4;
  s->field8 = 0;
  s->fieldA = 0;
  s->fieldC = 0;
  s->field10 = 0;
  s->field14 = 0;
  func_02082EA4(gExifVersion, s->field18, 4);
  s->field54 = 0;
  sb->count1++;
  s = &sb->ptrC[sb->count1];
  s->tag = 0x9003;
  s->type = 2;
  s->count = 20;
  s->field8 = 0;
  s->fieldA = 0;
  s->fieldC = 0;
  s->field10 = 0;
  s->field14 = 0;
  STD_CopyLString(s->str, dateTimeData, 20);
  s->field54 = 0;
  sb->count1++;
  s = &sb->ptrC[sb->count1];
  s->tag = 0x9004;
  s->type = 2;
  s->count = 20;
  s->field8 = 0;
  s->fieldA = 0;
  s->fieldC = 0;
  s->field10 = 0;
  s->field14 = 0;
  STD_CopyLString(s->str, dateTimeData, 20);
  s->field54 = 0;
  sb->count1++;
  s = &sb->ptrC[sb->count1];
  s->tag = 0x9101;
  s->type = 7;
  s->count = 4;
  s->field8 = 0;
  s->fieldA = 0;
  s->fieldC = 0;
  s->field10 = 0;
  s->field14 = 0;
  s->field18[0] = 1;
  s->field18[1] = 2;
  s->field18[2] = 3;
  s->field18[3] = 0;
  s->field54 = 0;
  sb->count1++;
  s = &sb->ptrC[sb->count1];
  s->tag = 0x927C;
  s->type = 7;
  s->count = 0;
  s->field8 = 0;
  s->fieldA = 0;
  s->fieldC = 0;
  s->field10 = 0;
  s->field14 = 0;
  s->field18[0] = 1;
  s->field18[1] = 2;
  s->field18[2] = 3;
  s->field18[3] = 0;
  s->field54 = 0;
  sb->count1++;
  s = &sb->ptrC[sb->count1];
  s->tag = 0xA000;
  s->type = 7;
  s->count = 4;
  s->field8 = 0;
  s->fieldA = 0;
  s->fieldC = 0;
  s->field10 = 0;
  s->field14 = 0;
  func_02082EA4(gExifFlashpixVersion, s->field18, 4);
  s->field54 = 0;
  sb->count1++;
  s = &sb->ptrC[sb->count1];
  s->tag = 0xA001;
  s->type = 3;
  s->count = 1;
  s->field8 = 0;
  s->fieldA = 1;
  s->fieldC = 0;
  s->field10 = 0;
  s->field14 = 0;
  s->field54 = 0;
  sb->count1++;
  s = &sb->ptrC[sb->count1];
  s->tag = 0xA002;
  s->type = 4;
  s->count = 1;
  s->field8 = 0;
  s->fieldA = 0;
  s->fieldC = (u32) cfg_input_width;
  s->field10 = 0;
  s->field14 = 0;
  s->field54 = 0;
  sb->count1++;
  s = &sb->ptrC[sb->count1];
  s->tag = 0xA003;
  s->type = 4;
  s->count = 1;
  s->field8 = 0;
  s->fieldA = 0;
  s->fieldC = (u32) cfg_input_height;
  s->field10 = 0;
  s->field14 = 0;
  s->field54 = 0;
  sb->count2 = 0;
  sb->count1++;
  s = &sb->ptr18[sb->count2];
  s->tag = gExifMakerNoteConfig.tag;
  s->type = gExifMakerNoteConfig.type;
  s->count = gExifMakerNoteConfig.count;
  s->field8 = gExifMakerNoteConfig.f8;
  s->fieldA = gExifMakerNoteConfig.fa;
  s->fieldC = gExifMakerNoteConfig.fc;
  s->field10 = gExifMakerNoteConfig.f10;
  s->field14 = gExifMakerNoteConfig.f14;
  STD_CopyLString(s->str, gExifMakerNoteConfigData, s->count);
  s->field54 = 0;
  sb->count2++;
  if (SSPiMakerNoteBufferSize != 0)
  {
    s = &sb->ptr18[sb->count2];
    s->tag = 0x1001;
    s->type = 7;
    s->count = SSPiMakerNoteBufferSize;
    s->field8 = 0;
    s->fieldA = 0;
    s->fieldC = 0;
    s->field10 = 0;
    s->field14 = 0;
    s->field54 = 0;
    sb->count2++;
  }
  if (SSPiMakerNoteUserBufferSize != 0)
  {
    s = &sb->ptr18[sb->count2];
    s->tag = 0x1002;
    s->type = 7;
    s->count = SSPiMakerNoteUserBufferSize;
    s->field8 = 0;
    s->fieldA = 0;
    s->fieldC = 0;
    s->field10 = 0;
    s->field14 = 0;
    s->field54 = 0;
    sb->count2++;
  }
  sb->count3 = 0;
  s = &sb->ptr24[sb->count3];
  s->tag = 0x0001;
  s->type = 2;
  s->count = 4;
  s->field8 = 0;
  s->fieldA = 0;
  s->fieldC = 0;
  s->field10 = 0;
  s->field14 = 0;
  STD_CopyLString(s->str, gExifInteropIndex, 4);
  s->field54 = 0;
  sb->count3++;
  s = &sb->ptr24[sb->count3];
  s->tag = 0x0002;
  s->type = 7;
  s->count = 4;
  s->field8 = 0;
  s->fieldA = 0;
  s->fieldC = 0;
  s->field10 = 0;
  s->field14 = 0;
  func_02082EA4(gExifFlashpixVersion, s->field18, 4);
  s->field54 = 0;
  sb->count3++;
  s = &sb->ptr24[sb->count3];
  s->tag = 0x1000;
  s->type = 2;
  s->count = 18;
  s->field8 = 0;
  s->fieldA = 0;
  s->fieldC = 0;
  s->field10 = 0;
  s->field14 = 0;
  STD_CopyLString(s->str, gExifRelatedImageFormat, 18);
  s->field54 = 0;
  sb->count4 = 0;
  sb->count3++;
  s = &sb->ptr30[sb->count4];
  s->tag = 0x0103;
  s->type = 3;
  s->count = 1;
  s->field8 = 0;
  s->fieldA = 6;
  s->fieldC = 0;
  s->field10 = 0;
  s->field14 = 0;
  s->field54 = 0;
  sb->count4++;
  s = &sb->ptr30[sb->count4];
  s->tag = 0x011A;
  s->type = 5;
  s->count = 1;
  s->field8 = 0;
  s->fieldA = 0;
  s->fieldC = 0;
  s->field10 = 72;
  s->field14 = 1;
  s->field54 = 0;
  sb->count4++;
  s = &sb->ptr30[sb->count4];
  s->tag = 0x011B;
  s->type = 5;
  s->count = 1;
  s->field8 = 0;
  s->fieldA = 0;
  s->fieldC = 0;
  s->field10 = 72;
  s->field14 = 1;
  s->field54 = 0;
  sb->count4++;
  s = &sb->ptr30[sb->count4];
  s->tag = 0x0128;
  s->type = 3;
  s->count = 1;
  s->field8 = 0;
  s->fieldA = 2;
  s->fieldC = 0;
  s->field10 = 0;
  s->field14 = 0;
  s->field54 = 0;
  cfg_encode_exif_ = cfg_encode_exif;
  sb->count4++;
  if (cfg_encode_exif_)
  {
    if (sb->count0 == 0)
    {
      return 0;
    }
    s = &sb->ptr0[sb->count0];
    s->tag = 0x8769;
    s->type = 4;
    s->count = 1;
    sb->count0++;
    if (sb->count2 != 0)
    {
      if (((gExifMakerNoteConfig.count + SSPiMakerNoteBufferSize) + SSPiMakerNoteUserBufferSize) != 0)
      {
        struct Slot *m = &sb->ptrC[4];
        m->tag = 0x927C;
        m->type = 7;
        m->count = 6;
        if (gExifMakerNoteConfig.count != 0)
        {
          m->count += 12;
        }
        if (SSPiMakerNoteBufferSize != 0)
        {
          m->count += 12;
        }
        if (SSPiMakerNoteUserBufferSize != 0)
        {
          m->count += 12;
        }
        m->count = ((gExifMakerNoteConfig.count + SSPiMakerNoteBufferSize) + SSPiMakerNoteUserBufferSize) + m->count;
      }
    }
    if (sb->count3 != 0)
    {
      s = &sb->ptrC[sb->count1];
      s->tag = 0xA005;
      s->type = 4;
      s->count = 1;
      sb->count1++;
    }
    s = &sb->ptr30[sb->count4];
    s->tag = 0x0201;
    s->type = 4;
    s->count = 1;
    sb->count4++;
    s = &sb->ptr30[sb->count4];
    s->tag = 0x0202;
    s->type = 4;
    s->count = 1;
    sb->field44 = (u32) thumb_size;
    sb->count4++;
  }
  else
  {
    if (sb->count0 == 0)
    {
      return 0;
    }
    s = &sb->ptr0[sb->count0];
    s->tag = 0x8769;
    s->type = 4;
    s->count = 1;
    sb->count0++;
    if (sb->count2 != 0)
    {
      if (((gExifMakerNoteConfig.count + SSPiMakerNoteBufferSize) + SSPiMakerNoteUserBufferSize) != 0)
      {
        struct Slot *m = &sb->ptrC[4];
        m->tag = 0x927C;
        m->type = 7;
        m->count = 6;
        if (gExifMakerNoteConfig.count != 0)
        {
          m->count += 12;
        }
        if (SSPiMakerNoteBufferSize != 0)
        {
          m->count += 12;
        }
        if (SSPiMakerNoteUserBufferSize != 0)
        {
          m->count += 12;
        }
        m->count = ((gExifMakerNoteConfig.count + SSPiMakerNoteBufferSize) + SSPiMakerNoteUserBufferSize) + m->count;
      }
    }
    if (sb->count3 != 0)
    {
      s = &sb->ptrC[sb->count1];
      s->tag = 0xA005;
      s->type = 4;
      s->count = 1;
      sb->count1++;
    }
    s = &sb->ptr30[sb->count4];
    s->tag = 0x0201;
    s->type = 4;
    s->count = 1;
    sb->count4++;
    s = &sb->ptr30[sb->count4];
    s->tag = 0x0202;
    s->type = 4;
    s->count = 1;
    sb->field44 = 0;
    sb->count4++;
  }
  dst[encode_file_size++] = 0xFF;
  dst[encode_file_size++] = 0xD8;
  if (cfg_encode_exif_)
  {
    if (write_exif_ifd_tables(sb, 0, thumb_src, thumb_size) == 0)
    {
      return 0;
    }
  }
  else
  {
    if (write_exif_ifd_tables(sb, 1, thumb_src, thumb_size) == 0)
    {
      return 0;
    }
  }
  if ((encode_file_size & 1) == 1)
  {
    dst[encode_file_size++] = 0;
  }
  return 1;
}


u32 SSP_ExifEncode(int a0, int a1, int a2, u8 *a3, u32 a4)
{
    char buf[0x20];
    u32 local;

    g_021CADF0.f14 = a0;
    gExifMakerNoteConfig.tag = 0x1000;
    gExifMakerNoteConfig.type = 7;
    gExifMakerNoteConfig.count = 0x1C;
    if (gExifMakerNoteConfig.count > 0x1E)
        gExifMakerNoteConfig.count = 0x1E;
    gExifMakerNoteConfig.f8 = 0;
    gExifMakerNoteConfig.fa = 0;
    gExifMakerNoteConfig.fc = 0;
    gExifMakerNoteConfig.f10 = 0;
    gExifMakerNoteConfig.f14 = 0;
    MI_CpuFill8(gExifMakerNoteConfigData, 0, gExifMakerNoteConfig.count);

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
