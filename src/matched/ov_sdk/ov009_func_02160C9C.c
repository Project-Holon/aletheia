/*
 * function: func_02160C9C
 * address:  0x02160C9C
 * packet:   pkt_ov009_02160C9C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      rcv_server_hello (libssl.TWL.HYB.a(ssl.o))
 *
 * symbols:
 *   MI_CpuCopy8  0x02082D44  arm
 *   func_020923F0  0x020923F0  arm
 *   func_0215FFD0  0x0215FFD0  arm  ov009
 */

typedef struct CPSSslConnection {
    unsigned char pad0[0x30];
    unsigned char cache;                /* +0x30 */
    unsigned char resumed;              /* +0x31 */
    unsigned short method;              /* +0x32 */
    unsigned char pad34[0x54 - 0x34];
    unsigned char random[0x20];         /* +0x54 */
    unsigned char session_id[0x455 - 0x74];  /* +0x74 */
    unsigned char state;                /* +0x455 */
} CPSSslConnection;

extern void MI_CpuCopy8(const void *srcp, void *dstp, unsigned long size);
typedef unsigned char  u8;
extern int func_020923F0(const u8 *a, const u8 *b, int n);
extern void func_0215FFD0(CPSSslConnection *con);

static void func_02160C9C(CPSSslConnection *con, unsigned char *s)
{
    int session_id_len;
    unsigned char cached;

    MI_CpuCopy8(s + 2, con->random, 0x20);
    cached = con->cache;
    session_id_len = s[0x22];
    s += 0x23;
    if (cached != 0 && session_id_len == 0x20 &&
        func_020923F0(con->session_id, s, 0x20) == 0) {
        con->resumed = 1;
    } else {
        if (cached != 0)
            func_0215FFD0(con);
        if (session_id_len != 0) {
            MI_CpuCopy8(s, con->session_id, 0x20);
            con->cache = 1;
        } else {
            con->cache = 0;
        }
        con->resumed = 0;
    }
    s += session_id_len;
    con->method = (s[0] << 8) + s[1];
    if (con->method != 4 && con->method != 5)
        con->state = 9;
    else
        con->state = 2;
}
