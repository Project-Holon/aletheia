/*
 * function: func_02183D4C
 * address:  0x02183D4C
 * packet:   pkt_02183D4C
 * region:   ov168
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02183D3C   0x02183D3C  thumb
 *   func_02183D34   0x02183D34  thumb
 *   func_02183DAC   0x02183DAC  thumb
 *   func_0202208C   0x0202208C  thumb
 *   func_020221A4   0x020221A4  thumb
 *
 * Step a two-slot state machine: publish through func_0202208C on state 0,
 *   poll func_020221A4 on 1, install func_02183D34 on 2.
 */


extern int func_02183D3C(int);
extern void func_02183D34(int, void *);
extern void func_02183DAC(void);
extern void func_0202208C(int, int, int, int, int, int, int);
extern int func_020221A4(void);

void func_02183D4C(int a, int *state)
{
    int x = func_02183D3C(a);
    switch (*state) {
    case 0:
        func_0202208C(0, 1, 1, 0, 6, 1, *(int *)(x + 0x14C));
        *state = 1;
        break;
    case 1:
        if (func_020221A4())
            *state = 2;
        break;
    case 2:
        func_02183D34(a, func_02183DAC);
        break;
    }
}
