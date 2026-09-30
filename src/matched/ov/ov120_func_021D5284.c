/*
 * function: func_021D5284
 * address: 0x021D5284
 * packet: pkt_ov120_021D5284
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D6E1C 0x021D6E1C thumb ov120
 *   func_021D6FF8 0x021D6FF8 thumb ov120
 *   func_021D822C 0x021D822C thumb ov120
 */
typedef unsigned char u8;
extern int func_021D6E1C(void *, void *);
extern void func_021D6FF8(void *, int);
extern void func_021D822C(void *, void *, int);
int func_021D5284(u8 *p)
{
    int result = func_021D6E1C(*(void **)(p + 0x3c), p + 0x150);
    switch (result) {
    case 0: break;
    case 1:
        if (*(int *)(p + 0x164) != 8)
            (*(int *)(p + 0x164))++;
        break;
    case 2:
        func_021D6FF8(*(void **)(p + 0x3c), 2);
        func_021D822C(*(void **)(p + 0x40), *(void **)(p + 0x2c), *(int *)(p + 0x158) + 2);
        break;
    }
    return result;
}
