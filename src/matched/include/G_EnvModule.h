#ifndef ALETHEIA_G_ENVMODULE_H
#define ALETHEIA_G_ENVMODULE_H
/* g_EnvModule (arm9) */
struct EnvEntry;
struct EnvModule {
    struct EnvEntry *entries;
    unsigned char *ids;
    unsigned short count;
    unsigned short resCount;
    unsigned short entryCount;
    unsigned short error;
};
#endif
