/*
 * function: func_02162418
 * address:  0x02162418
 * packet:   pkt_ov009_02162418
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      send_client_hello (libssl.TWL.HYB.a(ssl.o))
 *
 * symbols:
 *   func_0216003C  0x0216003C  arm  ov009
 *   func_02162128  0x02162128  arm  ov009
 *   MI_CpuCopy8    0x02082D44  arm
 *   func_0215FE3C  0x0215FE3C  arm  ov009
 *   func_0215B198  0x0215B198  arm  ov009
 *   func_02161C54  0x02161C54  arm  ov009
 *   g_021A8280     0x021A8280  data
 *   g_021A1D40     0x021A1D40  data
 *   g_021A82B0     0x021A82B0  data
 */

#define NELEMS(a) (sizeof(a) / sizeof((a)[0]))

typedef struct CPSSoc {
    unsigned char pad0[0xC];
    struct CPSSslConnection *con;
    unsigned char pad10[0x18 - 0x10];
    unsigned short remote_port;     /* +0x18 */
    unsigned long remote_ip;        /* +0x1c */
} CPSSoc;

typedef struct CPSSslConnection {
    unsigned char pad0[0x30];
    unsigned char session_id_len;   /* +0x30 */
    unsigned char pad31[3];
    unsigned char client_random[32];/* +0x34 */
    unsigned char pad54[0x74 - 0x54];
    unsigned char session_id[32];   /* +0x74 */
    unsigned char pad94[0x455 - 0x94];
    unsigned char state;            /* +0x455 */
} CPSSslConnection;

extern unsigned char *(*g_021A8280)(unsigned long size);
extern void (*g_021A82B0)(void *p);
extern unsigned short g_021A1D40[2];

extern unsigned long func_0216003C(void);
extern void func_02162128(unsigned char *d, int len);
extern void MI_CpuCopy8(void *srcp, void *dstp, unsigned long size);
extern void func_0215FE3C(CPSSslConnection *con, unsigned long ip, unsigned short port);
typedef unsigned int   u32;
typedef unsigned char  u8;
struct _CPSSoc;
extern u32 func_0215B198(u8 *buf, u32 len, u8 *buf2, u32 len2, struct _CPSSoc *soc);
extern void func_02161C54(CPSSslConnection *con, unsigned char *s, unsigned long len);

static void func_02162418(CPSSoc *soc)
{
    CPSSslConnection *con = soc->con;
    unsigned long sec;
    unsigned char *buf;
    unsigned char *d;
    int i;

    buf = g_021A8280(0x98);
    if (buf == 0) {
        con->state = 9;
        return;
    }
    buf[9] = 3;
    buf[10] = 0;
    sec = func_0216003C();
    con->client_random[0] = sec >> 24;
    con->client_random[1] = sec >> 16;
    con->client_random[2] = sec >> 8;
    con->client_random[3] = sec;
    func_02162128(con->client_random + 4, 28);
    MI_CpuCopy8(con->client_random, buf + 11, 32);
    func_0215FE3C(con, soc->remote_ip, soc->remote_port);
    if (con->session_id_len == 0) {
        buf[43] = 0;
        d = buf + 44;
    } else {
        buf[43] = 32;
        MI_CpuCopy8(con->session_id, buf + 44, 32);
        d = buf + 76;
    }
    d[0] = 0;
    d[1] = 4;
    d += 2;
    for (i = 0; i < NELEMS(g_021A1D40); i++) {
        d[0] = g_021A1D40[i] >> 8;
        d[1] = g_021A1D40[i];
        d += 2;
    }
    d[0] = 1;
    d[1] = 0;
    d += 2;
    i = d - buf - 5;
    buf[0] = 22;
    buf[1] = 3;
    buf[2] = 0;
    buf[3] = i >> 8;
    buf[4] = i;
    buf[5] = 1;
    buf[6] = (i - 4) >> 16;
    buf[7] = (i - 4) >> 8;
    buf[8] = i - 4;
    func_0215B198(buf, i + 5, 0, 0, (struct _CPSSoc *)soc);
    func_02161C54(con, buf + 5, i);
    g_021A82B0(buf);
}
