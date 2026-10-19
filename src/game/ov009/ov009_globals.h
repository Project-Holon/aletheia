#ifndef ALETHEIA_OV009_GLOBALS_H
#define ALETHEIA_OV009_GLOBALS_H
/*
 * Types for the ov009 data-section globals that more than one object reads.
 * One definition per object; offsets taken from the views the parts used.
 */

/* SOCLi_Resource: the SOCL socket counters, one per stream and one per datagram
 * socket, decremented as sockets close. */
typedef struct SoclResource {
    int streamCount;                    /* 0x00 */
    int datagramCount;                  /* 0x04 */
} SoclResource;

/* SOCLiCPSConfig: the CPS configuration object. Only bufSize (mymss) and the word at
 * 0x1c (lan_buf) are read. */
typedef struct CpsConfig {
    unsigned long mode;                 /* 0x00 */
    void *alloc;                        /* 0x04 */
    void *free;                         /* 0x08 */
    void *dhcp_callback;                /* 0x0c */
    void *link_is_on;                   /* 0x10 */
    unsigned long random_seed[2];       /* 0x14 */
    unsigned long lan_buf;              /* 0x1c */
    unsigned long lan_buflen;           /* 0x20 */
    int bufSize;                        /* 0x24 (CPSConfig.mymss) */
} CpsConfig;

/* g_021A5A7C / gNatNegMagic: the six-byte NAT negotiation magic. */
typedef struct NatNegMagic {
    unsigned char bytes[6];
} NatNegMagic;

#endif
