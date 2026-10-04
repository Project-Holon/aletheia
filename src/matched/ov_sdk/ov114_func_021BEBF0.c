/*
 * function: func_021BEBF0
 * address:  0x021BEBF0
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
 * ov114 tail-call thunk: func_021BEAB8(a, b, 2) via `ldr ip,pool; bx ip`.
 */

typedef unsigned char u8;
typedef unsigned int u32;
struct Conn;
extern struct Conn *func_021BEAB8(void *mutexInfo_p, struct Conn *handle_p, unsigned long order);

void func_021BEBF0(int a, int b)
{
    func_021BEAB8((void *)a, (struct Conn *)b, 2);
}
