/*
 * function: func_021BE61C
 * address: 0x021BE61C
 * packet: pkt_ov204_021BE61C
 * region: ov204
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021BF23C 0x021BF23C thumb ov204
 *   func_021BF2F4 0x021BF2F4 thumb ov204
 *   func_021BF7CC 0x021BF7CC thumb ov204
 *   func_021BF2E0 0x021BF2E0 thumb ov204
 */
extern void func_021BF23C(void *, unsigned, unsigned);
typedef unsigned int   u32;
typedef unsigned char  u8;
extern int func_021BF2F4(char *a);
extern void func_021BF7CC(void *, unsigned char, int);
extern u32 func_021BF2E0(u8 *p);
int func_021BE61C(char *p, int *state, unsigned *q)
{
    unsigned index = q[0];
    unsigned other = q[1];
    switch (*state) {
    case 0:
        func_021BF23C(*(void **)(p + 0x18), index, q[2]);
        ++*state;
        break;
    case 1:
        if (func_021BF2F4(*(void **)(p + 0x18)) != 0) {
            func_021BF7CC(*(void **)(p + 8), other, 1);
            return 1;
        }
        switch (func_021BF2E0(*(void **)(p + 0x18))) {
        case 1:
            func_021BF7CC(*(void **)(p + 8), other, 1);
            state[1] = 0;
            break;
        case 0:
            func_021BF7CC(*(void **)(p + 8), other, state[1] % 12 < 6 ? 1 : 0);
            state[1]++;
            break;
        case 2:
            break;
        }
        break;
    }
    return 0;
}
