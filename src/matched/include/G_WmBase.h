#ifndef ALETHEIA_G_WMBASE_H
#define ALETHEIA_G_WMBASE_H
/* g_021F6F90 (arm9) */
struct WmBase {
    unsigned short WM_DMA_NO;
    unsigned short pad;
    void *wmSysBuf;
    int isEnableReject;
    unsigned char *work;
    void *ext;
};
#endif
