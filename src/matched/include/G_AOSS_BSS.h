#ifndef ALETHEIA_G_AOSS_BSS_H
#define ALETHEIA_G_AOSS_BSS_H
/* aoss_bss (arm9) */
struct AOSS_BSS {
    int SecurityType;
    void *bssList;
    int initflg;
    void *linkInfo;
    unsigned int gError;
    void *s_buf;
    unsigned long randContext_x;
    unsigned long randContext_mul;
    unsigned long randContext_add;
    unsigned char *gData_p_name;
    unsigned int gData_p_name_len;
    unsigned int gData_sLevel;
    unsigned int gData_aLevel;
    unsigned int gData_apAddr;
    unsigned int gData_apMask;
    char gData_ip_chg;
    char gData_p_type;
    unsigned char pad_3E[0x2];
    unsigned char ProductInfo[640];
    unsigned long crc_table[256];
    unsigned char SecurityInfo[1696];
};
#endif
