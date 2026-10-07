#ifndef ALETHEIA_G_OSIRQCALLBACKINFO_H
#define ALETHEIA_G_OSIRQCALLBACKINFO_H
/* g_02150F38 (arm9) */
struct OSIrqCallbackInfo {
    void (*func)(void *);
    unsigned int enable;
    void *arg;
};
#endif
