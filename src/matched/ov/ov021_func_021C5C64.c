/*
 * function: func_021C5C64
 * address:  0x021C5C64
 * packet:   pkt_ov021_021C5C64
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02188C98  0x02188C98  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_021A3364  0x021A3364  thumb  ov021
 *   func_02188CFC  0x02188CFC  thumb  ov021
 *   func_0218DAEC  0x0218DAEC  thumb
 *   func_021AB0F0  0x021AB0F0  thumb  ov021
 *   func_021AB2E8  0x021AB2E8  thumb  ov021
 *   func_021AB3B0  0x021AB3B0  thumb
 *   func_02164208  0x02164208  thumb  ov010
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_02188C98(u8 *p);
extern void *func_02188CB4(unsigned char *p);
extern void *func_021A3074(u8 *p);
extern u16 func_0216D5F8(void *p);
extern void func_021A3364(u32 *a, int b, int *out);
extern u32 func_02188CFC(u8 *p);
extern int func_0218DAEC(u32 a, int *b, u32 *out);
extern u16 func_021AB0F0(u32 attr);
extern int func_021AB2E8(u16 id);
extern int func_021AB3B0(u16 id);
extern void func_02164208(int dir, int *p, int amt);

int func_021C5C64(u32 unused, u32 a, u32 *out)
{
    int v[3];
    u32 w[4];
    void *h1;
    u32 r;
    u8 s;

    r = func_02188C98((u8 *)a);
    h1 = func_02188CB4((void *)a);
    s = func_0216D5F8(func_021A3074((void *)h1));
    func_021A3364(h1, s, v);
    if (func_02188CFC((u8 *)a) == 1)
        return 0;
    if (func_0218DAEC(r, v, w) == 0)
        return 0;
    if (func_021AB2E8(func_021AB0F0(w[2])) == 1) {
        func_02164208(s, v, 0x10000);
        if (func_0218DAEC(r, v, w) == 0)
            return 0;
    }
    if (func_021AB3B0(func_021AB0F0(w[2])) == 0)
        return 0;
    if (out != 0) {
        out[0] = v[0];
        out[1] = w[3];
        out[2] = v[2];
    }
    return 1;
}
