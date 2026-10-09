/*
 * file:     unit_0215FDA4_p02.c
 * unit:     yes
 * function: cache_session
 * address:  0x0215FEE0
 * packet:   pkt_ov009_0215FEE0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      cache_session (ssl.o)
 *
 * symbols:
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_GetTick            0x020870D0  arm
 *   MI_CpuCopy8           0x02082D44  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   session               0x021AA664  data
*/

struct _CPSSslConnection;

typedef struct CPSSslSession {
    char pad0[0x50];
    unsigned long field_50;
    unsigned long field_54;
    unsigned short field_58;
    unsigned char field_5a;
    char pad1[0x5c - 0x5b];
} CPSSslSession;

extern CPSSslSession session[4];
extern unsigned long OS_DisableInterrupts(void);
extern unsigned long long OS_GetTick(void);
extern void MI_CpuCopy8(void *srcp, void *dstp, unsigned long size);
extern unsigned long OS_RestoreInterrupts(unsigned long state);

static void cache_session(struct _CPSSslConnection *con, unsigned long ip,
                          unsigned short port)
{
    int i;
    CPSSslSession *p;
    CPSSslSession *candidate;
    unsigned long biggest;
    unsigned long enabled;
    unsigned long now;

    enabled = OS_DisableInterrupts();
    now = (unsigned long)(OS_GetTick() >> 16);
    biggest = 0;
    candidate = session;
    for (i = 0; i < 4; i++) {
        p = &session[i];
        if (p->field_5a && ip != 0 && ip == p->field_54 && port != 0 &&
            port == p->field_58) {
            candidate = p;
            break;
        }
        if (biggest == (unsigned long)-1)
            continue;
        if (!p->field_5a) {
            biggest = (unsigned long)-1;
            candidate = p;
        } else {
            unsigned long age = now - p->field_50;
            if (age > biggest) {
                biggest = age;
                candidate = p;
            }
        }
    }
    MI_CpuCopy8((char *)con + 0x74, candidate, 0x20);
    MI_CpuCopy8(con, (char *)candidate + 0x20, 0x30);
    candidate->field_50 = now;
    candidate->field_5a = 1;
    candidate->field_54 = ip;
    candidate->field_58 = port;
    OS_RestoreInterrupts(enabled);
}
