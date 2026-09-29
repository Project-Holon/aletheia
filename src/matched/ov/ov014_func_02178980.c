/*
 * function: func_02178980
 * address:  0x02178980
 * packet:   pkt_ov014_02178980
 * region:   ov014
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   g_021797A8     0x021797A8  data  a4
 *   func_02178138  0x02178138  thumb  ov014
 *   func_0217814C  0x0217814C  thumb  ov014
 *   func_021789C8  0x021789C8  thumb  ov014
 */

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

extern u8 *g_021797A8;
void func_02178138(int a);
void func_0217814C(int a);
int func_021789C8(void);

void func_02178980(u8 *m)
{
    u8 *g;

    g_021797A8[0x1EDF] = 0;
    if (*(u16 *)(m + 2) != 0) {
        func_0217814C(*(u16 *)(m + 2));
        return;
    }
    func_02178138(1);
    g = g_021797A8;
    if (*(u16 *)(g + 0x1EB4) != 0) {
        *(u16 *)(g + 0x1EB4) = 0;
        if (func_021789C8() == 0)
            func_02178138(9);
    }
}
