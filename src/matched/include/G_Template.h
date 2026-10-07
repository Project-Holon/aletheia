#ifndef ALETHEIA_G_TEMPLATE_H
#define ALETHEIA_G_TEMPLATE_H
/* d_021BB060 (ov218) */
struct Template {
    unsigned char pad_0[0x18];
    unsigned char page;
    unsigned char pad19;
    unsigned short start;
    unsigned char pad_1C[0x8];
    void *owner;
};
#endif
