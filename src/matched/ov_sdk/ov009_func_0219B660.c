/*
 * function: qr2_buffer_addA
 * address:  0x0219B660
 * packet:   pkt_ov009_0219B660
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      qr2_buffer_addA (qr2.o)
 *
 * symbols:
 *   strlen   0x0209477C  arm
 *   memcpy   0x02092344  arm
 */

struct qr2_buffer_s {
    char buffer[1400];
    int len;
};

extern unsigned int strlen(const char *s);
extern void *memcpy(void *dst, const void *src, unsigned int n);

int qr2_buffer_addA(struct qr2_buffer_s *outbuf, char *value)
{
    int copylen = strlen(value) + 1;

    if (copylen > 1400 - outbuf->len)
        copylen = 1400 - outbuf->len;
    if (copylen <= 0)
        return 0;
    memcpy(outbuf->buffer + outbuf->len, value, copylen);
    outbuf->len += copylen;
    outbuf->buffer[outbuf->len - 1] = 0;
    return 1;
}
