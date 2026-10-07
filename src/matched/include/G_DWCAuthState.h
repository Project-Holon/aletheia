#ifndef ALETHEIA_G_DWCAUTHSTATE_H
#define ALETHEIA_G_DWCAUTHSTATE_H
/* g_021AB1A4 (arm9) */
struct DWCAuthState {
    int s_finished;
    int returnCode;
    int state;
    unsigned long long userid;
    unsigned long long tick;
};
#endif
