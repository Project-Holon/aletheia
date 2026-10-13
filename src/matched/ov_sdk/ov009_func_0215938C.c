/*
 * function: no_need_inq
 * address:  0x0215938C
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * One when the test fails, else the second call.
 *
 * symbols:
 *   get_targetip  0x021578C8  arm  ov009
 *   inq_arpcache  0x02157D8C  arm  ov009
 */

extern int get_targetip(void);
extern int inq_arpcache(void);

int no_need_inq(void)
{
    if (get_targetip() == 0) {
        return 1;
    }

    return inq_arpcache();
}

