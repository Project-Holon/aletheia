/*
 * function: jpeg_encode_ifd_direct
 * address:  0x021C3160
 * packet:   pkt_ov172_021C3160
 * region:   ov172
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * notes:    the pointer bytes are written through a short: byte 16 is
 *           (short)(p & 0xff0000) >> 16 and byte 8 is (short)(p & 0xff00) >> 8, which
 *           gives the image's lsl #16 / asr forms.  The second pass copies the two
 *           thumbnail buffers with its own unsigned long counter j; the first pass keeps
 *           the signed char i.
 *
 * sdk:      jpeg_encode_ifd_direct (libssp.TWL.HYB.a exifenc.o)
 *
 * symbols:
 *   func_021C2DC8  0x021C2DC8  arm  ov172
 *   func_021C2E1C  0x021C2E1C  arm  ov172
 *   g_021CADF0     0x021CADF0  data ov172
 *
 * The definition takes an unused first argument: r1 is the ifd pointer and
 * r2 is is_last, r0 is never read (the DWARF prototype lists only two).  r4
 * is the exifenc.o file-static block based at dateTimeDataFlag.
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

typedef struct exifenc_vars exifenc_vars;

extern unsigned long func_021C2DC8(exif_tag_entry *entry);
extern void func_021C2E1C(exif_tag_entry *entry);
extern struct exifenc_vars g_021CADF0;

#define PUT(v)  (g_021CADF0.buf[g_021CADF0.pos++] = (unsigned char)(v))

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


