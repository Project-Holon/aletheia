/*
 * function: func_0219FE10
 * address:  0x0219FE10
 * packet:   pkt_ov009_0219FE10
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      BufferAddData (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 *
 * symbols:
 *   unit_02092344  0x02092344  arm
 */

extern void *unit_02092344(void *dst, const void *src, unsigned long n);

void func_0219FE10(char **buffer, char *data, int dlen, int *len)
{
    unit_02092344(*buffer, data, dlen);
    *len += dlen;
    *buffer += dlen;
}
