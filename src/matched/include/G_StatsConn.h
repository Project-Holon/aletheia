#ifndef ALETHEIA_G_STATSCONN_H
#define ALETHEIA_G_STATSCONN_H
/* g_021ADFE0 (arm9) */
struct StatsConn {
    unsigned char pad_0[0x8];
    int inLen;
    unsigned char pad_C[0xC];
    int inSize;
    unsigned char pad_1C[0xC];
    char *inBuff;
    int state;
};
#endif
