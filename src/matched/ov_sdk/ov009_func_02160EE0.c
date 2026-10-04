/*
 * function: func_02160EE0
 * address:  0x02160EE0
 * packet:   pkt_ov009_02160EE0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      client_hello (libssl.TWL.HYB.a(ssl.o))
 *
 * symbols:
 *   func_02160E0C  0x02160E0C  arm  ov009
 *   func_02082D44  0x02082D44  arm
 *   func_0215FDA4  0x0215FDA4  arm  ov009
 *   func_02160DB4  0x02160DB4  arm  ov009
 */

typedef struct CPSSslConnection {
    unsigned char pad0[0x30];
    unsigned char cache;                /* +0x30 */
    unsigned char pad31;
    unsigned short method;              /* +0x32 */
    unsigned char random[0x74 - 0x34];  /* +0x34 */
    unsigned char session_id[0x455 - 0x74];  /* +0x74 */
    unsigned char state;                /* +0x455 */
} CPSSslConnection;

extern int func_02160E0C(unsigned char major, unsigned char minor);
extern void func_02082D44(const void *srcp, void *dstp, unsigned long size);
extern void func_0215FDA4(CPSSslConnection *con);
extern int func_02160DB4(int a0, int a1, int a2);

static void func_02160EE0(CPSSslConnection *con, unsigned char *s)
{
    int sessionID_len;
    unsigned short method;

    if (!func_02160E0C(s[0], s[1]))
        return;
    s += 2;
    func_02082D44(s, con->random, 0x20);
    s += 0x20;
    sessionID_len = *s++;
    if (sessionID_len != 0x20) {
        con->cache = 0;
    } else {
        func_02082D44(s, con->session_id, 0x20);
        func_0215FDA4(con);
    }
    s += sessionID_len;
    method = func_02160DB4((int)(s + 2), ((s[0] << 8) + s[1]) / 2, 2);
    con->method = method;
    if (method != 0)
        con->state = 1;
}
