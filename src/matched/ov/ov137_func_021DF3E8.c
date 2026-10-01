/*
 * function: func_021DF3E8
 * address: 0x021DF3E8
 * packet: pkt_ov137_021DF3E8
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * tail: 021DF432..021DF434 is two zero alignment bytes.
 * symbols:
 *   func_021E0450 0x021E0450 thumb ov137
 */
typedef unsigned char u8;
extern void func_021E0450(void *, int, int, int);
int func_021DF3E8(u8 *p)
{
    int index, i, count, selected;
    index = (*(int **)(p + 40))[4];
    *(int *)(p + 92) = 0;
    for (i = 0; i < *(int *)(p + 48); i++) {
        selected = *(int *)(p + 748 + index * 180);
        func_021E0450(p, *(int *)(p + 164 + selected * 4), i, selected);
        count = *(int *)(p + 48);
        index = (index + 1) % count;
    }
    *(int *)(p + 12) = 0;
    *(int *)p = 36;
    return 0;
}
