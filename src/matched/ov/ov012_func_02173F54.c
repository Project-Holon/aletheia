/*
 * function: func_02173F54
 * address: 0x02173F54
 * packet: pkt_ov012_02173F54
 * region: ov012
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02034714 0x02034714 arm
 *   func_02183FB8 0x02183FB8 thumb ov022
 *   func_02183FA8 0x02183FA8 thumb ov022
 *   d_02175624 0x02175624 data a1
 */
typedef unsigned char u8;
extern void func_02034714(void *, int, void *);
extern void func_02183FB8(int, void *, u8, int);
extern void func_02183FA8(int, u8);
extern u8 d_02175624[];
void func_02173F54(int a, int x, int y, u8 *p)
{
    if (*(int *)(p + 0x3528) == 0) {
        func_02034714(d_02175624, 0, d_02175624);
        return;
    }
    func_02183FB8(*(int *)(p + 0x3528), p, a, y);
    func_02183FA8(*(int *)(p + 0x3528), a);
}
