/*
 * function: func_021F10D8
 * address:  0x021F10D8
 * packet:   pkt_ov032_021F10D8
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021F10D8 0x021F10D8 thumb
 *   func_02165CB4 0x02165CB4 thumb ov010
 *   func_020215BC 0x020215BC thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;

extern u8 func_02165CB4(int a);
extern void func_020215BC(int, void *, int, u16, u16);

void func_021F10D8(char *this, u8 *p, int a)
{
    u8 v;
    int k;

    p[3] = func_02165CB4(a);
    v = p[3];
    if (v == 0) {
        k = 0x30;
        v = 5;
    } else {
        k = 0x35;
    }
    func_020215BC(*(int *)(this + 0xac), *(u16 **)(this + 0x3c8) + 0x30, 3, (p[0] + 4) * 16 + 8, 10);
    func_020215BC(*(int *)(this + 0xac), *(u16 **)(this + 0x3c8) + k, 3, (p[0] + 4) * 16 + 8, v * 2);
}
