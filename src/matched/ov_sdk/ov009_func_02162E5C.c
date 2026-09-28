/*
 * function: CPSi_SslClose
 * address:  0x02162E5C
 * packet:   pkt_ov009_02162E5C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CPSi_SslClose (ssl.o)
 *
 * symbols:
 *   CPSiFree  0x021A82B0  data
*/

struct _CPSSslConnection {
    char pad0[0x455];
    unsigned char f455;
    char pad1[0x824 - 0x455 - 1];
    void *f824;
};

struct _CPSSoc {
    char pad0[0xc];
    struct _CPSSslConnection *con;
};

extern void (*CPSiFree)(void *ptr);

void CPSi_SslClose(struct _CPSSoc *soc)
{
    struct _CPSSslConnection *con = soc->con;
    void *p;

    con->f455 = 0;
    p = con->f824;
    if (p != 0)
        CPSiFree(p);
    con->f824 = 0;
}
