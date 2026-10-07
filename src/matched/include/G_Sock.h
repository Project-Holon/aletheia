#ifndef ALETHEIA_G_SOCK_H
#define ALETHEIA_G_SOCK_H
/* g_021AA44C (arm9) */
struct Sock {
    unsigned char pad_0[0x48];
    unsigned long b48_size;
    unsigned char *b48_data;
    unsigned char pad_50[0x4];
    unsigned long b54_size;
    unsigned char *b54_data;
    unsigned long b5c_size;
    unsigned char *b5c_data;
    unsigned long b64_size;
    unsigned char *b64_data;
    unsigned char pad_6C[0x34];
    void *pipe_send;
    void *pipe_recv;
    unsigned char pad_A8[0x4];
    short state;
    signed char f_ae;
    signed char f_af;
    unsigned char pad_B0[0x8];
    void *next;
};
#endif
