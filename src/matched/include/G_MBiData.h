#ifndef ALETHEIA_G_MBIDATA_H
#define ALETHEIA_G_MBIDATA_H
/* mbi_life_mp (arm9) */
struct MBiData {
    unsigned short mbi_life_mp;
    unsigned short cam;
    unsigned short mbi_life_table_no;
    unsigned short frame;
    int mbi_power_save_mode;
    unsigned int unkC;
    unsigned int rejectGgid;
    unsigned int rejectGgidMask;
};
#endif
