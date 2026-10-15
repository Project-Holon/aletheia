/*
 * function: gpiAppendStringToBufferLen
 * address:  0x021893C8
 * packet:   pkt_0219091C
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * gpiAppendDataToBuffer: append `n` bytes of `src` to a GPIBuffer
 * (0=data, 4=size, 8=len).  Grows the store by max(0x4000, n) when the
 * free tail is shorter than n, then NUL-terminates.
 *
 * symbols:
 *   gsirealloc  0x0217EAC8  arm  ov009
 *   gpiSetErrorString  0x02193734  arm  ov009
 *   func_02092344  0x02092344  arm
 *   g_021A44C8     0x021A44C8  data
 */

extern char *gsirealloc(char *p, int n);
extern void gpiSetErrorString(int *connection, int string);
extern void *func_02092344(void *dest, const void *src, unsigned int n);
extern char g_021A44C8[];

int gpiAppendStringToBufferLen(int *connection, int *buffer, int src, int n)
{
    int buflen;
    int size;
    char *data;

    if (src == 0)
        return 0;
    buflen = buffer[2];
    size = buffer[1];
    data = (char *)buffer[0];
    if (size - buflen < n) {
        int grow = 0x4000;
        if (n >= grow)
            grow = n;
        size += grow;
        data = gsirealloc(data, size + 1);
        if (data == 0) {
            gpiSetErrorString(connection, (int)g_021A44C8);
            return 1;
        }
    }
    func_02092344(data + buflen, (const void *)src, n);
    data[buflen + n] = 0;
    buffer[1] = size;
    buffer[2] += n;
    buffer[0] = (int)data;
    return 0;
}
