/*
 * function: func_021BE578
 * address: 0x021BE578
 * packet: pkt_ov204_021BE578
 * region: ov204
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021BF794 0x021BF794 thumb ov204
 *   func_021BF720 0x021BF720 thumb ov204
 */
extern void func_021BF794(void *, unsigned char, unsigned char);
extern void func_021BF720(void *, int, unsigned char);
int func_021BE578(char *p, int *state, unsigned *q)
{
    switch (*state) {
    case 0:
        if (q[1] != 0)
            func_021BF794(*(void **)(p + 8), q[0], 1);
        else
            func_021BF794(*(void **)(p + 8), q[0], 31);
        func_021BF720(*(void **)(p + 8), 1, q[0]);
        state[1] = 31;
        ++*state;
        break;
    case 1:
        state[1] -= 2;
        if (state[1] <= 0) {
            func_021BF794(*(void **)(p + 8), q[0], 31);
            func_021BF720(*(void **)(p + 8), q[1], q[0]);
            return 1;
        }
        if (q[1] == 1)
            func_021BF794(*(void **)(p + 8), q[0], 31 - state[1]);
        else if (q[1] == 0)
            func_021BF794(*(void **)(p + 8), q[0], state[1]);
        break;
    }
    return 0;
}
