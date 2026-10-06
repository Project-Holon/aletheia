/*
 * function: func_021C1988
 * address:  0x021C1988
 * packet:   pkt_ov021_021C1988
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Runs the state table until a state returns other than 1.
 *
 * symbols:
 *   func_021C16AC  0x021C16AC  thumb  ov021
 *   d_021DA128     0x021DA128  data  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int (*Fn)(u16 *s);

extern Fn d_021DA128[];
extern void func_021C16AC(u8 *p);

void func_021C1988(void *a, u16 *s)
{
    if (s[0] != 0) {
        while (d_021DA128[(s16)s[1]](s) == 1)
            ;
    } else {
        func_021C16AC((u8 *)s);
    }
}
