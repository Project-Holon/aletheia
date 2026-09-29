/*
 * function: jpeg_encode_ifd_direct
 * address:  0x021C3160
 * packet:   pkt_ov172_021C3160
 * region:   ov172
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF (near miss, exact size, all 4 relocs resolved)
 *
 * blocker:  whole function reconstructed from the matched sibling
 *           jpeg_encode_ifd (0x021C3620).  337 concrete bytes differ,
 *           concentrated in the !is_last next_ifd_pointer byte-write block
 *           (image 0x021C3440): the original materialises byte 24 with
 *           `and; asr`, byte 16 with `and #0xff0000; lsl #16; asr #16;
 *           asr #16` and byte 8 with `and #0xff00; lsl #16; asr #24`
 *           (signed-shift forms); the source spelling that produces these
 *           exact forms was not found.  Second loop's inner byte-copy
 *           counters are a separate `int` (r3) in the image while ours
 *           coalesce to the outer `signed char i` (r7); declaring it as an
 *           extra local reallocates the whole function and is worse.
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

typedef struct exifenc_vars {
    int dateTimeDataFlag;       /* +0x00 */
    unsigned long pos;          /* +0x04 */
    unsigned long f08;
    unsigned long f0C;
    unsigned long len2;         /* +0x10 */
    unsigned char *buf;         /* +0x14 */
    unsigned long len1;         /* +0x18 */
    unsigned char *ptr1;        /* +0x1c */
    unsigned char *ptr2;        /* +0x20 */
} exifenc_vars;

extern unsigned long func_021C2DC8(exif_tag_entry *entry);
extern void func_021C2E1C(exif_tag_entry *entry);
extern exifenc_vars g_021CADF0;

#define PUT(v)  (g_021CADF0.buf[g_021CADF0.pos++] = (unsigned char)(v))

void jpeg_encode_ifd_direct(void *unused, exif_ifd_data *ifd, short is_last)
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
        PUT((next_ifd_pointer & 0xff0000) >> 16);
        PUT((signed char)(next_ifd_pointer >> 8));
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
                for (i = 0; i < g_021CADF0.len1; i++)
                    PUT(g_021CADF0.ptr1[i]);
            } else if (entry->tag == 0x1002) {
                for (i = 0; i < g_021CADF0.len2; i++)
                    PUT(g_021CADF0.ptr2[i]);
            }
        }
    }
}


