#ifndef ALETHEIA_G_AOSSLINK_BSS_H
#define ALETHEIA_G_AOSSLINK_BSS_H
/* aosslink_bss (arm9) */
struct AOSSLINK_BSS {
    void * (*AOSSi_Alloc)(unsigned long);
    void (*aoss_callback)(int);
    void *aoss_workbuffer;
    void (*AOSSi_Free)(void *);
};
#endif
