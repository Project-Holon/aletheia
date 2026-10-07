#ifndef ALETHEIA_G_PMIGENCALLBACKINFO_H
#define ALETHEIA_G_PMIGENCALLBACKINFO_H
/* g_02732FAC (arm9) */
struct PMiGenCallbackInfo {
    void (*callback)(void *);
    void *arg;
    int priority;
    struct PMiGenCallbackInfo *next;
};
#endif
