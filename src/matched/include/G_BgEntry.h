#ifndef ALETHEIA_G_BGENTRY_H
#define ALETHEIA_G_BGENTRY_H
/* d_021B9524 (arm9) */
struct BgEntry {
    unsigned int bg;
    unsigned char t_bytes[32];
    unsigned int type;
};
#endif
