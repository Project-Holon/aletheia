/*
 * file:     unit_0215FDA4_p17.c
 * unit:     yes
 * function: func_02162C28, func_02162CA0, func_02162DD8, func_02162E5C, func_02162E94, func_02162EC4
 * address:  0x02162C28
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02162AE4  0x02162AE4  arm  ov009
 *   MI_CpuCopy8    0x02082D44  arm
 *   func_021619CC  0x021619CC  arm  ov009
 *   func_0215B198  0x0215B198  arm  ov009
 *   g_021A8280     0x021A8280  data ov009
 *   g_021A82B0     0x021A82B0  data ov009
 *   CPSiFree  0x021A82B0  data
 *   OSi_ReferSymbol  0x02004EB0  arm
 *   id_string        0x020050F0  data
 *   OSi_ThreadInfo   0x02150FEC  data
 *   func_02087988  0x02087988  arm
 *   func_0208799C  0x0208799C  arm
 *   func_02085868  0x02085868  arm
 *   g_021AA664     0x021AA664  data
 *   g_02150FEC     0x02150FEC  data
 */
struct _CPSSoc_02162C28;
typedef struct CPSSslConnection {
    unsigned char pad0[0x455];
    unsigned char state;                /* +0x455 */
    unsigned char have_record;          /* +0x456 */
    unsigned char pad457[0x824 - 0x457];
    unsigned char *buf;                 /* +0x824 */
    unsigned long end;                  /* +0x828 */
    unsigned long pos;                  /* +0x82c */
} CPSSslConnection;

typedef struct CPSSoc_02162C28 {
    unsigned char pad0[8];
    unsigned char state;                /* +0x8 */
    unsigned char pad9[3];
    CPSSslConnection *con;              /* +0xc */
} CPSSoc_02162C28;

typedef struct CPSSoc_0215FDA4 {
    unsigned char pad[0xC];
    void *con;
} CPSSoc_0215FDA4;

typedef unsigned int   u32;

typedef unsigned char  u8;

struct _CPSSslConnection_02162C28 {
    char pad0[0x455];
    unsigned char f455;
    char pad1[0x824 - 0x455 - 1];
    void *f824;
};

struct _CPSSoc_02162C28 {
    char pad0[0xc];
    struct _CPSSslConnection_02162C28 *con;
};

typedef unsigned short u16;

typedef struct OSThread OSThread;

typedef struct OSThreadInfo {
    u16 isNeedRescheduling;
    u16 irqDepth;
    OSThread *current;
} OSThreadInfo;

struct CPSSslSession {
    unsigned char sessionID[32];
    unsigned char master_secret[48];
    unsigned long when;
    unsigned long ip;
    unsigned short port;
    unsigned char valid;
    unsigned char padding;
};

struct _CPSSslConnection_02162EC4 {
    char pad0[0x455];
    unsigned char state;
};

struct _CPSSoc_02162EC4 {
    struct _OSThread *thread;
    unsigned long block_type;
    unsigned char state;
    unsigned char ssl;
    char pad0[0xc - 0xa];
    void *con;
    unsigned long when;
};

struct _OSThread {
    char pad0[0x68];
    struct _OSThread *next;
    char pad1[0xa4 - 0x6c];
    void *specific[3];
};

struct OSiThreadInfo {
    char pad0[8];
    struct _OSThread *list;
};

extern void func_02162AE4(CPSSoc_02162C28 *soc);
extern int func_021619CC(void *con, unsigned char *s);
extern u32 func_0215B198(u8 *buf, u32 len, u8 *buf2, u32 len2, struct _CPSSoc_02162C28 *soc);
extern void MI_CpuCopy8(void *srcp, void *dstp, unsigned long size);
extern void OSi_ReferSymbol(const char *symbol);
void CPSi_SslClose(struct _CPSSoc_02162C28 *soc);
void CPS_SetSsl(int mode);
extern unsigned long func_02087988(void);
extern unsigned long func_0208799C(unsigned long state);
extern void func_02085868(struct _OSThread *thread);
long func_02162C28(CPSSoc_02162C28 *soc);
/* * sdk: CPSi_SslWrite2 (libssl.TWL.HYB.a ssl.o) * * Writes a two-part buffer as SSL application-data records of at most 2895 bytes; returns the bytes sent. */ unsigned long func_02162CA0(unsigned char *buf, unsigned long len, unsigned char *buf2, unsigned long len2, CPSSoc_0215FDA4 *soc);
/* * Flush a queued request when the object reached through +0xc is in state 8: * a 7-byte header is laid down on the stack, func_021619CC fills the rest of * the buffer and returns its length, and that buffer (plus the length) is * handed to func_0215B198 along with the two zero flags and this object. The * state byte is cleared either way. */ void func_02162DD8(void *p);
void func_02162EC4(unsigned long now);
extern OSThreadInfo OSi_ThreadInfo;
extern char id_string[];
extern struct CPSSslSession g_021AA664[4];
extern struct OSiThreadInfo g_02150FEC;




/*
 * sdk:      CPSi_SslGetLength (libssl.TWL.HYB.a(ssl.o))
 */
long func_02162C28(CPSSoc_02162C28 *soc)
{
    CPSSslConnection *con;

    con = soc->con;
    if (con->buf == 0 || con->have_record == 0)
        func_02162AE4(soc);
    if (con->buf != 0 && con->have_record != 0)
        return con->end - con->pos;
    if (con->buf == 0) {
        if (soc->state != 4 || con->state == 9)
            return -1;
    }
    return 0;
}





extern void *(*g_021A8280)(unsigned long size);




extern void (*g_021A82B0)(void *p);





/*
 * sdk:      CPSi_SslWrite2 (libssl.TWL.HYB.a ssl.o)
 *
 * Writes a two-part buffer as SSL application-data records of at most 2895 bytes; returns the bytes sent.
 */
unsigned long func_02162CA0(unsigned char *buf, unsigned long len, unsigned char *buf2, unsigned long len2, CPSSoc_0215FDA4 *soc)
{
    CPSSoc_0215FDA4 *con = (CPSSoc_0215FDA4 *)soc->con;
    unsigned char *tmp;
    long total_len;
    long part1_len;
    long this_len;
    long part2_len;
    long total_sent_len;
    long this_sent_len;
    total_sent_len = 0;
    total_len = len + len2;
    do {
        this_len = (total_len > 2895) ? 2895 : total_len;
        tmp = (unsigned char *)g_021A8280(this_len + 25);
        if (!tmp) break;
        part1_len = (len >= (unsigned long)this_len) ? this_len : len;
        part2_len = this_len - part1_len;
        MI_CpuCopy8(buf, tmp + 5, part1_len);
        buf += part1_len;
        len -= part1_len;
        MI_CpuCopy8(buf2, tmp + 5 + part1_len, part2_len);
        tmp[0] = 23;
        tmp[1] = 3;
        tmp[2] = 0;
        tmp[3] = this_len >> 8;
        buf2 += part2_len;
        tmp[4] = this_len;
        this_sent_len = func_021619CC(con, tmp);
        if (func_0215B198(tmp, this_sent_len, 0, 0, (struct _CPSSoc_02162C28 *)soc) < (unsigned long)this_sent_len) this_len = 0;
        g_021A82B0(tmp);
        total_sent_len += this_len;
        total_len -= this_len;
        if (total_len == 0) break;
    } while (this_len != 0);
    return total_sent_len;
}





/*
 * Flush a queued request when the object reached through +0xc is in state 8:
 * a 7-byte header is laid down on the stack, func_021619CC fills the rest of
 * the buffer and returns its length, and that buffer (plus the length) is
 * handed to func_0215B198 along with the two zero flags and this object.  The
 * state byte is cleared either way.
 */
void func_02162DD8(void *p)
{
    u8 *q;
    u8 buf[0x1c];

    q = *(u8 **)((u8 *)p + 0xc);
    if (q[0x455] == 8) {
        buf[0] = 0x15;
        buf[1] = 3;
        buf[2] = 0;
        buf[3] = 0;
        buf[4] = 2;
        buf[5] = 1;
        buf[6] = 0;
        func_0215B198(buf, func_021619CC(q, buf), 0, 0, p);
    }
    q[0x455] = 0;
}




extern void (*CPSiFree)(void *ptr);




void CPSi_SslClose(struct _CPSSoc_02162C28 *soc)
{
    struct _CPSSslConnection_02162C28 *con = soc->con;
    void *p;

    con->f455 = 0;
    p = con->f824;
    if (p != 0)
        CPSiFree(p);
    con->f824 = 0;
}


void CPS_SetSsl(int mode)
{
    struct _CPSSoc_02162C28 *soc;

    OSi_ReferSymbol(id_string);
    soc = *(struct _CPSSoc_02162C28 **)((char *)OSi_ThreadInfo.current + 0xa4);
    if (soc != 0)
        *(unsigned char *)((char *)soc + 9) = mode;
}


/*
 * sdk:      CPSi_SslPeriodical (ssl.o)
 */
void func_02162EC4(unsigned long now)
{
    int i;
    struct _CPSSoc_02162EC4 *soc;
    struct _OSThread *t;
    unsigned long enabled;

    enabled = func_02087988();
    for (i = 0; i < 4; i++) {
        struct CPSSslSession *p = &g_021AA664[i];
        if (p->valid && (long)(now - p->when) > 957)
            p->valid = 0;
    }
    func_0208799C(enabled);

    for (t = g_02150FEC.list; t != 0; t = t->next) {
        soc = (struct _CPSSoc_02162EC4 *)t->specific[0];
        if (soc && soc->thread && soc->ssl && soc->state == 4 &&
            ((struct _CPSSslConnection_02162EC4 *)soc->con)->state < 8 &&
            (long)(now - soc->when) > 239 && soc->block_type == 2) {
            soc->state = 0;
            soc->block_type = 0;
            func_02085868(soc->thread);
        }
    }
}
