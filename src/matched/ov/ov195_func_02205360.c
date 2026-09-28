/*
 * function: func_02205360
 * address:  0x02205360
 * packet:   pkt_02205360
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020061E4 0x020061E4 thumb
 *   func_02006238 0x02006238 thumb
 */

extern void func_020061E4(int);
extern int func_02006238(void);

int func_02205360(int a)
{
    switch (a) {
    case 3:
        func_020061E4(0x56b);
        break;
    case 5:
        return func_02006238();
    }
    return 0;
}
