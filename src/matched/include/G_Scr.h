#ifndef ALETHEIA_G_SCR_H
#define ALETHEIA_G_SCR_H
/* g_020A81F8 (arm9) */
struct Scr {
    unsigned short firstSRTransformedMtxIdx_;
    unsigned char pad_2[0x2];
    int currenVramTransferHandle_;
    int mtxI___00;
    int mtxI___01;
    int mtxI___10;
    int mtxI___11;
    int mtx_tx;
    int mtx_ty;
};
#endif
