#ifndef ALETHEIA_G_MBBEACON_H
#define ALETHEIA_G_MBBEACON_H
/* g_021F6F20 (arm9) */
struct MbBeacon {
    unsigned int ggid;
    unsigned char unk4_raw;
    unsigned char pad_5[0x1];
    unsigned char seqNoFixed;
    unsigned char seqNoVolat;
    unsigned char beaconNo;
    unsigned char pad_9[0x1];
    unsigned short data_volat_sum;
    unsigned char data_volat_nowPlayerNum;
    unsigned char data_volat_pad;
    unsigned short data_volat_nowPlayerFlag;
    unsigned short data_volat_changePlayerFlag;
    unsigned char data_volat_member_0_favoriteColor;
    unsigned char data_volat_member_0_playerNo;
    unsigned char data_volat_member_0_nameLength;
    unsigned char pad_15[0x1];
    unsigned short data_volat_member_0_name[10];
    unsigned char data_volat_member_1_favoriteColor;
    unsigned char data_volat_member_1_playerNo;
    unsigned char data_volat_member_1_nameLength;
    unsigned char pad_2D[0x1];
    unsigned short data_volat_member_1_name[10];
    unsigned char data_volat_member_2_favoriteColor;
    unsigned char data_volat_member_2_playerNo;
    unsigned char data_volat_member_2_nameLength;
    unsigned char pad_45[0x1];
    unsigned short data_volat_member_2_name[10];
    unsigned char data_volat_member_3_favoriteColor;
    unsigned char data_volat_member_3_playerNo;
    unsigned char data_volat_member_3_nameLength;
    unsigned char pad_5D[0x1];
    unsigned short data_volat_member_3_name[10];
    unsigned char data_volat_userVolatData[8];
};
#endif
