#ifndef ALETHEIA_G_CMD_H
#define ALETHEIA_G_CMD_H
/* g_021AA480 (arm9) */
struct Cmd {
    void *packets;
    unsigned char pad_4[0x14];
    int a;
    int pad1;
    int b;
};
#endif
