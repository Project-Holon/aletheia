/*
 * function: func_021F3868
 * address:  0x021F3868
 * packet:   pkt_021F3868
 * region:   ov061
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021A3080  0x021A3080  thumb
 *   func_021A308C  0x021A308C  thumb
 */

typedef unsigned int u32;

extern u32 func_021A3080(void *x);
extern u32 func_021A308C(void *x);

int func_021F3868(void *unused, void *x)
{
    u32 a = func_021A3080(x);

    if (func_021A308C(x) == 3 && a == 0) {
        return 1;
    }
    return 0;
}
