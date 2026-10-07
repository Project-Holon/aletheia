#ifndef ALETHEIA_G_CRYPTOALLOCATORS_H
#define ALETHEIA_G_CRYPTOALLOCATORS_H
/* g_021D422C (arm9) */
struct CryptoAllocators {
    void (*free_fn)(void *);
    void * (*alloc_fn)(unsigned long);
};
#endif
