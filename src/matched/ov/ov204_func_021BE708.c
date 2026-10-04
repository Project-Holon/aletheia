/*
 * function: func_021BE708
 * address: 0x021BE708
 * packet: pkt_ov204_021BE708
 * region: ov204
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BD3A0 0x021BD3A0 thumb ov088
 *   func_021BF23C 0x021BF23C thumb ov204
 *   func_021BF2F4 0x021BF2F4 thumb ov204
 *   func_021BF560 0x021BF560 thumb ov204
 *   func_021BF580 0x021BF580 thumb ov204
 */
typedef unsigned char  u8;
extern int func_021BD3A0(unsigned char *p);
extern void func_021BF23C(char *p, void *a, int flag);
extern int func_021BF2F4(char *a);
extern void func_021BF560(u8 *p);
extern void func_021BF580(u8 *p);
int func_021BE708(char *p, int *state)
{
    switch (*state) {
    case 0:
        if (func_021BD3A0(*(void **)(p + 0xa4)) == 1)
            return 1;
        func_021BF23C(*(void **)(p + 0x18), (void *)5, 0);
        ++*state;
        break;
    case 1:
        if (func_021BF2F4(*(void **)(p + 0x18)) == 1) {
            func_021BF560(*(void **)(p + 0x18));
            ++*state;
        }
        break;
    case 2:
        if (func_021BD3A0(*(void **)(p + 0xa4)) == 1) {
            func_021BF580(*(void **)(p + 0x18));
            return 1;
        }
        break;
    }
    return 0;
}
