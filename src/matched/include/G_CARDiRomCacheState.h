#ifndef ALETHEIA_G_CARDIROMCACHESTATE_H
#define ALETHEIA_G_CARDIROMCACHESTATE_H
/* CARDiEnableCacheInvalidationDC (arm9) */
struct CARDiRomCacheState {
    int enable_dc_invalidation;
    unsigned int cached_page;
};
#endif
