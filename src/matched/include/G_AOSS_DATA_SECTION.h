#ifndef ALETHEIA_G_AOSS_DATA_SECTION_H
#define ALETHEIA_G_AOSS_DATA_SECTION_H
/* aoss_data (arm9) */
struct AOSS_DATA_SECTION {
    int s_sFd;
    int before;
    unsigned char pad_8[0x10];
    unsigned long soconfig_addr;
    unsigned long soconfig_netmask;
    unsigned long soconfig_router;
    unsigned char pad_24[0x3C];
};
#endif
