/*
 * function: func_0218D644
 * address:  0x0218D644
 * packet:   pkt_ov009_0218D644
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gpiSetInfoCache (gpiinfo.o)
 *
 * symbols:
 *   func_0218D71C  0x0218D71C  arm   ov009
 *   func_0217EAB0  0x0217EAB0  arm   ov009
 *   goastrdup  0x0217F1E0  arm   ov009
 */

typedef struct GPIInfoCache {
    char *s0;
    char *s4;
    char *s8;
    char *sC;
    char *s10;
    char *s14;
    unsigned char pad[0xC8 - 0x18];
    char *sC8;
    unsigned char pad2[0xF0 - 0xCC];
} GPIInfoCache;

typedef struct GPIProfile {
    unsigned char pad[0x10];
    GPIInfoCache *cache;
} GPIProfile;

typedef struct GPIConnection {
    unsigned char pad[0x100];
    int f100;
} GPIConnection;

extern void func_0218D71C(GPIProfile *profile);
extern void *func_0217EAB0(unsigned long size);
extern char *goastrdup(char *src);

int func_0218D644(void **connection, GPIProfile *profile, GPIInfoCache *cache)
{
    if (((GPIConnection *)*connection)->f100 == 0)
        return 1;
    func_0218D71C(profile);
    profile->cache = func_0217EAB0(sizeof(GPIInfoCache));
    if (profile->cache != 0) {
        *profile->cache = *cache;
        profile->cache->s0 = goastrdup(cache->s0);
        profile->cache->s4 = goastrdup(cache->s4);
        profile->cache->s8 = goastrdup(cache->s8);
        profile->cache->sC = goastrdup(cache->sC);
        profile->cache->s10 = goastrdup(cache->s10);
        profile->cache->s14 = goastrdup(cache->s14);
        profile->cache->sC8 = goastrdup(cache->sC8);
    }
    return profile->cache != 0;
}
