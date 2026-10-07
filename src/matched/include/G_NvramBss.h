#ifndef ALETHEIA_G_NVRAMBSS_H
#define ALETHEIA_G_NVRAMBSS_H
/* g_02150EA0 (arm9) */
struct NvramBss {
    unsigned int nvramInitialized;
    unsigned char pad_4[0x1C];
    unsigned int nvramTemp[8];
};
#endif
