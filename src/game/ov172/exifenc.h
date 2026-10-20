#ifndef GAME_OV172_EXIFENC_H
#define GAME_OV172_EXIFENC_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of exifenc.c, prototypes copied from their definitions. */

struct exif_tag_entry;
struct exif_ifd_data;
struct jpeg_exif_data_structure;
typedef struct exif_tag_entry exif_tag_entry;
typedef struct exif_ifd_data exif_ifd_data;
typedef struct jpeg_exif_data_structure jpeg_exif_data_structure;

#include "../types.h"

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
u32 SSP_ExifEncode(int dstBuffer, int width, int height, u8 *thumbSrc, u32 thumbSize);
/* END mkheaders: generated region */

#endif
