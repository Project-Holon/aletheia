#ifndef ALETHEIA_G_BATTLEREC_H
#define ALETHEIA_G_BATTLEREC_H
/* g_0214616C (arm9) */
struct BattleRec {
    unsigned char pad_0[0x80];
    unsigned short unk80_unk00[12];
    unsigned char pad_98[0xC];
    unsigned short unk80_unk24;
    unsigned short unk80_unk26;
    unsigned short unk80_unk28;
    unsigned char unk80_unk2A;
    unsigned char unk80_unk2B;
    unsigned char pad_AC[0x14];
    unsigned short unk80_unk40;
    unsigned short unk80_unk42;
    unsigned char pad_C4[0x17D8];
    unsigned short unkC4_unk17D8;
    unsigned short unkC4_unk17DA;
    unsigned short unkC4_unk17DC;
    unsigned short unkC4_unk17DE;
};
#endif
