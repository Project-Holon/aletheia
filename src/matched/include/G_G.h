#ifndef ALETHEIA_G_G_H
#define ALETHEIA_G_G_H
/* g_021ACE5C (arm9) */
struct G {
    void *http;
    char *nc;
    int f08;
    unsigned long conntestip;
    int allow302;
    int flag;
    unsigned char pad_18[0x18];
    char *httpparam_url;
    int httpparam_action;
    unsigned long httpparam_len_recvbuf;
    void (*httpparam_alloc)();
    void (*httpparam_free)();
    int httpparam_ignoreca;
    int httpparam_timeout;
};
#endif
