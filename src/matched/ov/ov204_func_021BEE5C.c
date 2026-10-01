/*
 * function: func_021BEE5C
 * address: 0x021BEE5C
 * packet: pkt_ov204_021BEE5C
 * region: ov204
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: hardware BLDALPHA write at 021BEEDC.
 * symbols:
 *   func_0207D63C 0x0207D63C arm
 *   func_0204B688 0x0204B688 arm
 *   func_0204B3DC 0x0204B3DC arm
 */
extern void func_0207D63C(volatile void *, int, int, int, int);
extern void func_0204B688(void *, unsigned);
extern void func_0204B3DC(void *, unsigned);
static inline void change_alpha(int a, int b)
{
    *(volatile unsigned short *)0x04000052 = (unsigned short)(a | (b << 8));
}
int func_021BEE5C(char *p, unsigned *state, unsigned *q)
{
    unsigned i;
    switch (*state) {
    case 0:
        func_0207D63C((volatile void *)0x04000050, 0, 12, 16, 0);
        for (i = 0; i < 3; i++)
            func_0204B688(*(void **)(p + 0x10a8 + i * 4), 1);
        ++*state;
        break;
    case 16:
        for (i = 0; i < 3; i++) {
            char *row = p + i * 4;
            func_0204B688(*(void **)(row + 0x10a8), 0);
            func_0204B3DC(*(void **)(row + 0x10a8), 0);
        }
        *state = 0;
        return 1;
    default:
        ++*state;
        change_alpha(16 - *state, *state);
        break;
    }
    return 0;
}
