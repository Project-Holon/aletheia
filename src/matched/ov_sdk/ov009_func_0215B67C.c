/*
 * function: func_0215B67C
 * address:  0x0215B67C
 * packet:   pkt_ov009_0215B67C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      scavenger (libcps.TWL.HYB.a network.o, static)
 *
 * symbols:
 *   MI_CpuFill8  0x02082BCC  arm
 *   func_0215AA5C  0x0215AA5C  arm  ov009
 *   func_02085A38  0x02085A38  arm
 *   func_020870D0  0x020870D0  arm
 *   func_0215B644  0x0215B644  arm  ov009
 *   func_0215C2F8  0x0215C2F8  arm  ov009
 *   func_0215C350  0x0215C350  arm  ov009
 *   func_02157290  0x02157290  arm  ov009
 *   func_0215B5C4  0x0215B5C4  arm  ov009
 *   func_02157E54  0x02157E54  arm  ov009
 *   func_02085868  0x02085868  arm
 *   func_02162EC4  0x02162EC4  arm  ov009
 *   func_0215C44C  0x0215C44C  arm  ov009
 *   func_0215AA70  0x0215AA70  arm  ov009
 *   g_021A83E4     0x021A83E4  data
 *   g_021A826C     0x021A826C  data
 *   g_021A88E4     0x021A88E4  data
 *   g_021A8764     0x021A8764  data
 *   g_021A8384     0x021A8384  data
 *   g_02150FEC     0x02150FEC  data
 *   g_021A8A64     0x021A8A64  data
 *
 * g_021A826C is network.o's block of file statics (first symbol wfailed);
 * the fields below are named by the offsets this function touches.
 *
 * Case 0 spells the callback test out with a flag; cases 1 and 2 use the
 * ternary helper. The object compiles the two shapes differently.
 */

#include "../include/G_ArpEntry.h"
#include "../include/G_CPSFragTable.h"

typedef struct CPSSocBuf {
    unsigned long size;
    unsigned char *data;
} CPSSocBuf;

struct _OSThread;

typedef struct _CPSSoc {
    struct _OSThread *thread;         /* 0x00 */
    unsigned long block_type;         /* 0x04 */
    unsigned char state;              /* 0x08 */
    unsigned char ssl;                /* 0x09 */
    unsigned short local_port;        /* 0x0A */
    void *con;                        /* 0x0C */
    unsigned long when;               /* 0x10 */
    unsigned long local_ip_real;      /* 0x14 */
    unsigned short remote_port;       /* 0x18 */
    unsigned short remote_port_bound; /* 0x1A */
    unsigned long remote_ip;          /* 0x1C */
    unsigned long remote_ip_bound;    /* 0x20 */
    char pad24[0x48 - 0x24];
    CPSSocBuf rcvbuf;                 /* 0x48 */
    unsigned long rcvbufp;            /* 0x50 */
    CPSSocBuf sndbuf;                 /* 0x54 */
    char pad5c[0xA0 - 0x5C];
} CPSSoc;

typedef struct _OSThread {
    char pad0[0x68];
    struct _OSThread *next;           /* 0x68 */
    char pad6c[0xA4 - 0x6C];
    void *specific[3];                /* 0xA4 */
    char padb0[0xC0 - 0xB0];
} OSThread;

typedef struct {
    unsigned long ip;
    unsigned char mac[6];
    unsigned short when;
} CPSArpCache;

typedef struct {
    unsigned long ipfrom;
    unsigned short frags;
    unsigned short id;
    unsigned short last;
    unsigned short size;
    unsigned short from[8];
    unsigned short to[8];
    unsigned long when;
    unsigned char *ofs0;
    unsigned char *buf;
} CPSFragTable;

struct net_vars {
    char pad0[0x0C];
    unsigned long mode;               /* 0x0C */
    char pad10[0x18 - 0x10];
    int (*link_is_on)(void);          /* 0x18 */
    char pad1c[0x2C - 0x1C];
    unsigned long gateway_ip;         /* 0x2C */
    char pad30[0x34 - 0x30];
    void (*periodic)(void);           /* 0x34 */
    char pad38[0x44 - 0x38];
    void (*free)(void *);             /* 0x44 */
    int (*dhcp_callback)(void);       /* 0x48 */
    unsigned long state;              /* 0x4C */
    char pad50[0x58 - 0x50];
    unsigned long calm;               /* 0x58 */
};

struct thread_info {
    char pad0[8];
    OSThread *list;                   /* 0x08 */
};

extern CPSSoc g_021A83E4;
extern struct net_vars g_021A826C;
extern unsigned char g_021A88E4[384];
extern unsigned char g_021A8764[384];
extern struct ArpEntry g_021A8384[8];
extern struct thread_info g_02150FEC;
extern struct CPSFragTable g_021A8A64[8];

extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);
extern void func_0215AA5C(int v);
extern void func_02085A38(unsigned long msec);
extern unsigned long long func_020870D0(void);
extern void func_0215B644(void);
extern int func_0215C2F8(void);
extern int func_0215C350(unsigned long *sleep, int mode);
extern void func_02157290(int reason);
extern int func_0215B5C4(void);
extern void func_02157E54(unsigned long ip);
extern void func_02085868(OSThread *thread);
extern void func_02162EC4(unsigned long now);
extern void func_0215C44C(void);
extern void func_0215AA70(void);

static inline int dhcp_denied(void)
{
    return g_021A826C.dhcp_callback ? g_021A826C.dhcp_callback() == 0 : 0;
}

void func_0215B67C(void)
{
    int i;
    int dhcp_state;
    unsigned long dhcp_sleep;
    unsigned long gwcache_sleep;
    int first;
    CPSSoc *soc;
    OSThread *t;
    CPSArpCache *arp;
    unsigned long now;
    int denied;

    dhcp_state = 0;
    g_021A826C.calm = 0;
    MI_CpuFill8(&g_021A83E4, 0, sizeof(CPSSoc));
    g_021A83E4.rcvbuf.size = sizeof(g_021A88E4);
    g_021A83E4.rcvbuf.data = g_021A88E4;
    g_021A83E4.sndbuf.size = sizeof(g_021A8764);
    g_021A83E4.sndbuf.data = g_021A8764;
    func_0215AA5C((int)(&g_021A83E4));
    gwcache_sleep = 1;
    dhcp_sleep = 1;
    first = 1;
    g_021A826C.state = 1;

    for (;;)
    {
        func_02085A38(1000);
        if (g_021A826C.calm)
            break;
        now = (unsigned long)(func_020870D0() >> 16);

        if (g_021A826C.link_is_on())
        {
            if (--dhcp_sleep == 0)
            {
                if (g_021A826C.mode & 1)
                {
                    if (dhcp_state == 0)
                    {
                        func_0215B644();
                        dhcp_state = 1;
                    }
                }
                else
                {
                    switch (dhcp_state)
                    {
                    case 0:
                        if (first)
                        {
                            g_021A826C.state = 2;
                            first = 0;
                        }
                        if (!func_0215C2F8() || !func_0215C350(&dhcp_sleep, 0))
                        {
                            func_0215B644();
                            dhcp_state = 3;
                        }
                        else
                        {
                            denied = 0;
                            if (g_021A826C.dhcp_callback)
                            {
                                if (g_021A826C.dhcp_callback() == 0)
                                    denied = 1;
                            }
                            if (denied)
                            {
                                func_02157290(5);
                                func_0215B644();
                                dhcp_state = 3;
                            }
                            else
                            {
                                dhcp_state = 1;
                                if (!func_0215B5C4())
                                {
                                    func_02157290(4);
                                    dhcp_state = 3;
                                }
                            }
                        }
                        break;
                    case 1:
                        if (!func_0215C350(&dhcp_sleep, 1) && dhcp_sleep < 60)
                        {
                            dhcp_state = 2;
                        }
                        else if (dhcp_denied())
                        {
                            func_02157290(5);
                            func_0215B644();
                            dhcp_state = 3;
                        }
                        else if (!func_0215B5C4())
                        {
                            func_02157290(4);
                            dhcp_state = 3;
                        }
                        break;
                    case 2:
                        if (func_0215C350(&dhcp_sleep, 2))
                        {
                            if (dhcp_denied())
                            {
                                func_02157290(5);
                                func_0215B644();
                                dhcp_state = 3;
                            }
                            else
                            {
                                dhcp_state = 1;
                                if (!func_0215B5C4())
                                {
                                    func_02157290(4);
                                    dhcp_state = 3;
                                }
                            }
                        }
                        else if (dhcp_sleep < 60)
                        {
                            func_02157290(3);
                            gwcache_sleep = 1;
                            dhcp_sleep = 1;
                            dhcp_state = 0;
                        }
                        break;
                    case 3:
                        break;
                    }
                }
            }
        }
        else
        {
            gwcache_sleep = 1;
            func_02157290(1);
            dhcp_sleep = 1;
            dhcp_state = 0;
        }

        for (i = 0; i < 8; i++)
        {
            arp = &((CPSArpCache *)g_021A8384)[i];
            if (arp->ip && (short)(now - arp->when) > 957)
                arp->ip = 0;
        }

        if (g_021A826C.gateway_ip && --gwcache_sleep == 0)
        {
            func_02157E54(g_021A826C.gateway_ip);
            gwcache_sleep = 105;
        }

        for (t = g_02150FEC.list; t; t = t->next)
        {
            soc = (CPSSoc *)t->specific[0];
            if (soc && soc->thread)
            {
                if (soc->state == 3 && (long)(now - soc->when) > 39)
                {
                    soc->state = 1;
                    soc->remote_port = soc->remote_port_bound;
                    soc->remote_ip = soc->remote_ip_bound;
                }
                else if (soc->state == 2 && (long)(now - soc->when) > 39)
                {
                    if (soc->block_type == 1)
                    {
                        soc->state = 0;
                        soc->block_type = 0;
                        func_02085868(soc->thread);
                    }
                }
                else if (soc->state != 4 && soc->block_type == 2)
                {
                    soc->block_type = 0;
                    func_02085868(soc->thread);
                }
            }
        }

        for (i = 0; i < 8; i++)
        {
            CPSFragTable *f = &((CPSFragTable *)g_021A8A64)[i];
            if (f->frags && (long)(now - f->when) > 239)
            {
                g_021A826C.free(f->buf);
                f->frags = 0;
            }
        }

        func_02162EC4(now);
        if (g_021A826C.periodic)
            g_021A826C.periodic();
    }

    if (!(g_021A826C.mode & 1) && dhcp_state != 3)
        func_0215C44C();
    func_0215AA70();
}
