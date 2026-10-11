#ifndef OV009_CPS_TYPES_H
#define OV009_CPS_TYPES_H
/*
 * Shared libcps (network.o and friends) types for ov009 unit_021573C4.
 * One definition per object; every field sits at the offset the parts
 * used. g_021A826C is network.o's block of file statics, read through
 * one base: wfailed, ip_conflict, ipid, mymss, eport, pingseq,
 * CPSDhcpMode, cps, CPSMyMac, CPSDnsIp and the random context follow
 * each other from 0x021A826C to 0x021A82FC.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef unsigned long long u64;

struct _OSThread;
struct _CPSSoc;

typedef struct CPSSocBuf {
    u32 size;
    u8 *data;
} CPSSocBuf;

typedef struct CPSSocRcvBuf {
    u32 start;
    u32 len;
    u32 order;
} CPSSocRcvBuf;

struct _CPSSoc {
    struct _OSThread *thread;       /* 0x00 */
    u32 block_type;                 /* 0x04 */
    u8 state;                       /* 0x08 */
    u8 ssl;                         /* 0x09 */
    u16 local_port;                 /* 0x0A */
    void *con;                      /* 0x0C */
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
    int (*udpread_callback)(u8 *buf, u32 len, struct _CPSSoc *soc); /* 0x44 */
    CPSSocBuf rcvbuf;               /* 0x48 */
    u32 rcvbufp;                    /* 0x50 */
    CPSSocBuf sndbuf;               /* 0x54 */
    CPSSocBuf linbuf;               /* 0x5C */
    CPSSocBuf outbuf;               /* 0x64 */
    u32 outbufp;                    /* 0x6C */
    CPSSocRcvBuf chunks[4];         /* 0x70 */
};
typedef struct _CPSSoc CPSSoc;

struct _OSThread {
    u8 pad0[0x68];
    struct _OSThread *next;         /* 0x68 */
    u8 pad6c[0xA4 - 0x6C];
    struct _CPSSoc *specific[3];    /* 0xA4 */
    u8 padb0[0xC0 - 0xB0];
};
typedef struct _OSThread OSThread;

struct OSThreadInfo {
    u16 isNeedRescheduling;         /* 0x00 */
    u16 irqDepth;                   /* 0x02 */
    OSThread *current;              /* 0x04 */
    OSThread *list;                 /* 0x08 */
};

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
    u8 pad24[0x2C - 0x24];
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

extern struct CPSNetVars g_021A826C;
extern struct _OSThread g_021A8524;
extern struct _OSThread g_021A85E4;
extern struct _OSThread g_021A86A4;
extern struct OSThreadInfo g_02150FEC;

#endif
