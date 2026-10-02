/*
 * function: func_02161F14
 * address:  0x02161F14
 * packet:   pkt_ov010_02161F14
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021867C4  0x021867C4  thumb ov023
 *   func_0218682C  0x0218682C  thumb
 *   func_02186804  0x02186804  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;

extern int func_021867C4(int, int);
extern u16 *func_0218682C(int h);
extern void func_02186804(int);

void func_02161F14(u16 *out, u8 *in, int c)
{
    int h;
    u16 *q;
    if (*(u16 *)(in + 2) == 1) {
        h = func_021867C4(in[9], (u16)((c & 0x7FFF) | 0x8000));
        q = func_0218682C(h);
        out[0] = q[0x24 / 2];
        out[1] = q[8 / 2];
        func_02186804(h);
    } else {
        out[0] = 0;
        out[1] = 10;
    }
}
