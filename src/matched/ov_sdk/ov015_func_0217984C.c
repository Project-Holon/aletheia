/*
 * function: func_0217984C
 * address:  0x0217984C
 * packet:   pkt_0217984C
 * region:   ov015
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Guard/forward wrapper: returns the follower's result only when the predicate
 * holds, otherwise zero.
 *
 * symbols:
 *   func_02179D3C  0x02179D3C  thumb  ov015
 *   func_02179B24  0x02179B24  thumb  ov015
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

int func_02179D3C(void);
int func_02179B24(void);

int func_0217984C(void)
{
    if (func_02179D3C())
        return func_02179B24();
    return 0;
}
