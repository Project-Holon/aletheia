/*
 * function: func_0215FDA4
 * address:  0x0215FDA4
 * packet:   pkt_ov009_0215FDA4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      find_session_from_id (libssl.TWL.HYB.a(ssl.o))
 *
 * symbols:
 *   OS_DisableInterrupts  0x02087988  arm
 *   func_020923F0  0x020923F0  arm
 *   MI_CpuCopy8  0x02082D44  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   gCpsSslSessionCache  0x021AA664  data
 */

typedef struct CPSSslSession {
    unsigned char id[0x20];
    unsigned char master[0x30];         /* +0x20 */
    unsigned long field_50;
    unsigned long ip;                   /* +0x54 */
    unsigned short port;                /* +0x58 */
    unsigned char valid;                /* +0x5a */
    unsigned char pad5b;
} CPSSslSession;

typedef struct CPSSslConnection {
    unsigned char master[0x30];
    unsigned char cache;                /* +0x30 */
    unsigned char pad31[0x74 - 0x31];
    unsigned char session_id[0x20];     /* +0x74 */
} CPSSslConnection;

extern CPSSslSession gCpsSslSessionCache[4];

extern unsigned long OS_DisableInterrupts(void);
typedef unsigned char  u8;
extern int func_020923F0(const u8 *a, const u8 *b, int n);
extern void MI_CpuCopy8(void *srcp, void *dstp, unsigned long size);
extern unsigned long OS_RestoreInterrupts(unsigned long state);

static void func_0215FDA4(CPSSslConnection *con)
{
    int i;
    CPSSslSession *p;
    unsigned long enabled;

    enabled = OS_DisableInterrupts();
    con->cache = 0;
    for (i = 0; i < 4; i++) {
        p = &gCpsSslSessionCache[i];
        if (p->valid != 0 && p->ip == 0 && p->port == 0 &&
            func_020923F0((const u8 *)p, con->session_id, 0x20) == 0) {
            MI_CpuCopy8(p->master, con, 0x30);
            con->cache = 1;
            break;
        }
    }
    OS_RestoreInterrupts(enabled);
}
