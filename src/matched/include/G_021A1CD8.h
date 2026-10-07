#ifndef ALETHEIA_G_021A1CD8_H
#define ALETHEIA_G_021A1CD8_H
/* g_021A1CD8 (arm9) */
struct G_021A1CD8 {
    int pad0;
    unsigned long myIp;
    unsigned long netMask;
    unsigned long gatewayIp;
    unsigned long dnsIp[2];
    void * (*alloc)(unsigned long);
    void (*free)(void *);
    long cpMaxCount;
    unsigned char pad_24[0x4];
    int flag28;
};
#endif
