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

/* g_021A5A7C / gNatNegMagic: the six-byte NAT negotiation magic. */
typedef struct NatNegMagic {
    unsigned char bytes[6];
} NatNegMagic;

#endif
