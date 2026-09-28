/*
 * function: func_0218934C
 * address:  0x0218934C
 * packet:   pkt_0219091C
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * gpiAppendCharToBuffer: append one character to a GPIBuffer (0=data,
 * 4=size, 8=len), growing the backing store by 0x4000 bytes when full.
 *
 * symbols:
 *   func_0217EAC8  0x0217EAC8  arm  ov009
 *   func_02193734  0x02193734  arm  ov009
 *   g_021A44C8     0x021A44C8  data
 */

extern char *func_0217EAC8(char *p, int n);
extern void func_02193734(int *connection, int string);
extern char g_021A44C8[];

int func_0218934C(int *connection, int *buffer, int c)
{
    int len = buffer[2];
    int size = buffer[1];
    char *data;

    data = (char *)buffer[0];
    if (size == len) {
        size += 0x4000;
        data = func_0217EAC8(data, size + 1);
        if (data == 0) {
            func_02193734(connection, (int)g_021A44C8);
            return 1;
        }
    }
    data[len] = c;
    data[len + 1] = 0;
    buffer[0] = (int)data;
    buffer[2] += 1;
    buffer[1] = size;
    return 0;
}
