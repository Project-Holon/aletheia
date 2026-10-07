#ifndef ALETHEIA_G_WORK_H
#define ALETHEIA_G_WORK_H
/* d_021B3C80 (ov013) */
struct Node;
struct Work {
    unsigned char ring[2176];
    void *f880;
    unsigned char f884[4352];
    void (*f1984)(void);
    unsigned char pad_1988[0x18];
    int a[2];
    int f19A8;
    int f19AC;
    unsigned short f19B0;
    unsigned char pad_19B2[0x6];
    unsigned char f19B8[100];
    struct Node *f1A1C;
    int mic_type;
    void *mic_buffer;
    unsigned int mic_size;
    unsigned int mic_rate;
    int mic_loop;
    void *mic_callback;
    void *mic_arg;
    unsigned long long f1A3C;
    signed int f1A44;
    unsigned short f1A48;
    unsigned char pad_1A4A[0x1];
    unsigned char f1A4B;
};
#endif
