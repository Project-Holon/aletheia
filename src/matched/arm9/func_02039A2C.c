/*
 * unit:     no
 * function: GFL_NET_HANDLE_RequestNegotiation
 * address:  0x02039A2C
 * packet:   pkt_020399B8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

typedef signed int     s32;
typedef unsigned short u16;
struct Entry;
extern u16 func_02039338(void);
extern struct Entry *func_0203996C(s32 idx);
void GFL_NET_HANDLE_RequestNegotiation(int a)
{
    char *q;
    if (func_02039338())
        return;
    q = (char *)func_0203996C(0xff) + a * 2;
    q[0x2c] = (char)a;
    q[0x2d] = 1;
}
