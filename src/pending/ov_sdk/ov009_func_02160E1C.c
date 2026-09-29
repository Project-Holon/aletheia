/*
 * function: func_02160E1C
 * address:  0x02160E1C
 * packet:   pkt_ov009_02160E1C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * sdk:      client_hello_v2 (libssl.TWL.HYB.a(ssl.o))
 *
 * symbols:
 *   func_02160E0C  0x02160E0C  arm  ov009
 *   func_02160DB4  0x02160DB4  arm  ov009
 *   func_02082BCC  0x02082BCC  arm
 *   func_02082D44  0x02082D44  arm
 *
 * notes: near miss, 26 B differ, registers only. Bytes and instruction order are right;
 * s/con/random_len get r5/r6/r7 where the vendor has r6/r7/r5. Defining random_len
 * before sessionID_len fixes the registers but reorders the s[4..7] loads (16 B differ).
 */

typedef struct CPSSslConnection {
    unsigned char pad0[0x30];
    unsigned char cache;                /* +0x30 */
    unsigned char pad31;
    unsigned short method;              /* +0x32 */
    unsigned char random[0x20];         /* +0x34 */
    unsigned char pad54[0x455 - 0x54];
    unsigned char state;                /* +0x455 */
} CPSSslConnection;

extern int func_02160E0C(unsigned char major, unsigned char minor);
extern int func_02160DB4(unsigned char *s, int num, int size);
extern void func_02082BCC(void *dstp, unsigned char data, unsigned long size);
extern void func_02082D44(const void *srcp, void *dstp, unsigned long size);

static void func_02160E1C(CPSSslConnection *con, unsigned char *s)
{
    int pairlist_len;
    int sessionID_len;
    int random_len;
    unsigned short method;

    if (!func_02160E0C(s[0], s[1]))
        return;
    pairlist_len = (s[2] << 8) + s[3];
    method = func_02160DB4(s + 8, pairlist_len / 3, 3);
    if (method == 0)
        return;
    con->method = method;
    sessionID_len = (s[4] << 8) + s[5];
    random_len = (s[6] << 8) + s[7];
    con->cache = 0;
    pairlist_len = pairlist_len + 8 + sessionID_len;
    if (random_len >= 0x20) {
        func_02082D44(s + pairlist_len, con->random, 0x20);
    } else {
        func_02082BCC(con->random, 0, 0x20 - random_len);
        func_02082D44(s + pairlist_len, con->random + 0x20 - random_len, random_len);
    }
    con->state = 1;
}
