#ifndef ALETHEIA_G_CPSSSLSESSION_H
#define ALETHEIA_G_CPSSSLSESSION_H
/* g_021AA664 (arm9) */
struct CPSSslSession {
    unsigned char id[32];
    unsigned char master[48];
    unsigned long last_used;
    unsigned long ip;
    unsigned short port;
    unsigned char valid;
    unsigned char pad5b;
};
#endif
