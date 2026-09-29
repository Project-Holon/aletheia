/*
 * function: func_02161678
 * address:  0x02161678
 * packet:   pkt_ov009_02161678
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      rcv_finished (libssl.TWL.HYB.a(ssl.o))
 *
 * symbols:
 *   func_02082D44  0x02082D44  arm
 *   func_021614BC  0x021614BC  arm  ov009
 *   func_020923F0  0x020923F0  arm
 *   func_02161598  0x02161598  arm  ov009
 */

typedef struct CPSSslConnection {
    unsigned char pad0[0x2ec];
    unsigned char sha1[0x5c];           /* +0x2ec */
    unsigned char sha1_save[0x5c];      /* +0x348 */
    unsigned char md5[0x58];            /* +0x3a4 */
    unsigned char md5_save[0x58];       /* +0x3fc */
    unsigned char pad454[0x455 - 0x454];
    unsigned char state;                /* +0x455 */
} CPSSslConnection;

extern void func_02082D44(const void *srcp, void *dstp, unsigned long size);
extern void func_021614BC(CPSSslConnection *con, unsigned char *d, int flag);
extern int func_020923F0(const void *s1, const void *s2, unsigned long n);
extern void func_02161598(CPSSslConnection *con, unsigned char *d, int flag);

static void func_02161678(CPSSslConnection *con, unsigned char *s)
{
    unsigned char tmp[20];

    func_02082D44(con->md5, con->md5_save, 0x58);
    func_021614BC(con, tmp, 1);
    func_02082D44(con->md5_save, con->md5, 0x58);
    if (func_020923F0(s, tmp, 0x10) != 0) {
        con->state = 9;
        return;
    }
    func_02082D44(con->sha1, con->sha1_save, 0x5c);
    func_02161598(con, tmp, 1);
    func_02082D44(con->sha1_save, con->sha1, 0x5c);
    if (func_020923F0(s + 0x10, tmp, 0x14) != 0)
        con->state = 9;
    else
        con->state = 6;
}
