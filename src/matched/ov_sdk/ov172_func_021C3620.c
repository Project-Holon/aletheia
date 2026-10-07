/*
 * function: func_021C3620
 * address:  0x021C3620
 * packet:   pkt_ov172_021C3620
 * region:   ov172
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      jpeg_encode_ifd (libssp.TWL.HYB.a exifenc.o)
 *
 * symbols:
 *   func_021C2DC8  0x021C2DC8  arm  ov172
 *   func_021C2E1C  0x021C2E1C  arm  ov172
 *   g_021CADF0     0x021CADF0  data ov172
 *
 * exifenc.o's file statics sit in one block based at dateTimeDataFlag
 * (0x021CADF0); every use goes through that one pool word, so the block
 * is written as a struct overlay named by offset (+0x04 write position,
 * +0x14 output buffer).
 *
 * The app1 length adjust needs an unsigned last operand (6u, as a sizeof
 * would give): with plain `- 2 - 6` the compiler folds the two subtracts.
 */

#include "../include/G_exifenc_vars.h"

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

typedef struct exifenc_vars exifenc_vars;

extern unsigned long func_021C2DC8(exif_tag_entry *entry);
extern void func_021C2E1C(exif_tag_entry *entry);
extern struct exifenc_vars g_021CADF0;

#define PUT(v)  (g_021CADF0.buf[g_021CADF0.pos++] = (unsigned char)(v))

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
