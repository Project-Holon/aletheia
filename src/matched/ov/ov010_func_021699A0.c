/*
 * function: func_021699A0
 * address:  0x021699A0
 * packet:   pkt_ov010_021699A0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0206DDA4  0x0206DDA4  arm
 *   func_02169A14  0x02169A14  thumb  ov010
 */

typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;

extern void func_0206DDA4(u32 cmd, const void *params, u32 n);
extern u32 func_02169A14(u32 a);

int func_021699A0(void *p)
{
    s16 v[6];
    u32 w[3];
    u32 one;
    char *q;
    int r;

    r = 1;
    q = p ? (char *)p + 0x14 : 0;
    v[0] = *(s16 *)(q + 0x18);
    v[1] = *(s16 *)(q + 0x1a);
    v[2] = *(s16 *)(q + 0x1c);
    v[3] = *(s16 *)(q + 0x1e);
    v[4] = *(s16 *)(q + 0x20);
    v[5] = *(s16 *)(q + 0x22);
    func_0206DDA4(0x11, 0, 0);
    w[0] = *(u32 *)(q + 0x24);
    w[1] = w[0];
    w[2] = w[0];
    func_0206DDA4(0x1b, w, 3);
    if (func_02169A14((u32)v) == 0)
        r = 0;
    one = 1;
    func_0206DDA4(0x12, &one, 1);
    return r;
}
