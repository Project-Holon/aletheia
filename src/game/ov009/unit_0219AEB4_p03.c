/*
 * file:     unit_0219AEB4_p03.c
 * unit:     yes
 * function: func_0219B628, func_0219B660
 * address:  0x0219B628
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   OS_SPrintf       0x02084F40  arm
 *   g_021A7688       0x021A7688  data
 *   strlen   0x0209477C  arm
 *   memcpy   0x02092344  arm
 */
struct qr2_buffer_s {
    char buffer[1400];
    int len;
};

extern int OS_SPrintf(char *dst, const char *fmt, ...);
extern unsigned int strlen(const char *s);
extern void *memcpy(void *dst, const void *src, unsigned int n);
int qr2_buffer_add_int(struct qr2_buffer_s *outbuf, int value);
int qr2_buffer_addA(struct qr2_buffer_s *outbuf, char *value);
extern char g_021A7688[];


int qr2_buffer_add_int(struct qr2_buffer_s *outbuf, int value)
{
    char temp[20];

    OS_SPrintf(temp, g_021A7688, value);
    return qr2_buffer_addA(outbuf, temp);
}


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
