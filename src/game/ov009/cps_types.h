#ifndef OV009_CPS_TYPES_H
#define OV009_CPS_TYPES_H
/*
 * Shared libcps (network.o and friends) types for ov009 cps_network.
 * One definition per object; every field sits at the offset the parts
 * used. gCpsNetVars is network.o's block of file statics, read through
 * one base: wfailed, ip_conflict, ipid, mymss, eport, pingseq,
 * CPSDhcpMode, cps, CPSMyMac, CPSDnsIp and the random context follow
 * each other from 0x021A826C to 0x021A82FC.
 */

#include "../types.h"

#include "../sdk_os.h"
#include "../arm9/os_thread.h"

struct CPSSoc;
struct CPSSslConnection;

typedef struct CPSSocBuf {
    u32 size;
    u8 *data;
} CPSSocBuf;

typedef struct CPSSocRcvBuf {
    u32 start;
    u32 len;
    u32 order;
} CPSSocRcvBuf;

struct CPSSoc {
    struct _OSThread *thread;       /* 0x00 */
    u32 block_type;                 /* 0x04 */
    u8 state;                       /* 0x08 */
    u8 ssl;                         /* 0x09 */
    u16 local_port;                 /* 0x0A */
    struct CPSSslConnection *con;  /* 0x0C */
    u32 when;                       /* 0x10 */
    u32 local_ip_real;              /* 0x14 */
    u16 remote_port;                /* 0x18 */
    u16 remote_port_bound;          /* 0x1A */
    u32 remote_ip;                  /* 0x1C */
    u32 remote_ip_bound;            /* 0x20 */
    u32 ackno;                      /* 0x24 */
    u32 ackno_sent;                 /* 0x28 */
    u32 tick_acked;                 /* 0x2C */
    u16 win_sent;                   /* 0x30 */
    u8 ack_pending;                 /* 0x32 */
    u8 sack_enabled;                /* 0x33 */
    u32 seqno;                      /* 0x34 */
    u16 remote_win;                 /* 0x38 */
    u16 remote_mss;                 /* 0x3A */
    u32 remote_ackno;               /* 0x3C */
    u32 ackrcvd;                    /* 0x40 */
    int (*udpread_callback)(u8 *buf, u32 len, struct CPSSoc *soc); /* 0x44 */
    CPSSocBuf rcvbuf;               /* 0x48 */
    u32 rcvbufp;                    /* 0x50 */
    CPSSocBuf sndbuf;               /* 0x54 */
    CPSSocBuf linbuf;               /* 0x5C */
    CPSSocBuf outbuf;               /* 0x64 */
    u32 outbufp;                    /* 0x6C */
    CPSSocRcvBuf chunks[4];         /* 0x70 */
};
typedef struct CPSSoc CPSSoc;

typedef struct CPSConfig {
    u32 mode;
    void *(*alloc)(u32);
    void (*free)(void *);
    void (*dhcp_callback)(void);
    int (*link_is_on)(void);
    u64 random_seed;
    u8 *lan_buf;
    u32 lan_buflen;
    u32 mymss;
    u32 requested_ip;
    u32 yield_wait;
} CPSConfig;

extern CPSConfig SOCLiCPSConfig;

struct CPSNetVars {
    u8 wfailed;                     /* 0x00 */
    u8 ip_conflict;                 /* 0x01 */
    u16 ipid;                       /* 0x02 */
    u16 mymss;                      /* 0x04 */
    u16 eport;                      /* 0x06 */
    u32 pingseq;                    /* 0x08 */
    u32 mode;                       /* 0x0C */
    u32 netmask;                    /* 0x10 */
    void *(*alloc)(u32);            /* 0x14 */
    int (*link_is_on)(void);        /* 0x18 */
    u32 dhcp_server_ip;             /* 0x1C */
    u8 *buf;                        /* 0x20 */
    u8 pad24[0x28 - 0x24];
    void (*fixed_ip_hook)(void);    /* 0x28 */
    u32 gateway_ip;                 /* 0x2C */
    u32 xid;                        /* 0x30 */
    void (*periodic)(void);         /* 0x34 */
    u32 offered_myip;               /* 0x38 */
    u32 lease_time;                 /* 0x3C */
    u32 lease_sleep;                /* 0x40 */
    void (*free)(void *);           /* 0x44 */
    int (*dhcp_callback)(void);     /* 0x48 */
    u32 dhcp_state;                 /* 0x4C */
    u32 myip;                       /* 0x50 */
    void *thread;                   /* 0x54 */
    u32 calm;                       /* 0x58 */
    volatile u32 bufsize;           /* 0x5C */
    volatile u32 putpnt;            /* 0x60 */
    volatile u32 getpnt;            /* 0x64 */
    u8 mac[8];                      /* 0x68 */
    u32 dns[2];                     /* 0x70 */
    u64 rand_state;                 /* 0x78 */
    u64 rand_mult;                  /* 0x80 */
    u64 rand_inc;                   /* 0x88 */
};

#ifndef ALETHEIA_G_CPSFRAGTABLE_H
#define ALETHEIA_G_CPSFRAGTABLE_H
/* gCpsFragTable: IP reassembly table, 8 slots */
struct CPSFragTable {
    u32 ipfrom;
    u16 count;
    u16 id;
    u16 last;
    u16 size;
    u16 from[8];
    u16 end[8];
    u32 time;
    u8 *data;
    u8 *buf;
};
#endif
typedef struct CPSFragTable CPSFragTable;

extern struct CPSNetVars gCpsNetVars;
extern struct CPSFragTable gCpsFragTable[8];
extern struct _OSThread gCpsDackTimerThread;
extern struct _OSThread gCpsScavengerThread;
extern struct _OSThread gCpsTcpipThread;

#endif
