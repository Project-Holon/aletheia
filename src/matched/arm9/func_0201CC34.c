/*
 * unit:     no
 * function: func_0201CC34
 * address:  0x0201CC34
 * packet:   pkt_0201CA78
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef unsigned int   u32;
extern void func_0201DD78(u32 r, u32 g, u32 b);

u16 *func_0201CC34(u16 *a0, u16 *a1)
{
    u16 t;
    u8 b;
    u8 m;
    int x;

    if (a1[0] == 0xF000) {
        t = (u16)(a1[1] & 0xFF);
    } else {
        t = 0xFFFF;
    }
    if (t == 0) {
        b = (u8)((a1[0] == 0xF000) ? a1[3] : 0);
        if (b == 0xFF) {
            func_0201DD78((u8)((a0[7] >> 10) & 0x1F), (u8)((a0[7] >> 5) & 0x1F),
                          (u8)(a0[7] & 0x1F));
        } else {
            int x1;
            int x2;
            x = b * 2;
            m = (u8)(a0[6] & 0x1F);
            x2 = x + 2;
            x1 = x + 1;
            func_0201DD78((u8)x1, (u8)x2, m);
            a0[7] = (u16)((((u8)x1 & 0x1F) << 10) | (((u8)x2 & 0x1F) << 5)
                          | (m & 0x1F));
        }
    }
    if (a1[0] == 0xF000) return (u16 *)((char *)a1 + 6 + a1[2] * 2);
    return a1;
}
