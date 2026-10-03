/*
 * function: func_021D5230
 * address: 0x021D5230
 * packet: pkt_ov120_021D5230
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two zero padding bytes at 0x021D5282 precede labelled 0x021D5284.
 * symbols:
 *   func_021D6E50 0x021D6E50 thumb ov120
 *   func_021D6FF8 0x021D6FF8 thumb ov120
 *   func_021D82D8 0x021D82D8 thumb ov120
 */
typedef unsigned char u8;
extern int func_021D6E50(void *, void *);
extern void func_021D6FF8(u8 *p, int state);
extern void func_021D82D8(char *p, void *q, int n);
int func_021D5230(u8 *p)
{
    int result = func_021D6E50(*(void **)(p + 0x3c), p + 0x150);
    switch (result) {
    case 0: break;
    case 1:
        if (*(int *)(p + 0x164) != 6)
            (*(int *)(p + 0x164))--;
        break;
    case 2: {
        int index;
        func_021D6FF8(*(void **)(p + 0x3c), 1);
        index = *(int *)(p + 0x158) - 1;
        if (index >= 0)
            func_021D82D8(*(void **)(p + 0x40), *(void **)(p + 0x2c), index);
        break;
    }
    }
    return result;
}
