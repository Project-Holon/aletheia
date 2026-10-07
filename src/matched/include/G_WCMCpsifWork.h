#ifndef ALETHEIA_G_WCMCPSIFWORK_H
#define ALETHEIA_G_WCMCPSIFWORK_H
/* g_021AA7DC (arm9) */
struct WCMCpsifWork {
    unsigned char pad_0[0x28];
    void (*cb)(unsigned char *, unsigned char *, unsigned char *, long);
};
#endif
