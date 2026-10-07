/*
 * function: func_021C3A28
 * address:  0x021C3A28
 * packet:   pkt_ov172_021C3A28
 * region:   ov172
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      jpeg_encode_exif (libssp.TWL.HYB.a exifenc.o)
 *
 * The APP1 16-bit length high byte is written as
 * `(short)(app1_length & 0xff00) >> 8`: the (short) cast after the mask is
 * what makes mwcc emit the unwidened `and #0xff00; lsl #16; asr #24` triple
 * rather than a single `lsr #8`.
 *
 * symbols:
 *   func_021C2DC8  0x021C2DC8  arm  ov172
 *   func_021C3620  0x021C3620  arm  ov172
 *   func_021C3160  0x021C3160  arm  ov172
 *   STD_GetStringLength  0x0208CC78  arm
 *   MI_CpuCopy           0x02082EA4  arm
 *   g_021CADF0     0x021CADF0  data ov172
 *   @12604         0x021C7194  data
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

typedef struct jpeg_exif_data_structure {
    exif_ifd_data ifd[5];
    unsigned long app1_length;
    unsigned long thumb_compressed_data;
    long thumb_compressed_length;
} jpeg_exif_data_structure;

typedef struct exifenc_vars {
    int dateTimeDataFlag;       /* +0x00 */
    unsigned long pos;          /* +0x04 */
    unsigned long f08;
    unsigned long f0C;
    unsigned long f10;
    unsigned char *buf;         /* +0x14 */
} exifenc_vars;

extern unsigned long func_021C2DC8(exif_tag_entry *entry);
extern void func_021C3620(jpeg_exif_data_structure *jexif, exif_ifd_data *ifd, short is_last);
extern void func_021C3160(void *unused, exif_ifd_data *ifd, short is_last);
extern int STD_GetStringLength(char *str);
extern void MI_CpuCopy(void *srcp, void *destp, unsigned long size);
extern exifenc_vars g_021CADF0;

#define PUT(v)  (g_021CADF0.buf[g_021CADF0.pos++] = (unsigned char)(v))

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
        MI_CpuCopy(thumb_src, g_021CADF0.buf + g_021CADF0.pos, thumb_size);
        g_021CADF0.pos += thumb_size;
    }
    return 1;
}
