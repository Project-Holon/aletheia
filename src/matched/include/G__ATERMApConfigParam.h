#ifndef ALETHEIA_G__ATERMAPCONFIGPARAM_H
#define ALETHEIA_G__ATERMAPCONFIGPARAM_H
/* g_021DD13C (arm9) */
struct _ATERMApConfigParam {
    char ssid[32];
    int auth_mode;
    int wepkeyid;
    char wepkey[4][32];
    char wpakey[64];
};
#endif
