/*
 * function: func_021A3504
 * address:  0x021A3504
 * packet:   pkt_ov021_021A3504
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021A3098  0x021A3098  thumb  ov021
 *   func_021AB5AC  0x021AB5AC  thumb  ov021
 */

typedef unsigned int   u32;
typedef unsigned char  u8;
u32 func_021A3098(u8 *p);
int func_021AB5AC(unsigned long a, unsigned long b);

int func_021A3504(u8 *a, int b, int c)
{
    int r = func_021A3098(a);

    if (r == 2 || r == 3)
        return 0;
    return func_021AB5AC(b, c);
}
