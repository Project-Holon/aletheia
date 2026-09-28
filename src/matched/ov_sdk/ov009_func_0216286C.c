/*
 * function: mustget_change_cipher_spec_and_finished
 * address:  0x0216286C
 * packet:   pkt_ov009_0216286C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      mustget_change_cipher_spec_and_finished (ssl.o)
 *
 * symbols:
 *   parse_record  0x02161F98  arm
*/

struct _CPSSoc;

extern int parse_record(struct _CPSSoc *soc);

static int mustget_change_cipher_spec_and_finished(struct _CPSSoc *soc)
{
    if (parse_record(soc) != 7)
        return 1;
    if (parse_record(soc) != 6)
        return 1;
    return 0;
}
