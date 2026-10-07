#ifndef ALETHEIA_G_DWCAUTHPARAM_H
#define ALETHEIA_G_DWCAUTHPARAM_H
/* g_021AB1C0 (arm9) */
struct DWCAuthParam {
    unsigned char ingamesn[52];
    unsigned char gsbrcd[12];
    void * (*allocator)(unsigned long, long);
    void (*deallocator)(unsigned long, void *, long);
};
#endif
