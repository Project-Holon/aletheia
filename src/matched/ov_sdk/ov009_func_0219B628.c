/*
 * function: qr2_buffer_add_int
 * address:  0x0219B628
 * packet:   pkt_ov009_0219B628
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      qr2_buffer_add_int (qr2.o)
 *
 * symbols:
 *   OS_SPrintf       0x02084F40  arm
 *   qr2_buffer_addA  0x0219B660  arm  ov009
 *   g_021A7688       0x021A7688  data
 */

struct qr2_buffer_s {
    char buffer[1400];
    int len;
};

extern int OS_SPrintf(char *dst, const char *fmt, ...);
extern int qr2_buffer_addA(struct qr2_buffer_s *outbuf, char *value);
extern char g_021A7688[];

int qr2_buffer_add_int(struct qr2_buffer_s *outbuf, int value)
{
    char temp[20];

    OS_SPrintf(temp, g_021A7688, value);
    return qr2_buffer_addA(outbuf, temp);
}
