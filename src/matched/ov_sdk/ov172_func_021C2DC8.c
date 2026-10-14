/*
 * function: jpeg_exif_get_tag_size
 * address:  0x021C2DC8
 * packet:   pkt_ov172_021C2DC8
 * region:   ov172
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      jpeg_exif_get_tag_size (exifenc.o)
 *
 * The type_size initializer copies from the vendor template @12445 at
 * 0x021C719C (template class, ov172 scope).
 *
 * symbols:
 *   @12445  0x021C719C  data
 */

struct exif_tag_entry {
    unsigned short tag;
    unsigned short type;
    unsigned long count;
};

unsigned long jpeg_exif_get_tag_size(struct exif_tag_entry *entry)
{
    signed char type_size[11] = {0, 1, 1, 2, 4, 8, 0, 1, 0, 4, 8};

    return type_size[entry->type] * entry->count;
}
