/*
 * function: gpiGetPeerByAddr
 * address:  0x0218F0E8
 * packet:   pkt_ov009_0218F0E8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gpiGetPeerByAddr (gpipeer.o)
 */

typedef unsigned int   u32;
typedef unsigned short u16;

struct GPIPeer_s {
    int  state;      /* +0x00 */
    int  initiated;  /* +0x04 */
    u32  ip;         /* +0x08 */
    u16  port;       /* +0x0c */
    u16  pad0e;      /* +0x0e */
    int  profile;    /* +0x10 */
    char pad14[0x4c - 0x14];
    struct GPIPeer_s *pnext; /* +0x4c */
};

typedef struct GPIConnection {
    char pad0[0x5d8];
    struct GPIPeer_s *peers;  /* +0x5d8 */
} GPIConnection;

struct GPIPeer_s *gpiGetPeerByAddr(void **connection, u32 ip, u16 port)
{
    GPIConnection *iconnection = (GPIConnection *)*connection;
    struct GPIPeer_s *pcurr;

    if (ip == 0 && port == 0)
        return 0;
    for (pcurr = iconnection->peers; pcurr != 0; pcurr = pcurr->pnext) {
        if (pcurr->ip == ip && pcurr->port == port)
            return pcurr;
    }
    return 0;
}
