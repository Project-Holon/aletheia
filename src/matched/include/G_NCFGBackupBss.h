#ifndef ALETHEIA_G_NCFGBACKUPBSS_H
#define ALETHEIA_G_NCFGBACKUPBSS_H
/* FormatVersionNumber (arm9) */
struct NCFGBackupBss {
    unsigned char FormatVersionNumber;
    unsigned char pad_1[0x1F];
    unsigned char nvramBuf[32];
    unsigned short nvramBuf2[16];
};
#endif
