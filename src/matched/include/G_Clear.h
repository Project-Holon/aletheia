#ifndef ALETHEIA_G_CLEAR_H
#define ALETHEIA_G_CLEAR_H
/* d_021D9E40 (arm9) */
struct Clear {
    int record_words[78];
    int f138;
    unsigned char pad_13C[0x4];
    char name[256];
    unsigned char pad_240[0x18];
    int f258;
    unsigned char pad_25C[0x10];
    int f26c;
};
#endif
