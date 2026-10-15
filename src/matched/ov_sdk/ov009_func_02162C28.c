/*
 * function: CPSi_SslGetLength
 * address:  0x02162C28
 * packet:   pkt_ov009_02162C28
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CPSi_SslGetLength (libssl.TWL.HYB.a(ssl.o))
 *
 * symbols:
 *   try_fill_record  0x02162AE4  arm  ov009
 */

typedef struct CPSSslConnection {
    unsigned char pad0[0x455];
    unsigned char state;                /* +0x455 */
    unsigned char have_record;          /* +0x456 */
    unsigned char pad457[0x824 - 0x457];
    unsigned char *buf;                 /* +0x824 */
    unsigned long end;                  /* +0x828 */
    unsigned long pos;                  /* +0x82c */
} CPSSslConnection;

typedef struct CPSSoc {
    unsigned char pad0[8];
    unsigned char state;                /* +0x8 */
    unsigned char pad9[3];
    CPSSslConnection *con;              /* +0xc */
} CPSSoc;

extern void try_fill_record(CPSSoc *soc);

long CPSi_SslGetLength(CPSSoc *soc)
{
    CPSSslConnection *con;

    con = soc->con;
    if (con->buf == 0 || con->have_record == 0)
        try_fill_record(soc);
    if (con->buf != 0 && con->have_record != 0)
        return con->end - con->pos;
    if (con->buf == 0) {
        if (soc->state != 4 || con->state == 9)
            return -1;
    }
    return 0;
}
