/*
 * function: func_021F2CC4
 * address:  0x021F2CC4
 * packet:   pkt_ov032_021F2CC4
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F2CC4 0x021F2CC4 thumb
 *   func_02028148 0x02028148 thumb
 *   func_02045808 0x02045808 arm
 *   func_02027FD8 0x02027FD8 thumb
 *   func_02028604 0x02028604 thumb
 */

extern void func_02028148(int);
extern void func_02045808(int);
extern void func_02027FD8(int);
extern int func_02028604(int a0);

void func_021F2CC4(char *p)
{
    int i;

    for (i = 0; i < 2; i++) {
        if (*(int *)(p + i * 16 + 0xf0) != 0) {
            func_02028148(*(int *)(p + i * 16 + 0xf0));
        }
        func_02045808(*(int *)(p + i * 16 + 0xf4));
    }
    for (i = 0; i < 3; i++) {
        if (*(int *)(p + i * 16 + 0xc0) != 0) {
            func_02028148(*(int *)(p + i * 16 + 0xc0));
        }
        func_02045808(*(int *)(p + i * 16 + 0xc4));
    }
    func_02027FD8(*(int *)(p + 0xb8));
    func_02028604(*(unsigned *)(p + 0xbc));
}
