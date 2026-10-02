/*
 * function: func_021D299C
 * address: 0x021D299C
 * packet: pkt_ov093_021D299C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021EA8E4 0x021EA8E4 thumb ov093
 *   func_021EA8F4 0x021EA8F4 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern void func_021EA8E4(void *);
extern int func_021EA8F4(void *);
int func_021D299C(char *p, int *state)
{
    switch (*state) {
    case 0:
        func_021EA8E4(*(void **)(p + 0x54));
        (*state)++;
        break;
    case 1:
        if (func_021EA8F4(*(void **)(p + 0x54)) != 0) return 1;
        break;
    }
    return 0;
}
