#ifndef ALETHEIA_G_EXIFENC_VARS_H
#define ALETHEIA_G_EXIFENC_VARS_H
/* g_021CADF0 (ov172) */
struct exifenc_vars {
    int dateTimeDataFlag;
    unsigned long pos;
    unsigned long f08;
    unsigned long f0C;
    unsigned long len2;
    unsigned char *buf;
    unsigned int len1;
    unsigned char *ptr1;
    unsigned char *ptr2;
    unsigned char pad_24[0x13];
    unsigned char f37;
};
#endif
