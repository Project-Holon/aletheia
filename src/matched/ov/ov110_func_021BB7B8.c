/*
 * unit: yes
 * function: func_021BB7B8, func_021BB804
 * address: 0x021BB7B8
 * packet: pkt_ov110_021BB7B8
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * extent: includes the unlabelled tail-call stub at 0x021BB804.
 * symbols:
 *   func_021BC7DC 0x021BC7DC thumb ov110
 *   func_021BC8FC 0x021BC8FC thumb ov110
 *   func_021BC93C 0x021BC93C thumb ov110
 *   func_02040618 0x02040618 arm
 */
typedef unsigned char u8;
extern int func_021BC7DC(u8 *p);
extern void func_021BC8FC(u8 *p, int a, int start, int end, int n);
extern int func_021BC93C(u8 *p);
extern void func_02040618(unsigned, unsigned, unsigned);
int func_021BB7B8(u8 *p)
{
    switch (*(int *)(p + 0x10)) {
    case 0:
        if (func_021BC7DC(p + 0x38)) {
            func_021BC8FC(p + 0x18, 2, 0, -10, 16);
            ++*(int *)(p + 0x10);
        }
        break;
    case 1:
        return func_021BC93C(p + 0x18);
    }
    return 0;
}
void func_021BB804(void)
{
    func_02040618(1, 3, 16);
}
