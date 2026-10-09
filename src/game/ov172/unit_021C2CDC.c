/*
 * file:     unit_021C2CDC.c
 * unit:     yes
 * function: func_021C2CDC, func_021C2D0C, func_021C2D24, func_021C2D9C, func_021C2DC8, func_021C2E1C, func_021C3160, func_021C3620, func_021C3A28, func_021C3DF4
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
 *   dateTimeData  0x021CAE14  data  ov172
 *   dateTimeDataFlag  0x021CADF0  data  ov172
 *   func_020889C0  0x020889C0  arm
 *   g_021C8874  0x021C8874  data
 *   SSPiSoftware  0x021CAE28  data
 *   func_021C2E1C  0x021C2E1C  arm  ov172
 *   func_021C3160  0x021C3160  arm  ov172
 *   STD_GetStringLength  0x0208CC78  arm
 *   MI_CpuCopy           0x02082EA4  arm
 *   @12445  0x021C719C  data
 *   @12604         0x021C7194  data
 *   g_021CAE48 0x021CAE48 data ov172
 *   g_021CB728 0x021CB728 data
 *   g_021CC070 0x021CC070 data ov172
 *   g_021CAEE8 0x021CAEE8 data ov172
 *   g_021CB308 0x021CB308 data ov172
 *   g_021CBBA0 0x021CBBA0 data ov172
 *   g_021C8894 0x021C8894 data ov172
 *   g_021C88A0 0x021C88A0 data ov172
 *   dateTimeDataFlag 0x021CADF0 data ov172
 *   encode_file_size 0x021CADF4 data ov172
 *   SSPiEncodeSignCheckMode 0x021CADF8 data ov172
 *   SSPiSoftwareSize 0x021CADFC data ov172
 *   SSPiMakerNoteUserBufferSize 0x021CAE00 data ov172
 *   dst 0x021CAE04 data ov172
 *   SSPiMakerNoteBufferSize 0x021CAE08 data ov172
 *   SSPiMakerNoteBuffer 0x021CAE0C data ov172
 *   SSPiMakerNoteUserBuffer 0x021CAE10 data ov172
 *   dateTimeData 0x021CAE14 data ov172
 *   SSPiSoftware 0x021CAE28 data ov172
 *   g_021C88AC 0x021C88AC data ov172
 *   g_021C88B4 0x021C88B4 data ov172
 *   g_021CAE90 0x021CAE90 data
 *   g_021CAEC6 0x021CAEC6 data ov172
 *   g_021C88BC 0x021C88BC data ov172
 *   g_021C88C0 0x021C88C0 data ov172
 *   write_exif_ifd_tables 0x021C3A28 arm ov172
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

void func_02082EA4(const void *src, void *dst, u32 n);
extern int func_020889C0(struct RTCDate *date, struct RTCTime *time);
void func_0208D7E0(char *dst, const char *fmt, ...);
int func_0208CB10(char *destp, const char *srcp, int siz);
void func_021C2E1C(exif_tag_entry *entry);
extern int STD_GetStringLength(char *str);
extern void MI_CpuCopy(void *srcp, void *destp, unsigned long size);
extern void STD_CopyLString(char *dst, const char *src, u32 n);
extern void MI_CpuCopy8(const void *src, void *dst, u32 n);
extern u32 write_exif_ifd_tables(struct SlotManager *mgr, u32 mode, u8 *thumb_src, u32 thumb_size);
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

void func_021C2CDC(u8 *buf);
int func_021C2D0C(void *a, void *b);
int func_021C2D24(void);
void func_021C2D9C(const char *s);
unsigned long func_021C2DC8(struct exif_tag_entry *entry);
void func_021C3160(void *unused, exif_ifd_data *ifd, short is_last);
void func_021C3620(jpeg_exif_data_structure *jexif, exif_ifd_data *ifd, short is_last);
short func_021C3A28(jpeg_exif_data_structure *jexif, short option, unsigned char *thumb_src, unsigned long thumb_size);
s16 func_021C3DF4(s16 width, s16 height, u16 encode_option, u8 *thumb_src, u32 thumb_size);
extern const char g_021C8874[];
extern struct SlotManager g_021CAE48;
extern struct Slot g_021CB728[];
extern struct Slot g_021CC070[];
extern struct Slot g_021CAEE8[];
extern struct Slot g_021CB308[];
extern struct Slot g_021CBBA0[];
extern const char g_021C8894[];
extern const char g_021C88A0[];
extern const char g_021C88AC[];
extern const char g_021C88B4[];
extern struct Ae90 g_021CAE90;
extern const char g_021CAEC6[];
extern const char g_021C88BC[];
extern const char g_021C88C0[];





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
void func_021C2CDC(u8 *buf)
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
 * then handed to func_021C2CDC, which copies it out to dateTimeData.
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
    SSPiSoftwareSize = func_0208CB10(SSPiSoftware, s, 0x1e) + 1;
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






void func_021C2E1C(exif_tag_entry *entry)
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
        u32 size = func_021C2DC8(entry);
        u32 i;

        for (i = 0; i < size; i++)
            PUT(entry->undefined_data[i]);
        for (; i < 4; i++)
            PUT(0);
        break;
    }
    case 2: {
        u32 size = func_021C2DC8(entry);
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






void func_021C3160(void *unused, exif_ifd_data *ifd, short is_last)
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

        size = func_021C2DC8(entry);
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
        size = func_021C2DC8(entry);
        if (size > 4) {
            if (entry->tag == 0x1000) {
                func_021C2E1C(entry);
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
void func_021C3620(jpeg_exif_data_structure *jexif, exif_ifd_data *ifd, short is_last)
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

        if (func_021C2DC8(entry) <= 4) {
            func_021C2E1C(entry);
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
        size = func_021C2DC8(entry);
        if (size > 4 && entry->tag != 0x927c) {
            func_021C2E1C(entry);
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
short func_021C3A28(jpeg_exif_data_structure *jexif, short option,
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
            size = func_021C2DC8(entry);
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

    func_021C3620(jexif, &jexif->ifd[0], option);
    if (jexif->ifd[1].count > 0)
        func_021C3620(jexif, &jexif->ifd[1], 1);
    if (jexif->ifd[2].count > 0)
        func_021C3160(jexif, &jexif->ifd[2], 1);
    if (jexif->ifd[3].count > 0)
        func_021C3620(jexif, &jexif->ifd[3], 1);

    if (option == 0) {
        func_021C3620(jexif, &jexif->ifd[4], 1);
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
s16 func_021C3DF4(s16 width, s16 height, u16 encode_option, u8 *thumb_src, u32 thumb_size)
{
  s16 cfg_encode_exif;
  s16 cfg_encode_gray_scale;
  s16 cfg_input_width;
  s16 cfg_input_height;
  struct SlotManager *sb = &g_021CAE48;
  struct Slot *s;
  s16 cfg_encode_exif_;
  sb->ptr0 = g_021CB728;
  sb->count0 = 0;
  sb->field8 = 0;
  sb->ptrC = g_021CC070;
  sb->count1 = 0;
  sb->field14 = 0;
  sb->ptr18 = g_021CAEE8;
  sb->count2 = 0;
  sb->field20 = 0;
  sb->ptr24 = g_021CB308;
  sb->count3 = 0;
  sb->field2C = 0;
  sb->ptr30 = g_021CBBA0;
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
  STD_CopyLString(s->str, g_021C8894, 9);
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
  func_0208CB10(s->str, g_021C88A0, 11);
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
    func_0208CB10(s->str, SSPiSoftware, s->count);
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
  func_0208CB10(s->str, dateTimeData, 20);
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
  func_02082EA4(g_021C88AC, s->field18, 4);
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
  func_0208CB10(s->str, dateTimeData, 20);
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
  func_0208CB10(s->str, dateTimeData, 20);
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
  func_02082EA4(g_021C88B4, s->field18, 4);
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
  s->tag = g_021CAE90.tag;
  s->type = g_021CAE90.type;
  s->count = g_021CAE90.count;
  s->field8 = g_021CAE90.f8;
  s->fieldA = g_021CAE90.fa;
  s->fieldC = g_021CAE90.fc;
  s->field10 = g_021CAE90.f10;
  s->field14 = g_021CAE90.f14;
  func_0208CB10(s->str, g_021CAEC6, s->count);
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
  func_0208CB10(s->str, g_021C88BC, 4);
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
  func_02082EA4(g_021C88B4, s->field18, 4);
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
  func_0208CB10(s->str, g_021C88C0, 18);
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
      if (((g_021CAE90.count + SSPiMakerNoteBufferSize) + SSPiMakerNoteUserBufferSize) != 0)
      {
        struct Slot *m = &sb->ptrC[4];
        m->tag = 0x927C;
        m->type = 7;
        m->count = 6;
        if (g_021CAE90.count != 0)
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
        m->count = ((g_021CAE90.count + SSPiMakerNoteBufferSize) + SSPiMakerNoteUserBufferSize) + m->count;
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
      if (((g_021CAE90.count + SSPiMakerNoteBufferSize) + SSPiMakerNoteUserBufferSize) != 0)
      {
        struct Slot *m = &sb->ptrC[4];
        m->tag = 0x927C;
        m->type = 7;
        m->count = 6;
        if (g_021CAE90.count != 0)
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
        m->count = ((g_021CAE90.count + SSPiMakerNoteBufferSize) + SSPiMakerNoteUserBufferSize) + m->count;
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
