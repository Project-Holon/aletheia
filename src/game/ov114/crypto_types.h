#ifndef OV114_CRYPTO_TYPES_H
#define OV114_CRYPTO_TYPES_H
/* Big number types of the embedded crypto library (libcrypto, OpenSSL style): bobj1, bobj2, sign, util. */

#ifndef OV114_BASIC_TYPES
#define OV114_BASIC_TYPES
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
#endif

#define BN_BITS2 32

/* BIGNUM.flags */
#define BN_FLG_MALLOCED    0x0001
#define BN_FLG_STATIC_DATA 0x0002
#define BN_FLG_FREE        0x8000

typedef unsigned long BN_ULONG;

typedef struct bignum_st {
    BN_ULONG *d;
    int top;
    int dmax;
    int neg;
    int flags;
} BIGNUM;

typedef struct r_surrender_st {
    int (*callback)(struct r_surrender_st *, int, int);
    char *arg;
} R_SURRENDER;

typedef struct bignum_ctx {
    int tos;
    BIGNUM bn[13];
    int flags;
    R_SURRENDER *surrender;
} BN_CTX;

typedef struct bn_mont_ctx_st {
    int use_word;
    int unused;
    int ri;
    BIGNUM RR;
    BIGNUM N;
    BIGNUM Ni;
    BN_ULONG n0;
    int flags;
} BN_MONT_CTX;

typedef struct bn_recp_ctx_st {
    BIGNUM N;
    BIGNUM Nr;
    int num_bits;
    int shift;
    int flags;
} BN_RECP_CTX;

/* Allocator hooks of the library (crypto_util.c). */
typedef struct CRYPTOAllocators {
    void (*freeFunc)(void *);
    void *(*allocFunc)(unsigned long);
    void *(*reallocFunc)(void *, unsigned long);
} CRYPTOAllocators;

extern CRYPTOAllocators gCryptoAllocators;

#endif
