/*
 * function: gpiAppendIntToBuffer
 * address:  0x0218949C
 * packet:   pkt_0219091C
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * gpiAppendIntToBuffer: format the integer with sprintf("%d") into a small
 * stack buffer, then append that string to the GPIBuffer.
 *
 * symbols:
 *   gpiAppendStringToBuffer  0x0218946C  arm  ov009
 *   OS_SPrintf  0x02084F40  arm
 *   g_021A44D8     0x021A44D8  data
 */

extern int OS_SPrintf(char *dst, const char *fmt, ...);
extern int gpiAppendStringToBuffer(int *connection, int *buffer, const char *string);
extern char g_021A44D8[];

int gpiAppendIntToBuffer(int *connection, int *buffer, int value)
{
    char buf[0x10];

    OS_SPrintf(buf, g_021A44D8, value);
    return gpiAppendStringToBuffer(connection, buffer, buf);
}
