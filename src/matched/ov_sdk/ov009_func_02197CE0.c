/*
 * function: func_02197CE0
 * address:  0x02197CE0
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Dispatches on the fourth argument.
 *
 * symbols:
 *   func_02197594  0x02197594  arm  ov009
 *   func_02197930  0x02197930  arm  ov009
 */

extern void func_02197594(int a, int b, int c);
typedef unsigned char  u8;
struct GTI2Connection;
extern int func_02197930(struct GTI2Connection *connection, u8 *message, int len);

void func_02197CE0(int a, int b, int c, int d)
{
    if (d != 0) {
        func_02197594(a, b, c);
    } else {
        func_02197930((struct GTI2Connection *)a, (u8 *)b, c);
    }
}

