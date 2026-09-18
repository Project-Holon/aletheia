/*
 * function: func_0202F738
 * address:  0x0202F738
 * packet:   pkt_0202F498
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   func_02017E88  0x02017E88  thumb
 *   func_020212E4  0x020212E4  thumb
 */

typedef unsigned short u16;

extern int func_02017E88(void *p, int a, int b);
extern int func_020212E4(u16 v);

int func_0202F738(void *p)
{
    int i;

    for (i = 0; i < 4; i++) {
        if (func_020212E4((u16)func_02017E88(p, i + 0x36, 0)) != 0) {
            return 0;
        }
    }
    return 1;
}
