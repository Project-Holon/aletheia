/*
 * file:     unit_0215FDA4_p07.c
 * unit:     yes
 * function: func_02160C9C, func_02160D68, func_02160DB4, func_02160E0C
 * address:  0x02160C9C
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
 *   func_02082D44  0x02082D44  arm
 *   func_020923F0  0x020923F0  arm
 *   func_0215FFD0  0x0215FFD0  arm  ov009
 *   d_021A1D40     0x021A1D40  data
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

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

extern void func_02082D44(const void *srcp, void *dstp, unsigned long size);
extern int func_020923F0(const u8 *a, const u8 *b, int n);
extern void func_0215FFD0(CPSSslConnection *con);
/* * sdk: rcv_server_hello (libssl.TWL.HYB.a(ssl.o)) */ static void func_02160C9C(CPSSslConnection *con, unsigned char *s);
/* * sdk: has_method (libssl.TWL.HYB.a(ssl.o)) */ static int func_02160D68(unsigned char *s, int num, int size, unsigned short method);
/* * Scans the two halfword entries of a table, returning the first entry the * helper accepts, else zero. */ int func_02160DB4(int a0, int a1, int a2);
/* * True when the value is 3. */ int func_02160E0C(int v);
extern u16 d_021A1D40[];



/*
 * sdk:      rcv_server_hello (libssl.TWL.HYB.a(ssl.o))
 */
static void func_02160C9C(CPSSslConnection *con, unsigned char *s)
{
    int session_id_len;
    unsigned char cached;

    func_02082D44(s + 2, con->random, 0x20);
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
            func_02082D44(s, con->session_id, 0x20);
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


/*
 * sdk:      has_method (libssl.TWL.HYB.a(ssl.o))
 */
static int func_02160D68(unsigned char *s, int num, int size, unsigned short method)
{
    unsigned long n;
    int i;

    for (i = 0; i < num; i++) {
        n = (s[0] << 8) + s[1];
        if (size == 3)
            n = (n << 8) + s[2];
        if (n == method)
            return 1;
        s += size;
    }
    return 0;
}



/*
 * Scans the two halfword entries of a table, returning the first entry the
 * helper accepts, else zero.
 */
int func_02160DB4(int a0, int a1, int a2)
{
    u32 i;

    for (i = 0; i < 2; i++) {
        if (func_02160D68((unsigned char *)a0, a1, a2, d_021A1D40[i]))
            return d_021A1D40[i];
    }
    return 0;
}


/*
 * True when the value is 3.
 */
int func_02160E0C(int v)
{
    return v == 3;
}
