/*
 * function: gti2MessageCheck
 * address:  0x02198808
 * packet:   pkt_ov009_02198808
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gti2MessageCheck (libdwcgsgt2.TWL.HYB.a gt2utility.o)
 * symbols:
 *   strlen       0x0209477C arm
 *   gGt2EmptyMessage   0x021A595C data
 */

extern int strlen(const char *s);
extern char gGt2EmptyMessage[];

void gti2MessageCheck(unsigned char **message, int *len)
{
    if (*message == 0) {
        *message = (unsigned char *)gGt2EmptyMessage;
        *len = 0;
        return;
    }
    if (*len == -1)
        *len = strlen((char *)*message) + 1;
}
