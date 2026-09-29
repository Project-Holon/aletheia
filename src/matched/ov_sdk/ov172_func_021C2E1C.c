/*
 * function: jpeg_exif_set_tag_value
 * address:  0x021C2E1C
 * packet:   pkt_ov172_021C2E1C
 * region:   ov172
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      jpeg_exif_set_tag_value (libssp.TWL.HYB.a(exifenc.o))
 *
 * note:     each output byte re-reads entry->field from the struct (no local
 *           copy); the compiler reloads after every buf[] store because the
 *           store can alias *entry, and that reload is what the object does.
 *           The masks must also sit before the shift (`(x & 0xff00) >> 8`),
 *           otherwise 1.1p1 folds them into the strb and drops four bytes.
 *
 * symbols:
 *   jpeg_exif_get_tag_size  0x021C2DC8  arm
 *   dateTimeDataFlag        0x021CADF0  data
 */

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

extern ExifCtx dateTimeDataFlag;
extern u32 jpeg_exif_get_tag_size(ExifTagEntry *entry);

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
