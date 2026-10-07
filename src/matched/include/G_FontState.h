#ifndef ALETHEIA_G_FONTSTATE_H
#define ALETHEIA_G_FONTSTATE_H
/* g_02146578 (arm9) */
struct FontState {
    unsigned char colour[3];
    unsigned char pad;
    unsigned char *br_src;
    unsigned int br_avail;
    unsigned char br_cur;
};
#endif
