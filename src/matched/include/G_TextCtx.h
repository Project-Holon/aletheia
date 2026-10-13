#ifndef ALETHEIA_G_TEXTCTX_H
#define ALETHEIA_G_TEXTCTX_H
/* g_TextPrintWork (arm9) */
struct TextCtx {
    unsigned char pixels[32];
    unsigned char width;
    unsigned char pad21;
    unsigned short x;
    unsigned short y;
};
#endif
