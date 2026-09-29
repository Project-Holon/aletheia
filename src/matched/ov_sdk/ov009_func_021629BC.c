/*
 * function: func_021629BC
 * address:  0x021629BC
 * packet:   pkt_ov009_021629BC
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CPSi_SslRead (libssl.TWL.HYB.a(ssl.o))
 *
 * symbols:
 *   func_02161BE8  0x02161BE8  arm  ov009
 *   func_02161C80  0x02161C80  arm  ov009
 *   func_02161F98  0x02161F98  arm  ov009
 *   g_021A82B0  0x021A82B0  data
 */

typedef struct CPSSslConnection {
    unsigned char pad0[0x456];
    unsigned char have_record;          /* +0x456 */
    unsigned char pad457[0x824 - 0x457];
    unsigned char *buf;                 /* +0x824 */
    unsigned long end;                  /* +0x828 */
    unsigned long pos;                  /* +0x82c */
} CPSSslConnection;

typedef struct CPSSoc {
    unsigned char pad0[0xc];
    CPSSslConnection *con;              /* +0xc */
} CPSSoc;

extern void (*g_021A82B0)(void *p);

extern int func_02161BE8(unsigned char *d, int len, CPSSoc *soc);
extern void func_02161C80(CPSSslConnection *con, unsigned char *buf);
extern int func_02161F98(CPSSoc *soc);

unsigned char *func_021629BC(unsigned long *len, CPSSoc *soc)
{
    CPSSslConnection *con;

    con = soc->con;
    if (con->buf != 0 && con->have_record == 0) {
        if (func_02161BE8(con->buf + con->pos, con->end - con->pos, soc) != 0) {
            g_021A82B0(con->buf);
            con->buf = 0;
            *len = 0;
            return 0;
        }
        func_02161C80(con, con->buf);
        if (con->have_record == 0)
            con->buf = 0;
    }
    while (con->buf == 0) {
        if (func_02161F98(soc) == 9) {
            *len = 0;
            return 0;
        }
    }
    *len = con->end - con->pos;
    return con->buf + con->pos;
}
