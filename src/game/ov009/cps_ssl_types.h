#ifndef OV009_CPS_SSL_TYPES_H
#define OV009_CPS_SSL_TYPES_H
/*
 * Shared CPS SSL types for ov009 ssl. One definition per object,
 * offsets checked against every view the parts had.
 */

#include "../types.h"

#include "../sdk_os.h"
#include "../ov009/cps_types.h"

#include "../sdk_rtc.h"

struct CPSSslSession {
    unsigned char id[32];
    unsigned char master[48];
    unsigned long last_used;
    unsigned long ip;
    unsigned short port;
    unsigned char valid;
    unsigned char pad5b;
};
typedef struct CPSSslSession CPSSslSession;

typedef struct SOCLCaInfo {
    char *dn;
    int modulo_len;
    unsigned char *modulo;
    int exponent_len;
    unsigned char *exponent;
} SOCLCaInfo;

typedef struct CPSPrivateKey {
    int size;
    unsigned char *p0;
    int l1;
    unsigned char *p1;
    int l2;
    unsigned char *p2;
    int l3;
    unsigned char *p3;
    int l4;
    unsigned char *p4;
    int l5;
    unsigned char *p5;
} CPSPrivateKey;

/* SHA1/MD5 running contexts (md5.o, sha1.o). 92 and 88 bytes. */
typedef struct CPSSha1Ctx {
    u32 state[5];                         /* 0x00 */
    u32 count[2];                         /* 0x14 */
    unsigned char buffer[64];             /* 0x1C */
} CPSSha1Ctx;

typedef struct CPSMd5Ctx {
    u32 state[4];                         /* 0x00 */
    u32 count[2];                         /* 0x10 */
    unsigned char buffer[64];             /* 0x18 */
} CPSMd5Ctx;

typedef struct CPSRc4Ctx {
    unsigned char x;
    unsigned char y;
    unsigned char m[256];
} CPSRc4Ctx;

typedef union CPSCipherCtx {
    CPSRc4Ctx rc4;
    unsigned char b[0x104];
} CPSCipherCtx;

typedef struct {
    u64 x;
    u64 a;
    u64 c;
} Rand32Ctx;

typedef struct CPSSslConnection CPSSslConnection;

struct CPSSslConnection {
    unsigned char master_secret[48];      /* 0x000 */
    unsigned char cache;                  /* 0x030 */
    unsigned char resumed;                /* 0x031 */
    unsigned short method;                /* 0x032 */
    unsigned char client_random[32];      /* 0x034 */
    unsigned char server_random[32];      /* 0x054 */
    union {
        unsigned char session_id[0x20];
        unsigned char key_block[72];
    } common1;                            /* 0x074 */
    unsigned char *send_mac;              /* 0x0bc */
    unsigned char *send_key;              /* 0x0c0 */
    unsigned char *send_iv;               /* 0x0c4 */
    CPSCipherCtx send_cipher;             /* 0x0c8 */
    unsigned char send_seq[8];            /* 0x1cc */
    unsigned char *rcv_mac;               /* 0x1d4 */
    unsigned char *rcv_key;               /* 0x1d8 */
    unsigned char *rcv_iv;                /* 0x1dc */
    CPSCipherCtx rcv_cipher;              /* 0x1e0 */
    unsigned char rcv_seq[8];             /* 0x2e4 */
    CPSSha1Ctx sha1_hash;                 /* 0x2ec */
    CPSSha1Ctx sha1_hash_tmp;             /* 0x348 */
    CPSMd5Ctx md5_hash;                   /* 0x3a4 */
    CPSMd5Ctx md5_hash_tmp;               /* 0x3fc */
    unsigned char server;                 /* 0x454 */
    unsigned char state;                  /* 0x455 */
    unsigned char have_record;            /* 0x456 */
    unsigned char pad457;                 /* 0x457 */
    int hash_type;                        /* 0x458 */
    int pubkeyAlgo;                             /* 0x45c */
    unsigned char *cert_start;            /* 0x460 */
    unsigned char *cert_end;              /* 0x464 */
    unsigned char hash[0x14];             /* 0x468 */
    int hash_len;                         /* 0x47c */
    SOCLCaInfo ca;                        /* 0x480 */
    unsigned char modulus[0x100];         /* 0x494 */
    int modlen;                           /* 0x594 */
    unsigned char pubexp[8];              /* 0x598 */
    int pubexplen;                        /* 0x5a0 */
    unsigned char *sig;                   /* 0x5a4 */
    int sig_len;                          /* 0x5a8 */
    unsigned char subjectPhase;                   /* 0x5ac */
    unsigned char keyInfoOid;                   /* 0x5ad */
    unsigned char cnOid;                   /* 0x5ae */
    unsigned char dateValid;                   /* 0x5af */
    char dn[0x100];                       /* 0x5b0 */
    unsigned char subjectDn[0x100];            /* 0x6b0 */
    unsigned char commonName[0x50];             /* 0x7b0 */
    char *hostName;                           /* 0x800 */
    unsigned char *certData;                  /* 0x804 */
    int certLen;                             /* 0x808 */
    int currentDate;                             /* 0x80c */
    int (*f810)(int result, CPSSslConnection *con, int level);  /* 0x810 */
    SOCLCaInfo **rootCa;                  /* 0x814 */
    int rootCaNum;                        /* 0x818 */
    CPSPrivateKey *privkey;               /* 0x81c */
    unsigned char pad820[4];              /* 0x820 */
    unsigned char *buf;                   /* 0x824 */
    unsigned long end;                    /* 0x828 */
    unsigned long pos;                    /* 0x82c */
};

/* gCpsSslConfig: the supported cipher methods and the handshake priority */
typedef struct CPSSslConfig {
    unsigned short methods[2];            /* 0x0 */
    unsigned long priority;               /* 0x4 */
} CPSSslConfig;

extern CPSSslConfig gCpsSslConfig;
extern void *(*CPSiAlloc)(unsigned long size);   /* 0x021A8280 */
extern void (*CPSiFree)(void *ptr);              /* 0x021A82B0 */

#endif
