/*
 * file:     unit_0215FDA4_p09.c
 * unit:     yes
 * function: func_02160E1C, func_02160EE0
 * address:  0x02160E1C
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
 *   func_02160E0C  0x02160E0C  arm  ov009
 *   func_02160DB4  0x02160DB4  arm  ov009
 *   func_02082BCC  0x02082BCC  arm
 *   func_02082D44  0x02082D44  arm
 *   func_0215FDA4  0x0215FDA4  arm  ov009
 */
typedef struct CPSSslConnection_02160E1C {
    unsigned char pad0[0x30];
    unsigned char cache;                /* +0x30 */
    unsigned char pad31;
    unsigned short method;              /* +0x32 */
    unsigned char random[0x20];         /* +0x34 */
    unsigned char pad54[0x455 - 0x54];
    unsigned char state;                /* +0x455 */
} CPSSslConnection_02160E1C;

typedef struct CPSSslConnection_02160EE0 {
    unsigned char pad0[0x30];
    unsigned char cache;                /* +0x30 */
    unsigned char pad31;
    unsigned short method;              /* +0x32 */
    unsigned char random[0x74 - 0x34];  /* +0x34 */
    unsigned char session_id[0x455 - 0x74];  /* +0x74 */
    unsigned char state;                /* +0x455 */
} CPSSslConnection_02160EE0;

extern int func_02160E0C(unsigned char major, unsigned char minor);
extern int func_02160DB4(int a0, int a1, int a2);
extern void func_02082BCC(void *dstp, unsigned char data, unsigned long size);
extern void func_02082D44(const void *srcp, void *dstp, unsigned long size);
extern void func_0215FDA4(CPSSslConnection_02160EE0 *con);


/*
 * sdk:      client_hello_v2 (libssl.TWL.HYB.a(ssl.o))
 *
 * The offset `pairlist_len + 8 + sessionID_len` needs a local of its own
 * (`offset`); accumulating it back into pairlist_len colours r4/r5/r6/r7 as
 * pairlist_len/s/con/random_len where the vendor has pairlist_len/random_len/
 * s/con, which also pushes the s[4] temp out of r5 and into ip.  With the
 * separate name the coalescer merges pairlist_len and offset back into one
 * register and all four land as the vendor has them.
 *
 * Declaration order is inert here: all 24 permutations of the four locals
 * compile to the same 26-byte DIFF.
 */
static void func_02160E1C(CPSSslConnection_02160E1C *con, unsigned char *s)
{
    int pairlist_len;
    int offset;
    int sessionID_len;
    int random_len;
    unsigned short method;

    if (!func_02160E0C(s[0], s[1]))
        return;
    pairlist_len = (s[2] << 8) + s[3];
    method = func_02160DB4((int)(s + 8), pairlist_len / 3, 3);
    if (method == 0)
        return;
    con->method = method;
    sessionID_len = (s[4] << 8) + s[5];
    random_len = (s[6] << 8) + s[7];
    con->cache = 0;
    offset = pairlist_len + 8 + sessionID_len;
    if (random_len >= 0x20) {
        func_02082D44(s + offset, con->random, 0x20);
    } else {
        func_02082BCC(con->random, 0, 0x20 - random_len);
        func_02082D44(s + offset, con->random + 0x20 - random_len, random_len);
    }
    con->state = 1;
}


/*
 * sdk:      client_hello (libssl.TWL.HYB.a(ssl.o))
 */
static void func_02160EE0(CPSSslConnection_02160EE0 *con, unsigned char *s)
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
