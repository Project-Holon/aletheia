/*
 * function: func_0218946C
 * address:  0x0218946C
 * packet:   pkt_0219091C
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * gpiAppendStringToBuffer: append a NUL-terminated string's bytes to a
 * GPIBuffer, its length supplied by strlen.
 *
 * symbols:
 *   func_021893C8  0x021893C8  arm  ov009
 *   func_0209477C  0x0209477C  arm
 */

extern int func_021893C8(int *connection, int *buffer, int src, int n);
typedef unsigned char  u8;
extern int func_0209477C(const u8 *s);

int func_0218946C(int *connection, int *buffer, const char *string)
{
    return func_021893C8(connection, buffer, (int)string, func_0209477C((const u8 *)string));
}
