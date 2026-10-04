/*
 * function: func_021BEB88
 * address:  0x021BEB88
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021BEAB8  0x021BEAB8  arm  ov114
 *
 *
 * Unlinks node `a` from list class 3: 0 on success, -1 when absent.
 */

typedef unsigned char u8;
typedef unsigned int u32;
struct Conn;
extern struct Conn *func_021BEAB8(void *mutexInfo_p, struct Conn *handle_p, unsigned long order);

int func_021BEB88(int a, int b)
{
    return -(func_021BEAB8((void *)a, (struct Conn *)b, 3) == 0);
}
