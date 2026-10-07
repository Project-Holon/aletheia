/*
 * file:     unit_021C2CDC_p02.c
 * unit:     yes
 * function: func_021C2E1C, func_021C3160
 * address:  0x021C2E1C
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
 *   jpeg_exif_get_tag_size  0x021C2DC8  arm
 *   dateTimeDataFlag        0x021CADF0  data
 *   func_021C2DC8  0x021C2DC8  arm  ov172
 *   func_021C2E1C  0x021C2E1C  arm  ov172
 *   g_021CADF0     0x021CADF0  data ov172
 */
#include "../../matched/include/G_exifenc_vars.h"

#define PUT(v)  (g_021CADF0.buf[g_021CADF0.pos++] = (unsigned char)(v))
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned long u32;

typedef struct {
    u16 unk0;
    u16 tag;
    int unk4;
    signed char val8;
    signed char unk9;
    short val_a;
    long val_c;
    long val_10;
    long val_14;
    signed char str18[30];
    signed char str36[30];
} ExifTagEntry;

typedef struct {
    int unk0;
    int pos;
    int unk8;
    int unkc;
    int unk10;
    unsigned char *buf;
} ExifCtx;

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

typedef struct exifenc_vars exifenc_vars;

extern u32 jpeg_exif_get_tag_size(ExifTagEntry *entry);
extern unsigned long func_021C2DC8(exif_tag_entry *entry);
extern void func_021C2E1C(exif_tag_entry *entry);
void jpeg_encode_ifd_direct(void *unused, exif_ifd_data *ifd, short is_last);
extern ExifCtx dateTimeDataFlag;
extern struct exifenc_vars g_021CADF0;


static void jpeg_exif_set_tag_value(ExifTagEntry *entry)
{
    switch (entry->tag) {
    case 0:
        break;
    case 1:
        dateTimeDataFlag.buf[dateTimeDataFlag.pos++] = entry->val8;
        dateTimeDataFlag.buf[dateTimeDataFlag.pos++] = 0;
        dateTimeDataFlag.buf[dateTimeDataFlag.pos++] = 0;
        dateTimeDataFlag.buf[dateTimeDataFlag.pos++] = 0;
        break;
    case 3:
        dateTimeDataFlag.buf[dateTimeDataFlag.pos++] = (entry->val_a & 0xff00) >> 8;
        dateTimeDataFlag.buf[dateTimeDataFlag.pos++] = entry->val_a;
        dateTimeDataFlag.buf[dateTimeDataFlag.pos++] = 0;
        dateTimeDataFlag.buf[dateTimeDataFlag.pos++] = 0;
        break;
    case 4:
    case 9:
        dateTimeDataFlag.buf[dateTimeDataFlag.pos++] = (entry->val_c & 0xff000000) >> 24;
        dateTimeDataFlag.buf[dateTimeDataFlag.pos++] = (entry->val_c & 0xff0000) >> 16;
        dateTimeDataFlag.buf[dateTimeDataFlag.pos++] = (entry->val_c & 0xff00) >> 8;
        dateTimeDataFlag.buf[dateTimeDataFlag.pos++] = entry->val_c;
        break;
    case 5:
    case 10:
        dateTimeDataFlag.buf[dateTimeDataFlag.pos++] = (entry->val_10 & 0xff000000) >> 24;
        dateTimeDataFlag.buf[dateTimeDataFlag.pos++] = (entry->val_10 & 0xff0000) >> 16;
        dateTimeDataFlag.buf[dateTimeDataFlag.pos++] = (entry->val_10 & 0xff00) >> 8;
        dateTimeDataFlag.buf[dateTimeDataFlag.pos++] = entry->val_10;
        dateTimeDataFlag.buf[dateTimeDataFlag.pos++] = (entry->val_14 & 0xff000000) >> 24;
        dateTimeDataFlag.buf[dateTimeDataFlag.pos++] = (entry->val_14 & 0xff0000) >> 16;
        dateTimeDataFlag.buf[dateTimeDataFlag.pos++] = (entry->val_14 & 0xff00) >> 8;
        dateTimeDataFlag.buf[dateTimeDataFlag.pos++] = entry->val_14;
        break;
    case 7: {
        u32 size = jpeg_exif_get_tag_size(entry);
        u32 i;

        for (i = 0; i < size; i++)
            dateTimeDataFlag.buf[dateTimeDataFlag.pos++] = entry->str18[i];
        for (; i < 4; i++)
            dateTimeDataFlag.buf[dateTimeDataFlag.pos++] = 0;
        break;
    }
    case 2: {
        u32 size = jpeg_exif_get_tag_size(entry);
        u32 i;

        for (i = 0; i < size; i++)
            dateTimeDataFlag.buf[dateTimeDataFlag.pos++] = entry->str36[i];
        for (; i < 4; i++)
            dateTimeDataFlag.buf[dateTimeDataFlag.pos++] = 0;
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

        size = func_021C2DC8(entry);
        if (size <= 4) {
            if (size == 2) {
                PUT(0);
                PUT(0);
            }
            if (entry->tag == 0x1001) {
                for (i = 0; i < g_021CADF0.len1; i++)
                    PUT(g_021CADF0.ptr1[i]);
            } else if (entry->tag == 0x1002) {
                for (i = 0; i < g_021CADF0.len2; i++)
                    PUT(g_021CADF0.ptr2[i]);
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
                for (j = 0; j < g_021CADF0.len1; j++)
                    PUT(g_021CADF0.ptr1[j]);
            } else if (entry->tag == 0x1002) {
                for (j = 0; j < g_021CADF0.len2; j++)
                    PUT(g_021CADF0.ptr2[j]);
            }
        }
    }
}
