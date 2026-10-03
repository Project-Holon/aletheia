/*
 * function: func_02164BC4
 * address:  0x02164BC4
 * packet:   pkt_ov010_02164BC4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Two-step state machine on *st: step 0 registers a callback, step 1 polls.
 *
 * symbols:
 *   func_02030B50  0x02030B50  arm
 *   func_0203CBAC  0x0203CBAC  arm
 *   d_02171C30     0x02171C30  data  ov010  a4
 *   func_02164C04  0x02164C04  thumb ov010
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_02030B50(int a);
extern void func_0203CBAC(void *a, void *b, void *c);
extern u8 d_02171C30[];
extern void func_02164C04(u8 *p);

int func_02164BC4(int *st, int unused, int *q)
{
    switch (*st) {
    case 0:
        func_02030B50(12);
        func_0203CBAC(d_02171C30, func_02164C04, q);
        (*st)++;
        break;
    case 1:
        if (q[1] >= 1) {
            return 1;
        }
        break;
    }
    return 0;
}
