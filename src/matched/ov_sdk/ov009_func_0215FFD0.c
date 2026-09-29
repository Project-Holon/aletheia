/*
 * function: func_0215FFD0
 * address:  0x0215FFD0
 * packet:   pkt_ov009_0215FFD0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      purge_session (libssl.TWL.HYB.a(ssl.o))
 *
 * symbols:
 *   func_02087988  0x02087988  arm
 *   func_020923F0  0x020923F0  arm
 *   func_0208799C  0x0208799C  arm
 *   g_021AA664  0x021AA664  data
 */



typedef struct CPSSslSession {
    unsigned char id[0x20];
    unsigned char pad20[0x5a - 0x20];
    unsigned char valid;                /* +0x5a */
    unsigned char pad5b;
} CPSSslSession;

typedef struct CPSSslConnection {
    unsigned char pad0[0x74];
    unsigned char session_id[0x20];     /* +0x74 */
} CPSSslConnection;

extern CPSSslSession g_021AA664[4];

extern unsigned long func_02087988(void);
extern int func_020923F0(const void *s1, const void *s2, unsigned long n);
extern unsigned long func_0208799C(unsigned long state);

static void func_0215FFD0(CPSSslConnection *con)
{
    int i;
    CPSSslSession *p;
    unsigned long enabled;

    enabled = func_02087988();
    for (i = 0; i < 4; i++) {
        p = &g_021AA664[i];
        if (p->valid != 0) {
            if (func_020923F0(p, con->session_id, 0x20) == 0) {
                p->valid = 0;
                break;
            }
        }
    }
    func_0208799C(enabled);
}
