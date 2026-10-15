/*
 * function: COMM_HISTORY_RemoveAt
 * address:  0x0202ED00
 * packet:   pkt_0202ED00
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * note:     EXACT* only for the two bytes of alignment padding at
 *           0x0202ED5E.  Closed in wave 16 (the residue since wave 12 was
 *           the ldm/stm base order of the record copy): the copy goes
 *           through a named destination and a source derived from it
 *           (`dst = &t[n]; src = dst + 1; *dst = *src;`), and the flag test
 *           must NOT share the `t + n` subexpression with them, or the
 *           front end rematerialises t + n*0x28 and computes the source
 *           first.  `(t + 1)[n]` shares only the n*0x28 product, which is
 *           what the image keeps in r7.  See docs/notes/pkt_0202ED00.c.txt.
 */
typedef unsigned char u8;
typedef unsigned int  u32;

/* 0x28-byte slot; the u32 member is load-bearing (4-byte alignment turns
 * the record copy into five ldm/stm pairs). */
struct Slot {
    u32 w00;
    u8  pad04[0x22];
    u8      : 4;
    u8 flag : 1;
    u8      : 3;
    u8  pad27;
};

void COMM_HISTORY_RemoveAt(struct Slot *t, u32 n)
{
    struct Slot *dst;
    struct Slot *src;

    if (n >= 0x14)
        return;

    if (n < 0x13) {
        while (1) {
            dst = &t[n];
            src = dst + 1;
            *dst = *src;
            if (!(t + 1)[n].flag) {
                n++;
                break;
            }
            n++;
            if (n >= 0x13)
                break;
        }
    }

    while (n < 0x14) {
        t[n].flag = 0;
        n++;
    }
}
